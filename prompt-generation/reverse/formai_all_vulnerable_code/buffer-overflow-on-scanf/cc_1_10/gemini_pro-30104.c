//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILES_COUNT 1000

typedef struct {
    char path[MAX_PATH_LENGTH];
    long long size;
} FileInfo;

int compareFiles(const void *a, const void *b) {
    const FileInfo *a1 = (const FileInfo *)a;
    const FileInfo *b1 = (const FileInfo *)b;
    return b1->size - a1->size;
}

int main() {
    char path[MAX_PATH_LENGTH];
    char pathTemp[MAX_PATH_LENGTH];
    DIR *dir;
    struct dirent *ent;
    int fd;
    struct stat st;
    int fileCount = 0;
    FileInfo files[MAX_FILES_COUNT];

    printf("Enter the path to analyze: ");
    scanf("%s", path);

    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        snprintf(pathTemp, MAX_PATH_LENGTH, "%s/%s", path, ent->d_name);
        if (lstat(pathTemp, &st) == -1) {
            perror("Error getting file info");
            continue;
        }

        if (st.st_mode & S_IFDIR) {
            continue;
        }

        if (fileCount == MAX_FILES_COUNT) {
            printf("Warning: Too many files to analyze. Only the first %d files will be analyzed.\n", MAX_FILES_COUNT);
            break;
        }

        fd = open(pathTemp, O_RDONLY);
        if (fd == -1) {
            perror("Error opening file");
            continue;
        }

        files[fileCount].size = st.st_size;
        snprintf(files[fileCount].path, MAX_PATH_LENGTH, "%s", pathTemp);
        fileCount++;

        close(fd);
    }

    closedir(dir);

    qsort(files, fileCount, sizeof(FileInfo), compareFiles);

    printf("Top 10 largest files:\n");
    for (int i = 0; i < 10 && i < fileCount; i++) {
        printf("%s: %.2f MB\n", files[i].path, (double)files[i].size / (1024 * 1024));
    }

    return EXIT_SUCCESS;
}