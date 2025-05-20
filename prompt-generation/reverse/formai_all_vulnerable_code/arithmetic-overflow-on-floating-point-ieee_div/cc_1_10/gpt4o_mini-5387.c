//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_DRIVES 26 // A-Z drives
#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)

void printDiskUsage(const char *path, struct statvfs *stat) {
    unsigned long total = stat->f_blocks * stat->f_frsize;
    unsigned long free = stat->f_bfree * stat->f_frsize;
    unsigned long used = total - free;

    printf("Disk Usage for %s:\n", path);
    printf("Total Space: %.2f GB\n", (double)total / GB);
    printf("Used Space: %.2f GB\n", (double)used / GB);
    printf("Free Space: %.2f GB\n", (double)free / GB);
    printf("Usage Percentage: %.2f%%\n", (100.0 * used / total));
    printf("----------------------------------\n");
}

void analyzeDrive(const char driveLetter) {
    char path[8];
    snprintf(path, sizeof(path), "%c:/", driveLetter);

    struct statvfs stat;
    if (statvfs(path, &stat) == 0) {
        printDiskUsage(path, &stat);
    } else {
        perror("Error retrieving disk information");
    }
}

void displayMenu() {
    printf("Disk Space Analyzer\n");
    printf("====================\n");
    printf("1. Analyze All Drives\n");
    printf("2. Analyze Specific Drive\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

void analyzeAllDrives() {
    for (char drive = 'A'; drive <= 'Z'; drive++) {
        analyzeDrive(drive);
    }
}

void analyzeSpecificDrive() {
    char drive;
    printf("Enter the drive letter (A-Z): ");
    scanf(" %c", &drive);
    drive = toupper(drive); // Convert to uppercase
    if (drive >= 'A' && drive <= 'Z') {
        analyzeDrive(drive);
    } else {
        printf("Invalid drive letter.\n");
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                analyzeAllDrives();
                break;
            case 2:
                analyzeSpecificDrive();
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}