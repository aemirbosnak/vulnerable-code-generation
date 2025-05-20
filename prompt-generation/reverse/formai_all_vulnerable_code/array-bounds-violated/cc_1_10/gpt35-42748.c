//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze(char* dir_path, int depth, long int* total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat stat_buf;

    char sub_dir_path[512];
    strcpy(sub_dir_path, dir_path);
    if (sub_dir_path[strlen(sub_dir_path)-1] != '/') {
        strcat(sub_dir_path, "/");
    }

    // Open the directory
    if (!(dir = opendir(dir_path))) {
        fprintf(stderr, "Cannot open directory '%s'\n", dir_path);
        return;
    }

    // Loop through the directory and analyze all files and directories within it
    while ((entry = readdir(dir)) != NULL) {
        char file_path[512];
        strcpy(file_path, sub_dir_path);
        strcat(file_path, entry->d_name);

        // Get the statistics of the file or directory
        if (lstat(file_path, &stat_buf) == -1) {
            fprintf(stderr, "Cannot get information about '%s'\n", file_path);
            continue;
        }

        // Check whether this is a directory or not (ignore hidden directories)
        if (S_ISDIR(stat_buf.st_mode) && entry->d_name[0] != '.') {
            // Recursively analyze the sub-directory
            analyze(file_path, depth+1, total_size);
        } else {
            // Calculate the size of the file and add it to the total
            long int size = stat_buf.st_size;
            *total_size += size;
        }
    }

    // Close the directory
    closedir(dir);

    // Print the total size of the directory including all sub-directories
    if (depth == 0) {
        printf("Total size of '%s': %ld bytes\n", dir_path, *total_size);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [directory_path]\n", argv[0]);
        exit(1);
    }

    // Analyze the specified directory
    long int total_size = 0;
    analyze(argv[1], 0, &total_size);

    return 0;
}