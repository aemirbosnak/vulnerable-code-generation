//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to print the disk space usage of a directory
void print_dir_space_usage(char* dir_path) {
    struct statvfs statvfs_buf;
    statvfs(dir_path, &statvfs_buf);

    printf("Directory: %s\n", dir_path);
    printf("Total space: %lld bytes\n", statvfs_buf.f_blocks * statvfs_buf.f_frsize);
    printf("Free space: %lld bytes\n", statvfs_buf.f_bavail * statvfs_buf.f_frsize);
    printf("Used space: %lld bytes\n", (statvfs_buf.f_blocks - statvfs_buf.f_bfree) * statvfs_buf.f_frsize);
    printf("Used percentage: %.2f%%\n", ((double) (statvfs_buf.f_blocks - statvfs_buf.f_bfree) / statvfs_buf.f_blocks) * 100.0);
    printf("\n");
}

// Function to print the disk space usage of all subdirectories
void print_subdir_space_usage(char* dir_path) {
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(dir_path);

    if (dp == NULL) {
        printf("Error opening directory %s\n", dir_path);
        return;
    }

    char subdir_path[BUFFER_SIZE];
    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_DIR) {
            strcpy(subdir_path, dir_path);
            strcat(subdir_path, "/");
            strcat(subdir_path, dirp->d_name);

            print_dir_space_usage(subdir_path);
        }
    }

    closedir(dp);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char dir_path[BUFFER_SIZE];
    strcpy(dir_path, argv[1]);

    print_dir_space_usage(dir_path);
    print_subdir_space_usage(dir_path);

    return 0;
}