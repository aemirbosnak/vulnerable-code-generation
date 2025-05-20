//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>

// Structure to store the size of each file and its path
typedef struct {
    long long size;
    char *path;
} FileSize;

// Function to compare two FileSize structures by size
int compareFileSize(const void *a, const void *b) {
    FileSize *fa = (FileSize *)a;
    FileSize *fb = (FileSize *)b;
    return (int)(fb->size - fa->size);
}

// Function to get the size of a file or directory
long long getFileSize(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Function to walk through a directory and get the size of all files and directories
long long getDirectorySize(const char *path) {
    long long totalSize = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *newPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(newPath, "%s/%s", path, entry->d_name);
        if (entry->d_type == DT_DIR) {
            totalSize += getDirectorySize(newPath);
        } else {
            totalSize += getFileSize(newPath);
        }
        free(newPath);
    }
    closedir(dir);
    return totalSize;
}

int main() {
    // Get the path to the directory to analyze
    char path[PATH_MAX];
    printf("Enter the path to the directory to analyze: ");
    scanf("%s", path);

    // Get the size of the directory
    long long totalSize = getDirectorySize(path);
    if (totalSize == -1) {
        return EXIT_FAILURE;
    }

    // Get a list of all files and directories in the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }
    struct dirent *entry;
    int numFiles = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        numFiles++;
    }
    closedir(dir);

    // Allocate memory for the FileSize structures
    FileSize *fileSizes = malloc(sizeof(FileSize) * numFiles);

    // Get the size of each file and directory
    dir = opendir(path);
    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *newPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(newPath, "%s/%s", path, entry->d_name);
        fileSizes[i].size = getFileSize(newPath);
        fileSizes[i].path = newPath;
        i++;
    }
    closedir(dir);

    // Sort the FileSize structures by size
    qsort(fileSizes, numFiles, sizeof(FileSize), compareFileSize);

    // Print the size of the top 10 largest files and directories
    printf("The top 10 largest files and directories in %s are:\n", path);
    for (i = 0; i < 10 && i < numFiles; i++) {
        printf("%lld bytes: %s\n", fileSizes[i].size, fileSizes[i].path);
    }

    // Free the memory allocated for the FileSize structures
    for (i = 0; i < numFiles; i++) {
        free(fileSizes[i].path);
    }
    free(fileSizes);

    return EXIT_SUCCESS;
}