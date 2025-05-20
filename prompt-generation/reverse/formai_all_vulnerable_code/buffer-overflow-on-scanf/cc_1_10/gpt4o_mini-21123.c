//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

void displayDiskUsage(char *path) {
    struct statvfs stat;

    // Get filesystem statistics
    if (statvfs(path, &stat) != 0) {
        // Error handling
        perror("statvfs failed");
        exit(EXIT_FAILURE);
    }

    // Calculating sizes
    unsigned long total = stat.f_blocks * stat.f_frsize; // Total size
    unsigned long used = (stat.f_blocks - stat.f_bfree) * stat.f_frsize; // Used size
    unsigned long free = stat.f_bfree * stat.f_frsize; // Free size

    // Calculate percentage used
    double percent_used = (double)used / (double)total * 100.0;

    // Displaying results
    printf("Disk Usage for %s:\n", path);
    printf("Total Size: %.2f GB\n", total / (1024.0 * 1024.0 * 1024.0));
    printf("Used Size: %.2f GB\n", used / (1024.0 * 1024.0 * 1024.0));
    printf("Free Size: %.2f GB\n", free / (1024.0 * 1024.0 * 1024.0));
    printf("Percentage Used: %.2f%%\n", percent_used);
}

void menu() {
    printf("\nDisk Space Analyzer\n");
    printf("1. Analyze root (/) space\n");
    printf("2. Analyze home (/home) space\n");
    printf("3. Analyze another directory\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char path[256];

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayDiskUsage("/");
                break;
            case 2:
                displayDiskUsage("/home");
                break;
            case 3:
                printf("Enter directory path: ");
                scanf("%s", path);
                displayDiskUsage(path);
                break;
            case 4:
                printf("Exiting the Disk Space Analyzer.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}