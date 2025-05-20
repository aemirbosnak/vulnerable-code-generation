//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define BLOCK_SIZE 512
#define MAX_FILE_NAME_LENGTH 256

struct file_info {
    char name[MAX_FILE_NAME_LENGTH];
    int inode;
    int size;
    int blocks;
};

void print_usage(char *program) {
    printf("Usage: %s <device>\n", program);
}

int is_directory(char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

int is_file(char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        return 0;
    }
    return S_ISREG(statbuf.st_mode);
}

int get_inode(char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        return 0;
    }
    return statbuf.st_ino;
}

int get_size(char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        return 0;
    }
    return statbuf.st_size;
}

int get_blocks(char *path, int block_size) {
    int size = get_size(path);
    return (size + block_size - 1) / block_size;
}

void list_files(char *path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    if (dir == NULL) {
        printf("Cannot open directory: %s\n", path);
        return;
    }
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR || ent->d_type == DT_UNKNOWN) {
            printf("%s/\n", ent->d_name);
        } else if (ent->d_type == DT_REG) {
            struct file_info info;
            info.inode = get_inode(ent->d_name);
            info.size = get_size(ent->d_name);
            info.blocks = get_blocks(ent->d_name, BLOCK_SIZE);
            strncpy(info.name, ent->d_name, MAX_FILE_NAME_LENGTH);
            printf("%s %10d %10d %10d\n", info.name, info.inode, info.size, info.blocks);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }
    char *device = argv[1];
    int fd = open(device, O_RDONLY);
    if (fd == -1) {
        printf("Cannot open device: %s\n", device);
        return 1;
    }
    printf("Scanning device: %s\n", device);
    list_files(device);
    close(fd);
    return 0;
}