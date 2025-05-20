//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void analyzeDiskSpace(char *path);
int calculateFileSize(char *path);

int main() {
    char path[100];
    printf("Enter the path that you want to analyze: ");
    scanf("%s", path);
    analyzeDiskSpace(path);
    return 0;
}

void analyzeDiskSpace(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat filestat;

    dir = opendir(path);
    if (!dir) {
        printf("Could not open directory.\n");
        return;
    }

    int totalSize = 0;

    while ((entry = readdir(dir)) != NULL) {
        char filePath[200];
        strcpy(filePath, path);
        strcat(filePath, "/");
        strcat(filePath, entry->d_name);

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            totalSize += calculateFileSize(filePath);
            analyzeDiskSpace(filePath);
        } else {
            if (entry->d_type == DT_REG) {
                stat(filePath, &filestat);
                totalSize += filestat.st_size;
            }
        }
    }

    printf("%s: %d\n", path, totalSize);

    closedir(dir);
}

int calculateFileSize(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat filestat;

    int totalSize = 0;

    dir = opendir(path);
    if (!dir) {
        printf("Could not open directory.\n");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        char filePath[200];
        strcpy(filePath, path);
        strcat(filePath, "/");
        strcat(filePath, entry->d_name);

        if (entry->d_type == DT_REG) {
            stat(filePath, &filestat);
            totalSize += filestat.st_size;
        }
    }

    closedir(dir);
    return totalSize;
}