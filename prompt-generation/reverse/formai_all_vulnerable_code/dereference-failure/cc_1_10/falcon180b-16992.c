//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct {
    char path[1024];
    unsigned long long size;
} File;

void add_file(File *files, int count, const char *path, unsigned long long size) {
    if (count >= BUFFER_SIZE) {
        printf("Buffer overflow\n");
        return;
    }
    strcpy(files[count].path, path);
    files[count].size = size;
    count++;
}

void print_files(File *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%llu bytes)\n", files[i].path, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;
    File files[BUFFER_SIZE];
    int count = 0;

    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char path[1024];
            sprintf(path, "%s/%s", argv[1], ent->d_name);
            struct statvfs fs;
            if (statvfs(path, &fs) == 0) {
                add_file(files, count, path, fs.f_blocks * fs.f_frsize);
            }
        }
    }

    closedir(dir);
    print_files(files, count);

    return 0;
}