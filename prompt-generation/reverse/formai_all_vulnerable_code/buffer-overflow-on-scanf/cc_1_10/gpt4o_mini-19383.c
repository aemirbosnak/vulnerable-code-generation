//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

void analyzeDiskSpace(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("statvfs failed");
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;
    
    printf("Disk space analysis for path: %s\n", path);
    printf("Total space: %.2f GB\n", total / (1024.0 * 1024.0 * 1024.0));
    printf("Used space: %.2f GB\n", used / (1024.0 * 1024.0 * 1024.0));
    printf("Free space: %.2f GB\n", free / (1024.0 * 1024.0 * 1024.0));
    printf("Percentage of used space: %.2f%%\n", (used / (float)total) * 100);
    printf("Percentage of free space: %.2f%%\n", (free / (float)total) * 100);
}

void displayMenu() {
    printf("\nDisk Space Analyzer Menu:\n");
    printf("1. Analyze root disk\n");
    printf("2. Analyze home directory\n");
    printf("3. Analyze current working directory\n");
    printf("4. Analyze custom path\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char customPath[MAX_PATH_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                analyzeDiskSpace("/");
                break;
            case 2:
                analyzeDiskSpace("/home");
                break;
            case 3:
                analyzeDiskSpace(".");
                break;
            case 4:
                printf("Enter the path to analyze: ");
                scanf("%s", customPath);
                analyzeDiskSpace(customPath);
                break;
            case 5:
                printf("Exiting the Disk Space Analyzer. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}