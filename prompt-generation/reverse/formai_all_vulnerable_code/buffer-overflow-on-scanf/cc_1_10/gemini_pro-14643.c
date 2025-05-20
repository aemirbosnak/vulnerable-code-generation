//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *dirent;
    struct stat statbuf;
    char path[1024];
    long long totalSize = 0;

    // Prompt the user to enter a directory path
    printf("Enter the path to the directory you want to analyze: ");
    scanf("%s", path);

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return -1;
    }

    // Iterate over the directory entries
    while ((dirent = readdir(dir)) != NULL) {
        // Ignore hidden files and directories
        if (dirent->d_name[0] == '.') {
            continue;
        }

        // Get the full path to the file or directory
        snprintf(path, sizeof(path), "%s/%s", path, dirent->d_name);

        // Get the file or directory size
        if (stat(path, &statbuf) == -1) {
            perror("Error getting file or directory size");
            continue;
        }

        // Add the file or directory size to the total size
        totalSize += statbuf.st_size;
    }

    // Close the directory
    closedir(dir);

    // Print the total size of the directory
    printf("Total size of the directory: %lld bytes\n", totalSize);

    return 0;
}