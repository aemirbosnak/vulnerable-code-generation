//Falcon-180B DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH 1024

void print_error(const char *func, int err) {
    fprintf(stderr, "Error in %s: %s\n", func, strerror(err));
    exit(1);
}

int main() {
    char path[MAX_PATH];
    char *dir;
    char *file;
    int res;

    printf("Enter directory path: ");
    scanf("%s", path);

    dir = strrchr(path, '/');
    if (dir == NULL) {
        print_error("main", ENOENT);
    }
    *dir = '\0';

    res = mkdir(path, 0700);
    if (res!= 0) {
        if (errno!= EEXIST) {
            print_error("main", errno);
        }
    }

    printf("Enter file name: ");
    scanf("%s", file);

    res = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (res == -1) {
        print_error("main", errno);
    }

    res = close(res);
    if (res == -1) {
        print_error("main", errno);
    }

    res = chmod(file, 0600);
    if (res == -1) {
        print_error("main", errno);
    }

    res = chown(file, getuid(), getgid());
    if (res == -1) {
        print_error("main", errno);
    }

    res = rename(file, path);
    if (res!= 0) {
        print_error("main", errno);
    }

    printf("File created successfully!\n");

    return 0;
}