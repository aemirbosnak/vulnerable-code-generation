//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_DIR_LEN 256
#define MAX_FILE_LEN 256
#define MAX_PATH_LEN 1024

typedef struct {
    char dir[MAX_DIR_LEN];
    char file[MAX_FILE_LEN];
    char path[MAX_PATH_LEN];
    unsigned long long size;
} FileData;

void readDir(const char* path, void (*callback)(const FileData*)) {
    DIR* dir = opendir(path);
    if (!dir) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type!= DT_DIR) {
            char filePath[MAX_PATH_LEN];
            sprintf(filePath, "%s/%s", path, ent->d_name);

            struct stat st;
            stat(filePath, &st);

            FileData data = {
               .dir = path,
               .file = ent->d_name,
               .path = filePath,
               .size = st.st_size
            };

            callback(&data);
        }
    }

    closedir(dir);
}

int compare(const void* a, const void* b) {
    const FileData* fileDataA = (const FileData*)a;
    const FileData* fileDataB = (const FileData*)b;

    return strcmp(fileDataA->file, fileDataB->file);
}

void printData(const FileData* data) {
    printf("%-40s %10lu\n", data->file, data->size);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    readDir(argv[1], printData);

    return 0;
}