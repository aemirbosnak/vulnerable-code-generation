//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define RECOVERY_DIR "recovered_files"

void createRecoveryDirectory();
int isFileDeleted(const char *path);
void recoverFile(const char *filename);
void listFilesInDirectory(const char *directory);
void handleUserInput();

int main() {
    createRecoveryDirectory();
    handleUserInput();
    return 0;
}

// Function to create a recovery directory if it does not exist
void createRecoveryDirectory() {
    struct stat st = {0};
    if (stat(RECOVERY_DIR, &st) == -1) {
        mkdir(RECOVERY_DIR, 0700);
        printf("Recovery directory created: %s\n", RECOVERY_DIR);
    }
}

// Function to check if a file is deleted (for demonstration purposes, we assume deleted files have the extension ".del")
int isFileDeleted(const char *path) {
    return (strstr(path, ".del") != NULL);
}

// Function to recover a file from the given path
void recoverFile(const char *filename) {
    char deletedPath[MAX_FILENAME_LENGTH];
    char recoveryPath[MAX_FILENAME_LENGTH];
    snprintf(deletedPath, sizeof(deletedPath), "%s/%s", ".", filename); // Current directory
    snprintf(recoveryPath, sizeof(recoveryPath), "%s/%s", RECOVERY_DIR, filename);

    // Simulating file recovery by moving it
    if (rename(deletedPath, recoveryPath) == 0) {
        printf("Recovered file: %s --> %s\n", deletedPath, recoveryPath);
    } else {
        perror("Failed to recover file");
    }
}

// Function to list files in a given directory and process recoverable files
void listFilesInDirectory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip the current and parent directory entries
        if (entry->d_name[0] == '.') continue;

        if (isFileDeleted(entry->d_name)) {
            recoverFile(entry->d_name);
        }
    }
    closedir(dp);
}

// Function to handle user input for the operation
void handleUserInput() {
    char directory[MAX_FILENAME_LENGTH];

    printf("Enter the directory to scan for deleted files: ");
    scanf("%s", directory);

    // Handle scanning for deleted files in user-provided directory
    listFilesInDirectory(directory);
}