//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

typedef struct {
    char *path;
    size_t size;
} FileInfo;

void print_file_info(FileInfo *file_info) {
    printf("Path: %s\n", file_info->path);
    printf("Size: %zu bytes\n", file_info->size);
    printf("\n");
}

void print_directory_info(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char subdir_path[MAX_PATH];
            snprintf(subdir_path, MAX_PATH, "%s/%s", path, ent->d_name);
            print_directory_info(subdir_path);
        } else {
            char file_path[MAX_PATH];
            snprintf(file_path, MAX_PATH, "%s/%s", path, ent->d_name);
            struct stat stat_buf;
            if (stat(file_path, &stat_buf) == -1) {
                perror("Error getting file information");
                exit(1);
            }

            FileInfo file_info = {
               .path = file_path,
               .size = stat_buf.st_size
            };
            print_file_info(&file_info);
        }
    }

    closedir(dir);
}

void print_disk_space_info(const char *path) {
    struct statvfs statvfs_buf;
    if (statvfs(path, &statvfs_buf) == -1) {
        perror("Error getting disk space information");
        exit(1);
    }

    printf("Total space: %zu bytes\n", statvfs_buf.f_blocks * statvfs_buf.f_frsize);
    printf("Available space: %zu bytes\n", statvfs_buf.f_bavail * statvfs_buf.f_frsize);
    printf("Used space: %zu bytes\n", (statvfs_buf.f_blocks - statvfs_buf.f_bfree) * statvfs_buf.f_frsize);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        exit(1);
    }

    const char *path = argv[1];
    print_disk_space_info(path);
    print_directory_info(path);

    return 0;
}