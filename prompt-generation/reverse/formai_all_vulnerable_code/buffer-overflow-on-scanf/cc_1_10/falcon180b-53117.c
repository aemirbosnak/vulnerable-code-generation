//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILE_NAME_LEN 256
#define MAX_PATH_LEN 4096

typedef struct {
    char filename[MAX_FILE_NAME_LEN];
    unsigned long size;
    unsigned int is_dir;
} FileInfo;

void get_file_info(const char* path, FileInfo* file_info) {
    struct stat stat_buf;
    if (stat(path, &stat_buf) == -1) {
        printf("Failed to get file info for %s\n", path);
        return;
    }
    strncpy(file_info->filename, path, MAX_FILE_NAME_LEN - 1);
    file_info->size = stat_buf.st_size;
    file_info->is_dir = S_ISDIR(stat_buf.st_mode);
}

void analyze_dir(const char* path, unsigned long* total_size, unsigned long* total_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory %s\n", path);
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char full_path[MAX_PATH_LEN];
        snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, entry->d_name);
        FileInfo file_info;
        get_file_info(full_path, &file_info);
        if (file_info.is_dir) {
            analyze_dir(full_path, total_size, total_files);
        } else {
            *total_size += file_info.size;
            (*total_files)++;
        }
    }
    closedir(dir);
}

int main() {
    char path[MAX_PATH_LEN];
    printf("Enter directory path: ");
    scanf("%s", path);
    unsigned long total_size = 0, total_files = 0;
    analyze_dir(path, &total_size, &total_files);
    printf("Total size: %lu bytes\n", total_size);
    printf("Total files: %lu\n", total_files);
    return 0;
}