//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_DIR_SIZE 1024
#define MAX_FILE_SIZE 1024
#define MAX_PATH_SIZE 4096

typedef struct {
    char path[MAX_PATH_SIZE];
    unsigned long long size;
} file_t;

void add_file(file_t *files, int count, const char *path, unsigned long long size) {
    if (count >= MAX_DIR_SIZE) {
        return;
    }

    strncpy(files[count].path, path, MAX_PATH_SIZE - 1);
    files[count].path[MAX_PATH_SIZE - 1] = '\0';

    files[count].size = size;
    count++;
}

void print_files(file_t *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %llu bytes\n", files[i].path, files[i].size);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    file_t files[MAX_DIR_SIZE];
    int count = 0;

    if ((dir = opendir("."))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            char path[MAX_PATH_SIZE];
            snprintf(path, MAX_PATH_SIZE, "%s/%s", ".", ent->d_name);

            if (ent->d_type == DT_DIR) {
                add_file(files, count, path, 0);
            } else {
                unsigned long long size = ent->d_reclen;
                add_file(files, count, path, size);
            }
        }

        closedir(dir);
    }

    print_files(files, count);

    return 0;
}