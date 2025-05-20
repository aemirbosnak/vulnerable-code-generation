//GEMINI-pro DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    int fd, nbytes;
    char buf[BUF_SIZE];
    struct stat st;
    struct dirent *dent;
    DIR *dir;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dir = opendir(argv[1])) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((dent = readdir(dir)) != NULL) {
        if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
            continue;
        }

        if ((fd = openat(dirfd(dir), dent->d_name, O_RDONLY)) == -1) {
            perror("openat");
            continue;
        }

        while ((nbytes = read(fd, buf, BUF_SIZE)) > 0) {
            if (write(STDOUT_FILENO, buf, nbytes) == -1) {
                perror("write");
                break;
            }
        }

        if (nbytes == -1) {
            perror("read");
        }

        if (close(fd) == -1) {
            perror("close");
        }
    }

    if (closedir(dir) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}