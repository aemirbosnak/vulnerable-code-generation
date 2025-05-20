//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

void displayDiskUsage(const char *path) {
    struct statvfs stat;

    // Fetching filesystem statistics
    if (statvfs(path, &stat) != 0) {
        perror("statvfs error");
        return; // Error occurred
    }

    // Compute total and available space
    unsigned long totalSize = stat.f_frsize * stat.f_blocks;
    unsigned long freeSize = stat.f_frsize * stat.f_bfree;
    unsigned long usedSize = totalSize - freeSize;

    printf("Disk Space Usage for %s:\n", path);
    printf("Total space:        %.2f GB\n", totalSize / (1024.0 * 1024.0 * 1024.0));
    printf("Used space:         %.2f GB\n", usedSize / (1024.0 * 1024.0 * 1024.0));
    printf("Free space:         %.2f GB\n", freeSize / (1024.0 * 1024.0 * 1024.0));
    printf("Percentage Used:    %.2f%%\n", (double)usedSize / totalSize * 100);
    printf("-----------------------------\n");
}

void analyzeDirectory(const char *dirPath) {
    // Here be dragons! Or rather, the contents of the directory!
    FILE *fp;
    char command[256];
    snprintf(command, sizeof(command), "ls -l %s", dirPath);

    printf("Analyzing directory: %s\n", dirPath);
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    char path[256];
    while (fgets(path, sizeof(path), fp) != NULL) {
        // Print each file or directory found
        printf("%s", path);
    }

    pclose(fp);
    printf("-----------------------------\n");
}

int main() {
    char path[100];

    printf("Welcome to the Curious Disk Space Analyzer! 🌍\n");
    printf("Please enter the path you wish to analyze (e.g., /home/user): ");
    scanf("%99s", path);

    displayDiskUsage(path);
    analyzeDirectory(path);

    // As a cherry on top, let's check a subdirectory
    char subDir[256];
    snprintf(subDir, sizeof(subDir), "%s/.config", path);
    displayDiskUsage(subDir);
    analyzeDirectory(subDir);

    char choice;
    printf("Would you like to analyze another directory? (y/n): ");
    scanf(" %c", &choice);

    while(choice == 'y' || choice == 'Y') {
        printf("Please enter the path you wish to analyze: ");
        scanf("%99s", path);
        displayDiskUsage(path);
        analyzeDirectory(path);

        snprintf(subDir, sizeof(subDir), "%s/.config", path);
        displayDiskUsage(subDir);
        analyzeDirectory(subDir);

        printf("Would you like to analyze another directory? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Curious Disk Space Analyzer! 🚀\n");
    return 0;
}