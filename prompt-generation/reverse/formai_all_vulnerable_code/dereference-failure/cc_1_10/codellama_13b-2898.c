//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: calm
/*
 * C Disk Space Analyzer Example Program
 *
 * Written by [Your Name]
 *
 * This program will analyze the disk space usage of a directory and all its subdirectories.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LENGTH 1024

/* Structure to hold information about a directory and its subdirectories */
typedef struct {
    char path[MAX_PATH_LENGTH];
    int total_size;
    int num_subdirs;
} DirectoryInfo;

/* Function to recursively analyze a directory and its subdirectories */
void analyze_directory(DirectoryInfo *dir_info, const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    /* Open the directory */
    dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Error: unable to open directory %s\n", path);
        exit(1);
    }

    /* Read the directory entries */
    while ((entry = readdir(dir)) != NULL) {
        /* Ignore the current directory (.) and the parent directory (..) */
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        /* Get the full path of the entry */
        snprintf(dir_info->path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        /* Get the file status */
        if (stat(dir_info->path, &statbuf) == -1) {
            fprintf(stderr, "Error: unable to get status of file %s\n", dir_info->path);
            exit(1);
        }

        /* If the entry is a directory, recursively analyze it */
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(dir_info, dir_info->path);
        } else {
            /* If the entry is a file, add its size to the total */
            dir_info->total_size += statbuf.st_size;
        }
    }

    /* Close the directory */
    closedir(dir);
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Check the number of arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    /* Declare a structure to hold information about the directory */
    DirectoryInfo dir_info;

    /* Initialize the structure */
    dir_info.total_size = 0;
    dir_info.num_subdirs = 0;

    /* Analyze the directory */
    analyze_directory(&dir_info, argv[1]);

    /* Print the results */
    printf("Total size of directory %s: %d bytes\n", argv[1], dir_info.total_size);
    printf("Number of subdirectories: %d\n", dir_info.num_subdirs);

    return 0;
}