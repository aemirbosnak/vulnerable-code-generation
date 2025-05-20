//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct {
    char path[1024];
    long long size;
} file_t;

void add_file(file_t *file, const char *path) {
    strcpy(file->path, path);
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        file->size = buf.f_blocks * buf.f_frsize;
    } else {
        file->size = 0;
    }
}

int compare_files(const void *a, const void *b) {
    file_t *filea = (file_t *)a;
    file_t *fileb = (file_t *)b;
    return (int)((filea->size - fileb->size) * 1000);
}

void print_files(file_t *files, int count) {
    qsort(files, count, sizeof(file_t), compare_files);
    printf("File\tSize\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%lld\n", files[i].path, files[i].size);
    }
}

void process_dir(const char *path, file_t *files, int *count) {
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(path);
    if (dp!= NULL) {
        while ((dirp = readdir(dp))!= NULL) {
            if (strcmp(dirp->d_name, ".")!= 0 && strcmp(dirp->d_name, "..")!= 0) {
                char full_path[1024];
                strcpy(full_path, path);
                strcat(full_path, "/");
                strcat(full_path, dirp->d_name);
                add_file(&files[*count], full_path);
                (*count)++;
            }
        }
        closedir(dp);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }
    file_t *files = malloc(BUFFER_SIZE * sizeof(file_t));
    int count = 0;
    process_dir(argv[1], files, &count);
    print_files(files, count);
    free(files);
    return 0;
}