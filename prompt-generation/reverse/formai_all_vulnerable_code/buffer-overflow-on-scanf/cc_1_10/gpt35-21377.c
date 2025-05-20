//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// function to calculate the total disk space used by a directory
long long calculateSize(char* path) {
    DIR* dir;
    struct dirent* entry;
    struct stat info;
    long long size = 0;

    // open the directory and handle errors if any
    if ((dir = opendir(path)) == NULL) {
        perror("Unable to open directory");
        exit(1);
    }

    // read each directory entry and calculate the size recursively
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[1024];
        sprintf(file_path, "%s/%s", path, entry->d_name);

        if (stat(file_path, &info) == -1) {
            perror("Unable to get file status");
            exit(1);
        }

        size += info.st_size;

        if (S_ISDIR(info.st_mode)) {
            size += calculateSize(file_path);
        }
    }

    // close the directory and return the size
    closedir(dir);
    return size;
}

int main() {
    char path[1024];
    printf("Enter the directory path to analyze: ");
    scanf("%s", path);

    // calculate the size of the directory and print the results
    long long total_size = calculateSize(path);
    printf("Total disk space used by %s: %lld bytes\n", path, total_size);

    return 0;
}