//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

void display_disk_usage(const char *path) {
    struct statvfs stat;

    // Get filesystem statistics
    if (statvfs(path, &stat) != 0) {
        perror("statvfs");
        return;
    }

    // Calculate disk space in bytes
    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;
    unsigned long available = stat.f_bavail * stat.f_frsize;

    // Display the results
    printf("Disk Usage for %s:\n", path);
    printf("Total Space: %.2f GB\n", total / (1024.0 * 1024.0 * 1024.0));
    printf("Used Space: %.2f GB\n", used / (1024.0 * 1024.0 * 1024.0));
    printf("Free Space: %.2f GB\n", free / (1024.0 * 1024.0 * 1024.0));
    printf("Available Space: %.2f GB\n", available / (1024.0 * 1024.0 * 1024.0));
}

int main() {
    char path[256];
    char choice;

    printf("Welcome to Disk Space Analyzer!\n");

    while (1) {
        printf("\nEnter the path to analyze (or type 'exit' to quit): ");
        scanf("%s", path);

        if (strcmp(path, "exit") == 0) {
            break;
        }

        display_disk_usage(path);

        printf("\nWould you like to analyze another path? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    printf("Thank you for using Disk Space Analyzer. Goodbye!\n");
    return 0;
}