//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_DIR_LENGTH 256
#define MAX_FILE_LENGTH 256

typedef struct {
    char dir_name[MAX_DIR_LENGTH];
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
    unsigned long long num_files;
    unsigned long long num_dirs;
} DirectoryStats;

void get_directory_stats(const char *dir_path, DirectoryStats *stats) {
    DIR *dir = opendir(dir_path);
    struct dirent *ent;
    struct statvfs fs_info;

    if (dir == NULL) {
        printf("Error: Could not open directory '%s'\n", dir_path);
        exit(1);
    }

    if (statvfs(dir_path, &fs_info) == -1) {
        printf("Error: Could not get filesystem info for directory '%s'\n", dir_path);
        exit(1);
    }

    stats->total_space = fs_info.f_blocks * fs_info.f_frsize;
    stats->used_space = fs_info.f_blocks - fs_info.f_bfree;
    stats->free_space = fs_info.f_bavail * fs_info.f_frsize;
    stats->num_files = 0;
    stats->num_dirs = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            stats->num_dirs++;
        } else if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
            stats->num_files++;
        }
    }

    closedir(dir);
}

void print_directory_stats(const DirectoryStats *stats) {
    printf("Directory: %s\n", stats->dir_name);
    printf("Total space: %llu bytes\n", stats->total_space);
    printf("Used space: %llu bytes\n", stats->used_space);
    printf("Free space: %llu bytes\n", stats->free_space);
    printf("Number of files: %lu\n", stats->num_files);
    printf("Number of directories: %lu\n\n", stats->num_dirs);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    DirectoryStats stats;
    strncpy(stats.dir_name, argv[1], MAX_DIR_LENGTH);

    get_directory_stats(argv[1], &stats);
    print_directory_stats(&stats);

    return 0;
}