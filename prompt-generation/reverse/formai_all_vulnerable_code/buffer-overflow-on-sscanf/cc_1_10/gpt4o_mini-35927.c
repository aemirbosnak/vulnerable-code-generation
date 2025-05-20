//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <string.h>

// Function to print disk usage details
void print_disk_usage(const char *path) {
    struct statvfs stat;

    // Fetch filesystem statistics
    if (statvfs(path, &stat) != 0) {
        perror("statvfs failed");
        return; // Exit if there is an error
    }

    // Calculate disk usage in bytes
    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;
    unsigned long available = stat.f_bavail * stat.f_frsize;

    // Print out the stats nicely
    printf("Disk Usage for: %s\n", path);
    printf("-------------------------\n");
    printf("Total Space:       %lu bytes\n", total);
    printf("Used Space:        %lu bytes\n", used);
    printf("Free Space:        %lu bytes\n", free);
    printf("Available Space:   %lu bytes\n", available);
    printf("\n");
}

// Function to list all mounted filesystems and analyze their disk usage
void analyze_disk_space() {
    FILE *fp;
    char buffer[256];

    // Open the file that contains disk info
    fp = fopen("/proc/mounts", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/mounts");
        return;
    }

    // Read through the file line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char device[50], mount_point[100], type[50], options[100];
        int freq, passno;

        // Parse the line to extract relevant info
        if (sscanf(buffer, "%49s %99s %49s %99s %d %d", device, mount_point, type, options, &freq, &passno) == 6) {
            print_disk_usage(mount_point);
        }
    }

    fclose(fp);
}

int main() {
    printf("***************************************\n");
    printf("* Welcome to the Disk Space Analyzer! *\n");
    printf("***************************************\n\n");

    analyze_disk_space();

    printf("=======================================\n");
    printf("* Thank you for using the analyzer!   *\n");
    printf("=======================================\n");

    return 0;
}