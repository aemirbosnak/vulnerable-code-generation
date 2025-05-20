//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char content[MAX_FILE_SIZE];
} File;

File files[MAX_FILES];
int numFiles;

void createFile(char* name, int size) {
    strcpy(files[numFiles].name, name);
    files[numFiles].size = size;
    files[numFiles].content[0] = '\0';
    numFiles++;
}

void deleteFile(char* name) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            numFiles--;
            memmove(&files[i], &files[i+1], (numFiles - i) * sizeof(File));
            break;
        }
    }
}

void renameFile(char* oldName, char* newName) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, oldName) == 0) {
            strcpy(files[i].name, newName);
            break;
        }
    }
}

void readFile(char* name, char* buffer, int size) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memcpy(buffer, files[i].content, size);
            break;
        }
    }
}

void writeFile(char* name, char* buffer, int size) {
    int i;
    for (i = 0; i < numFiles; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(files[i].content, buffer, size);
            files[i].content[size] = '\0';
            break;
        }
    }
}

int main() {
    createFile("test.txt", 10);
    writeFile("test.txt", "Hello World", 11);
    readFile("test.txt", "buffer", 11);
    printf("%s\n", "buffer");
    deleteFile("test.txt");
    return 0;
}