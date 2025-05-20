//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <dirent.h>

#define PATH_MAX 4096
#define BUFFER_SIZE 256

// Function to traverse directories and analyze disk usage
void analyze_disk_space(const char *path, long long *total_size, long long *total_files) {
    struct statvfs stat;
    if (statvfs(path, &stat) != 0) {
        perror("Failed to get filesystem statistics");
        return;
    }

    // Calculate the total space
    *total_size += (stat.f_blocks * stat.f_frsize); // total space in bytes
    *total_files = 0;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current directory (.) and the parent directory (..)
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char new_path[PATH_MAX];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);

            if (entry->d_type == DT_DIR) {
                // If it is a directory, recurse into it
                analyze_disk_space(new_path, total_size, total_files);
            } else {
                // If it is a file, increment the file count
                FILE *file = fopen(new_path, "rb");
                if (file) {
                    fseek(file, 0, SEEK_END);
                    long file_size = ftell(file);
                    fclose(file);
                    *total_size += file_size;
                    (*total_files)++;
                }
            }
        }
    }
    closedir(dir);
}

// Function to display the disk usage statistics
void display_usage(long long total_size, long long total_files) {
    printf("Total size of analyzed files/directories: %.2f GB\n", total_size / (1024.0 * 1024 * 1024));
    printf("Total number of files: %lld\n", total_files);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    long long total_size = 0;
    long long total_files = 0;

    analyze_disk_space(directory_path, &total_size, &total_files);
    display_usage(total_size, total_files);

    return EXIT_SUCCESS;
}