//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define BLOCK_SIZE 1024
#define MAX_PATH_LENGTH 512

void displayDiskSpace(const char *path) {
    struct statvfs stat;

    // Retrieve file system statistics
    if (statvfs(path, &stat) != 0) {
        perror("statvfs error");
        return;
    }

    // Calculate disk space
    unsigned long totalBlocks = stat.f_blocks;
    unsigned long freeBlocks = stat.f_bfree;
    unsigned long totalSpace = totalBlocks * BLOCK_SIZE;
    unsigned long freeSpace = freeBlocks * BLOCK_SIZE;
    unsigned long usedSpace = totalSpace - freeSpace;

    // Display disk space information
    printf("Disk Space Analysis for: %s\n", path);
    printf("-----------------------------------\n");
    printf("Total Space: %lu MB\n", totalSpace / (1024 * 1024));
    printf("Used Space: %lu MB\n", usedSpace / (1024 * 1024));
    printf("Free Space: %lu MB\n", freeSpace / (1024 * 1024));
    printf("-----------------------------------\n");
}

void printMenu() {
    printf("=== C Disk Space Analyzer ===\n");
    printf("1. Analyze root directory\n");
    printf("2. Analyze home directory\n");
    printf("3. Analyze current directory\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Choose an option (1-4): ");
}

int main() {
    int choice;
    char path[MAX_PATH_LENGTH];

    while(1) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                strcpy(path, "/");
                break;
            case 2:
                strcpy(path, getenv("HOME"));
                break;
            case 3:
                getcwd(path, sizeof(path));
                break;
            case 4:
                printf("Exiting the Disk Space Analyzer. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }

        // Analyze the chosen path
        displayDiskSpace(path);
    }

    return 0;
}