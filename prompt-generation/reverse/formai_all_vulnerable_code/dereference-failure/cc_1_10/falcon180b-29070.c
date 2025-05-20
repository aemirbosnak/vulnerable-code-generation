//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_DEPTH 1000
#define MAX_FILE_NAME_LEN 1024
#define MAX_PATH_LEN 4096

typedef struct {
    char path[MAX_PATH_LEN];
    size_t size;
} FileInfo;

void print_file_info(FileInfo *file_info) {
    printf("%s (%zu bytes)\n", file_info->path, file_info->size);
}

void print_dir_info(char *dir_path, size_t dir_size) {
    printf("Directory: %s (%zu bytes)\n", dir_path, dir_size);
}

size_t get_dir_size(char *path) {
    size_t size = 0;
    DIR *dir = opendir(path);
    if (dir!= NULL) {
        struct dirent *ent;
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
                char file_path[MAX_PATH_LEN];
                snprintf(file_path, MAX_PATH_LEN, "%s/%s", path, ent->d_name);
                struct stat stat_buf;
                if (stat(file_path, &stat_buf) == 0) {
                    size += stat_buf.st_size;
                }
            } else if (ent->d_type == DT_DIR) {
                char sub_dir_path[MAX_PATH_LEN];
                snprintf(sub_dir_path, MAX_PATH_LEN, "%s/%s", path, ent->d_name);
                size += get_dir_size(sub_dir_path);
            }
        }
        closedir(dir);
    }
    return size;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char dir_path[MAX_PATH_LEN];
    snprintf(dir_path, MAX_PATH_LEN, "%s", argv[1]);

    size_t dir_size = get_dir_size(dir_path);

    printf("Directory size: %zu bytes\n", dir_size);

    return 0;
}