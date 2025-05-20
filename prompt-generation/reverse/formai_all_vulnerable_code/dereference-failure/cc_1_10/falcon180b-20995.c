//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_NAME 256

struct dirent *readdir(DIR *dir);

int main(int argc, char *argv[]) {
    char path[MAX_FILE_NAME];
    DIR *dir;
    struct dirent *ent;
    struct statvfs buf;
    char *dirPath;
    long totalSpace, freeSpace;
    float usedPercentage;
    int totalFiles, totalDirs;

    if (argc!= 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    strcpy(path, argv[1]);
    dirPath = path;

    dir = opendir(dirPath);
    if (dir == NULL) {
        printf("Error: Cannot open directory %s\n", dirPath);
        return 1;
    }

    totalFiles = 0;
    totalDirs = 0;
    totalSpace = 0;
    freeSpace = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            totalDirs++;
        } else {
            totalFiles++;
        }
    }

    if (statvfs(dirPath, &buf) == -1) {
        printf("Error: Cannot get disk space information\n");
        closedir(dir);
        return 1;
    }

    totalSpace = buf.f_blocks * buf.f_frsize;
    freeSpace = buf.f_bavail * buf.f_frsize;

    usedPercentage = ((float) (totalSpace - freeSpace) / totalSpace) * 100;

    printf("Directory: %s\n", dirPath);
    printf("Total files: %d\n", totalFiles);
    printf("Total directories: %d\n", totalDirs);
    printf("Total space: %ld bytes\n", totalSpace);
    printf("Free space: %ld bytes\n", freeSpace);
    printf("Used space: %ld bytes\n", totalSpace - freeSpace);
    printf("Used percentage: %.2f%%\n", usedPercentage);

    closedir(dir);
    return 0;
}

struct dirent *readdir(DIR *dir) {
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            printf("%s\n", ent->d_name);
        }
    }
    return ent;
}