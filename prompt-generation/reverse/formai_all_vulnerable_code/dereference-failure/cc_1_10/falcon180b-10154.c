//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    unsigned long long size;
    unsigned long long num_files;
    unsigned long long num_dirs;
} Directory;

void add_size(Directory *dir, const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            dir->num_dirs++;
            return;
        }
        dir->num_files++;
        dir->size += st.st_size;
    }
}

void analyze_directory(const char *path, Directory *dir) {
    DIR *dp;
    struct dirent *ep;
    if ((dp = opendir(path))!= NULL) {
        while ((ep = readdir(dp))!= NULL) {
            char full_path[MAX_PATH];
            sprintf(full_path, "%s/%s", path, ep->d_name);
            add_size(dir, full_path);
            if (ep->d_type == DT_DIR) {
                Directory sub_dir = {0};
                analyze_directory(full_path, &sub_dir);
                dir->size += sub_dir.size;
                dir->num_files += sub_dir.num_files;
                dir->num_dirs += sub_dir.num_dirs;
            }
        }
        closedir(dp);
    }
}

void print_directory(const Directory *dir) {
    printf("Directory: %s\n", dir->name);
    printf("Size: %llu bytes\n", dir->size);
    printf("Number of files: %llu\n", dir->num_files);
    printf("Number of directories: %llu\n", dir->num_dirs);
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    Directory dir = {0};
    strncpy(dir.name, argv[1], MAX_PATH - 1);
    analyze_directory(argv[1], &dir);
    print_directory(&dir);
    return 0;
}