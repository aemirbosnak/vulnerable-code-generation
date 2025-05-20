//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
/*
 *  C Disk Space Analyzer Example Program
 *  by Expert-Level Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function to calculate the disk space usage of a directory
int calculate_directory_size(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    int total_size = 0;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory %s\n", path);
        return -1;
    }

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip over . and .. entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the file status
        char full_path[256];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &statbuf) == -1) {
            fprintf(stderr, "Failed to stat %s\n", full_path);
            continue;
        }

        // If it's a directory, recursively calculate its size
        if (S_ISDIR(statbuf.st_mode)) {
            int dir_size = calculate_directory_size(full_path);
            if (dir_size == -1) {
                continue;
            }
            total_size += dir_size;
        } else {
            // Otherwise, add the file size to the total
            total_size += statbuf.st_size;
        }
    }

    // Close the directory
    closedir(dir);

    return total_size;
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Calculate the disk space usage of the directory
    int dir_size = calculate_directory_size(argv[1]);
    if (dir_size == -1) {
        fprintf(stderr, "Failed to calculate disk space usage\n");
        return 1;
    }

    // Print the result
    printf("Disk space usage: %d bytes\n", dir_size);

    return 0;
}