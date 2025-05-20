//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char filePath[MAX_FILE_NAME_LENGTH];
} FileData;

int compareFileData(const void *a, const void *b) {
    const FileData *fileDataA = (const FileData *) a;
    const FileData *fileDataB = (const FileData *) b;

    return strcmp(fileDataA->fileName, fileDataB->fileName);
}

void printFileData(const FileData *fileData) {
    printf("FileName: %s\n", fileData->fileName);
    printf("FilePath: %s\n", fileData->filePath);
}

int main() {
    // Initialize variables
    int numFiles = 0;
    FileData *fileDataArray = NULL;

    // Get number of files from user
    printf("Enter number of files: ");
    scanf("%d", &numFiles);

    // Allocate memory for fileDataArray
    fileDataArray = (FileData *) malloc(numFiles * sizeof(FileData));

    // Get file data from user
    for (int i = 0; i < numFiles; i++) {
        printf("Enter file %d data:\n", i + 1);
        printf("FileName: ");
        scanf("%s", fileDataArray[i].fileName);
        printf("FilePath: ");
        scanf("%s", fileDataArray[i].filePath);
    }

    // Sort fileDataArray by fileName
    qsort(fileDataArray, numFiles, sizeof(FileData), compareFileData);

    // Print sorted fileDataArray
    printf("Sorted by file name:\n");
    for (int i = 0; i < numFiles; i++) {
        printFileData(&fileDataArray[i]);
    }

    // Free memory
    free(fileDataArray);

    return 0;
}