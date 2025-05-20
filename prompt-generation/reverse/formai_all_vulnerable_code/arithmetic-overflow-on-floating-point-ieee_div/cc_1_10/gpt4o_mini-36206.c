//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void analyze_disk_space(const char *path);
void print_disk_usage(const char *path, unsigned long used, unsigned long total);
void get_disk_statistics(const char *path, unsigned long *used, unsigned long *total);

int main(int argc, char *argv[]) {
    // Validate input arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check if the directory exists
    if (access(argv[1], F_OK) != 0) {
        perror("Error accessing directory");
        exit(EXIT_FAILURE);
    }

    // Analyze disk space for the specified path
    analyze_disk_space(argv[1]);
    return EXIT_SUCCESS;
}

void analyze_disk_space(const char *path) {
    unsigned long used_space = 0;
    unsigned long total_space = 0;

    get_disk_statistics(path, &used_space, &total_space);
    print_disk_usage(path, used_space, total_space);
}

void get_disk_statistics(const char *path, unsigned long *used, unsigned long *total) {
    struct statvfs stat;

    // Get file system statistics
    if (statvfs(path, &stat) != 0) {
        perror("Error retrieving file system statistics");
        exit(EXIT_FAILURE);
    }

    // Calculate total and used space
    *total = stat.f_blocks * stat.f_frsize;
    *used = (*total - stat.f_bfree * stat.f_frsize);
}

void print_disk_usage(const char *path, unsigned long used, unsigned long total) {
    printf("Disk Usage Statistics for: %s\n", path);
    printf("-------------------------------------\n");
    printf("Total Disk Space: %.2f GB\n", (float)total / (1024 * 1024 * 1024));
    printf("Used Disk Space: %.2f GB\n", (float)used / (1024 * 1024 * 1024));
    printf("Available Disk Space: %.2f GB\n", (float)(total - used) / (1024 * 1024 * 1024));
    printf("-------------------------------------\n");
    printf("Disk Usage Percentage: %.2f%%\n", ((float)used / total) * 100);
}

void list_files_in_directory(const char *path) {
    char command[MAX_PATH + 50];
    snprintf(command, sizeof(command), "ls -lh %s | awk '{print $9 \" -> \" $5}'", path);
    printf("Files in Directory (%s):\n", path);
    system(command);
    printf("-------------------------------------\n");
}