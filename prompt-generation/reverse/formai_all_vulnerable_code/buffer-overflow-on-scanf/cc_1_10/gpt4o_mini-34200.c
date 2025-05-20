//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 1024

void get_size(const char *directory, long *total_size, long threshold, long *above_threshold) {
    struct dirent *entry;
    struct stat file_info;
    DIR *dir = opendir(directory);
    
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[BUFFER_SIZE];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory, entry->d_name);

        if (stat(file_path, &file_info) < 0) {
            perror("Could not get file info");
            continue;
        }

        if (S_ISREG(file_info.st_mode)) { // It's a regular file
            *total_size += file_info.st_size;

            if (file_info.st_size > threshold) {
                *above_threshold += file_info.st_size;
                printf("File: %s | Size: %ld bytes\n", file_path, file_info.st_size);
            }
        } else if (S_ISDIR(file_info.st_mode)) { // It's a directory
            get_size(file_path, total_size, threshold, above_threshold); // Recurse into sub-directory
        }
    }
    
    closedir(dir);
}

int main() {
    char directory[BUFFER_SIZE];
    long total_size = 0;
    long above_threshold = 0;
    long threshold;

    printf("Enter the directory path to analyze: ");
    fgets(directory, sizeof(directory), stdin);
    directory[strcspn(directory, "\n")] = 0; // Remove the newline character

    printf("Enter the file size threshold in bytes (only files larger than this will be displayed): ");
    scanf("%ld", &threshold);

    get_size(directory, &total_size, threshold, &above_threshold);

    printf("\nTotal size of files in directory '%s': %ld bytes\n", directory, total_size);
    printf("Total size of files above %ld bytes: %ld bytes\n", threshold, above_threshold);

    return 0;
}