//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src dir> <dst dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *src_dir = argv[1];
    char *dst_dir = argv[2];

    // Create the destination directory if it doesn't exist.
    if (mkdir(dst_dir, 0755) == -1 && errno != EEXIST) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }

    // Open the source directory.
    DIR *src_dirp = opendir(src_dir);
    if (src_dirp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Process each file in the source directory.
    struct dirent *src_dirent;
    while ((src_dirent = readdir(src_dirp)) != NULL) {
        // Skip hidden files.
        if (src_dirent->d_name[0] == '.') {
            continue;
        }

        // Get the source file path.
        char *src_file_path = malloc(strlen(src_dir) + strlen(src_dirent->d_name) + 2);
        if (src_file_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(src_file_path, "%s/%s", src_dir, src_dirent->d_name);

        // Get the destination file path.
        char *dst_file_path = malloc(strlen(dst_dir) + strlen(src_dirent->d_name) + 2);
        if (dst_file_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(dst_file_path, "%s/%s", dst_dir, src_dirent->d_name);

        // Open the source file.
        int src_fd = open(src_file_path, O_RDONLY);
        if (src_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Create the destination file.
        int dst_fd = open(dst_file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (dst_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Copy the file data.
        char buf[BUF_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(src_fd, buf, BUF_SIZE)) > 0) {
            if (write(dst_fd, buf, bytes_read) != bytes_read) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Close the files.
        if (close(src_fd) == -1) {
            perror("close");
            exit(EXIT_FAILURE);
        }

        if (close(dst_fd) == -1) {
            perror("close");
            exit(EXIT_FAILURE);
        }

        // Free the memory.
        free(src_file_path);
        free(dst_file_path);
    }

    // Close the source directory.
    if (closedir(src_dirp) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}