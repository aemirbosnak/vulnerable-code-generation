//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_FILE_LENGTH 256
#define MAX_DIR_LENGTH 4096

typedef struct {
    char name[MAX_FILE_LENGTH];
    unsigned long long size;
} FileInfo;

typedef struct {
    char name[MAX_DIR_LENGTH];
    unsigned long long totalSize;
    unsigned long long numFiles;
    FileInfo *files;
} DirInfo;

void addFile(DirInfo *dir, const char *path) {
    struct statvfs fs;
    statvfs(path, &fs);

    FileInfo *file = (FileInfo *)malloc(sizeof(FileInfo));
    strncpy(file->name, path, MAX_FILE_LENGTH - 1);
    file->size = fs.f_blocks * fs.f_frsize;

    dir->totalSize += file->size;
    dir->numFiles++;

    dir->files = (FileInfo *)realloc(dir->files, dir->numFiles * sizeof(FileInfo));
    dir->files[dir->numFiles - 1] = *file;
}

void printDir(DirInfo *dir, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }

    printf("%s (%lu files, %lu bytes)\n", dir->name, dir->numFiles, dir->totalSize);

    for (int i = 0; i < dir->numFiles; i++) {
        printf("%s%s (%lu bytes)\n", indent > 0? "  " : "", dir->files[i].name, dir->files[i].size);
    }
}

void freeDir(DirInfo *dir) {
    for (int i = 0; i < dir->numFiles; i++) {
        free(dir->files[i].name);
    }

    free(dir->files);
}

int main() {
    char path[MAX_DIR_LENGTH];
    printf("Enter the directory path: ");
    scanf("%s", path);

    DirInfo dir;
    strncpy(dir.name, path, MAX_DIR_LENGTH - 1);
    dir.totalSize = 0;
    dir.numFiles = 0;
    dir.files = NULL;

    DIR *d = opendir(path);

    if (d!= NULL) {
        struct dirent *dirp;
        while ((dirp = readdir(d))!= NULL) {
            if (strcmp(dirp->d_name, ".")!= 0 && strcmp(dirp->d_name, "..")!= 0) {
                char filePath[MAX_DIR_LENGTH];
                strcat(filePath, path);
                strcat(filePath, "/");
                strcat(filePath, dirp->d_name);

                addFile(&dir, filePath);
            }
        }

        closedir(d);
    }

    printDir(&dir, 0);

    freeDir(&dir);

    return 0;
}