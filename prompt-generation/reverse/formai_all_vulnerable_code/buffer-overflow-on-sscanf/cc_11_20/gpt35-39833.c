//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <math.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

void print_size(double size);

int main(int argc, char *argv[]) {
    int depth = 1;
    char *path = ".";
    if (argc == 2) {
        path = argv[1];
    } else if (argc == 3) {
        path = argv[2];
        sscanf(argv[1], "-%d", &depth);
    }

    DIR* dir = opendir(path);

    if (!dir) {
        printf("Error: Could not open directory '%s'\n", path);
        return 1;
    }

    struct dirent *entry;
    struct stat statbuf;
    char fullpath[1024];
    unsigned long long total_size = 0;

    while ((entry = readdir(dir)) != NULL) {
        snprintf(fullpath, sizeof fullpath, "%s/%s", path, entry->d_name);
        if (stat(fullpath, &statbuf) == -1) {
            continue;
        }

        if (entry->d_name[0] == '.' || !S_ISDIR(statbuf.st_mode)) {
            continue;
        }

        unsigned long long size = 0;

        if (depth > 1) {
            char subpath[1024];
            strcpy(subpath, fullpath);
            strcat(subpath, "/");
            DIR* subdir = opendir(subpath);
            if (!subdir) {
                printf("Error: Could not open directory '%s'\n", subpath);
                continue;
            }
            struct dirent *subentry;
            while ((subentry = readdir(subdir)) != NULL) {
                if (stat(subentry->d_name, &statbuf) == -1) {
                    continue;
                }
                if (subentry->d_name[0] == '.' || !S_ISDIR(statbuf.st_mode)) {
                    size += statbuf.st_size;
                } else {
                    char subsubpath[1024];
                    strcpy(subsubpath, subpath);
                    strcat(subsubpath, subentry->d_name);
                    unsigned long long sub_size = 0;
                    DIR* subsubdir = opendir(subsubpath);
                    if (subsubdir) {
                        struct dirent *subsubentry;
                        while ((subsubentry = readdir(subsubdir)) != NULL) {
                            if (stat(subsubentry->d_name, &statbuf) == -1) {
                                continue;
                            }
                            if (subsubentry->d_name[0] == '.') {
                                continue;
                            }
                            sub_size += statbuf.st_size;
                        }
                        closedir(subsubdir);
                    }
                    printf("%*s", depth * 4, "");
                    printf("'%s': ", subentry->d_name);
                    print_size(sub_size);
                    printf("\n");
                    size += sub_size;
                }
            }
            closedir(subdir);
            printf("%*s", (depth - 1) * 4, "");
        }

        printf("'%s': ", entry->d_name);
        print_size(size);
        printf("\n");

        total_size += size;
    }

    closedir(dir);

    printf("Total disk usage: ");
    print_size(total_size);
    printf("\n");

    return 0;
}

void print_size(double size) {
    if (size < KB) {
        printf("%llu B", (unsigned long long) size);
    } else if (size < MB) {
        printf("%.1f KB", round(size / KB * 10) / 10);
    } else if (size < GB) {
        printf("%.1f MB", round(size / MB * 10) / 10);
    } else {
        printf("%.1f GB", round(size / GB * 10) / 10);
    }
}