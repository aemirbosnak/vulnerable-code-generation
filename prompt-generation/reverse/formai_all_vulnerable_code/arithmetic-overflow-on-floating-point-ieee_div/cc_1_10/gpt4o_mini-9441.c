//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

void calculate_disk_space(const char *path) {
    struct statvfs stat;
    
    // Obtain file system statistics
    if (statvfs(path, &stat) != 0) {
        perror("Statvfs failed");
        return;
    }

    // Calculate total size, free size, and used size
    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;

    // Display size information in a mystifying table
    printf("\nMystic Disk Space Analysis of: %s\n", path);
    printf("----------------------------------\n");
    printf("| Type               | Size (bytes) |\n");
    printf("|--------------------|--------------|\n");
    printf("| Total Space        | %12lu |\n", total);
    printf("| Free Space         | %12lu |\n", free);
    printf("| Used Space         | %12lu |\n", used);
    printf("----------------------------------\n");

    // Calculate percentage used
    double used_percentage = (double)used / total * 100;

    // Display a puzzling interpretation
    printf("Used Space Percentage: %.2f%%\n", used_percentage);
    printf("Thus, I conjure the conclusion with mystic musings...\n");
}

void print_usage() {
    printf("Usage: ./disk_space_analyzer <path>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    const char *path = argv[1];
    calculate_disk_space(path);

    // A whimsical farewell
    printf("Thus ends the exploration of space,\n");
    printf("May you wander in your data's grace!\n");

    return 0;
}