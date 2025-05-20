//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define DEPTH_LIMIT 1000 // Maximum depth of directories to scan

// Function to print usage instructions
void print_usage() {
    printf("Usage:./disk_space_analyzer [directory]\n");
}

// Function to calculate total disk space used by a directory and its subdirectories
long long calculate_directory_size(const char* path) {
    struct statvfs statvfs_buf;
    if (statvfs(path, &statvfs_buf) == -1) {
        perror("statvfs");
        return -1;
    }

    long long total_space = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
    long long free_space = statvfs_buf.f_bavail * statvfs_buf.f_frsize;

    return total_space - free_space;
}

// Function to scan a directory and its subdirectories for files and directories
void scan_directory(const char* path, int depth) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR && depth < DEPTH_LIMIT) {
            char* subdir_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(subdir_path, "%s/%s", path, entry->d_name);
            scan_directory(subdir_path, depth + 1);
            free(subdir_path);
        } else if (entry->d_type == DT_REG) {
            printf("%s\t%lld bytes\n", entry->d_name, entry->d_reclen);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    const char* path = argv[1];
    long long directory_size = calculate_directory_size(path);

    if (directory_size == -1) {
        return 1;
    }

    printf("Directory size: %lld bytes\n", directory_size);

    scan_directory(path, 0);

    return 0;
}