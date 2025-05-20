//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    unsigned long long size;
} File;

void readDirectory(const char *path, void (*callback)(const char *, unsigned long long)) {
    DIR *d;
    struct dirent *dir;

    if ((d = opendir(path))!= NULL) {
        while ((dir = readdir(d))!= NULL) {
            if (strcmp(dir->d_name, ".")!= 0 && strcmp(dir->d_name, "..")!= 0) {
                callback(dir->d_name, dir->d_off);
            }
        }
        closedir(d);
    }
}

unsigned long long getTotalSize(const char *path) {
    unsigned long long totalSize = 0;
    struct statvfs buf;

    if (statvfs(path, &buf) == 0) {
        totalSize = buf.f_blocks * buf.f_frsize;
    }

    return totalSize;
}

unsigned long long getFreeSize(const char *path) {
    unsigned long long freeSize = 0;
    struct statvfs buf;

    if (statvfs(path, &buf) == 0) {
        freeSize = buf.f_bavail * buf.f_frsize;
    }

    return freeSize;
}

void printFile(const char *name, unsigned long long size) {
    printf("%-40s %10llu\n", name, size);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    unsigned long long totalSize, freeSize;
    totalSize = getTotalSize(argv[1]);
    freeSize = getFreeSize(argv[1]);

    printf("Disk Space Analyzer\n\n");
    printf("Directory: %s\n", argv[1]);
    printf("Total Size: %llu bytes\n", totalSize);
    printf("Free Space: %llu bytes\n\n", freeSize);

    readDirectory(argv[1], printFile);

    return 0;
}