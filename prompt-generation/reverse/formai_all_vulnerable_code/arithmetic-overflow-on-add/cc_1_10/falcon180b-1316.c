//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_FILE_NAME 1024
#define MAX_DIR_NAME 1024

struct dir_info {
    char dir_name[MAX_DIR_NAME];
    long total_size;
    long num_files;
    long num_dirs;
};

void get_dir_info(const char* path, struct dir_info* info) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Failed to open directory %s\n", path);
        exit(1);
    }

    struct dirent* dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR) {
            info->num_dirs++;
        } else {
            info->num_files++;
        }
    }

    closedir(dir);

    info->total_size = 0;
    struct statvfs statbuf;
    if (statvfs(path, &statbuf) == 0) {
        info->total_size = statbuf.f_blocks * statbuf.f_frsize;
    }

    strcpy(info->dir_name, path);
}

void print_dir_info(const struct dir_info* info) {
    printf("Directory: %s\n", info->dir_name);
    printf("Total size: %ld bytes\n", info->total_size);
    printf("Number of files: %ld\n", info->num_files);
    printf("Number of directories: %ld\n", info->num_dirs);
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    struct dir_info root_info;
    get_dir_info(argv[1], &root_info);
    print_dir_info(&root_info);

    char path[MAX_DIR_NAME];
    strcpy(path, argv[1]);
    strcat(path, "/");

    struct dirent* dirent;
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Failed to open directory %s\n", path);
        exit(1);
    }

    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR) {
            strcpy(path + strlen(path), dirent->d_name);
            strcat(path, "/");

            struct dir_info info;
            get_dir_info(path, &info);
            print_dir_info(&info);
        }
    }

    closedir(dir);

    return 0;
}