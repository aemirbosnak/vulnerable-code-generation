//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Helper function to get file size
long get_file_size(const char *filepath) {
    struct stat st;
    if (stat(filepath, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Recursive function to analyze disk space usage
void analyze_disk_space(const char *path, long *total_size) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct stat file_stat;
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                // Recursively analyze subdirectories
                analyze_disk_space(full_path, total_size);
            } else {
                // Count file size
                long file_size = get_file_size(full_path);
                if (file_size >= 0) {
                    *total_size += file_size;
                } else {
                    fprintf(stderr, "Error getting file size for %s\n", full_path);
                }
            }
        } else {
            fprintf(stderr, "Error getting file status for %s\n", full_path);
        }
    }

    closedir(dir);
}

int main() {
    char root_path[1024];
    printf("Enter the root path to analyze: ");
    scanf("%s", root_path);

    long total_size = 0;
    analyze_disk_space(root_path, &total_size);

    printf("Total disk space used: %ld bytes\n", total_size);

    return 0;
}