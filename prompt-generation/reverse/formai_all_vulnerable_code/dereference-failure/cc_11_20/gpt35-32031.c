//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void copy(char *src, char *dest);

int main(int argc, char *argv[]) {
    DIR *src_dir, *dest_dir;
    struct dirent *src_ent, *dest_ent;
    struct stat src_stat, dest_stat;
    char src_path[BUF_SIZE], dest_path[BUF_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    if ((src_dir = opendir(argv[1])) == NULL) {
        fprintf(stderr, "Error: %s could not be opened.\n", argv[1]);
        perror("");
        exit(1);
    }

    if ((dest_dir = opendir(argv[2])) == NULL) {
        fprintf(stderr, "Error: %s could not be opened.\n", argv[2]);
        perror("");
        exit(1);
    }

    while ((src_ent = readdir(src_dir)) != NULL) {
        if (strcmp(src_ent->d_name, ".") == 0 ||
            strcmp(src_ent->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, BUF_SIZE, "%s/%s", argv[1], src_ent->d_name);
        snprintf(dest_path, BUF_SIZE, "%s/%s", argv[2], src_ent->d_name);

        if (stat(src_path, &src_stat) == -1) {
            fprintf(stderr, "Error: stat() of %s failed.\n", src_ent->d_name);
            perror("");
            continue;
        }

        if (stat(dest_path, &dest_stat) == -1 && errno != ENOENT) {
            fprintf(stderr, "Error: stat() of %s failed.\n", dest_path);
            perror("");
            continue;
        }

        if (S_ISREG(src_stat.st_mode)) {
            if (errno == ENOENT || src_stat.st_mtime > dest_stat.st_mtime) {
                printf("Copying %s...\n", src_ent->d_name);
                if (S_ISREG(dest_stat.st_mode)) {
                    unlink(dest_path);
                }
                copy(src_path, dest_path);
            }
        } else if (S_ISDIR(src_stat.st_mode)) {
            if (errno == ENOENT) {
                printf("Creating directory %s...\n", src_ent->d_name);
                if (mkdir(dest_path, src_stat.st_mode) == -1) {
                    fprintf(stderr, "Error: mkdir() of %s failed.\n", dest_path);
                    perror("");
                }
            }
        } else {
            fprintf(stderr, "Error: %s is not a regular file or directory.\n", src_ent->d_name);
        }
    }
    closedir(src_dir);
    closedir(dest_dir);
    return 0;
}

void copy(char *src, char *dest) {
    char buf[BUF_SIZE];
    int fd_src, fd_dest, sz;

    if ((fd_src = open(src, O_RDONLY)) == -1) {
        fprintf(stderr, "Error: %s could not be opened.\n", src);
        perror("");
        return;
    }
    if ((fd_dest = open(dest, O_WRONLY | O_CREAT, 0666)) == -1) {
        fprintf(stderr, "Error: %s could not be opened.\n", dest);
        perror("");
        return;
    }

    while ((sz = read(fd_src, buf, BUF_SIZE)) > 0) {
        if (write(fd_dest, buf, sz) != sz) {
            fprintf(stderr, "Error: write() failed.\n");
            perror("");
            break;
        }
    }

    close(fd_src);
    close(fd_dest);
}