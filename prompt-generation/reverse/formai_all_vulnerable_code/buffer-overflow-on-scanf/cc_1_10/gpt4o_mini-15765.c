//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define MAX_PATH 512

void displayFiles(const char *directory, char files[MAX_FILES][MAX_PATH], int *fileCount) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            strcpy(files[*fileCount], entry->d_name);
            (*fileCount)++;
        }
    }
    closedir(dp);
}

void displayFileList(char files[MAX_FILES][MAX_PATH], int fileCount) {
    printf("Available files:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%d: %s\n", i + 1, files[i]);
    }
}

int backupFile(const char *sourceFile, const char *backupDir) {
    char backupFilePath[MAX_PATH];
    snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s.bak", backupDir, sourceFile);

    FILE *src = fopen(sourceFile, "rb");
    if (!src) {
        perror("fopen source");
        return -1;
    }

    FILE *dest = fopen(backupFilePath, "wb");
    if (!dest) {
        perror("fopen destination");
        fclose(src);
        return -1;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

int main() {
    char files[MAX_FILES][MAX_PATH];
    int fileCount = 0;
    char directory[MAX_PATH];
    char backupDir[MAX_PATH];
    int fileIndex;

    printf("Enter the directory to back up files from: ");
    scanf("%s", directory);
    displayFiles(directory, files, &fileCount);
    
    if (fileCount == 0) {
        printf("No files found in the directory.\n");
        return 1;
    }

    displayFileList(files, fileCount);

    printf("Enter the number of the file you want to back up (1-%d): ", fileCount);
    scanf("%d", &fileIndex);
    
    if (fileIndex < 1 || fileIndex > fileCount) {
        printf("Invalid selection.\n");
        return 1;
    }

    printf("Enter the backup directory: ");
    scanf("%s", backupDir);

    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        mkdir(backupDir, 0700);
    }

    if (backupFile(files[fileIndex - 1], backupDir) == 0) {
        printf("Backup of '%s' created in '%s'.\n", files[fileIndex - 1], backupDir);
    } else {
        printf("Backup failed.\n");
    }

    return 0;
}