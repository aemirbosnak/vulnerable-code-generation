//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

typedef struct {
    char path[BUF_SIZE];
    long long total_space;
    long long used_space;
    long long free_space;
} disk_info_t;

void print_disk_info(disk_info_t *info) {
    printf("Path: %s\n", info->path);
    printf("Total space: %lld bytes\n", info->total_space);
    printf("Used space: %lld bytes\n", info->used_space);
    printf("Free space: %lld bytes\n", info->free_space);
    printf("\n");
}

void get_disk_info(char *path, disk_info_t *info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        printf("Error getting disk info for %s\n", path);
        exit(1);
    }
    info->total_space = buf.f_blocks * buf.f_frsize;
    info->used_space = buf.f_blocks - buf.f_bfree;
    info->free_space = buf.f_bfree * buf.f_frsize;
    strcpy(info->path, path);
}

void analyze_disk(char *path) {
    DIR *dir;
    struct dirent *ent;
    disk_info_t root_info;
    disk_info_t curr_info;

    get_disk_info(path, &root_info);

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", path);
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        char sub_path[BUF_SIZE];
        sprintf(sub_path, "%s/%s", path, ent->d_name);

        get_disk_info(sub_path, &curr_info);
        curr_info.path[strcspn(curr_info.path, "/")] = '\0'; // Remove trailing slash from path

        printf("Analyzing %s...\n", curr_info.path);
        print_disk_info(&curr_info);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    analyze_disk(argv[1]);

    return 0;
}