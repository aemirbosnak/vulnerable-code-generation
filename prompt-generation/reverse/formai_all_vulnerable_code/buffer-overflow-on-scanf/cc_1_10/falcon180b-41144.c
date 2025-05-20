//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/vfs.h>

#define MAX_PATH 1024
#define MAX_FILES 1024

typedef struct {
    char path[MAX_PATH];
    off_t size;
} FileInfo;

void add_file(char *path, off_t size) {
    FileInfo *files = malloc(sizeof(FileInfo) * MAX_FILES);
    int count = 0;
    for (int i = 0; i < MAX_FILES - 1 && count < MAX_FILES - 1; i++) {
        if (files[i].size < size) {
            for (int j = i; j > 0; j--) {
                files[j] = files[j - 1];
            }
            files[0].size = size;
            strcpy(files[0].path, path);
            count++;
        }
    }
    free(files);
}

void scan_dir(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        char *file_path = malloc(MAX_PATH);
        sprintf(file_path, "%s/%s", path, ent->d_name);
        struct stat stat_buf;
        stat(file_path, &stat_buf);
        if (S_ISDIR(stat_buf.st_mode)) {
            scan_dir(file_path);
        } else {
            add_file(file_path, stat_buf.st_size);
        }
        free(file_path);
    }
    closedir(dir);
}

int main() {
    char path[MAX_PATH];
    printf("Enter directory path: ");
    scanf("%s", path);
    scan_dir(path);
    return 0;
}