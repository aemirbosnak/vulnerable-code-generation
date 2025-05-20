//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 100

typedef struct BackupFile {
    char fileName[MAX_FILE_NAME_LENGTH];
    int fileSize;
    char backupFileName[MAX_FILE_NAME_LENGTH];
} BackupFile;

void backupFile(BackupFile *backup, char *fileName, int fileSize) {
    strcpy(backup->fileName, fileName);
    backup->fileSize = fileSize;
    strcpy(backup->backupFileName, fileName);
    strcat(backup->backupFileName, ".bak");
}

void printBackupFiles(BackupFile *backups, int numBackups) {
    printf("Backup Files:\n");
    for (int i = 0; i < numBackups; i++) {
        printf("Name: %s\nSize: %d bytes\nBackup File: %s\n", backups[i].fileName, backups[i].fileSize, backups[i].backupFileName);
    }
}

int main() {
    BackupFile backups[MAX_BACKUP_FILES];
    int numBackups = 0;

    char fileName[MAX_FILE_NAME_LENGTH];
    char backupFileName[MAX_FILE_NAME_LENGTH];

    while (1) {
        printf("Enter file name to backup (or type 'exit' to quit): ");
        scanf("%s", fileName);

        if (strcmp(fileName, "exit") == 0) {
            break;
        }

        FILE *file = fopen(fileName, "rb");
        if (file == NULL) {
            printf("Error: File not found.\n");
            continue;
        }

        fseek(file, 0, SEEK_END);
        int fileSize = ftell(file);
        rewind(file);

        BackupFile backup;
        backupFile(&backup, fileName, fileSize);

        fclose(file);

        for (int i = 0; i < numBackups; i++) {
            if (strcmp(backups[i].fileName, fileName) == 0) {
                printf("File already backed up.\n");
                return 0;
            }
        }

        strcpy(backupFileName, fileName);
        strcat(backupFileName, ".bak");

        FILE *backupFile = fopen(backupFileName, "wb");
        if (backupFile == NULL) {
            printf("Error: Could not create backup file.\n");
            return 0;
        }

        char buffer[1024];
        int bytesRead;
        while ((bytesRead = fread(buffer, 1, 1024, file)) > 0) {
            fwrite(buffer, 1, bytesRead, backupFile);
        }

        fclose(file);
        fclose(backupFile);

        backups[numBackups++] = backup;
    }

    printBackupFiles(backups, numBackups);

    return 0;
}