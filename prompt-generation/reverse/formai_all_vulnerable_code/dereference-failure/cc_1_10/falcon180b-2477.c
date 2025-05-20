//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int numFiles = 0;
File files[MAX_FILES];

void createFile(char* name, int size) {
    if (numFiles >= MAX_FILES) {
        printf("Error: Too many files\n");
        return;
    }
    strcpy(files[numFiles].name, name);
    files[numFiles].size = size;
    numFiles++;
}

void deleteFile(char* name) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].data, 0, files[i].size);
            numFiles--;
            return;
        }
    }
    printf("Error: File not found\n");
}

void writeFile(char* name, char* data) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(files[i].data, data, files[i].size);
            printf("File written successfully\n");
            return;
        }
    }
    printf("Error: File not found\n");
}

void readFile(char* name, char* buffer) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(buffer, files[i].data, files[i].size);
            printf("File read successfully\n");
            return;
        }
    }
    printf("Error: File not found\n");
}

void main() {
    createFile("test1.txt", 10);
    writeFile("test1.txt", "Hello World!");
    readFile("test1.txt", "buffer");
    printf("%s\n", "buffer");
    deleteFile("test1.txt");
}