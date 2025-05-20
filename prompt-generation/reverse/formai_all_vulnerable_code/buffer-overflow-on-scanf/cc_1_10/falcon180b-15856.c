//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_DATA_LEN 1000

typedef struct {
    char fileName[MAX_FILE_NAME_LEN];
    char fileData[MAX_FILE_DATA_LEN];
    int fileSize;
} File;

int createFile(File* file, char* fileName, char* fileData, int fileSize) {
    strcpy(file->fileName, fileName);
    strcpy(file->fileData, fileData);
    file->fileSize = fileSize;

    printf("File created successfully!\n");

    return 0;
}

int readFile(File* file) {
    printf("File data:\n%s\n", file->fileData);

    return 0;
}

int writeFile(File* file, char* fileData, int fileSize) {
    strcpy(file->fileData, fileData);
    file->fileSize = fileSize;

    printf("File data updated successfully!\n");

    return 0;
}

int deleteFile(File* file) {
    printf("File deleted successfully!\n");

    return 0;
}

int main() {
    File file;
    char fileName[MAX_FILE_NAME_LEN];
    char fileData[MAX_FILE_DATA_LEN];
    int fileSize;

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter file data: ");
    scanf("%s", fileData);

    printf("Enter file size: ");
    scanf("%d", &fileSize);

    createFile(&file, fileName, fileData, fileSize);
    readFile(&file);
    writeFile(&file, "Updated file data", 20);
    readFile(&file);
    deleteFile(&file);

    return 0;
}