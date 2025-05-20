//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

// Function to get the size of a file in bytes
long long get_file_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Function to recursively calculate the size of a directory
long long get_directory_size(const char *path) {
    long long total_size = 0;

    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    // Loop through the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the full path of the entry
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        // Get the size of the entry
        long long size = get_file_size(full_path);
        if (size == -1) {
            closedir(dir);
            return -1;
        }

        // Add the size of the entry to the total size
        total_size += size;

        // If the entry is a directory, recursively calculate its size
        if (entry->d_type == DT_DIR) {
            long long subdir_size = get_directory_size(full_path);
            if (subdir_size == -1) {
                closedir(dir);
                return -1;
            }
            total_size += subdir_size;
        }
    }

    // Close the directory
    closedir(dir);

    return total_size;
}

int main() {
    // Get the path of the directory to analyze
    char path[MAX_PATH_LENGTH];
    printf("Enter the path of the directory to analyze: ");
    scanf("%s", path);

    // Calculate the size of the directory
    long long size = get_directory_size(path);
    if (size == -1) {
        perror("Error calculating directory size");
        return EXIT_FAILURE;
    }

    // Print the size of the directory
    printf("The size of the directory is %lld bytes\n", size);

    return EXIT_SUCCESS;
}