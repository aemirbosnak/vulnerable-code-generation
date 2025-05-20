//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: realistic
/*
 * Disk Space Analyzer
 *
 * Written by [Your Name]
 *
 * This program takes in a directory path and
 * displays the total size of all files in the
 * directory, as well as the total size of all
 * subdirectories.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Structure to store file information
struct file_info {
    char name[100];
    long size;
};

// Function to get the size of a file
long get_file_size(char *path) {
    struct stat st;
    stat(path, &st);
    return st.st_size;
}

// Function to get the size of a directory
long get_dir_size(char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    long total_size = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            total_size += get_file_size(entry->d_name);
        } else if (entry->d_type == DT_DIR) {
            total_size += get_dir_size(entry->d_name);
        }
    }
    return total_size;
}

// Function to print the size of a file or directory
void print_size(char *path, long size) {
    printf("%s: %ld bytes\n", path, size);
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get the directory path
    char *path = argv[1];

    // Get the size of the directory
    long total_size = get_dir_size(path);

    // Print the size of the directory
    print_size(path, total_size);

    return 0;
}