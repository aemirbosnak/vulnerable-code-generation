//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
} DiskInfo;

void print_disk_info(DiskInfo* disk_info) {
    printf("Path: %s\n", disk_info->path);
    printf("Total space: %lld bytes\n", disk_info->total_space);
    printf("Used space: %lld bytes\n", disk_info->used_space);
    printf("Free space: %lld bytes\n", disk_info->free_space);
    printf("\n");
}

void get_disk_info(const char* path, DiskInfo* disk_info) {
    struct statvfs buf;
    if (statvfs(path, &buf)!= 0) {
        printf("Error getting disk info for %s\n", path);
        return;
    }

    disk_info->total_space = buf.f_blocks * buf.f_frsize;
    disk_info->used_space = buf.f_blocks - buf.f_bfree;
    disk_info->free_space = buf.f_bfree * buf.f_frsize;

    strncpy(disk_info->path, path, MAX_PATH);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    strncpy(path, argv[1], MAX_PATH);

    DiskInfo disk_info;
    get_disk_info(path, &disk_info);
    print_disk_info(&disk_info);

    return 0;
}