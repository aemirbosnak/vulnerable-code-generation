//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

void analyze_disk_space(const char *path);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    analyze_disk_space(argv[1]);
    return 0;
}

void analyze_disk_space(const char *path) {
    struct statvfs stat;

    // Fetch file system statistics
    if (statvfs(path, &stat) != 0) {
        perror("Error fetching disk statistics");
        exit(EXIT_FAILURE);
    }

    // Calculate the total, used, and free space
    unsigned long total = stat.f_frsize * stat.f_blocks;
    unsigned long free  = stat.f_frsize * stat.f_bfree;
    unsigned long used  = total - free;

    // Prepare for output
    double total_mb = total / (1024.0 * 1024.0);
    double used_mb = used / (1024.0 * 1024.0);
    double free_mb = free / (1024.0 * 1024.0);
    double used_percent = (used / (double)total) * 100;

    // Output the results
    printf("Disk Space Analysis for: %s\n", path);
    printf("----------------------------------\n");
    printf("Total Space: %.2f MB\n", total_mb);
    printf("Used Space: %.2f MB (%.2f%%)\n", used_mb, used_percent);
    printf("Free Space: %.2f MB\n", free_mb);
    printf("----------------------------------\n");

    // Convert space sizes into human-readable format
    char total_str[50], used_str[50], free_str[50];
    snprintf(total_str, sizeof(total_str), "%.2f MB", total_mb);
    snprintf(used_str, sizeof(used_str), "%.2f MB (%.2f%%)", used_mb, used_percent);
    snprintf(free_str, sizeof(free_str), "%.2f MB", free_mb);

    // Decide if user should clean up space
    if (used_percent > 80.0) {
        printf("Warning: You are running low on disk space! Consider cleaning up some files.\n");
    } else {
        printf("Good news! You have enough space left.\n");
    }

    // Summon the spirits of storage
    printf("Remember, disk space management is key to system performance!\n");
    printf("Perform regular clean-ups and organize your files efficiently.\n");
    printf("Explore tools like 'du' and 'df' for even deeper analysis!\n");
    
    // Optional: Print out file system type (assuming the stat structure has this)
    // For now, let's keep it simple as it may vary between filesystems
    // printf("File System Type: %s\n", "Unknown"); // Placeholder for example sake
}