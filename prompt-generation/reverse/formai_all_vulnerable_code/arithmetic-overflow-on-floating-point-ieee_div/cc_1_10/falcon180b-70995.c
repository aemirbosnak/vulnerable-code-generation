//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH_LEN 1024
#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)

typedef struct {
    char path[MAX_PATH_LEN];
    size_t size;
    size_t used;
    size_t available;
    double percent_used;
} disk_info_t;

void print_usage() {
    printf("Usage:./disk_analyzer <path>\n");
}

void print_disk_info(disk_info_t *disk_info) {
    printf("Path: %s\n", disk_info->path);
    printf("Total Size: %.2f %s\n", disk_info->size / GB, "GB");
    printf("Used Space: %.2f %s\n", disk_info->used / GB, "GB");
    printf("Available Space: %.2f %s\n", disk_info->available / GB, "GB");
    printf("Percentage Used: %.2f%%\n\n", disk_info->percent_used);
}

void get_disk_info(const char *path, disk_info_t *disk_info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        printf("Error: could not get disk info for %s\n", path);
        exit(1);
    }

    disk_info->size = buf.f_blocks * buf.f_frsize;
    disk_info->used = buf.f_blocks - buf.f_bfree;
    disk_info->available = buf.f_bfree * buf.f_frsize;
    disk_info->percent_used = (double)disk_info->used / disk_info->size * 100;

    strcpy(disk_info->path, path);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    disk_info_t disk_info;
    get_disk_info(argv[1], &disk_info);
    print_disk_info(&disk_info);

    return 0;
}