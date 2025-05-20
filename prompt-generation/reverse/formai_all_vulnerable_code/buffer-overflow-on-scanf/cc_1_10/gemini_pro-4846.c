//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Declare functions
void backupFiles(char *sourcePath, char *destinationPath);
void createDirectory(char *directoryPath);
void copyFile(char *sourcePath, char *destinationPath);

int main() {
    // Get the current time
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    // Generate a backup directory name
    char backupDirectoryName[100];
    strftime(backupDirectoryName, sizeof(backupDirectoryName), "%Y-%m-%d_%H-%M-%S", timeinfo);

    // Create the backup directory
    char backupDirectoryPath[256];
    sprintf(backupDirectoryPath, "%s/%s", "/path/to/backup", backupDirectoryName);
    createDirectory(backupDirectoryPath);

    // Get the source directory path
    char sourceDirectoryPath[256];
    printf("Enter the source directory path: ");
    scanf("%s", sourceDirectoryPath);

    // Backup the files
    backupFiles(sourceDirectoryPath, backupDirectoryPath);

    // Print a success message
    printf("Backup completed successfully!\n");

    return 0;
}

void backupFiles(char *sourcePath, char *destinationPath) {
    // Open the source directory
    DIR *sourceDirectory = opendir(sourcePath);

    // Check if the source directory is valid
    if (sourceDirectory == NULL) {
        printf("Error opening source directory: %s\n", sourcePath);
        return;
    }

    // Iterate over the files in the source directory
    struct dirent *dirent;
    while ((dirent = readdir(sourceDirectory)) != NULL) {
        // Skip hidden files
        if (dirent->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char filePath[256];
        sprintf(filePath, "%s/%s", sourcePath, dirent->d_name);

        // Check if the file is a directory
        struct stat statbuf;
        stat(filePath, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively backup the directory
            char subDirectoryPath[256];
            sprintf(subDirectoryPath, "%s/%s", destinationPath, dirent->d_name);
            createDirectory(subDirectoryPath);
            backupFiles(filePath, subDirectoryPath);
        } else {
            // Copy the file
            char destinationFilePath[256];
            sprintf(destinationFilePath, "%s/%s", destinationPath, dirent->d_name);
            copyFile(filePath, destinationFilePath);
        }
    }

    // Close the source directory
    closedir(sourceDirectory);
}

void createDirectory(char *directoryPath) {
    // Check if the directory already exists
    struct stat statbuf;
    if (stat(directoryPath, &statbuf) == 0) {
        return;
    }

    // Create the directory
    if (mkdir(directoryPath, 0755) == -1) {
        printf("Error creating directory: %s\n", directoryPath);
    }
}

void copyFile(char *sourcePath, char *destinationPath) {
    // Open the source file
    FILE *sourceFile = fopen(sourcePath, "rb");

    // Check if the source file is valid
    if (sourceFile == NULL) {
        printf("Error opening source file: %s\n", sourcePath);
        return;
    }

    // Open the destination file
    FILE *destinationFile = fopen(destinationPath, "wb");

    // Check if the destination file is valid
    if (destinationFile == NULL) {
        printf("Error opening destination file: %s\n", destinationPath);
        return;
    }

    // Copy the file
    char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);
}