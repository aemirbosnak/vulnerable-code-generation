//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH_LEN 512
#define MAX_DIRS 1024

typedef struct {
    char name[MAX_PATH_LEN];
    long size;
} FileInfo;

typedef struct {
    int num_files;
    FileInfo files[MAX_DIRS];
} DirInfo;

long calculate_size(const char *path) {
    long size = 0;
    char cmd[MAX_PATH_LEN];
    snprintf(cmd, MAX_PATH_LEN, "du -bs %s", path);
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen");
        exit(1);
    }
    fscanf(fp, "%ld", &size);
    pclose(fp);
    return size;
}

void list_files(const char *dir_path, DirInfo *dir) {
    char cmd[MAX_PATH_LEN];
    snprintf(cmd, MAX_PATH_LEN, "find %s -type f", dir_path);
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen");
        exit(1);
    }
    while (fgets(cmd, MAX_PATH_LEN, fp) != NULL) {
        if (*cmd == '\0' || *cmd == '\n') {
            continue;
        }
        cmd[strlen(cmd) - 1] = '\0';
        FileInfo *file = &dir->files[dir->num_files++];
        strncpy(file->name, cmd, MAX_PATH_LEN);
        file->size = calculate_size(cmd);
    }
    pclose(fp);
}

int cmp_files(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *) a;
    const FileInfo *fb = (const FileInfo *) b;
    return (fb->size - fa->size);
}

void print_files(DirInfo *dir, long total_size) {
    for (int i = 0; i < dir->num_files; i++) {
        FileInfo *file = &dir->files[i];
        printf("%10ld %6.2f%% %s\n", file->size, (float) file->size / total_size * 100, file->name);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <dir_path>\n", argv[0]);
        exit(1);
    }
    char *dir_path = argv[1];
    long total_size = calculate_size(dir_path);
    DirInfo dir = {0};
    list_files(dir_path, &dir);
    qsort(dir.files, dir.num_files, sizeof(FileInfo), cmp_files);
    print_files(&dir, total_size);
    return 0;
}