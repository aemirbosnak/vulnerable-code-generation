//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
// Disk space analyzer program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

// Structure to store disk space information
struct disk_space {
    char *mount_point;
    unsigned long long total_bytes;
    unsigned long long free_bytes;
    unsigned long long used_bytes;
    double percentage_used;
};

// Function to get disk space information
void get_disk_space(struct disk_space *disk) {
    struct statvfs stat;
    if (statvfs(disk->mount_point, &stat) == 0) {
        disk->total_bytes = (unsigned long long)stat.f_blocks * (unsigned long long)stat.f_bsize;
        disk->free_bytes = (unsigned long long)stat.f_bfree * (unsigned long long)stat.f_bsize;
        disk->used_bytes = disk->total_bytes - disk->free_bytes;
        disk->percentage_used = (double)disk->used_bytes / (double)disk->total_bytes;
    } else {
        disk->total_bytes = 0;
        disk->free_bytes = 0;
        disk->used_bytes = 0;
        disk->percentage_used = 0.0;
    }
}

// Function to print disk space information
void print_disk_space(struct disk_space *disk) {
    printf("Disk: %s\n", disk->mount_point);
    printf("Total bytes: %llu\n", disk->total_bytes);
    printf("Free bytes: %llu\n", disk->free_bytes);
    printf("Used bytes: %llu\n", disk->used_bytes);
    printf("Percentage used: %.2f%%\n", disk->percentage_used * 100.0);
}

// Main function
int main() {
    // Get disk space information
    struct disk_space disk;
    disk.mount_point = "/";
    get_disk_space(&disk);

    // Print disk space information
    print_disk_space(&disk);

    return 0;
}