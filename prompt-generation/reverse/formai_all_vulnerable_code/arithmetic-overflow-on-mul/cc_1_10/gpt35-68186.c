//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCK_SIZE 512

typedef struct {
    unsigned long long total_size;
    unsigned long long used_size;
    unsigned long long free_size;
} disk_space_info;

// Function to recursively calculate disk usage
void calculate_disk_usage(char *path, disk_space_info *info) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Unable to open directory %s\n", path);
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *child_path = (char *) malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(child_path, "%s/%s", path, entry->d_name);
        struct stat st;
        if (stat(child_path, &st) == -1) {
            printf("Unable to get information for %s\n", child_path);
            free(child_path);
            continue;
        }
        if (S_ISDIR(st.st_mode)) {
            calculate_disk_usage(child_path, info);
        } else if (S_ISREG(st.st_mode)) {
            info->total_size += st.st_size;
            info->used_size += (st.st_blocks * BLOCK_SIZE);
        }
        free(child_path);
    }
    closedir(dir);
}

// Function to print disk space information
void print_disk_space_info(disk_space_info *info) {
    printf("Total disk space: %.2f GB\n", (double)info->total_size / 1024 / 1024 / 1024);
    printf("Used disk space: %.2f GB\n", (double)info->used_size / 1024 / 1024 / 1024);
    printf("Free disk space: %.2f GB\n", (double)info->free_size / 1024 / 1024 / 1024);
    printf("Disk usage percentage: %.2f%%\n", (double)info->used_size / info->total_size * 100);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please specify a directory path\n");
        return 1;
    }
    char *path = argv[1];
    disk_space_info info = {0, 0, 0};
    calculate_disk_usage(path, &info);
    info.free_size = (info.total_size - info.used_size);
    print_disk_space_info(&info);
    return 0;
}