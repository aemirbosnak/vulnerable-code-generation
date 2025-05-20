//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s <source dir> <destination dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* src_dir = argv[1];
    char* dst_dir = argv[2];

    DIR* src_dp = opendir(src_dir);
    if(src_dp == NULL) {
        printf("Cannot open source directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    DIR* dst_dp = opendir(dst_dir);
    if(dst_dp == NULL) {
        printf("Creating destination directory: %s\n", dst_dir);
        if(mkdir(dst_dir, 0777) == -1) {
            printf("Cannot create destination directory: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        else {
            dst_dp = opendir(dst_dir);
        }
    }

    struct dirent * entry;
    while((entry = readdir(src_dp))) {
        if(entry->d_name[0] == '.') {
            continue;  // ignore hidden files
        }

        char src_path[BUF_SIZE];
        char dst_path[BUF_SIZE];
        sprintf(src_path, "%s/%s", src_dir, entry->d_name);
        sprintf(dst_path, "%s/%s", dst_dir, entry->d_name);

        struct stat src_stat;
        if(stat(src_path, &src_stat) == -1) {
            printf("Cannot get stat of file '%s': %s\n", src_path, strerror(errno));
            continue;
        }

        if(S_ISDIR(src_stat.st_mode)) {
            DIR* subdir_dp = opendir(src_path);
            if(subdir_dp == NULL) {
                printf("Cannot open subdirectory '%s': %s\n", src_path, strerror(errno));
                continue;
            }

            closedir(subdir_dp);
            mkdir(dst_path, 0777);
            printf("Created directory '%s'\n", dst_path);
        }
        else if(S_ISREG(src_stat.st_mode)) {
            int src_fd = open(src_path, O_RDONLY);
            if(src_fd == -1) {
                printf("Cannot open file '%s': %s\n", src_path, strerror(errno));
                continue;
            }

            int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
            if(dst_fd == -1) {
                printf("Cannot open file '%s': %s\n", dst_path, strerror(errno));
                close(src_fd);
                continue;
            }

            char buf[BUF_SIZE];
            ssize_t bytes_read;
            while((bytes_read = read(src_fd, buf, BUF_SIZE)) > 0) {
                if(write(dst_fd, buf, bytes_read) != bytes_read) {
                    printf("Cannot write to file '%s': %s\n", dst_path, strerror(errno));
                    break;
                }
            }

            close(src_fd);
            close(dst_fd);

            printf("Copied file '%s' to '%s'\n", src_path, dst_path);
        }
        else {
            printf("Unsupported file type for '%s'\n", src_path);
        }
    }

    closedir(src_dp);
    closedir(dst_dp);

    return EXIT_SUCCESS;
}