#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct FileSystem{
	char name[20];
	int st_blk, nof_blk, filled=0;
};

int main(){
	int spc_avail, i, j, ch=1, spc_giv;
	printf("\nEnter Space Available In File System: ");
	scanf("%d", &spc_avail);
	int spc_fill_num = spc_avail/3;
	int spc_fill_count = rand()%spc_fill_num;
	struct FileSystem FS[spc_avail];
	for(i=0; i<spc_fill_count; i++){
		int spc_fill_num = rand()%spc_avail;
		strcpy(FS[spc_fill_num].name, "Filled Space");
		FS[spc_fill_num].nof_blk = 1;
		FS[spc_fill_num].st_blk = spc_fill_num;
		FS[spc_fill_num].filled = 1;
		printf("\n\nThe Space At Block %d is Filled By File Of Name %s", FS[spc_fill_num].st_blk, FS[spc_fill_num].name);
	}
	while(ch==1){
		printf("\nEnter Start Block: ");
		scanf("%d", &spc_fill_num);
		FS[spc_fill_num].st_blk = spc_fill_num;
		printf("\nEnter File Name: ");
		scanf("%s", FS[spc_fill_num].name);
		printf("\nEnter Number Of Blocks: ");
		scanf("%d", &FS[spc_fill_num].nof_blk);
		int spc_all = FS[spc_fill_num].nof_blk, cnt_spc = 0;
		for(i=0; i<spc_all; i++){
				if(FS[spc_fill_num + i].filled == 1){
						spc_fill_num = spc_fill_num + i + 1;
						cnt_spc = 0, i = 0;
				}
				else{
						++cnt_spc;
						printf("%d, ", cnt_spc);
				}			
		}
		printf("%d, ", FS[spc_fill_num].st_blk-1);
		if(cnt_spc == FS[spc_fill_num].nof_blk - 1){
			printf("\nFile Allocated From Block %d to Block %d", FS[spc_fill_num].st_blk, FS[spc_fill_num].st_blk+cnt_spc);
			for(j=0; j<cnt_spc; j++){
				FS[spc_fill_num + j].filled = 1;
			}
		}
		else{
			printf("\nCouldn't Allocate File, Not Enough Continuous Space Available");
		}
		printf("\nEnter 1 to Add new file, 0 to exit : ");
		scanf("%d",&ch);
		if(ch==2)
			exit(0);
	}
}
