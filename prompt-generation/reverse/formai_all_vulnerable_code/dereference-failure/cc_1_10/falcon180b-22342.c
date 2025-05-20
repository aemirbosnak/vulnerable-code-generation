//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_PATH_LENGTH 1024

// Function to count the total number of files and directories in a given path
int count_files_and_dirs(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    int count = 0;
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        count++;
    }

    closedir(dir);
    return count;
}

// Function to get the total disk space used by a directory and its subdirectories
int get_total_disk_space(const char* path) {
    struct statvfs stats;
    if (statvfs(path, &stats) == -1) {
        return -1;
    }

    int total_space = stats.f_blocks * stats.f_frsize;
    return total_space;
}

// Function to get the total number of files and directories in a given path recursively
int get_total_files_and_dirs(const char* path) {
    int count = 0;
    struct dirent* entry;
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char* full_path = malloc(MAX_PATH_LENGTH);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        int type = entry->d_type;
        if (type & DT_DIR) {
            count += get_total_files_and_dirs(full_path);
        } else {
            count++;
        }

        free(full_path);
    }

    closedir(dir);
    return count;
}

// Function to print the disk space usage of a directory and its subdirectories
void print_disk_space(const char* path) {
    int total_space = get_total_disk_space(path);
    int total_files_and_dirs = get_total_files_and_dirs(path);

    printf("Total disk space used: %d bytes\n", total_space);
    printf("Total number of files and directories: %d\n", total_files_and_dirs);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return -1;
    }

    const char* path = argv[1];
    print_disk_space(path);

    return 0;
}