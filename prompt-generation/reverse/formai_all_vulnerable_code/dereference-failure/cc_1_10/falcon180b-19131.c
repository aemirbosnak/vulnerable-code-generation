//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_DIR_LENGTH 1024

typedef struct {
    char path[MAX_DIR_LENGTH];
    struct statvfs stat;
} dir_stat_t;

void print_dir_stat(dir_stat_t* stat) {
    printf("Path: %s\n", stat->path);
    printf("Total space: %ld bytes\n", stat->stat.f_blocks * stat->stat.f_frsize);
    printf("Used space: %ld bytes\n", (stat->stat.f_blocks - stat->stat.f_bfree) * stat->stat.f_frsize);
    printf("Free space: %ld bytes\n", stat->stat.f_bfree * stat->stat.f_frsize);
}

void get_dir_stat(const char* path, dir_stat_t* stat) {
    memset(stat, 0, sizeof(dir_stat_t));
    strncpy(stat->path, path, MAX_DIR_LENGTH);

    if (statvfs(path, &stat->stat)!= 0) {
        perror("statvfs");
        exit(1);
    }
}

void analyze_dir(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    dir_stat_t root_stat;
    get_dir_stat(path, &root_stat);
    print_dir_stat(&root_stat);

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char subdir_path[MAX_DIR_LENGTH];
            snprintf(subdir_path, MAX_DIR_LENGTH, "%s/%s", path, entry->d_name);

            dir_stat_t subdir_stat;
            get_dir_stat(subdir_path, &subdir_stat);
            print_dir_stat(&subdir_stat);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    analyze_dir(argv[1]);

    return 0;
}