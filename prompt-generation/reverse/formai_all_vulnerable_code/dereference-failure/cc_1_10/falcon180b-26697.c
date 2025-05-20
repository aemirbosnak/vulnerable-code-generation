//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_DEPTH 1000
#define MAX_PATH 1024

// Function to calculate directory size
long long dir_size(char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        return -1;
    }
    return (long long)buf.f_blocks * buf.f_frsize;
}

// Function to print directory tree
void print_tree(char* path, int depth) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char subpath[MAX_PATH];
            snprintf(subpath, MAX_PATH, "%s/%s", path, ent->d_name);
            if (ent->d_type == DT_DIR) {
                if (depth < MAX_DEPTH) {
                    print_tree(subpath, depth + 1);
                }
            } else {
                long long size = dir_size(subpath);
                if (size!= -1) {
                    printf("%*s%10lld %s\n", depth * 2, "", size, ent->d_name);
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "%s", argv[1]);
    print_tree(path, 0);
    return 0;
}