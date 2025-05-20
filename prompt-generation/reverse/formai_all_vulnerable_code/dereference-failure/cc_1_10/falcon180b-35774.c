//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_DIR_DEPTH 8

typedef struct {
    char dir_name[256];
    struct dirent *dir;
    struct statvfs statvfs_buf;
} dir_info;

void print_usage(char *prog_name) {
    printf("Usage: %s [dir]\n", prog_name);
    exit(1);
}

void print_dir_info(dir_info *dir_info, int depth) {
    printf("%*s ", depth * 4, "");
    printf("%-20s ", dir_info->dir_name);
    printf("%-10lu ", dir_info->statvfs_buf.f_blocks);
    printf("%-10lu ", dir_info->statvfs_buf.f_bfree);
    printf("%-10lu\n", dir_info->statvfs_buf.f_bavail);
}

void get_dir_info(dir_info *dir_info) {
    struct statvfs statvfs_buf;
    statvfs(dir_info->dir_name, &statvfs_buf);
    dir_info->statvfs_buf = statvfs_buf;
}

int get_dir_list(char *dir_name, dir_info *dir_info, int depth) {
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(dir_name);
    if (dp == NULL) {
        printf("Error: Cannot open directory %s\n", dir_name);
        return 1;
    }
    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_DIR) {
            strcpy(dir_info->dir_name, dir_name);
            strcat(dir_info->dir_name, "/");
            strcat(dir_info->dir_name, dirp->d_name);
            if (depth < MAX_DIR_DEPTH) {
                dir_info->dir = readdir(dp);
                while (dir_info->dir!= NULL && dir_info->dir->d_name[0]!= '.') {
                    dir_info->dir = readdir(dp);
                }
                get_dir_info(dir_info);
                if (get_dir_list(dir_info->dir_name, dir_info, depth + 1)!= 0) {
                    return 1;
                }
            }
        }
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
    }
    dir_info dir_info;
    strcpy(dir_info.dir_name, argv[1]);
    if (get_dir_list(dir_info.dir_name, &dir_info, 0)!= 0) {
        return 1;
    }
    printf("Directory\tSize\tUsed\tAvailable\n");
    printf("------------------------------------\n");
    print_dir_info(&dir_info, 0);
    return 0;
}