//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define HANDLE_ERROR(msg) { perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char* argv[]) {
    struct dirent *entry;
    struct stat file_info;
    DIR *dir;
    long long total_size = 0;
    char path[PATH_MAX];

    // Check for a directory argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the directory
    dir = opendir(argv[1]);
    if (dir == NULL) {
        HANDLE_ERROR("opendir");
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Get the file information
        snprintf(path, PATH_MAX, "%s/%s", argv[1], entry->d_name);
        if (stat(path, &file_info) == -1) {
            HANDLE_ERROR("stat");
        }

        // Accumulate the total size
        if (S_ISREG(file_info.st_mode)) {
            total_size += file_info.st_size;
        } else if (S_ISDIR(file_info.st_mode)) {
            // Recursively analyze subdirectories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            long long subdir_size = 0;
            char subdir[PATH_MAX];
            snprintf(subdir, PATH_MAX, "%s/%s", argv[1], entry->d_name);

            DIR *subdir_dir = opendir(subdir);
            if (subdir_dir == NULL) {
                HANDLE_ERROR("opendir");
            }

            struct dirent *subdir_entry;
            while ((subdir_entry = readdir(subdir_dir)) != NULL) {
                snprintf(path, PATH_MAX, "%s/%s", subdir, subdir_entry->d_name);
                if (stat(path, &file_info) == -1) {
                    HANDLE_ERROR("stat");
                }

                if (S_ISREG(file_info.st_mode)) {
                    subdir_size += file_info.st_size;
                }
            }

            total_size += subdir_size;
        }
    }

    closedir(dir);

    printf("Total size: %lld bytes\n", total_size);
    return EXIT_SUCCESS;
}