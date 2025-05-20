//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX_DIR_LEN 1024
#define MAX_FILE_LEN 1024

typedef struct {
    char dir_name[MAX_DIR_LEN];
    long long total_size;
    int num_files;
    int num_dirs;
} dir_info;

void get_dir_info(const char* path, dir_info* info) {
    DIR* dir = opendir(path);
    struct dirent* ent;
    info->num_files = 0;
    info->num_dirs = 0;
    info->total_size = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            info->num_dirs++;
        } else {
            info->num_files++;
            struct stat st;
            stat(ent->d_name, &st);
            info->total_size += st.st_size;
        }
    }
    closedir(dir);
}

void print_dir_info(const char* path, int depth) {
    char full_path[MAX_DIR_LEN];
    sprintf(full_path, "%*s%s", depth*4, "", path);
    dir_info info;
    get_dir_info(full_path, &info);
    printf("%s:\n", full_path);
    printf("  Total size: %lld bytes\n", info.total_size);
    printf("  Number of files: %d\n", info.num_files);
    printf("  Number of directories: %d\n\n", info.num_dirs);
}

void traverse_dir(const char* path, int depth) {
    DIR* dir = opendir(path);
    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char new_path[MAX_DIR_LEN];
            sprintf(new_path, "%s/%s", path, ent->d_name);
            traverse_dir(new_path, depth+1);
        } else {
            print_dir_info(path, depth);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    traverse_dir(argv[1], 0);
    return 0;
}