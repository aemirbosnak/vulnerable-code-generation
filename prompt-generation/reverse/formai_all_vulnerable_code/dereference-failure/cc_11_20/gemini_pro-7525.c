//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

#define BUFSIZE 4096

char *progname;

void usage(void) {
    fprintf(stderr, "Usage: %s <srcdir> <dstdir>\n", progname);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int srcfd, dstfd;
    struct stat srcstat, dststat;
    char buf[BUFSIZE];
    ssize_t nbytes;

    if (argc != 3) {
        usage();
    }

    progname = argv[0];

    if (stat(argv[1], &srcstat) == -1) {
        perror("stat srcdir");
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(srcstat.st_mode)) {
        fprintf(stderr, "%s: not a directory\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[2], &dststat) == -1 && errno != ENOENT) {
        perror("stat dstdir");
        exit(EXIT_FAILURE);
    }

    if (errno == ENOENT) {
        if (mkdir(argv[2], 0755) == -1) {
            perror("mkdir dstdir");
            exit(EXIT_FAILURE);
        }
    } else if (!S_ISDIR(dststat.st_mode)) {
        fprintf(stderr, "%s: not a directory\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if (chdir(argv[1]) == -1) {
        perror("chdir srcdir");
        exit(EXIT_FAILURE);
    }

    DIR *dirp = opendir(".");
    if (dirp == NULL) {
        perror("opendir srcdir");
        exit(EXIT_FAILURE);
    }

    while ((errno = 0, nbytes = readdir_r(dirp, buf, BUFSIZE)) > 0) {
        if (strcmp(buf, ".") == 0 || strcmp(buf, "..") == 0) {
            continue;
        }

        if (stat(buf, &srcstat) == -1) {
            perror("stat srcfile");
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(srcstat.st_mode)) {
            char dstpath[PATH_MAX];
            snprintf(dstpath, sizeof(dstpath), "%s/%s", argv[2], buf);
            if (mkdir(dstpath, 0755) == -1) {
                perror("mkdir dstdir");
                exit(EXIT_FAILURE);
            }
            if (chdir(buf) == -1) {
                perror("chdir srcdir");
                exit(EXIT_FAILURE);
            }
            main(argc, argv);
            if (chdir("..") == -1) {
                perror("chdir srcdir");
                exit(EXIT_FAILURE);
            }
            continue;
        }

        snprintf(buf, BUFSIZE, "%s/%s", argv[2], buf);
        if ((dstfd = open(buf, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
            perror("open dstfile");
            exit(EXIT_FAILURE);
        }

        if ((srcfd = open(buf, O_RDONLY)) == -1) {
            perror("open srcfile");
            exit(EXIT_FAILURE);
        }

        while ((errno = 0, nbytes = read(srcfd, buf, BUFSIZE)) > 0) {
            if (write(dstfd, buf, nbytes) != nbytes) {
                perror("write dstfile");
                exit(EXIT_FAILURE);
            }
        }

        if (nbytes == -1) {
            perror("read srcfile");
            exit(EXIT_FAILURE);
        }

        if (close(srcfd) == -1) {
            perror("close srcfile");
            exit(EXIT_FAILURE);
        }

        if (close(dstfd) == -1) {
            perror("close dstfile");
            exit(EXIT_FAILURE);
        }
    }

    if (errno != 0) {
        perror("readdir srcdir");
        exit(EXIT_FAILURE);
    }

    if (closedir(dirp) == -1) {
        perror("closedir srcdir");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}