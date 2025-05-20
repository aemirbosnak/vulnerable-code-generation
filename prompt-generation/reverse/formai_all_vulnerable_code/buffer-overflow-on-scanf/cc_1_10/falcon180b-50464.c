//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_EXTENSION ".bak"

typedef enum {
    FILE_NOT_FOUND,
    FILE_COPIED,
    BACKUP_FAILED
} BackupStatus;

typedef struct {
    char sourceFilePath[MAX_FILE_NAME_LENGTH];
    char destinationFilePath[MAX_FILE_NAME_LENGTH];
} FileInfo;

BackupStatus backupFile(FileInfo *fileInfo) {
    FILE *sourceFile, *destFile;
    char backupFilePath[MAX_FILE_NAME_LENGTH];
    strcat(fileInfo->destinationFilePath, BACKUP_EXTENSION);
    strcpy(backupFilePath, fileInfo->destinationFilePath);

    sourceFile = fopen(fileInfo->sourceFilePath, "r");
    if (sourceFile == NULL) {
        printf("Error: %s not found.\n", fileInfo->sourceFilePath);
        return FILE_NOT_FOUND;
    }

    destFile = fopen(backupFilePath, "w");
    if (destFile == NULL) {
        printf("Error: Failed to create backup file %s.\n", backupFilePath);
        return BACKUP_FAILED;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, sourceFile)!= NULL) {
        fputs(buffer, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    printf("Backup of %s created successfully.\n", fileInfo->sourceFilePath);
    return FILE_COPIED;
}

int main() {
    FileInfo fileInfo;

    printf("Enter the path of the file to backup: ");
    scanf("%s", fileInfo.sourceFilePath);

    printf("Enter the destination path for the backup file: ");
    scanf("%s", fileInfo.destinationFilePath);

    BackupStatus status = backupFile(&fileInfo);

    switch (status) {
        case FILE_NOT_FOUND:
            printf("Backup failed: File not found.\n");
            break;
        case FILE_COPIED:
            printf("Backup successful.\n");
            break;
        case BACKUP_FAILED:
            printf("Backup failed.\n");
            break;
    }

    return 0;
}