//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

int main(int argc, char *argv[]) {
    // check if a directory was provided as input
    if (argc < 2) {
        printf("Please specify a directory path.\n");
        return 1;
    }

    long long total_size = 0; // total size of the directory
    char path[MAX_PATH]; // current file/folder path
    DIR *dir; // directory stream
    struct dirent *entry; // directory entry
    struct stat file_info; // file info struct

    // iterate through directory
    strcpy(path, argv[1]); // copy directory path to path variable
    dir = opendir(path); // open directory
    if (dir == NULL) {
        printf("Invalid directory path.\n");
        return 1;
    }

    printf("Analyzing disk usage for directory: %s\n", path);

    while ((entry = readdir(dir)) != NULL) { // iterate through directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // skip . and ..
        }

        snprintf(path, MAX_PATH, "%s/%s", argv[1], entry->d_name); // create full path for entry
        if (stat(path, &file_info) == -1) { // get file info
            printf("Failed to retrieve file information for: %s\n", path);
            continue;
        }

        long long size;
        if (S_ISDIR(file_info.st_mode)) { // if entry is a directory
            size = 0;
            DIR *subdir = opendir(path); // open subdirectory
            if (subdir == NULL) {
                printf("Failed to open subdirectory: %s\n", path);
                continue;
            }

            struct dirent *subentry;
            while ((subentry = readdir(subdir)) != NULL) {
                if (strcmp(subentry->d_name, ".") == 0 || strcmp(subentry->d_name, "..") == 0) {
                    continue;
                }

                snprintf(path, MAX_PATH, "%s/%s", entry->d_name, subentry->d_name);
                if (stat(path, &file_info) == -1) {
                    printf("Failed to retrieve file information for: %s\n", path);
                    continue;
                }

                if (S_ISREG(file_info.st_mode)) {
                    size += file_info.st_size; // add size of regular file
                }
            }

            closedir(subdir); // close subdirectory
        } else if (S_ISREG(file_info.st_mode)) { // if entry is a regular file
            size = file_info.st_size;
        } else { // if entry is not a directory or a regular file
            continue;
        }

        total_size += size;

        printf("%-50s%10lld bytes\n", entry->d_name, size);
    }

    closedir(dir); // close directory
    printf("----------------------------------------------\n");
    printf("%-50s%10lld bytes\n", "Total directory size:", total_size);

    return 0;
}