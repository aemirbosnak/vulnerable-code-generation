//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

typedef struct {
    char path[BUF_SIZE];
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
} disk_info_t;

void print_usage(char *program_name) {
    printf("Usage: %s [directory]\n", program_name);
}

int get_disk_info(disk_info_t *disk_info, char *path) {
    struct statvfs statvfs_buf;
    if (statvfs(path, &statvfs_buf) == -1) {
        printf("Error getting disk info for %s: %s\n", path, strerror(errno));
        return 1;
    }

    disk_info->total_space = (unsigned long long) statvfs_buf.f_blocks * statvfs_buf.f_frsize;
    disk_info->used_space = (unsigned long long) statvfs_buf.f_blocks - statvfs_buf.f_bfree;
    disk_info->free_space = (unsigned long long) statvfs_buf.f_bfree * statvfs_buf.f_frsize;

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    disk_info_t disk_info;
    strncpy(disk_info.path, argv[1], BUF_SIZE - 1);

    if (get_disk_info(&disk_info, disk_info.path)) {
        return 1;
    }

    printf("Disk info for %s:\n", disk_info.path);
    printf("Total space: %llu bytes\n", disk_info.total_space);
    printf("Used space: %llu bytes\n", disk_info.used_space);
    printf("Free space: %llu bytes\n", disk_info.free_space);

    return 0;
}