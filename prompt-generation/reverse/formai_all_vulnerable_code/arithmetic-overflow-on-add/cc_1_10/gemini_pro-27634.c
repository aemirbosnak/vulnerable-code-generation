//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Define some colors for output
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Define the main function
int main(int argc, char **argv) {
    // Check if the user has provided a directory to analyze
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get the directory name from the user
    char *directory = argv[1];

    // Open the directory
    DIR *dir = opendir(directory);

    // Check if the directory could not be opened
    if (dir == NULL) {
        printf("Could not open directory: %s\n", directory);
        return 1;
    }

    // Create a data structure to store the file and directory information
    struct dirent *entry;

    // Create a variable to store the total disk space used
    long long total_size = 0;

    // Iterate over the directory
    while ((entry = readdir(dir)) != NULL) {
        // Get the file or directory name
        char *name = entry->d_name;

        // Get the file or directory path
        char path[512];
        snprintf(path, sizeof(path), "%s/%s", directory, name);

        // Get the file or directory status
        struct stat statbuf;
        if (lstat(path, &statbuf) != 0) {
            printf("Could not get file or directory status: %s\n", path);
            continue;
        }

        // Check if the file or directory is a regular file
        if (S_ISREG(statbuf.st_mode)) {
            // Add the file size to the total disk space used
            total_size += statbuf.st_size;
        }
    }

    // Close the directory
    closedir(dir);

    // Print the total disk space used
    printf("Total disk space used: %lld bytes\n", total_size);

    // Return 0 to indicate success
    return 0;
}