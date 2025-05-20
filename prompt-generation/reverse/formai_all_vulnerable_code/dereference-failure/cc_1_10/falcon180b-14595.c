//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_space;
    unsigned long long used_space;
} disk_info;

void get_disk_info(disk_info *disk, const char *path) {
    struct statvfs buf;
    if (statvfs(path, &buf)!= 0) {
        printf("Error: cannot get disk info for %s\n", path);
        exit(1);
    }
    disk->total_space = buf.f_blocks * buf.f_frsize;
    disk->used_space = buf.f_blocks - buf.f_bavail;
    strcpy(disk->path, path);
}

void print_disk_info(const disk_info *disk) {
    printf("Path: %s\n", disk->path);
    printf("Total space: %llu bytes\n", disk->total_space);
    printf("Used space: %llu bytes\n", disk->used_space);
}

void analyze_dir(const char *path, int depth) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char full_path[MAX_PATH];
            sprintf(full_path, "%s/%s", path, ent->d_name);
            if (ent->d_type == DT_DIR) {
                analyze_dir(full_path, depth + 1);
            } else {
                disk_info disk;
                get_disk_info(&disk, full_path);
                print_disk_info(&disk);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    analyze_dir(argv[1], 0);
    return 0;
}