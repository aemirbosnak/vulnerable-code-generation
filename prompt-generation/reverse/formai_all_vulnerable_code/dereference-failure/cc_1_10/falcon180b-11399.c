//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_LENGTH 1024
#define MAX_FILE_LENGTH 256

typedef struct {
    char name[MAX_FILE_LENGTH];
    long size;
} FileInfo;

long GetDirSize(const char* path) {
    long size = 0;
    DIR* dir = opendir(path);
    if (dir!= NULL) {
        struct dirent* ent;
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                char filePath[MAX_DIR_LENGTH];
                sprintf(filePath, "%s/%s", path, ent->d_name);
                struct stat st;
                stat(filePath, &st);
                if (S_ISDIR(st.st_mode)) {
                    size += GetDirSize(filePath);
                } else {
                    FileInfo fileInfo;
                    strncpy(fileInfo.name, ent->d_name, MAX_FILE_LENGTH - 1);
                    fileInfo.name[MAX_FILE_LENGTH - 1] = '\0';
                    fileInfo.size = st.st_size;
                    printf("%s (%ld bytes)\n", fileInfo.name, fileInfo.size);
                    size += fileInfo.size;
                }
            }
        }
        closedir(dir);
    }
    return size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_DIR_LENGTH];
    strncpy(path, argv[1], MAX_DIR_LENGTH - 1);
    path[MAX_DIR_LENGTH - 1] = '\0';

    long totalSize = GetDirSize(path);

    printf("Total size of '%s': %ld bytes\n", path, totalSize);

    return 0;
}