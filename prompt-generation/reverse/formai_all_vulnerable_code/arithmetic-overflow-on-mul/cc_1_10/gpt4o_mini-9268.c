//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define BLOCK_SIZE 4096

void calculateDiskUsage(const char *path, unsigned long long *totalSize, unsigned long long *usedSize) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    
    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[MAX_PATH_LENGTH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (stat(fullPath, &fileStat) == 0) {
            if (S_ISDIR(fileStat.st_mode)) {
                calculateDiskUsage(fullPath, totalSize, usedSize);
            } else {
                *usedSize += fileStat.st_size;
            }

            *totalSize += (fileStat.st_blocks * BLOCK_SIZE);
        }
    }

    closedir(dir);
}

void printUsageInfo(const char *path, unsigned long long totalSize, unsigned long long usedSize) {
    double percentageUsed = ((double)usedSize / totalSize) * 100;

    printf("Disk Usage Information for: %s\n", path);
    printf("Total Disk Space: %llu bytes\n", totalSize);
    printf("Used Disk Space: %llu bytes\n", usedSize);
    printf("Unused Disk Space: %llu bytes\n", totalSize - usedSize);
    printf("Usage Percentage: %.2f%%\n", percentageUsed);
}

int main(int argc, char *argv[]) {
    unsigned long long totalSize = 0;
    unsigned long long usedSize = 0;

    const char *path = (argc > 1) ? argv[1] : "."; // Default to current directory

    printf("Analyzing disk usage...\n");
    calculateDiskUsage(path, &totalSize, &usedSize);

    if (totalSize == 0) {
        fprintf(stderr, "No valid files found or insufficient permissions.\n");
        return EXIT_FAILURE;
    }

    printUsageInfo(path, totalSize, usedSize);

    return EXIT_SUCCESS;
}