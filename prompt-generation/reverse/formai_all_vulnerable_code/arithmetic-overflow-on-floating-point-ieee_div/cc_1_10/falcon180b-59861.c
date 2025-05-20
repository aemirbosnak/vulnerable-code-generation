//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_PATH 1024
#define GIGABYTE (1024 * 1024 * 1024)

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_size;
    unsigned long long used_size;
    unsigned long long available_size;
    unsigned long long percentage;
} DiskSpace;

void calculate_percentage(DiskSpace *disk_space) {
    disk_space->percentage = (double)disk_space->used_size / disk_space->total_size * 100.0;
}

void print_disk_space(DiskSpace *disk_space) {
    printf("%-30s %10llu %10llu %10llu %10.2f%%\n", disk_space->path, disk_space->total_size, disk_space->used_size, disk_space->available_size, disk_space->percentage);
}

int get_disk_space(const char *path, DiskSpace *disk_space) {
    struct statvfs statvfs_buffer;
    if (statvfs(path, &statvfs_buffer) == -1) {
        perror("statvfs");
        return -1;
    }

    disk_space->total_size = statvfs_buffer.f_blocks * statvfs_buffer.f_frsize;
    disk_space->used_size = statvfs_buffer.f_blocks - statvfs_buffer.f_bavail;
    disk_space->available_size = statvfs_buffer.f_bavail * statvfs_buffer.f_frsize;

    calculate_percentage(disk_space);
    strcpy(disk_space->path, path);

    return 0;
}

void print_header() {
    printf("%-30s %10s %10s %10s %s\n", "Path", "Total", "Used", "Available", "Percentage");
}

int main() {
    printf("Disk Space Analyzer\n\n");
    print_header();

    char path[MAX_PATH];
    if (getcwd(path, MAX_PATH) == NULL) {
        perror("getcwd");
        return -1;
    }

    DiskSpace disk_space;
    get_disk_space(path, &disk_space);
    print_disk_space(&disk_space);

    return 0;
}