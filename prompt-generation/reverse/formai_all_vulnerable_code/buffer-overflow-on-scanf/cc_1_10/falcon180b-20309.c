//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_NUM_FILES 100

typedef struct {
    char filename[MAX_STRING_LENGTH];
    int filesize;
    int isDeleted;
} FileInfo;

int numFiles = 0;
FileInfo files[MAX_NUM_FILES];

void addFile(char* filename, int filesize, int isDeleted) {
    if (numFiles >= MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    strcpy(files[numFiles].filename, filename);
    files[numFiles].filesize = filesize;
    files[numFiles].isDeleted = isDeleted;
    numFiles++;
}

void deleteFile(char* filename) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            files[i].isDeleted = 1;
            printf("File %s deleted.\n", filename);
            return;
        }
    }
    printf("File %s not found.\n", filename);
}

void recoverFiles() {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (files[i].isDeleted == 1) {
            printf("Recovering file %s...\n", files[i].filename);
            files[i].isDeleted = 0;
        }
    }
}

int main() {
    char command[MAX_STRING_LENGTH];
    while (1) {
        printf("Enter command (add/delete/recover/exit): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char filename[MAX_STRING_LENGTH];
            int filesize, isDeleted;
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter filesize: ");
            scanf("%d", &filesize);
            printf("Enter isDeleted (0 or 1): ");
            scanf("%d", &isDeleted);
            addFile(filename, filesize, isDeleted);
        } else if (strcmp(command, "delete") == 0) {
            char filename[MAX_STRING_LENGTH];
            printf("Enter filename: ");
            scanf("%s", filename);
            deleteFile(filename);
        } else if (strcmp(command, "recover") == 0) {
            recoverFiles();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}