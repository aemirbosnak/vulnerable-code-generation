//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_DIR_DEPTH 10000

typedef struct {
    char path[MAX_DIR_DEPTH];
    int depth;
    unsigned long long size;
} dir_t;

void add_dir(dir_t* dir, const char* path, int depth) {
    strcpy(dir->path, path);
    dir->depth = depth;
    struct statvfs svfs;
    if (statvfs(path, &svfs) == 0) {
        dir->size = svfs.f_blocks * svfs.f_frsize;
    }
}

void print_dir(dir_t* dir) {
    for (int i = 0; i < dir->depth; i++) {
        printf(" ");
    }
    printf("%s (%llu bytes)\n", dir->path, dir->size);
}

void print_dirs(dir_t* dirs, int count) {
    for (int i = 0; i < count; i++) {
        print_dir(&dirs[i]);
    }
}

int main() {
    dir_t dirs[MAX_DIR_DEPTH];
    int count = 0;
    DIR* dp;
    struct dirent* ep;
    if ((dp = opendir("."))!= NULL) {
        while ((ep = readdir(dp))!= NULL) {
            if (ep->d_type == DT_DIR) {
                if (count >= MAX_DIR_DEPTH) {
                    printf("Error: Maximum directory depth exceeded.\n");
                    exit(1);
                }
                char path[MAX_DIR_DEPTH];
                sprintf(path, "%s/%s", ".", ep->d_name);
                add_dir(&dirs[count], path, 0);
                count++;
            }
        }
        closedir(dp);
    }
    print_dirs(dirs, count);
    return 0;
}