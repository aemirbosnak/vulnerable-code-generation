//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(argv[1])) == NULL) {
        printf("Could not open directory %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    struct stat st;
    long long totalSize = 0;

    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        if (stat(path, &st) == -1) {
            printf("Stat error on %s\n", path);
            continue;
        }
        if (S_ISDIR(st.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            long long size = 0;
            DIR *subdir = opendir(path);
            if (subdir) {
                struct dirent *subentry;
                while ((subentry = readdir(subdir)) != NULL) {
                    char subpath[1024];
                    sprintf(subpath, "%s/%s", path, subentry->d_name);
                    if (stat(subpath, &st) == -1) {
                        printf("Stat error on %s\n", subpath);
                        continue;
                    }
                    if (!S_ISDIR(st.st_mode)) {
                        size += st.st_size;
                    }
                }
                closedir(subdir);
                printf("%s: %lld bytes\n", path, size);
                totalSize += size;
            } else {
                printf("Could not open subdirectory %s\n", path);
            }
        } else {
            totalSize += st.st_size;
        }
    }
    closedir(dir);

    printf("\nTotal Size: %lld bytes\n", totalSize);

    return 0;
}