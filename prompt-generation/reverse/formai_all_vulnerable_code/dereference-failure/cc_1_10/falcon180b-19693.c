//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char path[MAX_PATH_LENGTH];
    long long total_space;
    long long used_space;
    long long free_space;
} DiskSpace;

void get_directory_space(const char* directory, DiskSpace* disk_space) {
    struct statvfs buf;

    if (statvfs(directory, &buf)!= 0) {
        printf("Error getting directory space for %s\n", directory);
        exit(1);
    }

    disk_space->total_space = buf.f_blocks * buf.f_frsize;
    disk_space->used_space = buf.f_blocks - buf.f_bavail;
    disk_space->free_space = buf.f_bavail * buf.f_frsize;

    strcpy(disk_space->path, directory);
}

void print_disk_space(DiskSpace* disk_space) {
    printf("Path: %s\n", disk_space->path);
    printf("Total space: %lld bytes\n", disk_space->total_space);
    printf("Used space: %lld bytes\n", disk_space->used_space);
    printf("Free space: %lld bytes\n", disk_space->free_space);
    printf("\n");
}

void analyze_directory(const char* directory) {
    DIR* dir;
    struct dirent* ent;
    DiskSpace disk_space;

    if ((dir = opendir(directory))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char path[MAX_PATH_LENGTH];

            sprintf(path, "%s/%s", directory, ent->d_name);

            if (ent->d_type == DT_DIR) {
                analyze_directory(path);
            } else {
                get_directory_space(path, &disk_space);
                print_disk_space(&disk_space);
            }
        }

        closedir(dir);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);

    return 0;
}