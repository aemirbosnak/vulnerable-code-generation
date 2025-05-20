//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 50
#define MAX_FILENAME_LEN 100

struct FileInfo {
    char filename[MAX_FILENAME_LEN];
    char backupFilename[MAX_FILENAME_LEN];
    time_t lastBackupTime;
};

struct FileInfo fileInfos[MAX_FILES];
int numFiles = 0;

void createBackup(char *filename) {
    FILE *srcFile, *dstFile;
    char srcFileName[MAX_FILENAME_LEN];
    char dstFileName[MAX_FILENAME_LEN];
    struct FileInfo *fileInfo;
    int i;

    strcpy(srcFileName, filename);
    strcat(srcFileName, ".orig"); // Add .orig extension for backup files

    if ((srcFile = fopen(srcFileName, "rb")) == NULL) {
        printf("Error: Unable to read file %s for backup\n", srcFileName);
        return;
    }

    strcpy(dstFileName, filename);
    strcat(dstFileName, ".bak"); // Add .bak extension for backup files

    for (i = 0; i < numFiles; i++) {
        if (strcmp(fileInfos[i].filename, dstFileName) == 0) {
            printf("Warning: File %s already has a backup\n", dstFileName);
            fclose(srcFile);
            return;
        }
    }

    if ((dstFile = fopen(dstFileName, "wb")) == NULL) {
        printf("Error: Unable to create backup file %s\n", dstFileName);
        fclose(srcFile);
        return;
    }

    fileInfo = &fileInfos[numFiles];
    strcpy(fileInfo->filename, dstFileName);
    strcpy(fileInfo->backupFilename, srcFileName);
    fileInfo->lastBackupTime = time(NULL);

    while (1) {
        size_t read = fread(fileInfo->backupFilename + numFiles * sizeof(struct FileInfo), 1, 1, srcFile);
        if (read == 1) {
            fwrite(fileInfo->backupFilename + numFiles * sizeof(struct FileInfo), 1, 1, dstFile);
        } else {
            break;
        }
    }

    fclose(srcFile);
    fclose(dstFile);

    numFiles++;
    printf("Backup created successfully for file %s\n", dstFileName);
}

void listBackups() {
    int i;

    printf("\nListing backup files:\n");
    for (i = 0; i < numFiles; i++) {
        printf("%s -> %s (Last backup: %s)\n", fileInfos[i].filename, fileInfos[i].backupFilename, ctime(&fileInfos[i].lastBackupTime));
    }
}

int main() {
    char filename[MAX_FILENAME_LEN];

    while (1) {
        printf("\nHappy File Backup System!\n");
        printf("Enter a file name to backup (or type 'exit' to quit): ");
        scanf("%s", filename);

        if (strcmp(filename, "exit") == 0) {
            break;
        }

        createBackup(filename);
    }

    listBackups();

    return 0;
}