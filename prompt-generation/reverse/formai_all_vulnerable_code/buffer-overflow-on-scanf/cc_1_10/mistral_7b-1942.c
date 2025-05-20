//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_BACKUP_NAME_LEN 512
#define BACKUP_EXTENSION ".bkp"

struct FileInfo {
    char name[MAX_FILE_NAME_LEN];
    time_t lastModified;
};

void backupFile(const char* filePath) {
    FILE* srcFile = fopen(filePath, "rb");
    char backupFileName[MAX_BACKUP_NAME_LEN];
    struct FileInfo* fileInfo = (struct FileInfo*)calloc(1, sizeof(struct FileInfo));

    if (!srcFile || !fileInfo) {
        fprintf(stderr, "Error: Could not open file or allocate memory.\n");
        if (srcFile) fclose(srcFile);
        if (fileInfo) free(fileInfo);
        return;
    }

    strcpy(fileInfo->name, filePath);
    fileInfo->lastModified = time(NULL);

    strcpy(backupFileName, filePath);
    strcat(backupFileName, BACKUP_EXTENSION);

    FILE* destFile = fopen(backupFileName, "wb");

    if (!destFile) {
        fprintf(stderr, "Error: Could not create backup file.\n");
        if (srcFile) fclose(srcFile);
        if (fileInfo) free(fileInfo);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);

    printf("Backed up file \"%s\" to \"%s\".\n", filePath, backupFileName);

    free(fileInfo);
}

int main() {
    char inputFilePath[MAX_FILE_NAME_LEN];

    printf("Hello there! I'm a cheerful file backup system.\n");
    printf("Enter the file path you'd like to backup: ");
    scanf("%s", inputFilePath);

    backupFile(inputFilePath);

    printf("File backup complete! Keep your files safe and sound!\n");
    return 0;
}