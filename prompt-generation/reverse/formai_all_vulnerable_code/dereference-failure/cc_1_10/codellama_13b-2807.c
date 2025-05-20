//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define PATH_MAX 4096

struct dirent_stat {
    struct dirent d;
    struct stat st;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    char path[PATH_MAX];
    strcpy(path, argv[1]);
    strcat(path, "/");

    struct dirent_stat *dir;
    DIR *dp;
    struct stat st;
    size_t total_size = 0;

    if ((dp = opendir(path)) == NULL) {
        perror("opendir");
        return 1;
    }

    while ((dir = readdir(dp)) != NULL) {
        if (dir->d.d_type == DT_DIR) {
            continue;
        }

        char filepath[PATH_MAX];
        strcpy(filepath, path);
        strcat(filepath, dir->d.d_name);

        if (lstat(filepath, &st) != 0) {
            perror("lstat");
            continue;
        }

        total_size += st.st_size;
    }

    printf("Total size: %zu\n", total_size);

    closedir(dp);
    return 0;
}