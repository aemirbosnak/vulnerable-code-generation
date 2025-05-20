//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define BUFFER_SIZE 1024

typedef struct {
    char filename[100];
    int size;
    int modified;
} FileInfo;

FileInfo fileList[100];
int numFiles = 0;

void addFile(char* filename) {
    strcpy(fileList[numFiles].filename, filename);
    fileList[numFiles].size = 0;
    fileList[numFiles].modified = 0;
    numFiles++;
}

int compareFiles(const void* a, const void* b) {
    FileInfo* fileA = (FileInfo*)a;
    FileInfo* fileB = (FileInfo*)b;

    if (fileA->size > fileB->size) {
        return 1;
    } else if (fileA->size < fileB->size) {
        return -1;
    } else {
        return 0;
    }
}

void sortFiles() {
    qsort(fileList, numFiles, sizeof(FileInfo), compareFiles);
}

void printFileList() {
    printf("File List:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s (%d bytes)\n", fileList[i].filename, fileList[i].size);
    }
}

int main() {
    char dirPath[100];
    printf("Enter directory path: ");
    scanf("%s", dirPath);

    FILE* fp = fopen(dirPath, "r");
    if (fp == NULL) {
        printf("Error: Directory does not exist.\n");
        return 1;
    }

    while ((fileList[numFiles].filename[0] = fgetc(fp))!= EOF) {
        int index = 0;
        while (fileList[numFiles].filename[index]!= '\0') {
            if (fileList[numFiles].filename[index] == '.') {
                strcat(fileList[numFiles].filename, "txt");
                break;
            }
            index++;
        }
        addFile(fileList[numFiles].filename);
    }

    fclose(fp);

    sortFiles();

    printf("Sorted File List:\n");
    printFileList();

    return 0;
}