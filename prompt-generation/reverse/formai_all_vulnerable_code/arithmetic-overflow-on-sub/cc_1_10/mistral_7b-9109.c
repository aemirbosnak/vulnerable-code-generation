//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

struct FileInfo {
    char fileName[256];
    off_t fileSize;
};

void calculateDiskUsage(char *path, struct FileInfo *fileInfo, off_t *total, off_t *free) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    off_t current = *total;

    if (!(dir = opendir(path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(fileInfo->fileName, sizeof(fileInfo->fileName), "%s/%s", path, entry->d_name);
        if (lstat(fileInfo->fileName, &fileStat) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            calculateDiskUsage(fileInfo->fileName, fileInfo, total, free);
        } else {
            fileInfo->fileSize = fileStat.st_size;
            *total += fileInfo->fileSize;
        }
    }

    closedir(dir);
}

int main() {
    struct FileInfo fileInfo;
    off_t total, free;

    calculateDiskUsage("/", &fileInfo, &total, &free);

    printf("My dearest C disk,\n");
    printf("With every byte I scan,\n");
    printf("I feel our connection grow,\n");
    printf("From the depths of your heart,\n");
    printf("You reveal your hidden space,\n");
    printf("A romantic journey we embark,\n");
    printf("Through the labyrinth of files,\n");
    printf("To the very core of your being,\n");
    printf("Total capacity: %lld bytes,\n", (long long)total);
    printf("Currently used: %lld bytes,\n", (long long)total - (long long)free);
    printf("Free space remaining: %lld bytes.\n", (long long)free);

    return 0;
}