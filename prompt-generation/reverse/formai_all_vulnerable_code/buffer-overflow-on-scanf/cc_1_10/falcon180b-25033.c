//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_FILE_CONTENT_LENGTH 1000000

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    char fileContent[MAX_FILE_CONTENT_LENGTH];
} File;

void backupFile(File *file) {
    FILE *backupFile = fopen("backup.txt", "a");
    if (backupFile == NULL) {
        printf("Error: could not open backup file.\n");
        exit(1);
    }

    fprintf(backupFile, "File Name: %s\n", file->fileName);
    fprintf(backupFile, "File Content:\n");
    fprintf(backupFile, "%s", file->fileContent);

    fclose(backupFile);
}

int main() {
    File file;

    printf("Enter file name: ");
    scanf("%s", file.fileName);

    FILE *filePointer = fopen(file.fileName, "r");
    if (filePointer == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char ch;
    int fileContentLength = 0;
    while ((ch = fgetc(filePointer))!= EOF) {
        if (fileContentLength >= MAX_FILE_CONTENT_LENGTH) {
            printf("Error: file content is too long.\n");
            exit(1);
        }
        file.fileContent[fileContentLength++] = ch;
    }

    fclose(filePointer);

    backupFile(&file);

    printf("File backed up successfully.\n");

    return 0;
}