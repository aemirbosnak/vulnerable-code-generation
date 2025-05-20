//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

typedef struct {
    char name[20];
    int size;
    int type;
    char content[100];
} File;

int numFiles = 0;
File files[MAX_FILES];

int main() {
    printf("Welcome to the File System Simulation!\n");
    while(1) {
        printf("\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. View File\n");
        printf("4. Exit\n");
        printf("\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(numFiles >= MAX_FILES) {
                    printf("Maximum number of files reached.\n");
                } else {
                    printf("Enter File Name: ");
                    scanf("%s", files[numFiles].name);
                    printf("Enter File Size: ");
                    scanf("%d", &files[numFiles].size);
                    printf("Enter File Type (0 for Text, 1 for Image): ");
                    scanf("%d", &files[numFiles].type);
                    printf("Enter File Content: ");
                    scanf("%s", files[numFiles].content);
                    numFiles++;
                    printf("File Created Successfully!\n");
                }
                break;
            case 2:
                printf("Enter File Name to Delete: ");
                scanf("%s", files[numFiles].name);
                for(int i=0;i<numFiles;i++) {
                    if(strcmp(files[i].name, files[numFiles].name) == 0) {
                        numFiles--;
                        printf("File Deleted Successfully!\n");
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter File Name to View: ");
                scanf("%s", files[numFiles].name);
                for(int i=0;i<numFiles;i++) {
                    if(strcmp(files[i].name, files[numFiles].name) == 0) {
                        printf("File Name: %s\n", files[i].name);
                        printf("File Size: %d\n", files[i].size);
                        printf("File Type: %d\n", files[i].type);
                        printf("File Content: %s\n", files[i].content);
                        break;
                    }
                }
                break;
            case 4:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}