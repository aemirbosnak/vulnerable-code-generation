//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_DIR_DEPTH 1000
#define MAX_FILE_NAME_LEN 1024
#define MAX_PATH_LEN 4096

struct dir_stack {
    char path[MAX_PATH_LEN];
    DIR *dir;
    struct dirent dirent;
    int is_file;
    struct dir_stack *next;
};

struct dir_stack *dir_stack = NULL;

void push_dir(const char *path) {
    struct dir_stack *stack = (struct dir_stack *)malloc(sizeof(struct dir_stack));
    strcpy(stack->path, path);
    stack->dir = opendir(path);
    stack->is_file = 0;
    stack->next = dir_stack;
    dir_stack = stack;
}

void pop_dir() {
    if (dir_stack == NULL) {
        return;
    }
    struct dir_stack *stack = dir_stack;
    dir_stack = dir_stack->next;
    closedir(stack->dir);
    free(stack);
}

void analyze_file(const char *file_path) {
    struct statvfs fs_info;
    if (statvfs(file_path, &fs_info) == -1) {
        perror("statvfs");
        return;
    }
    printf("File: %s\n", file_path);
    printf("Total space: %ld bytes\n", fs_info.f_blocks * fs_info.f_frsize);
    printf("Used space: %ld bytes\n", (fs_info.f_blocks - fs_info.f_bfree) * fs_info.f_frsize);
    printf("Free space: %ld bytes\n", fs_info.f_bfree * fs_info.f_frsize);
    printf("\n");
}

void analyze_dir(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent dirent;
    while ((readdir(dir)!= NULL) && (getcwd(NULL, MAX_PATH_LEN)!= NULL)) {
        if (dirent.d_type == DT_DIR) {
            push_dir(dirent.d_name);
        } else {
            analyze_file(dirent.d_name);
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }
    char cwd[MAX_PATH_LEN];
    if (getcwd(cwd, MAX_PATH_LEN) == NULL) {
        perror("getcwd");
        return 1;
    }
    char *dir_path = argv[1];
    if (dir_path[0]!= '/') {
        strcat(cwd, "/");
        strcat(cwd, dir_path);
        dir_path = cwd;
    }
    analyze_dir(dir_path);
    while (dir_stack!= NULL) {
        pop_dir();
    }
    return 0;
}