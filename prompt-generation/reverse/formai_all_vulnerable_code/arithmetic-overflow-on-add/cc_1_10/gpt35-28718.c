//FormAI DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000 // Maximum length of file path
#define MAX_FILES 1000 // Maximum number of files to backup

// Function to backup a single file
void backupFile(char* filePath) {
    char backupPath[MAX_LENGTH];
    time_t rawtime;
    struct tm* timeInfo;

    // Get current time
    time(&rawtime);
    timeInfo = localtime(&rawtime);

    // Create backup path with timestamp
    sprintf(backupPath, "%s_%04d%02d%02d%02d%02d%02d",
        filePath, timeInfo->tm_year+1900, timeInfo->tm_mon+1, timeInfo->tm_mday,
        timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

    // Copy file to backup path
    FILE* source = fopen(filePath, "rb");
    FILE* backup = fopen(backupPath, "wb");
    if(source == NULL || backup == NULL) {
        printf("Error: Failed to backup file %s\n", filePath);
        return;
    }
    char buffer[MAX_LENGTH];
    int size;
    while((size = fread(buffer, 1, MAX_LENGTH, source)) > 0) {
        fwrite(buffer, 1, size, backup);
    }
    fclose(source);
    fclose(backup);
}

int main(int argc, char** argv) {
    char* fileList[MAX_FILES];
    int numFiles = 0;

    // Parse command line arguments for files to backup
    for(int i = 1; i < argc; i++) {
        if(numFiles >= MAX_FILES) {
            printf("Error: Maximum number of backup files exceeded\n");
            break;
        }
        fileList[numFiles++] = argv[i];
    }
    if(numFiles == 0) {
        printf("Usage: backup <file1> <file2> ...\n");
        return 1;
    }

    // Backup each file in file list
    for(int i = 0; i < numFiles; i++) {
        backupFile(fileList[i]);
    }

    printf("Backup complete\n");
    return 0;
}