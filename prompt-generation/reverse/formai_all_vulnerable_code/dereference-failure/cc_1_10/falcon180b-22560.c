//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: futuristic
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

File fileSystem[MAX_FILES];
int numFiles = 0;

void createFile(char* name, int size) {
    strcpy(fileSystem[numFiles].name, name);
    fileSystem[numFiles].size = size;
    numFiles++;
}

void deleteFile(char* name) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(fileSystem[i].name, name) == 0) {
            memset(&fileSystem[i], 0, sizeof(File));
            numFiles--;
            return;
        }
    }
}

void renameFile(char* oldName, char* newName) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(fileSystem[i].name, oldName) == 0) {
            strcpy(fileSystem[i].name, newName);
            return;
        }
    }
}

void writeFile(char* name, char* data, int size) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(fileSystem[i].name, name) == 0) {
            strcpy(fileSystem[i].data, data);
            fileSystem[i].size = size;
            return;
        }
    }
}

void readFile(char* name, char* data, int size) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(fileSystem[i].name, name) == 0) {
            strcpy(data, fileSystem[i].data);
            return;
        }
    }
}

int main() {
    createFile("test.txt", 10);
    writeFile("test.txt", "Hello World!", 11);
    readFile("test.txt", "data", 5);
    printf("%s\n", "data");
    renameFile("test.txt", "test2.txt");
    deleteFile("test2.txt");
    return 0;
}