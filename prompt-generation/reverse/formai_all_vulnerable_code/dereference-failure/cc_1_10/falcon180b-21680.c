//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char path[MAX_PATH_LEN];
    unsigned long long total_size;
    unsigned long long used_size;
    unsigned long long free_size;
    float usage_percent;
} disk_info_t;

void show_usage(void) {
    printf("Usage:./disk_analyzer [path]\n");
    exit(1);
}

void print_disk_info(disk_info_t* info) {
    printf("Path: %s\n", info->path);
    printf("Total size: %llu bytes\n", info->total_size);
    printf("Used size: %llu bytes\n", info->used_size);
    printf("Free size: %llu bytes\n", info->free_size);
    printf("Usage percentage: %.2f%%\n\n", info->usage_percent);
}

void analyze_dir(const char* path, disk_info_t* info) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: failed to open directory '%s'\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char subpath[MAX_PATH_LEN];
            snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
            analyze_dir(subpath, info);
        } else {
            char filepath[MAX_PATH_LEN];
            snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
            struct statvfs fs_info;
            if (statvfs(filepath, &fs_info) == 0) {
                info->total_size += fs_info.f_bsize * fs_info.f_blocks;
                info->used_size += fs_info.f_bsize * fs_info.f_blocks - fs_info.f_bavail;
            }
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        show_usage();
    }

    char path[MAX_PATH_LEN];
    strncpy(path, argv[1], sizeof(path));

    disk_info_t info = {0};
    info.path[0] = '\0';

    analyze_dir(path, &info);

    print_disk_info(&info);

    return 0;
}