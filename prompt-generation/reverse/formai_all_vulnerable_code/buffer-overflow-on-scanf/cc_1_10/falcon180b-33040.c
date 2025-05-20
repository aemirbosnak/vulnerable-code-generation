//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

int numFiles = 0;
File files[MAX_FILES];

void createFile(char* name) {
    strcpy(files[numFiles].name, name);
    files[numFiles].size = 0;
    numFiles++;
}

void deleteFile(char* name) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].data, 0, MAX_FILE_SIZE);
            numFiles--;
            break;
        }
    }
}

void writeFile(char* name, char* data) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcat(files[i].data, data);
            files[i].size += strlen(data);
            break;
        }
    }
}

void readFile(char* name) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("%s", files[i].data);
            break;
        }
    }
}

int main() {
    char cmd[100];
    while (1) {
        printf("> ");
        scanf("%s", cmd);
        if (strcmp(cmd, "exit") == 0) {
            break;
        } else if (strcmp(cmd, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            createFile(name);
        } else if (strcmp(cmd, "delete") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            deleteFile(name);
        } else if (strcmp(cmd, "write") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            char data[MAX_FILE_SIZE];
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter data: ");
            scanf("%s", data);
            writeFile(name, data);
        } else if (strcmp(cmd, "read") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            readFile(name);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}