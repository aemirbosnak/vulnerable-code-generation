//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
    char *name;
    char *path;
} File;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void sync_files(char *src, char *dest, int delete) {
    DIR *d;
    struct dirent *dir;
    d = opendir(src);
    if (d == NULL) {
        printf("Cannot open source directory\n");
        exit(1);
    }
    File files[1000];
    int count = 0;
    while ((dir = readdir(d))!= NULL) {
        if (strcmp(dir->d_name, ".")!= 0 && strcmp(dir->d_name, "..")!= 0) {
            files[count].name = strdup(dir->d_name);
            files[count].path = malloc(strlen(src) + strlen(dir->d_name) + 2);
            strcpy(files[count].path, src);
            strcat(files[count].path, "/");
            strcat(files[count].path, dir->d_name);
            count++;
        }
    }
    closedir(d);
    qsort(files, count, sizeof(File), compare);
    for (int i = 0; i < count; i++) {
        char dest_path[1024];
        strcpy(dest_path, dest);
        strcat(dest_path, files[i].name);
        if (delete) {
            remove(dest_path);
        }
        if (files[i].path[strlen(files[i].path) - 1] == '/') {
            mkdir(dest_path, 0777);
        }
        sync_files(files[i].path, dest_path, delete);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_directory destination_directory [delete]\n", argv[0]);
        exit(1);
    }
    sync_files(argv[1], argv[2], atoi(argv[3]) == 1);
    return 0;
}