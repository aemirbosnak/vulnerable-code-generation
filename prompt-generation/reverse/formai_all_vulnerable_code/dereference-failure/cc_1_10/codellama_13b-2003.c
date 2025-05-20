//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

typedef struct {
    char path[MAX_PATH_LENGTH];
    unsigned long size;
} directory_t;

void scan_directory(const char *path, directory_t *dir) {
    DIR *dp;
    struct dirent *ep;
    struct stat statbuf;

    if ((dp = opendir(path)) == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", path);
        exit(1);
    }

    while ((ep = readdir(dp)) != NULL) {
        if (ep->d_type == DT_REG) {
            char filepath[MAX_PATH_LENGTH];
            sprintf(filepath, "%s/%s", path, ep->d_name);
            stat(filepath, &statbuf);
            dir->size += statbuf.st_size;
        } else if (ep->d_type == DT_DIR) {
            char subdirpath[MAX_PATH_LENGTH];
            sprintf(subdirpath, "%s/%s", path, ep->d_name);
            scan_directory(subdirpath, dir);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    directory_t dir;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    dir.size = 0;
    scan_directory(argv[1], &dir);

    printf("Total size of directory: %ld\n", dir.size);

    return 0;
}