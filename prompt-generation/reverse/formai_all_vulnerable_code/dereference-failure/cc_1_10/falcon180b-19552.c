//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_size;
    unsigned long long used_size;
    unsigned long long free_size;
} disk_info;

void get_disk_info(const char* path, disk_info* info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        info->total_size = buf.f_blocks * buf.f_frsize;
        info->used_size = (buf.f_blocks - buf.f_bavail) * buf.f_frsize;
        info->free_size = buf.f_bavail * buf.f_frsize;
    }
}

void print_disk_info(const disk_info* info) {
    printf("Path: %s\n", info->path);
    printf("Total size: %llu bytes\n", info->total_size);
    printf("Used size: %llu bytes\n", info->used_size);
    printf("Free size: %llu bytes\n", info->free_size);
    printf("\n");
}

void analyze_directory(const char* path, int depth) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char new_path[MAX_PATH];
            strcpy(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, ent->d_name);

            analyze_directory(new_path, depth + 1);
        } else {
            disk_info info;
            strcpy(info.path, path);
            get_disk_info(info.path, &info);
            print_disk_info(&info);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1], 0);

    return 0;
}