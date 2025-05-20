//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024 // Maximum length of a path

typedef struct {
    char path[MAX_PATH]; // Path of the directory
    unsigned long long total_space; // Total space of the directory
    unsigned long long used_space; // Used space of the directory
    unsigned long long free_space; // Free space of the directory
} DirectoryInfo;

void get_directory_info(const char* path, DirectoryInfo* info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        info->total_space = buf.f_blocks * buf.f_frsize;
        info->used_space = (buf.f_blocks - buf.f_bfree) * buf.f_frsize;
        info->free_space = buf.f_bfree * buf.f_frsize;
        strcpy(info->path, path);
    }
}

void print_directory_info(const DirectoryInfo* info) {
    printf("Path: %s\n", info->path);
    printf("Total space: %llu bytes\n", info->total_space);
    printf("Used space: %llu bytes\n", info->used_space);
    printf("Free space: %llu bytes\n", info->free_space);
    printf("\n");
}

void analyze_directory(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Cannot open directory '%s'\n", path);
        return;
    }

    DirectoryInfo root_info;
    get_directory_info(path, &root_info);
    print_directory_info(&root_info);

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char sub_path[MAX_PATH];
            sprintf(sub_path, "%s/%s", path, entry->d_name);
            analyze_directory(sub_path);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH];
    strcpy(path, argv[1]);
    analyze_directory(path);

    return 0;
}