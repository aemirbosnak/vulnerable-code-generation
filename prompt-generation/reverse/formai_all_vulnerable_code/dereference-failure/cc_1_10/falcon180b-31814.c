//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_PATH 1024

// Function to get the size of a directory in bytes
long long get_dir_size(const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        return buf.f_blocks * buf.f_frsize;
    }
    return -1;
}

// Function to get the total size of all files in a directory
long long get_total_size(const char* path) {
    long long size = 0;
    DIR* dir = opendir(path);
    if (dir!= NULL) {
        struct dirent* ent;
        while ((ent = readdir(dir))!= NULL) {
            char full_path[MAX_PATH];
            sprintf(full_path, "%s/%s", path, ent->d_name);
            if (ent->d_type == DT_REG) {
                size += get_dir_size(full_path);
            }
        }
        closedir(dir);
    }
    return size;
}

// Function to print the disk usage of a directory
void print_disk_usage(const char* path) {
    long long dir_size = get_dir_size(path);
    long long total_size = get_total_size(path);
    double disk_usage = (double)total_size / dir_size * 100.0;
    printf("Directory: %s\n", path);
    printf("Total size: %.2f GB\n", disk_usage);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    print_disk_usage(argv[1]);
    return 0;
}