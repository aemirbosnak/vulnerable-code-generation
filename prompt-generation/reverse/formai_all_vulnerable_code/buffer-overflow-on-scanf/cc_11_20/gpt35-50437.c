//FormAI DATASET v1.0 Category: File Backup System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024

typedef struct file{
        char name[50];
        char content[MAX_FILE_SIZE];
    }File;

int main(){

    File files[10];
    int numFiles = 0;

    while(1){
        printf("\n1. Add file\n");
        printf("2. Delete file\n");
        printf("3. Show all files\n");
        printf("4. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                if(numFiles == 10){
                    printf("\nMaximum number of files reached!\n");
                    break;
                }
                printf("\nEnter file name: ");
                scanf("%s", files[numFiles].name);
                printf("Enter file content: ");
                scanf(" %[^\n]", files[numFiles].content);
                numFiles++;
                printf("\nFile backed up successfully!\n");
                break;
            case 2: 
                if(numFiles == 0){
                    printf("\nThere are no files to delete!\n");
                    break;
                }
                printf("\nEnter file name to delete: ");
                char deleteFile[50];
                scanf("%s", deleteFile);
                int deleteIndex = -1;
                for(int i=0; i<numFiles; i++){
                    if(!strcmp(files[i].name, deleteFile)){
                        deleteIndex = i;
                        break;
                    }
                }
                if(deleteIndex == -1){
                    printf("\nFile not found!\n");
                    break;
                }
                for(int i=deleteIndex; i<numFiles-1; i++){
                    files[i] = files[i+1];
                }
                numFiles--;
                printf("\nFile deleted successfully!\n");
                break;
            case 3: 
                if(numFiles == 0){
                    printf("\nNo files to show!\n");
                    break;
                }
                printf("\n");
                for(int i=0; i<numFiles; i++){
                    printf("%d. File Name: %s\n",i+1, files[i].name);
                    printf("   File Content: %s\n", files[i].content);
                }
                break;
            case 4: 
                printf("\nExiting program!");
                exit(0);
            default: 
                printf("\nInvalid Choice!");
        }

    }
    return 0;
}