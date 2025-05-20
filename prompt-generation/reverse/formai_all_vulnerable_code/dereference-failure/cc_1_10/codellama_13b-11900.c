//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char path[MAX_PATH_LEN];
    int dir;
    int file;
} FileInfo;

void traverse_directory(const char *path, FileInfo *file_info) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) {
            char subpath[MAX_PATH_LEN];
            snprintf(subpath, MAX_PATH_LEN, "%s/%s", path, entry->d_name);
            traverse_directory(subpath, file_info);
        } else if (entry->d_type == DT_REG) {
            int fd;
            if ((fd = open(path, O_RDONLY)) < 0) {
                perror("open");
                continue;
            }

            struct stat statbuf;
            if (fstat(fd, &statbuf) < 0) {
                perror("fstat");
                close(fd);
                continue;
            }

            file_info->path[file_info->file++] = path;
            file_info->dir++;

            close(fd);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    FileInfo file_info = {0};
    traverse_directory(argv[1], &file_info);

    printf("Total directories: %d\n", file_info.dir);
    printf("Total files: %d\n", file_info.file);

    return 0;
}