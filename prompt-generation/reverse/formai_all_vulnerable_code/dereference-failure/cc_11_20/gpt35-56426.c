//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/*
 * This program analyzes the disk space usage of a given directory
 * and outputs a report of the largest directories and files.
 */

// Function to calculate directory size recursively
long long int calculateDirSize(const char *dirPath) {
    long long int dirSize = 0;
    DIR *dirStream = opendir(dirPath); // Open directory
    if (dirStream == NULL) {
        return -1; // Return -1 if error opening directory
    }
    struct dirent *dirEntry;
    struct stat fileStat;
    char pathBuffer[1024]; // Buffer for storing path of subdirectories/files
    while ((dirEntry = readdir(dirStream)) != NULL) { // Loop through all directory entries
        if (strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0) {
            continue; // Skip . and .. directories
        }
        snprintf(pathBuffer, sizeof(pathBuffer), "%s/%s", dirPath, dirEntry->d_name);
        if (lstat(pathBuffer, &fileStat) == -1) {
            continue; // Skip files/directories with read errors
        }
        if (S_ISDIR(fileStat.st_mode)) { // Directory
            dirSize += calculateDirSize(pathBuffer); // Recursively calculate the size of the directory
        }
        else if (S_ISREG(fileStat.st_mode)) { // Regular file
            dirSize += fileStat.st_size; // Add the size of the file to the directory size
        }
    }
    closedir(dirStream); // Close directory
    return dirSize;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        return -1;
    }
    const char *dirPath = argv[1];

    printf("Scanning directory '%s'...\n\n", dirPath);

    // Calculate size of directory
    long long int dirSize = calculateDirSize(dirPath);
    if (dirSize == -1) {
        printf("Error: Failed to open directory '%s'.\n", dirPath);
        return -1;
    }

    printf("Total size of directory: %lld bytes\n\n", dirSize);

    // Open directory and loop through all entries
    DIR *dirStream = opendir(dirPath);
    if (dirStream == NULL) {
        printf("Error: Failed to open directory '%s'.\n", dirPath);
        return -1;
    }
    struct dirent *dirEntry;
    struct stat fileStat;
    char pathBuffer[1024];
    printf("Largest directories:\n");
    printf("--------------------\n");
    int dirCount = 0;
    while ((dirEntry = readdir(dirStream)) != NULL) {
        if (strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0) {
            continue; // Skip . and .. directories
        }
        snprintf(pathBuffer, sizeof(pathBuffer), "%s/%s", dirPath, dirEntry->d_name);
        if (lstat(pathBuffer, &fileStat) == -1) {
            continue; // Skip files/directories with read errors
        }
        if (S_ISDIR(fileStat.st_mode)) { // Directory
            long long int size = calculateDirSize(pathBuffer);
            if (size > 0) {
                printf("%-30s %10lld bytes\n", dirEntry->d_name, size);
                dirCount++;
            }
        }
    }
    if (dirCount == 0) {
        printf("No directories found.\n");
    }
    printf("\n");

    // Reset directory stream and loop through all entries again for files
    rewinddir(dirStream);
    printf("Largest files:\n");
    printf("---------------\n");
    int fileCount = 0;
    while ((dirEntry = readdir(dirStream)) != NULL) {
        if (strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0) {
            continue; // Skip . and .. directories
        }
        snprintf(pathBuffer, sizeof(pathBuffer), "%s/%s", dirPath, dirEntry->d_name);
        if (lstat(pathBuffer, &fileStat) == -1) {
            continue; // Skip files/directories with read errors
        }
        if (S_ISREG(fileStat.st_mode)) { // Regular file
            long long int size = fileStat.st_size;
            if (size > 0) {
                printf("%-30s %10lld bytes\n", dirEntry->d_name, size);
                fileCount++;
            }
        }
    }
    if (fileCount == 0) {
        printf("No files found.\n");
    }

    closedir(dirStream); // Close directory stream
    return 0;
}