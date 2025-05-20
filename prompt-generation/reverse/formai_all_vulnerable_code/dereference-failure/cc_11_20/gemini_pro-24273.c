//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *source = argv[1];
    char *destination = argv[2];

    DIR *source_dir = opendir(source);
    if (source_dir == NULL) {
        perror("opendir failed");
        return EXIT_FAILURE;
    }

    struct dirent *dirent;
    while ((dirent = readdir(source_dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        char *source_path = malloc(strlen(source) + strlen(dirent->d_name) + 2);
        sprintf(source_path, "%s/%s", source, dirent->d_name);

        char *destination_path = malloc(strlen(destination) + strlen(dirent->d_name) + 2);
        sprintf(destination_path, "%s/%s", destination, dirent->d_name);

        struct stat st;
        if (stat(source_path, &st) == -1) {
            perror("stat failed");
            free(source_path);
            free(destination_path);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (mkdir(destination_path, st.st_mode) == -1) {
                perror("mkdir failed");
                free(source_path);
                free(destination_path);
                continue;
            }
        } else {
            int source_fd = open(source_path, O_RDONLY);
            if (source_fd == -1) {
                perror("open failed");
                free(source_path);
                free(destination_path);
                continue;
            }

            int destination_fd = open(destination_path, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode);
            if (destination_fd == -1) {
                perror("open failed");
                close(source_fd);
                free(source_path);
                free(destination_path);
                continue;
            }

            char buf[BUFSIZE];
            ssize_t n;
            while ((n = read(source_fd, buf, BUFSIZE)) > 0) {
                if (write(destination_fd, buf, n) != n) {
                    perror("write failed");
                    close(source_fd);
                    close(destination_fd);
                    free(source_path);
                    free(destination_path);
                    return EXIT_FAILURE;
                }
            }

            if (n == -1) {
                perror("read failed");
                close(source_fd);
                close(destination_fd);
                free(source_path);
                free(destination_path);
                return EXIT_FAILURE;
            }

            close(source_fd);
            close(destination_fd);
        }

        free(source_path);
        free(destination_path);
    }

    closedir(source_dir);

    return EXIT_SUCCESS;
}