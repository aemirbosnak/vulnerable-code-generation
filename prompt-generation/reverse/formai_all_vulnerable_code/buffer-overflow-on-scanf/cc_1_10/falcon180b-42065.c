//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MAX_FILE_NAME_LEN 1024
#define TOTAL_SPACE 100

struct directory {
    char name[MAX_FILE_NAME_LEN];
    long long total_space;
    long long used_space;
    long long free_space;
};

void get_directory_space(char* path, struct directory* dir) {
    DIR* d;
    d = opendir(path);

    if (d) {
        struct dirent* dir_entry;
        while ((dir_entry = readdir(d))!= NULL) {
            if (dir_entry->d_type == DT_DIR) {
                char sub_dir_path[MAX_FILE_NAME_LEN];
                strcat(sub_dir_path, path);
                strcat(sub_dir_path, "/");
                strcat(sub_dir_path, dir_entry->d_name);

                struct directory sub_dir;
                get_directory_space(sub_dir_path, &sub_dir);

                dir->total_space += sub_dir.total_space;
                dir->used_space += sub_dir.used_space;
                dir->free_space += sub_dir.free_space;
            }
        }

        closedir(d);
    }
}

void print_directory_space(struct directory* dir) {
    printf("Directory: %s\n", dir->name);
    printf("Total space: %lld bytes\n", dir->total_space);
    printf("Used space: %lld bytes\n", dir->used_space);
    printf("Free space: %lld bytes\n", dir->free_space);
    printf("\n");
}

void main() {
    char path[MAX_FILE_NAME_LEN];
    printf("Enter directory path: ");
    scanf("%s", path);

    struct directory dir;
    get_directory_space(path, &dir);

    printf("Directory tree:\n");
    print_directory_space(&dir);
}