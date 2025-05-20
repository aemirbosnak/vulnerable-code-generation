//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

typedef struct {
    char name[50];
    int size;
    char content[100];
} File;

File files[MAX_FILES];
int numFiles = 0;

void createFile() {
    printf("Enter file name: ");
    scanf("%s", files[numFiles].name);
    printf("Enter file size: ");
    scanf("%d", &files[numFiles].size);
    printf("Enter file content: ");
    scanf("%s", files[numFiles].content);
    numFiles++;
}

void deleteFile() {
    printf("Enter file name to delete: ");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(name, files[i].name) == 0) {
            memset(&files[i], 0, sizeof(File));
            numFiles--;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void listFiles() {
    printf("File name\tFile size\n");
    int i;
    for (i = 0; i < numFiles; i++) {
        printf("%s\t%d\n", files[i].name, files[i].size);
    }
}

void main() {
    int choice;
    while (1) {
        printf("1. Create file\n2. Delete file\n3. List files\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                listFiles();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}