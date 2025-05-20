//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

void analyzeDiskSpace(const char *path) {
    struct statvfs stat;

    // Check if the filesystem data can be retrieved
    if (statvfs(path, &stat) != 0) {
        perror("Failed to retrieve file system statistics");
        return;
    }

    // Calculate the total, free, and used space
    unsigned long totalSpace = stat.f_blocks * stat.f_frsize;
    unsigned long freeSpace = stat.f_bfree * stat.f_frsize;
    unsigned long usedSpace = totalSpace - freeSpace;
    
    // Display the results
    printf("Disk Space Analysis for: %s\n", path);
    printf("------------------------------------------\n");
    printf("Total Space: %lu bytes (%.2f GB)\n", totalSpace, totalSpace / (1024.0 * 1024 * 1024));
    printf("Used Space : %lu bytes (%.2f GB)\n", usedSpace, usedSpace / (1024.0 * 1024 * 1024));
    printf("Free Space : %lu bytes (%.2f GB)\n", freeSpace, freeSpace / (1024.0 * 1024 * 1024));
    
    if (freeSpace < (totalSpace * 0.1)) {
        printf("⚠️ Warning! Free space is less than 10%% of total space! ⚠️\n");
    }

    printf("Disk Usage Percentage: %.2f%%\n", (usedSpace / (double)totalSpace) * 100);
    
    // Check if the free space is critically low
    if (freeSpace < 1024 * 1024) {
        printf("🚨 Critical Alert! Very low disk space detected! 🚨\n");
    }

    printf("\nEnd of Analysis.\n");
}

int main() {
    char path[256];
    
    // User input for the path
    printf("👀 Enter the directory to analyze its disk space (or leave blank for current directory): ");
    fgets(path, sizeof(path), stdin);
    
    // Remove newline character from fgets
    path[strcspn(path, "\n")] = 0;  
     
    // If the user didn't provide a path, use current directory
    if (strlen(path) == 0) {
        strcpy(path, ".");
    }

    analyzeDiskSpace(path);

    return 0;
}