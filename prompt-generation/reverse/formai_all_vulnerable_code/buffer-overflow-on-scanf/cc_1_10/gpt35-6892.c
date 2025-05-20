//FormAI DATASET v1.0 Category: File system simulation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
struct file{
    char fileName[20];
    int fileSize;
    int startBlock;
}f[10];
int blocks[100];
int n;  // number of files
void createFiles(){
    printf("\nEnter the number of files : ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        printf("\nEnter the name of file (maximum 20 characters) : ");
        scanf("%s",f[i].fileName);
        printf("\nEnter the size of the file (in blocks) : ");
        scanf("%d",&f[i].fileSize);
        int j,k=0;
        for(j=0;j<100;j++){
            if(blocks[j]==0){
                k++;
                if(k==f[i].fileSize){
                    f[i].startBlock=j-k+1;
                    break;
                }
            }
            else
                k=0;
        }
        int l;
        for(l=f[i].startBlock;l<f[i].startBlock+f[i].fileSize;l++)
            blocks[l]=1;
    }
}
void displayFiles(){
    printf("\n\nFile Allocation Table\n");
    printf("---------------------------------------------------------\n");
    printf("FileName\tFileSize\tStartBlock\tEndBlock\n");
    printf("---------------------------------------------------------\n");
    int i;
    for(i=0;i<n;i++){
        printf("%s\t\t%d\t\t%d\t\t%d\n",f[i].fileName,f[i].fileSize,f[i].startBlock,f[i].startBlock+f[i].fileSize-1);
    }
}
void deleteFile(char str[]){
    int i,j;
    for(i=0;i<n;i++){
        if(strcmp(f[i].fileName,str)==0){
            for(j=f[i].startBlock;j<f[i].startBlock+f[i].fileSize;j++)
                blocks[j]=0;
            f[i].fileSize=0;
            printf("\n%s deleted successfully!",str);
            return;
        }
    }
    printf("\nSorry, file not found!");
}
int main(){
    int choice;
    printf("\nFile System Simulation\n");
    while(1){
        printf("\n1. Create files\n2. Display files\n3. Delete file\n4. Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : createFiles();
                     break;
            case 2 : displayFiles();
                     break;
            case 3 : {
                        char fileName[20];
                        printf("\nEnter the name of file to delete : ");
                        scanf("%s",fileName);
                        deleteFile(fileName);
                     }
                     break;
            case 4 : exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}