//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>
#include <pwd.h>

#define MAX_PATH 4096

typedef struct {
    char path[MAX_PATH];
    unsigned long size;
    unsigned long used;
    unsigned long free;
} dir_info;

void get_user(char* path, char* user) {
    struct passwd* pw = getpwuid(geteuid());
    strcpy(user, pw->pw_name);
}

void get_dir_info(char* path, dir_info* info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        exit(1);
    }

    info->size = (unsigned long)buf.f_blocks * buf.f_frsize;
    info->used = (unsigned long)buf.f_blocks - buf.f_bfree;
    info->free = buf.f_bfree * buf.f_frsize;

    strcpy(info->path, path);
}

void print_dir_info(dir_info* info) {
    printf("Path: %s\n", info->path);
    printf("Size: %lu bytes\n", info->size);
    printf("Used: %lu bytes\n", info->used);
    printf("Free: %lu bytes\n", info->free);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(1);
    }

    dir_info info;
    get_dir_info(argv[1], &info);
    print_dir_info(&info);

    return 0;
}