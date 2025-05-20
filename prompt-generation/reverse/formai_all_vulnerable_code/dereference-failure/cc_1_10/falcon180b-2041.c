//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH_LEN 1024
#define MAX_FILES 100

typedef struct {
    char path[MAX_PATH_LEN];
    unsigned long long size;
} FileInfo;

void addFile(FileInfo* files, int* numFiles, const char* path, unsigned long long size) {
    if (*numFiles >= MAX_FILES) {
        printf("Error: Too many files\n");
        return;
    }

    strcpy(files[*numFiles].path, path);
    files[*numFiles].size = size;
    (*numFiles)++;
}

void printFiles(FileInfo* files, int numFiles) {
    printf("Files:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s (%llu bytes)\n", files[i].path, files[i].size);
    }
}

void analyzeDirectory(const char* path, FileInfo* files, int* numFiles) {
    DIR* dir = opendir(path);

    if (dir == NULL) {
        printf("Error: Could not open directory '%s'\n", path);
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char filePath[MAX_PATH_LEN];
            sprintf(filePath, "%s/%s", path, ent->d_name);
            struct stat st;
            if (stat(filePath, &st) == 0) {
                addFile(files, numFiles, filePath, st.st_size);
            }
        } else if (ent->d_type == DT_DIR) {
            char subPath[MAX_PATH_LEN];
            sprintf(subPath, "%s/%s", path, ent->d_name);
            analyzeDirectory(subPath, files, numFiles);
        }
    }

    closedir(dir);
}

int main() {
    FileInfo files[MAX_FILES];
    int numFiles = 0;

    char path[MAX_PATH_LEN];
    printf("Enter directory path: ");
    scanf("%s", path);

    analyzeDirectory(path, files, &numFiles);

    printFiles(files, numFiles);

    return 0;
}