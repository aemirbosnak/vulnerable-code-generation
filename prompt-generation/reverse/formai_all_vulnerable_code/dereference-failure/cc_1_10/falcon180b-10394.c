//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 1024

struct file_info {
    char path[MAX_PATH_LEN];
    unsigned long long size;
};

void print_file_info(struct file_info* file_info) {
    printf("Path: %s\n", file_info->path);
    printf("Size: %llu bytes\n", file_info->size);
}

void get_file_info(const char* path, struct file_info* file_info) {
    struct stat stat_buf;
    memset(file_info, 0, sizeof(struct file_info));

    if (stat(path, &stat_buf) == -1) {
        printf("Error: Could not stat file %s\n", path);
        return;
    }

    strncpy(file_info->path, path, MAX_PATH_LEN - 1);
    file_info->size = stat_buf.st_size;
}

void print_directory_info(const char* path) {
    DIR* dir = opendir(path);

    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        return;
    }

    struct dirent* dirent = NULL;
    while ((dirent = readdir(dir))!= NULL) {
        struct file_info file_info;
        get_file_info(dirent->d_name, &file_info);
        print_file_info(&file_info);
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    print_directory_info(argv[1]);

    return 0;
}