//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>
#include <dirent.h>

void display_disk_usage(const char *path) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("statvfs");
        return; // cannot retrieve information
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;     // Total number of bytes
    unsigned long free = stat.f_bfree * stat.f_frsize;       // Free bytes
    unsigned long used = total - free;                         // Used bytes
    unsigned long available = stat.f_bavail * stat.f_frsize; // Available bytes

    double used_percent = ((double)used / total) * 100;
    double free_percent = ((double)free / total) * 100;

    printf("Mount Point: %s\n", path);
    printf("Total Space: %lu bytes\n", total);
    printf("Used Space: %lu bytes (%.2f%%)\n", used, used_percent);
    printf("Free Space: %lu bytes (%.2f%%)\n", free, free_percent);
    printf("Available Space: %lu bytes\n", available);
    printf("---------------------------------------------------\n");
}

void scan_mounts() {
    FILE *mounts_file = fopen("/proc/mounts", "r");
    if (mounts_file == NULL) {
        perror("Unable to open /proc/mounts");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), mounts_file)) {
        char mount_point[128];
        sscanf(line, "%*s %127s %*s %*s %*s %*s", mount_point);
        display_disk_usage(mount_point);
    }
    
    fclose(mounts_file);
}

int main() {
    printf("Disk Usage Report\n");
    printf("---------------------------------------------------\n");
    scan_mounts();
    return 0;
}