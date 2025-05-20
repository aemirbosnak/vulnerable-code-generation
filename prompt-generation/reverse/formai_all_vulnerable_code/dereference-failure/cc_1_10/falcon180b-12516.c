//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
    float used_percentage;
} DirectoryStats;

void get_directory_stats(const char* directory, DirectoryStats* stats) {
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }

    struct dirent* dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR) {
            char subdirectory[MAX_PATH];
            snprintf(subdirectory, MAX_PATH, "%s/%s", directory, dirent->d_name);
            get_directory_stats(subdirectory, stats);
        }
    }

    closedir(dir);

    stats->total_space = 0;
    stats->used_space = 0;
    stats->free_space = 0;
    stats->used_percentage = 0.0;

    struct statvfs statvfs_buf;
    if (statvfs(directory, &statvfs_buf) == -1) {
        perror("Error getting file system information");
        exit(1);
    }

    stats->total_space = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
    stats->free_space = stats->total_space - stats->used_space;
    stats->used_percentage = (float) stats->used_space / stats->total_space * 100.0;
}

void print_directory_stats(DirectoryStats* stats) {
    printf("Directory: %s\n", stats->path);
    printf("Total space: %lld bytes\n", stats->total_space);
    printf("Used space: %lld bytes\n", stats->used_space);
    printf("Free space: %lld bytes\n", stats->free_space);
    printf("Used percentage: %.2f%%\n", stats->used_percentage);
    printf("\n");
}

void analyze_disk_space(const char* root_directory) {
    DirectoryStats root_stats;
    get_directory_stats(root_directory, &root_stats);

    printf("Disk space analysis for %s:\n", root_directory);
    print_directory_stats(&root_stats);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}