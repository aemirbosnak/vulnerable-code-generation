//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int numFiles = 0;
File files[MAX_FILES];

void createFile(char *name) {
    if (numFiles >= MAX_FILES) {
        printf("Error: Too many files\n");
        return;
    }
    strcpy(files[numFiles].name, name);
    files[numFiles].size = 0;
    numFiles++;
}

void deleteFile(char *name) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].data, 0, MAX_FILE_SIZE);
            strcpy(files[i].name, "");
            files[i].size = 0;
            break;
        }
    }
}

void writeFile(char *name, char *data) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (files[i].size + strlen(data) > MAX_FILE_SIZE) {
                printf("Error: File is full\n");
                return;
            }
            strcat(files[i].data, data);
            files[i].size += strlen(data);
            break;
        }
    }
}

void readFile(char *name, char *buffer) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(buffer, files[i].data);
            break;
        }
    }
}

void listFiles() {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (files[i].name[0]!= '\0') {
            printf("%s (%d bytes)\n", files[i].name, files[i].size);
        }
    }
}

int main() {
    createFile("test.txt");
    writeFile("test.txt", "Hello, world!");
    readFile("test.txt", "buffer");
    printf("%s\n", "buffer");
    deleteFile("test.txt");
    listFiles();
    return 0;
}