//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

struct dir_info {
    char* path;
    long total_size;
    long free_space;
    long used_space;
};

void get_dir_info(const char* path, struct dir_info* info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        printf("Error getting directory info for %s\n", path);
        exit(1);
    }
    info->total_size = buf.f_blocks * buf.f_frsize;
    info->free_space = buf.f_bavail * buf.f_frsize;
    info->used_space = info->total_size - info->free_space;
}

void print_dir_info(const struct dir_info* info) {
    printf("Path: %s\n", info->path);
    printf("Total size: %ld bytes\n", info->total_size);
    printf("Free space: %ld bytes\n", info->free_space);
    printf("Used space: %ld bytes\n", info->used_space);
    printf("\n");
}

void analyze_directory(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", path);
        exit(1);
    }
    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        char* full_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
        sprintf(full_path, "%s/%s", path, ent->d_name);
        struct dir_info dir_info;
        get_dir_info(full_path, &dir_info);
        print_dir_info(&dir_info);
        free(full_path);
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    analyze_directory(argv[1]);
    return 0;
}