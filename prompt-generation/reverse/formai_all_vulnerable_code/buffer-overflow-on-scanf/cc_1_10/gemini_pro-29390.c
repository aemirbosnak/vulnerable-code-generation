//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

// Helper function to get file size in KB
long long fileSizeKB(char *path) {
    struct stat st;
    stat(path, &st);
    return st.st_size / 1024;
}

// Recursive function to traverse directories and calculate total size
long long dirSizeKB(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    long long totalSize = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char subpath[strlen(path) + strlen(entry->d_name) + 2];
        sprintf(subpath, "%s/%s", path, entry->d_name);

        struct stat st;
        stat(subpath, &st);
        if (S_ISDIR(st.st_mode)) {
            totalSize += dirSizeKB(subpath);
        } else {
            totalSize += fileSizeKB(subpath);
        }
    }

    closedir(dir);
    return totalSize;
}

int main() {
    char path[256];
    printf("Enter the path to analyze (e.g., 'C:\\'): ");
    scanf("%s", path);

    long long totalSizeKB = dirSizeKB(path);
    if (totalSizeKB < 0) {
        perror("dirSizeKB");
        return EXIT_FAILURE;
    }

    printf("Total size of '%s': %.2f MB\n", path, (float)totalSizeKB / 1024);

    return 0;
}