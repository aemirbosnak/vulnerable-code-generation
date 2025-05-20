//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_DIR_DEPTH 100

typedef struct {
    char path[MAX_DIR_DEPTH];
    unsigned long long size;
} directory_t;

void print_directory(directory_t *dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s (%llu bytes)\n", dir->path, dir->size);
}

void traverse_directory(const char *path, int depth) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            char full_path[MAX_DIR_DEPTH];
            sprintf(full_path, "%s/%s", path, ent->d_name);
            struct stat st;
            if (stat(full_path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    directory_t dir_info;
                    strcpy(dir_info.path, full_path);
                    dir_info.size = 0;
                    traverse_directory(full_path, depth + 1);
                    print_directory(&dir_info, depth);
                } else {
                    printf("  %s (%llu bytes)\n", full_path, st.st_size);
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char path[MAX_DIR_DEPTH];
    strcpy(path, argv[1]);
    traverse_directory(path, 0);
    return 0;
}