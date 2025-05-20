//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

// Global variables to store total disk space and used disk space
long long total_space = 0;
long long used_space = 0;

// Function to convert bytes to human readable format
void to_human_readable(long long size, char *buf) {
    if (size < KB) {
        sprintf(buf, "%lld B", size);
    } else if (size < MB) {
        sprintf(buf, "%.2f KB", (double) size / KB);
    } else if (size < GB) {
        sprintf(buf, "%.2f MB", (double) size / MB);
    } else {
        sprintf(buf, "%.2f GB", (double) size / GB);
    }
}

// Function to analyze disk usage for a given directory
void analyze_dir(const char *dirpath) {
    // Open directory for reading
    DIR *dir = opendir(dirpath);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", dirpath);
        return;
    }

    // Loop over all directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Build full path of the current entry
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirpath, entry->d_name);

        // Get statistics for the current entry
        struct stat statbuf;
        if (lstat(path, &statbuf) == -1) {  // Use lstat instead of stat to handle symbolic links
            printf("Error getting statistics for file: %s\n", path);
            continue;
        }

        // Add space usage of the current entry to total and used space
        total_space += statbuf.st_blocks * 512;
        used_space += statbuf.st_size;

        // Recursively analyze subdirectories
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_dir(path);
        }
    }

    // Close directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check that a directory was provided as argument
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Analyze disk usage for the given directory
    analyze_dir(argv[1]);

    // Print results
    char total_size_str[32];
    to_human_readable(total_space, total_size_str);

    char used_size_str[32];
    to_human_readable(used_space, used_size_str);

    printf("Total disk space: %s\n", total_size_str);
    printf("Used disk space: %s\n", used_size_str);

    return 0;
}