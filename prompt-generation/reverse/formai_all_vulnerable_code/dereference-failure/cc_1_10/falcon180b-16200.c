//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH 4096

typedef struct {
    char name[MAX_PATH];
    unsigned long long size;
    unsigned long long blocks;
} FileInfo;

void print_file_info(FileInfo* file_info) {
    printf("%s %llu bytes %llu blocks\n", file_info->name, file_info->size, file_info->blocks);
}

void get_file_info(const char* path, FileInfo* file_info) {
    struct stat stat_buf;
    if (stat(path, &stat_buf) == -1) {
        printf("Error: failed to get file info for %s\n", path);
        exit(1);
    }
    file_info->size = stat_buf.st_size;
    file_info->blocks = stat_buf.st_blocks;
    strncpy(file_info->name, path, MAX_PATH);
}

void analyze_dir(const char* dir_path) {
    DIR* dir;
    struct dirent* dirent;
    if ((dir = opendir(dir_path)) == NULL) {
        printf("Error: failed to open directory %s\n", dir_path);
        exit(1);
    }
    while ((dirent = readdir(dir))!= NULL) {
        char path[MAX_PATH];
        snprintf(path, MAX_PATH, "%s/%s", dir_path, dirent->d_name);
        if (dirent->d_type == DT_DIR) {
            analyze_dir(path);
        } else {
            FileInfo file_info;
            get_file_info(path, &file_info);
            print_file_info(&file_info);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    analyze_dir(argv[1]);
    return 0;
}