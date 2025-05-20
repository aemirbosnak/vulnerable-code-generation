//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

long long int totalSize = 0;

void analyzeDirectory(char *directoryPath) {
    struct dirent *dir;
    DIR *directory = opendir(directoryPath);
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            char *fullPath = malloc(strlen(directoryPath) + strlen(dir->d_name) + 2);
            sprintf(fullPath, "%s/%s", directoryPath, dir->d_name);

            struct stat fileInfo;
            if (lstat(fullPath, &fileInfo) >= 0) {
                if (S_ISREG(fileInfo.st_mode)) { // Regular file
                    totalSize += fileInfo.st_size;
                } else if (S_ISDIR(fileInfo.st_mode)) { // Directory
                    if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                        analyzeDirectory(fullPath);
                    }
                } else if (S_ISLNK(fileInfo.st_mode)) { // Symbolic link
                    char *linkDestination = malloc(fileInfo.st_size + 1);
                    readlink(fullPath, linkDestination, fileInfo.st_size + 1);
                    linkDestination[fileInfo.st_size] = '\0';
                    printf("Symbolic link: %s -> %s\n", fullPath, linkDestination);
                    free(linkDestination);
                } else { // Other file types
                    printf("Unknown file type: %s\n", fullPath);
                }
            } else {
                printf("Error analyzing file: %s\n", fullPath);
            }

            free(fullPath);
        }
        closedir(directory);
    } else {
        printf("Error opening directory: %s\n", directoryPath);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory path>\n", argv[0]);
        return 1;
    }

    char *directoryPath = argv[1];

    printf("Analyzing directory: %s\n", directoryPath);

    analyzeDirectory(directoryPath);

    printf("\nTotal size: %lld bytes\n", totalSize);

    return 0;
}