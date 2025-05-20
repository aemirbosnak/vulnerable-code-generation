//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_space;
    unsigned long long free_space;
    unsigned long long used_space;
} disk_info;

void get_disk_info(disk_info* disk, const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        disk->total_space = buf.f_blocks * buf.f_frsize;
        disk->free_space = buf.f_bavail * buf.f_frsize;
        disk->used_space = disk->total_space - disk->free_space;
        strcpy(disk->path, path);
    }
}

void print_disk_info(const disk_info* disk) {
    printf("path: %s\n", disk->path);
    printf("total space: %llu bytes\n", disk->total_space);
    printf("free space: %llu bytes\n", disk->free_space);
    printf("used space: %llu bytes\n", disk->used_space);
    printf("\n");
}

void analyze_dir(const char* path, disk_info* disk_list, int num_disks) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        char full_path[MAX_PATH];
        sprintf(full_path, "%s/%s", path, ent->d_name);

        if (ent->d_type == DT_DIR) {
            disk_info disk;
            get_disk_info(&disk, full_path);
            print_disk_info(&disk);
            disk_list[num_disks++] = disk;
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: %s <directory>\n", argv[0]);
        return 1;
    }

    disk_info disk_list[100];
    int num_disks = 0;

    analyze_dir(argv[1], disk_list, num_disks);

    for (int i = 0; i < num_disks; i++) {
        print_disk_info(&disk_list[i]);
    }

    return 0;
}