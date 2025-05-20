//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    long size;
} File;

int compare_files(const void *a, const void *b) {
    return ((File *)a)->size - ((File *)b)->size;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[1024];
    File *files = NULL;
    int num_files = 0;
    long total_size = 0;

    printf("Welcome to the C Disk Space Analyzer!\n\n");

    printf("Enter the path to the directory you want to analyze: ");
    scanf("%s", path);

    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        struct stat st;
        char full_path[1024];
        sprintf(full_path, "%s/%s", path, entry->d_name);
        if (stat(full_path, &st) == -1) {
            perror("Error getting file info");
            continue;
        }

        if (st.st_mode & S_IFDIR) {
            continue;
        }

        num_files++;
        files = realloc(files, sizeof(File) * num_files);
        files[num_files - 1].name = strdup(entry->d_name);
        files[num_files - 1].size = st.st_size;

        total_size += st.st_size;
    }

    closedir(dir);

    qsort(files, num_files, sizeof(File), compare_files);

    printf("\nDisk space usage for %s:\n\n", path);
    printf("%-30s %-12s\n", "Filename", "Size (bytes)");
    printf("%-30s %.1Lf\n", "Total", (double)total_size);

    for (int i = 0; i < num_files; i++) {
        printf("%-30s %-12ld\n", files[i].name, files[i].size);
    }

    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}