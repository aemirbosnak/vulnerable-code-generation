//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} FileInfo;

unsigned long long getDirectorySize(const char* path) {
    unsigned long long size = 0;
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return size;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char subPath[MAX_PATH];
            sprintf(subPath, "%s/%s", path, ent->d_name);
            size += getDirectorySize(subPath);
        } else {
            FileInfo fileInfo;
            sprintf(fileInfo.path, "%s/%s", path, ent->d_name);
            struct stat st;
            stat(fileInfo.path, &st);
            fileInfo.size = st.st_size;
            size += fileInfo.size;
        }
    }

    closedir(dir);
    return size;
}

void printFileInfo(const FileInfo* fileInfo, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("%s (%llu bytes)\n", fileInfo->path, fileInfo->size);
}

void analyzeDirectory(const char* path, int indent) {
    unsigned long long size = getDirectorySize(path);
    printf("Total size of '%s': %llu bytes\n", path, size);

    DIR* dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char subPath[MAX_PATH];
            sprintf(subPath, "%s/%s", path, ent->d_name);
            analyzeDirectory(subPath, indent + 2);
        } else {
            FileInfo fileInfo;
            sprintf(fileInfo.path, "%s/%s", path, ent->d_name);
            struct stat st;
            stat(fileInfo.path, &st);
            fileInfo.size = st.st_size;
            printFileInfo(&fileInfo, indent + 2);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyzeDirectory(argv[1], 0);

    return 0;
}