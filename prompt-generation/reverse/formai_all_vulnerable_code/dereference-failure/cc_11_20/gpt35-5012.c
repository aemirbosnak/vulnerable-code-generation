//FormAI DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* This program synchronizes two directories by copying files from one directory to the other if they are not present or have been modified */

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return -1;
    }

    char *src_dir = argv[1];
    char *dst_dir = argv[2];

    DIR *dirp;
    struct dirent *dp;
    struct stat src_stat, dst_stat;

    dirp = opendir(src_dir);
    if (dirp == NULL) {
        printf("Error opening directory: %s (%s)\n", src_dir, strerror(errno));
        return -1;
    }

    while ((dp = readdir(dirp)) != NULL) {
        char src_path[256];
        char dst_path[256];

        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, dp->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, dp->d_name);

        if (stat(src_path, &src_stat) == -1) {
            printf("Error getting stat for file: %s (%s)\n", src_path, strerror(errno));
            break;
        }

        if (stat(dst_path, &dst_stat) == -1 && errno != ENOENT) {
            printf("Error getting stat for file: %s (%s)\n", dst_path, strerror(errno));
            break;
        }

        bool copy_required = false;

        if (errno == ENOENT) {
            copy_required = true;
        } else if (src_stat.st_mtime > dst_stat.st_mtime) {
            copy_required = true;
        }

        if (copy_required) {
            int src_fd = open(src_path, O_RDONLY);
            if (src_fd == -1) {
                printf("Error opening file for reading: %s (%s)\n", src_path, strerror(errno));
                break;
            }

            int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);
            if (dst_fd == -1) {
                printf("Error opening file for writing: %s (%s)\n", dst_path, strerror(errno));
                break;
            }

            char buffer[4096];
            ssize_t read_bytes, written_bytes;

            while ((read_bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
                written_bytes = write(dst_fd, buffer, read_bytes);
                if (written_bytes == -1) {
                    printf("Error writing to file: %s (%s)\n", dst_path, strerror(errno));
                    break;
                }

                if (written_bytes != read_bytes) {
                    printf("Short write to file: %s (%s)\n", dst_path, strerror(errno));
                    break;
                }
            }

            if (read_bytes == -1) {
                printf("Error reading from file: %s (%s)\n", src_path, strerror(errno));
                break;
            }

            if (close(src_fd) == -1) {
                printf("Error closing file: %s (%s)\n", src_path, strerror(errno));
                break;
            }

            if (close(dst_fd) == -1) {
                printf("Error closing file: %s (%s)\n", dst_path, strerror(errno));
                break;
            }
        }
    }

    closedir(dirp);

    return 0;
}