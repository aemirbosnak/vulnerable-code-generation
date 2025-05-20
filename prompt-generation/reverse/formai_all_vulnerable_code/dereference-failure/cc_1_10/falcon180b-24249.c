//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <unistd.h>

#define BLOCK_SIZE 1024
#define TOTAL_SPACE 1048576 // 1 MB

typedef struct {
    char* path;
    unsigned long long total_space;
    unsigned long long used_space;
    unsigned long long free_space;
    unsigned long long total_files;
    unsigned long long total_directories;
} Directory;

void get_directory_info(Directory* dir_info, const char* path) {
    DIR* dir = opendir(path);
    struct dirent* entry;
    if (dir!= NULL) {
        while ((entry = readdir(dir))!= NULL) {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".")!= 0 && strcmp(entry->d_name, "..")!= 0) {
                dir_info->total_directories++;
            } else if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
                dir_info->total_files++;
            }
        }
        closedir(dir);
    }
}

void get_space_info(Directory* dir_info, const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        dir_info->total_space = buf.f_bsize * buf.f_blocks;
        dir_info->used_space = buf.f_blocks - buf.f_bfree;
        dir_info->free_space = buf.f_bfree * buf.f_bsize;
    }
}

void print_directory_info(Directory* dir_info) {
    printf("Total Space: %llu bytes\n", dir_info->total_space);
    printf("Used Space: %llu bytes\n", dir_info->used_space);
    printf("Free Space: %llu bytes\n", dir_info->free_space);
    printf("Total Files: %llu\n", dir_info->total_files);
    printf("Total Directories: %llu\n", dir_info->total_directories);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    Directory dir_info;
    dir_info.path = argv[1];
    get_directory_info(&dir_info, argv[1]);
    get_space_info(&dir_info, argv[1]);
    print_directory_info(&dir_info);

    return 0;
}