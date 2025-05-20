//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to convert bytes to human-readable units
void convertToReadable(long long size, char *unit) {
    if (size >= 1024 * 1024 * 1024) {
        sprintf(unit, "%.2fGB", (float)size / (1024 * 1024 * 1024));
    }
    else if (size >= 1024 * 1024) {
        sprintf(unit, "%.2fMB", (float)size / (1024 * 1024));
    }
    else if (size >= 1024) {
        sprintf(unit, "%.2fKB", (float)size / 1024);
    }
    else {
        sprintf(unit, "%dB", size);
    }
}

// Function to print directories and their sizes recursively
long long printDirectoryInfo(char *dirPath) {
    long long totalSize = 0;
    DIR *dir = opendir(dirPath);
    struct dirent *entry;
    struct stat info;
    char fullPath[PATH_MAX];
    char readableSize[20];

    // Traverse all entries in the directory sequentially
    while ((entry = readdir(dir)) != NULL) {
        // Ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Construct the full path of the entry
        strcpy(fullPath, dirPath);
        strcat(fullPath, "/");
        strcat(fullPath, entry->d_name);

        // Get the size and mode of the entry
        stat(fullPath, &info);

        // If the entry is a directory, print its info recursively
        if (S_ISDIR(info.st_mode)) {
            totalSize += printDirectoryInfo(fullPath);
        }
        // Else if the entry is a file, print its info
        else if (S_ISREG(info.st_mode)) {
            convertToReadable(info.st_size, readableSize);
            printf("%s [%s]\n", fullPath, readableSize);
            totalSize += info.st_size;
        }
    }

    closedir(dir);

    // Print the total size of the directory
    convertToReadable(totalSize, readableSize);
    printf("\n%s [%s]\n\n", dirPath, readableSize);

    return totalSize;
}

int main() {
    char dirPath[PATH_MAX];
    long long totalSize;
    char readableSize[20];

    // Get the directory path and validate it
    printf("Enter the directory path to analyze:\n");
    fgets(dirPath, PATH_MAX, stdin);
    dirPath[strlen(dirPath)-1] = '\0';
    if (strlen(dirPath) == 0) {
        printf("Invalid directory path.\n");
        return 1;
    }

    printf("\nAnalyzing directory: %s\n\n", dirPath);

    // Print the info of the directory and all its contents recursively
    totalSize = printDirectoryInfo(dirPath);

    // Print the total size of the directory and its contents
    convertToReadable(totalSize, readableSize);
    printf("Total size of %s and its contents: %s\n", dirPath, readableSize);

    return 0;
}