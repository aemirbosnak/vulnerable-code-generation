//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

struct dirent *readdir(DIR *dir) {
    struct dirent *d;
    if ((d = readdir(dir))!= NULL)
        return d;
    else {
        perror("readdir");
        exit(EXIT_FAILURE);
    }
}

void print_space(char *path, struct statvfs buf) {
    printf("%s:\n", path);
    printf("  Total space: %ld bytes\n", buf.f_blocks * buf.f_frsize);
    printf("  Free space: %ld bytes\n", buf.f_bfree * buf.f_frsize);
    printf("  Available space: %ld bytes\n", buf.f_bavail * buf.f_frsize);
    printf("\n");
}

int main(int argc, char *argv[]) {
    char path[BUF_SIZE];
    struct statvfs buf;
    DIR *dir;
    struct dirent *d;

    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(path, argv[1]);
    strcat(path, "/");

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((d = readdir(dir))!= NULL) {
        if (d->d_type == DT_DIR) {
            strcat(path, d->d_name);
            strcat(path, "/");
            if (statvfs(path, &buf) == -1) {
                perror("statvfs");
                exit(EXIT_FAILURE);
            }
            print_space(d->d_name, buf);
        }
    }

    closedir(dir);
    return 0;
}