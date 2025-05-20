//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define MAX_DIR_SIZE 1024
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_DIR_SIZE];
    int size;
} DirEntry;

void print_entry(DirEntry *entry) {
    printf("%s\t%d bytes\n", entry->name, entry->size);
}

int is_file(const char *path) {
    struct stat st;
    stat(path, &st);
    return (st.st_mode & S_IFREG);
}

int is_dir(const char *path) {
    struct stat st;
    stat(path, &st);
    return (st.st_mode & S_IFDIR);
}

void scan_dir(const char *dir, int level) {
    DIR *d;
    struct dirent *dirp;
    d = opendir(dir);
    if (d == NULL) {
        printf("Error opening directory: %s\n", dir);
        return;
    }

    while ((dirp = readdir(d))!= NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_DIR_SIZE];
        strcpy(path, dir);
        strcat(path, "/");
        strcat(path, dirp->d_name);

        if (is_file(path)) {
            DirEntry entry;
            strcpy(entry.name, dirp->d_name);
            entry.size = get_file_size(path);
            print_entry(&entry);
        } else if (is_dir(path)) {
            scan_dir(path, level + 1);
        }
    }

    closedir(d);
}

int get_file_size(const char *path) {
    struct stat st;
    stat(path, &st);
    return st.st_size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_DIR_SIZE];
    strcpy(path, argv[1]);

    scan_dir(path, 0);

    return 0;
}