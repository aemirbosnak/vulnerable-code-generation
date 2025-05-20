//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    size_t size;
} File;

void add_file(File *files, int count, const char *path, size_t size) {
    if (count >= MAX_FILES) {
        return;
    }

    strcpy(files[count].path, path);
    files[count].size = size;
    count++;
}

int compare_files(const void *a, const void *b) {
    const File *file_a = (const File *)a;
    const File *file_b = (const File *)b;

    return (int)file_a->size - (int)file_b->size;
}

void print_files(File *files, int count) {
    qsort(files, count, sizeof(File), compare_files);

    for (int i = 0; i < count; i++) {
        printf("%-40s %10zu bytes\n", files[i].path, files[i].size);
    }
}

void analyze_directory(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    File files[MAX_FILES];
    int count = 0;

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char full_path[MAX_PATH];
            snprintf(full_path, MAX_PATH, "%s/%s", path, ent->d_name);

            struct statvfs buf;
            if (statvfs(full_path, &buf)!= 0) {
                continue;
            }

            add_file(files, count, full_path, buf.f_bsize * buf.f_blocks);
        }
    }

    closedir(dir);

    print_files(files, count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);

    return 0;
}