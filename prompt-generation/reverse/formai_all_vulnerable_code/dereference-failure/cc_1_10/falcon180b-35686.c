//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_FILE_SIZE 1024
#define MAX_DIR_DEPTH 100

typedef struct {
    char path[MAX_FILE_SIZE];
    unsigned long long size;
} file_info_t;

typedef struct {
    char path[MAX_FILE_SIZE];
    unsigned long long total_size;
    unsigned long long num_files;
} dir_info_t;

void print_file_info(file_info_t *file_info) {
    printf("Path: %s\n", file_info->path);
    printf("Size: %llu bytes\n\n", file_info->size);
}

void print_dir_info(dir_info_t *dir_info) {
    printf("Path: %s\n", dir_info->path);
    printf("Total size: %llu bytes\n", dir_info->total_size);
    printf("Number of files: %llu\n\n", dir_info->num_files);
}

void analyze_dir(const char *path, int depth, dir_info_t *dir_info) {
    DIR *dir;
    struct dirent *ent;
    struct statvfs statvfs_buf;

    if ((dir = opendir(path)) == NULL) {
        perror("");
        return;
    }

    if (statvfs(path, &statvfs_buf) == -1) {
        perror("");
        closedir(dir);
        return;
    }

    dir_info->total_size = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
    dir_info->num_files = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (depth > MAX_DIR_DEPTH) {
            break;
        }

        char sub_path[MAX_FILE_SIZE];
        sprintf(sub_path, "%s/%s", path, ent->d_name);

        if (ent->d_type == DT_DIR) {
            analyze_dir(sub_path, depth + 1, dir_info);
        } else {
            file_info_t file_info;
            sprintf(file_info.path, "%s/%s", path, ent->d_name);
            file_info.size = ent->d_reclen;

            print_file_info(&file_info);
            dir_info->num_files++;
            dir_info->total_size += file_info.size;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir_info_t dir_info;
    analyze_dir(argv[1], 0, &dir_info);

    return 0;
}