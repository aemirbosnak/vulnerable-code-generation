//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 100
#define BACKUP_DIR "backup/"

typedef struct FileData {
    char fileName[FILE_NAME_LENGTH];
    char fileContent[1024];
    time_t lastBackupTime;
} FileData;

FileData files[MAX_FILES];
int fileCount = 0;

void backupFile(char *fileName) {
    FILE *srcFile = fopen(fileName, "rb");
    FileData *fileData = NULL;

    if (srcFile == NULL) {
        printf("Error: Unable to open file %s for reading.\n", fileName);
        return;
    }

    if (fileCount >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        fclose(srcFile);
        return;
    }

    fileData = &files[fileCount];

    strcpy(fileData->fileName, fileName);
    fread(fileData->fileContent, sizeof(char), 1024, srcFile);
    fileData->lastBackupTime = time(NULL);

    char backupFileName[FILE_NAME_LENGTH];
    strcpy(backupFileName, BACKUP_DIR);
    strcat(backupFileName, fileData->fileName);
    FILE *destFile = fopen(backupFileName, "wb");

    if (destFile == NULL) {
        printf("Error: Unable to open backup file %s for writing.\n", backupFileName);
        fclose(srcFile);
        return;
    }

    fwrite(fileData->fileContent, sizeof(char), strlen(fileData->fileContent), destFile);
    fclose(srcFile);
    fclose(destFile);

    fileCount++;
    printf("File %s backed up successfully.\n", fileName);
}

int main() {
    char fileName[FILE_NAME_LENGTH];

    while (1) {
        printf("Enter file name to backup (or 'quit' to exit): ");
        scanf("%s", fileName);

        if (strcmp(fileName, "quit") == 0) {
            break;
        }

        backupFile(fileName);
    }

    return 0;
}