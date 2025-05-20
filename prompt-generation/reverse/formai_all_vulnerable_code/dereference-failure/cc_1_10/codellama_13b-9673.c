//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
/*
 * File Backup System
 *
 * A program to backup files in a Sherlock Holmes style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LEN 1024

typedef struct {
    char *path;
    char *name;
    int size;
} file_t;

int backup_file(const char *path, const char *backup_path) {
    int fd_src, fd_dst;
    char buf[4096];
    ssize_t nread;
    struct stat st;

    if (stat(path, &st) != 0) {
        return -1;
    }

    if ((fd_src = open(path, O_RDONLY)) == -1) {
        return -1;
    }

    if ((fd_dst = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode)) == -1) {
        close(fd_src);
        return -1;
    }

    while ((nread = read(fd_src, buf, sizeof(buf))) > 0) {
        if (write(fd_dst, buf, nread) != nread) {
            close(fd_src);
            close(fd_dst);
            return -1;
        }
    }

    close(fd_src);
    close(fd_dst);

    return 0;
}

int main(int argc, char *argv[]) {
    int i;
    char *backup_path;
    file_t files[1024];
    int num_files = 0;

    // Parse command-line arguments
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0) {
            backup_path = argv[i + 1];
        } else {
            files[num_files].path = argv[i];
            num_files++;
        }
    }

    // Backup files
    for (i = 0; i < num_files; i++) {
        backup_file(files[i].path, backup_path);
    }

    return 0;
}