//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

// Function to print disk usage information
void print_usage(char *path, struct statvfs f_statvfs) {
    printf("Disk usage for %s:\n", path);
    printf("Total space: %ld bytes\n", f_statvfs.f_bsize * f_statvfs.f_blocks);
    printf("Available space: %ld bytes\n", f_statvfs.f_bsize * f_statvfs.f_bavail);
    printf("Used space: %ld bytes\n", f_statvfs.f_bsize * (f_statvfs.f_blocks - f_statvfs.f_bavail));
}

// Function to get disk usage information for a directory
void get_usage(char *path) {
    struct statvfs f_statvfs;
    if (statvfs(path, &f_statvfs)!= 0) {
        perror("Could not get disk usage information");
        exit(1);
    }
    print_usage(path, f_statvfs);
}

// Function to traverse a directory and get disk usage information for all subdirectories
void traverse_directory(char *path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d == NULL) {
        perror("Could not open directory");
        exit(1);
    }
    while ((dir = readdir(d))!= NULL) {
        char subpath[strlen(path) + strlen(dir->d_name) + 2];
        strcpy(subpath, path);
        strcat(subpath, "/");
        strcat(subpath, dir->d_name);
        if (dir->d_type == DT_DIR) {
            get_usage(subpath);
        }
    }
    closedir(d);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(1);
    }
    char path[strlen(argv[1]) + 1];
    strcpy(path, argv[1]);
    traverse_directory(path);
    return 0;
}