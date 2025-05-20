//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[BUFFER_SIZE];
    unsigned long long size;
} File;

void addFile(File *files, int count, const char *path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                File file;
                strncpy(file.name, ent->d_name, BUFFER_SIZE - 1);
                file.name[BUFFER_SIZE - 1] = '\0';
                file.size = ent->d_reclen;

                files[count] = file;
                count++;
            }
        }
        closedir(dir);
    }
}

void printFiles(File *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %llu bytes\n", files[i].name, files[i].size);
    }
}

void getDirectorySize(const char *path, unsigned long long *size) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        *size = buf.f_blocks * buf.f_frsize;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[BUFFER_SIZE];
    strncpy(path, argv[1], BUFFER_SIZE - 1);
    path[BUFFER_SIZE - 1] = '\0';

    File files[1000];
    int count = 0;

    addFile(files, count, path);

    unsigned long long dirSize = 0;
    getDirectorySize(path, &dirSize);

    printf("Directory size: %llu bytes\n", dirSize);
    printf("Files:\n");
    printFiles(files, count);

    return 0;
}