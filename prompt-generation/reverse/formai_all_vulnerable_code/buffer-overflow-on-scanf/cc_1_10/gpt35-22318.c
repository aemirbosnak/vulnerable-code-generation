//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 256
#define MAX_FILENAME_LEN 256

// Struct to hold file information
typedef struct {
    char path[MAX_PATH_LEN];
    char filename[MAX_FILENAME_LEN];
} FileInfo;

// Function to get file info from a given path
FileInfo getFileInfo(const char* filePath) {
    FileInfo fileInfo;
    char* lastSlash = strrchr(filePath, '/');
    if (lastSlash == NULL) {
        strcpy(fileInfo.path, ".");
        strcpy(fileInfo.filename, filePath);
    } else {
        strncpy(fileInfo.path, filePath, lastSlash - filePath);
        fileInfo.path[lastSlash - filePath] = '\0';
        strcpy(fileInfo.filename, lastSlash + 1);
    }
    return fileInfo;
}

// Function to perform file synchronization
void syncFiles(const char* sourcePath, const char* destPath) {
    FileInfo sourceFileInfo = getFileInfo(sourcePath);
    FileInfo destFileInfo = getFileInfo(destPath);

    // Open directories
    DIR* sourceDir = opendir(sourceFileInfo.path);
    DIR* destDir = opendir(destFileInfo.path);
    if (sourceDir == NULL) {
        printf("Error opening source directory.\n");
        return;
    }
    if (destDir == NULL) {
        printf("Error opening destination directory.\n");
        return;
    }

    // Check if destination file already exists
    struct dirent* destEntry;
    while ((destEntry = readdir(destDir)) != NULL) {
        if (strcmp(destEntry->d_name, destFileInfo.filename) == 0) {
            closedir(destDir);
            printf("Destination file already exists.\n");
            return;
        }
    }

    // Open files for copying
    FILE* sourceFile = fopen(sourcePath, "rb");
    FILE* destFile = fopen(destPath, "wb");
    if (sourceFile == NULL) {
        printf("Error opening source file.\n");
        closedir(sourceDir);
        closedir(destDir);
        return;
    }
    if (destFile == NULL) {
        printf("Error opening destination file.\n");
        fclose(sourceFile);
        closedir(sourceDir);
        closedir(destDir);
        return;
    }

    // Read in blocks and copy to destination file
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), sourceFile)) != 0) {
        fwrite(buffer, 1, bytes, destFile);
    }

    // Close files and directories
    fclose(sourceFile);
    fclose(destFile);
    closedir(sourceDir);
    closedir(destDir);

    printf("Synchronization successful.\n");
}

int main() {
    char sourcePath[MAX_PATH_LEN];
    char destPath[MAX_PATH_LEN];
    printf("Enter source file path: ");
    scanf("%s", sourcePath);
    printf("Enter destination file path: ");
    scanf("%s", destPath);
    syncFiles(sourcePath, destPath);
    return 0;
}