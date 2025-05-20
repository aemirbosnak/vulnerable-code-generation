//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char path[BUFFER_SIZE];
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
} disk_space_t;

void get_disk_space(disk_space_t* disk_space) {
    struct statvfs buf;
    if (statvfs(disk_space->path, &buf)!= 0) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }
    disk_space->total_space = buf.f_blocks * buf.f_frsize;
    disk_space->used_space = buf.f_blocks - buf.f_bfree;
    disk_space->free_space = buf.f_bfree * buf.f_frsize;
}

void print_disk_space(disk_space_t* disk_space) {
    printf("Path: %s\n", disk_space->path);
    printf("Total Space: %llu bytes\n", disk_space->total_space);
    printf("Used Space: %llu bytes\n", disk_space->used_space);
    printf("Free Space: %llu bytes\n\n", disk_space->free_space);
}

void analyze_disk_space(char* path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d))!= NULL) {
            disk_space_t disk_space;
            strcpy(disk_space.path, path);
            strcat(disk_space.path, "/");
            strcat(disk_space.path, dir->d_name);
            get_disk_space(&disk_space);
            print_disk_space(&disk_space);
        }
        closedir(d);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage:./program path\n");
        return 1;
    }
    analyze_disk_space(argv[1]);
    return 0;
}