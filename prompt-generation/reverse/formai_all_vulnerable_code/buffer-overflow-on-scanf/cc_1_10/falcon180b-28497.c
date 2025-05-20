//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH 1024

typedef struct _file_info {
    char filename[MAX_PATH];
    unsigned long long filesize;
} FileInfo;

void get_directory_contents(const char *path, FileInfo *files, int count) {
    DIR *dir = opendir(path);
    struct dirent *ent;

    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    int i = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (i >= count) {
            printf("Directory contains too many files.\n");
            closedir(dir);
            return;
        }

        strcpy(files[i].filename, ent->d_name);
        files[i].filesize = 0;
        i++;
    }

    closedir(dir);
}

unsigned long long get_file_size(const char *filename) {
    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        printf("Error getting file size: %s\n", filename);
        return 0;
    }

    return statbuf.st_size;
}

void print_file_info(FileInfo *files, int count) {
    printf("Filename\tSize\n");

    for (int i = 0; i < count; i++) {
        files[i].filesize = get_file_size(files[i].filename);
        printf("%s\t%llu bytes\n", files[i].filename, files[i].filesize);
    }
}

int main() {
    char path[MAX_PATH];
    printf("Enter directory path: ");
    scanf("%s", path);

    int count = 100;
    FileInfo files[count];

    get_directory_contents(path, files, count);
    print_file_info(files, count);

    return 0;
}