//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

void displayDiskUsage(char *path) {
    struct statvfs stats;

    // Get filesystem statistics
    if (statvfs(path, &stats) != 0) {
        perror("Error retrieving disk statistics");
        exit(EXIT_FAILURE);
    }

    unsigned long total_space = stats.f_blocks * stats.f_frsize;
    unsigned long free_space = stats.f_bfree * stats.f_frsize;
    unsigned long used_space = total_space - free_space;

    // Convert bytes to Gigabytes
    unsigned long total_gb = total_space / (1024 * 1024 * 1024);
    unsigned long free_gb = free_space / (1024 * 1024 * 1024);
    unsigned long used_gb = used_space / (1024 * 1024 * 1024);

    // Calculate percentage used
    double used_percentage = ((double)used_space / total_space) * 100;

    // Display the results
    printf("Disk usage for: %s\n", path);
    printf("Total Space: %lu GB\n", total_gb);
    printf("Used Space: %lu GB (%.2f%%)\n", used_gb, used_percentage);
    printf("Free Space: %lu GB\n\n", free_gb);
}

void printDivider() {
    printf("======================================\n");
}

int main(int argc, char *argv[]) {
    // Check if user provided arguments
    if (argc < 2) {
        printf("Welcome to the Disk Space Analyzer!\n");
        printf("This program will help you analyze disk usage on your system.\n\n");
        printf("Usage: %s <directory_path1> <directory_path2> ...\n", argv[0]);

        // Show usage for the root directory if no arguments
        printf("Analyzing root directory by default:\n");
        displayDiskUsage("/");
        return 0;
    }

    // Analyze each directory provided by user
    printf("Analyzing disk usage for the specified paths:\n\n");
    for (int i = 1; i < argc; i++) {
        printDivider();
        displayDiskUsage(argv[i]);
    }

    printf("Thank you for using the Disk Space Analyzer! Keep track of your storage wisely!\n");
    return 0;
}