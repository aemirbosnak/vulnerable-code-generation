//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_DEPTH 100
#define MAX_FILE_SIZE 1024
#define MAX_DIR_SIZE 1024

typedef struct {
    char path[MAX_DIR_DEPTH];
    long size;
} dir_t;

void add_dir(dir_t *dir, const char *path) {
    strcat(dir->path, path);
    strcat(dir->path, "/");
}

void analyze_dir(const char *path, dir_t *dir) {
    DIR *d;
    struct dirent *dent;
    d = opendir(path);
    if (d) {
        while ((dent = readdir(d))!= NULL) {
            if (dent->d_type == DT_DIR) {
                char *full_path = malloc(strlen(path) + strlen(dent->d_name) + 2);
                strcpy(full_path, path);
                strcat(full_path, "/");
                strcat(full_path, dent->d_name);
                dir_t child_dir;
                memset(&child_dir, 0, sizeof(child_dir));
                add_dir(&child_dir, full_path);
                analyze_dir(full_path, &child_dir);
                free(full_path);
            } else if (dent->d_type == DT_REG) {
                struct stat st;
                char *full_path = malloc(strlen(path) + strlen(dent->d_name) + 2);
                strcpy(full_path, path);
                strcat(full_path, "/");
                strcat(full_path, dent->d_name);
                stat(full_path, &st);
                dir->size += st.st_size;
                free(full_path);
            }
        }
        closedir(d);
    }
}

void print_dir(const dir_t *dir) {
    printf("Path: %s\n", dir->path);
    printf("Size: %ld bytes\n", dir->size);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    dir_t dir;
    memset(&dir, 0, sizeof(dir));
    strcpy(dir.path, argv[1]);
    analyze_dir(argv[1], &dir);
    print_dir(&dir);
    return 0;
}