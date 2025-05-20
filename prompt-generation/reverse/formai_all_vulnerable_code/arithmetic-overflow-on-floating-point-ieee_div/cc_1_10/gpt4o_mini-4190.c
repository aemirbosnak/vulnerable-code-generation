//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

void printDiskSpace(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) { 
        perror("statvfs");
        exit(EXIT_FAILURE);
    }

    unsigned long total = stat.f_frsize * stat.f_blocks; // Total space 
    unsigned long free = stat.f_frsize * stat.f_bfree;   // Free space
    unsigned long used = total - free;                     // Used space

    printf("Disk Space Analysis for: %s\n", path);
    printf("====================================\n");
    printf("Total Space: %.2f GB\n", total / (1024.0 * 1024.0 * 1024.0));
    printf("Used Space: %.2f GB\n", used / (1024.0 * 1024.0 * 1024.0));
    printf("Free Space: %.2f GB\n", free / (1024.0 * 1024.0 * 1024.0));
    printf("Percentage Used: %.2f%%\n", (used / (double)total) * 100);
    printf("====================================\n");
}

void listDirectories(const char *path) {
    char command[256];
    snprintf(command, sizeof(command), "du -h --max-depth=1 %s", path);
    printf("Listing directories in: %s\n", path);
    printf("====================================\n");
    system(command);
    printf("====================================\n");
}

void promptUserForPath() {
    char path[1024];

    printf("Enter the directory path to analyze (default is current directory): ");
    if (fgets(path, sizeof(path), stdin) != NULL) {
        path[strcspn(path, "\n")] = 0; // Remove newline character
        if (strlen(path) == 0) {
            strcpy(path, "."); // Default to current directory
        }
    }

    printDiskSpace(path);
    listDirectories(path);
}

int main() {
    printf("Welcome to the Disk Space Analyzer!\n");
    printf("This program will analyze the disk space usage of a specified directory.\n\n");
    
    promptUserForPath();

    printf("Thank you for using the Disk Space Analyzer. Goodbye!\n");
    return 0;
}