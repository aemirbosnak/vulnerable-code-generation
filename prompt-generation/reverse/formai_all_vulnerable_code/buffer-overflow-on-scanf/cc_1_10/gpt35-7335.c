//FormAI DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Function to copy file
void copyFile(char *sourceFile, char *destFile) {
    // Create buffer for temporary data storage
    char buffer[BUFFER_SIZE];
    // Open source file for reading
    FILE *source = fopen(sourceFile, "r");
    if (!source) {
        // If the file does not exist, print error message
        printf("Error: Unable to open file %s for reading\n", sourceFile);
        return;
    }
    // Open destination file for writing
    FILE *dest = fopen(destFile, "w");
    if (!dest) {
        // If unable to create new file, print error message
        printf("Error: Unable to create file %s for writing\n", destFile);
        return;
    }
    // Copy contents of source file to destination file
    while (fgets(buffer, BUFFER_SIZE, source)) {
        fputs(buffer, dest);
    }
    // Close both files
    fclose(source);
    fclose(dest);
}

// Function to create backup of a file
void backupFile(char *filePath) {
    // Get file name
    char *fileName = strrchr(filePath, '/');
    if (!fileName) {
        // If the file is in the current directory, set file name
        fileName = filePath;
    } else {
        // If the file is in a subdirectory, move pointer forward
        fileName++;
    }
    // Get current date and time
    time_t currentTime = time(NULL);
    struct tm* timeInfo = localtime(&currentTime);
    // Create backup file name
    char backupFileName[100];
    sprintf(backupFileName, "%s_bak_%04d%02d%02d%02d%02d%02d", fileName, timeInfo->tm_year+1900, timeInfo->tm_mon+1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
    // Create folder for backup files (if it does not already exist)
    struct stat st = {0};
    if (stat("backups", &st) == -1) {
        mkdir("backups", 0700);
    }
    // Set backup file path
    char backupFilePath[100];
    sprintf(backupFilePath, "backups/%s", backupFileName);
    // Create backup file
    copyFile(filePath, backupFilePath);
    // Print success message
    printf("Backup created for file: %s\n", filePath);
}

// Function to iterate through all files in the directory
void iterateDirectory(char *directoryPath) {
    DIR *directory;
    struct dirent *entry;
    struct stat fileStat;

    // Open directory
    directory = opendir(directoryPath);
    if (!directory) {
        // If the directory does not exist, print error message
        printf("Error: Unable to open directory %s\n", directoryPath);
        return;
    }
    // Read files and directories in the directory
    while ((entry = readdir(directory)) != NULL) {
        // Get file path
        char filePath[200];
        sprintf(filePath, "%s/%s", directoryPath, entry->d_name);
        // Check if file is a directory
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // If the file is a directory, recurse into the directory
            iterateDirectory(filePath);
        } else if (entry->d_type == DT_REG) {
            // If the file is a regular file, create backup of the file
            backupFile(filePath);
        }
    }
    // Close directory
    closedir(directory);
}

int main() {
    // Provide directory path
    char directoryPath[200];
    printf("Enter the directory path for backup: ");
    scanf("%s", directoryPath);
    // Iterate through all files in the directory
    iterateDirectory(directoryPath);

    return 0;
}