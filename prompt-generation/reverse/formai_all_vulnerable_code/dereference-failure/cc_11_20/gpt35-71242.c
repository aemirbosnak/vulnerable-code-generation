//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH 1024

int main(int argc, char *argv[])
{
    char path[MAX_PATH];
    struct stat buf;

    if (argc == 1) {
        fprintf(stderr, "Usage: %s path\n", argv[0]);
        return 1;
    }

    strncpy(path, argv[1], MAX_PATH);

    if (stat(path, &buf) < 0) {
        fprintf(stderr, "Could not stat %s: %s\n", path, strerror(errno));
        return 1;
    }

    if (!S_ISDIR(buf.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", path);
        return 1;
    }

    /* We have a valid directory path, now let's start calculating the directory size */
    long long total_size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Could not open directory %s: %s\n", path, strerror(errno));
        return 1;
    }

    struct dirent *entry = readdir(dir);
    while (entry != NULL) {
        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);

        if (lstat(full_path, &buf) < 0) {
            fprintf(stderr, "Could not stat %s: %s\n", full_path, strerror(errno));
        } else {
            /* Get size of file or directory */
            long long size = 0;
            if (S_ISREG(buf.st_mode)) {
                size = buf.st_size;
            } else if (S_ISDIR(buf.st_mode)) {
                DIR *subdir = opendir(full_path);
                if (subdir == NULL) {
                    fprintf(stderr, "Could not open directory %s: %s\n", full_path, strerror(errno));
                } else {
                    struct dirent *subentry = readdir(subdir);
                    while (subentry != NULL) {
                        if (strcmp(subentry->d_name, ".") != 0 && strcmp(subentry->d_name, "..") != 0) {
                            char sub_full_path[MAX_PATH];
                            snprintf(sub_full_path, MAX_PATH, "%s/%s", full_path, subentry->d_name);
                            if (lstat(sub_full_path, &buf) < 0) {
                                fprintf(stderr, "Could not stat %s: %s\n", sub_full_path, strerror(errno));
                            } else if (S_ISREG(buf.st_mode)) {
                                size += buf.st_size;
                            }
                        }
                        subentry = readdir(subdir);
                    }
                    closedir(subdir);
                }
            }
            total_size += size;
        }

        entry = readdir(dir);
    }
    closedir(dir);

    /* Print the total size in human-readable format */
    printf("Total size of directory %s: ", path);
    if (total_size < 1024) {
        printf("%lld bytes\n", total_size);
    } else if (total_size < 1024 * 1024) {
        printf("%lld KB\n", total_size / 1024);
    } else if (total_size < 1024 * 1024 * 1024) {
        printf("%lld MB\n", total_size / (1024 * 1024));
    } else {
        printf("%lld GB\n", total_size / (1024 * 1024 * 1024));
    }

    return 0;
}