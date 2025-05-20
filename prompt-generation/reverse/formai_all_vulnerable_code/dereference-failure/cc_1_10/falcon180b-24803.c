//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH_LENGTH 1024

typedef struct {
    char path[MAX_PATH_LENGTH];
    size_t size;
    size_t used;
    size_t available;
} DiskSpaceInfo;

void get_size_info(const char* path, DiskSpaceInfo* info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        info->size = buf.f_blocks * buf.f_frsize;
        info->used = buf.f_blocks - buf.f_bfree;
        info->available = buf.f_bavail * buf.f_frsize;
    } else {
        printf("Error: failed to get disk space info for %s\n", path);
        exit(1);
    }
}

void print_disk_space_info(DiskSpaceInfo* info) {
    printf("Path: %s\n", info->path);
    printf("Size: %zu bytes\n", info->size);
    printf("Used: %zu bytes\n", info->used);
    printf("Available: %zu bytes\n\n", info->available);
}

void analyze_disk_space(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: failed to open directory %s\n", path);
        exit(1);
    }

    DiskSpaceInfo root_info;
    get_size_info(path, &root_info);
    print_disk_space_info(&root_info);

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            DiskSpaceInfo dir_info;
            get_size_info(full_path, &dir_info);
            print_disk_space_info(&dir_info);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);
    return 0;
}