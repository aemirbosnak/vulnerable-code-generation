//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
/*
 * disk_space_analyzer.c
 *
 * A rigorous program to analyze the disk space usage of a directory and its subdirectories
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

// Function to recursively scan a directory and its subdirectories
void scan_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat stat_buf;

    if (!(dir = opendir(dir_path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir))) {
        char file_path[256];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively scan subdirectory
            scan_directory(file_path);
        } else {
            // Get file status
            if (stat(file_path, &stat_buf) < 0) {
                perror("stat");
                return;
            }

            // Print file information
            printf("%s: %ld bytes\n", entry->d_name, (long)stat_buf.st_size);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    // Scan directory and its subdirectories
    scan_directory(argv[1]);

    return 0;
}