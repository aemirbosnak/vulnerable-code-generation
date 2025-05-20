//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 64
#define MAX_FILE_CONTENT_LENGTH 1024
#define MAX_NUM_FILES 100

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char fileContent[MAX_FILE_CONTENT_LENGTH];
} File;

int numFiles = 0;
File files[MAX_NUM_FILES];

void createFile(char* fileName, char* fileContent) {
    if (numFiles >= MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[numFiles].fileName, fileName);
    strcpy(files[numFiles].fileContent, fileContent);

    numFiles++;
}

void deleteFile(char* fileName) {
    int i;

    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].fileName, fileName) == 0) {
            memset(files[i].fileContent, 0, sizeof(files[i].fileContent));
            strcpy(files[i].fileName, "");
            numFiles--;

            printf("File deleted successfully.\n");
            return;
        }
    }

    printf("Error: File not found.\n");
}

void renameFile(char* oldFileName, char* newFileName) {
    int i;

    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].fileName, oldFileName) == 0) {
            strcpy(files[i].fileName, newFileName);

            printf("File renamed successfully.\n");
            return;
        }
    }

    printf("Error: File not found.\n");
}

void viewFile(char* fileName) {
    int i;

    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].fileName, fileName) == 0) {
            printf("File content:\n%s\n", files[i].fileContent);

            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    char command[100];

    while (1) {
        printf("Enter command (create/delete/rename/view/exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char fileName[MAX_FILE_NAME_LENGTH];
            char fileContent[MAX_FILE_CONTENT_LENGTH];

            printf("Enter file name: ");
            scanf("%s", fileName);

            printf("Enter file content: ");
            scanf("%s", fileContent);

            createFile(fileName, fileContent);
        } else if (strcmp(command, "delete") == 0) {
            char fileName[MAX_FILE_NAME_LENGTH];

            printf("Enter file name: ");
            scanf("%s", fileName);

            deleteFile(fileName);
        } else if (strcmp(command, "rename") == 0) {
            char oldFileName[MAX_FILE_NAME_LENGTH];
            char newFileName[MAX_FILE_NAME_LENGTH];

            printf("Enter old file name: ");
            scanf("%s", oldFileName);

            printf("Enter new file name: ");
            scanf("%s", newFileName);

            renameFile(oldFileName, newFileName);
        } else if (strcmp(command, "view") == 0) {
            char fileName[MAX_FILE_NAME_LENGTH];

            printf("Enter file name: ");
            scanf("%s", fileName);

            viewFile(fileName);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}