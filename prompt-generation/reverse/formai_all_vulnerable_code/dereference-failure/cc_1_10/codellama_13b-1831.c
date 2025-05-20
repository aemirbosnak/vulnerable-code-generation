//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
/*
 * disk_space.c
 *
 * This program provides a simple way to analyze the disk space usage of a given directory.
 * It uses dynamic memory allocation to store the list of files and their sizes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

/* Structure to store file information */
struct file_info {
    char* name;
    off_t size;
};

/* Function to recursively walk through a directory and store the list of files and their sizes */
void walk_directory(char* directory, struct file_info** files, int* num_files) {
    DIR* dir;
    struct dirent* entry;
    struct stat statbuf;

    /* Open the directory */
    dir = opendir(directory);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", directory);
        return;
    }

    /* Walk through the directory */
    while ((entry = readdir(dir)) != NULL) {
        /* Skip '.' and '..' entries */
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        /* Get the full path of the file */
        char* path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
        strcpy(path, directory);
        strcat(path, "/");
        strcat(path, entry->d_name);

        /* Get the file information */
        if (lstat(path, &statbuf) == -1) {
            fprintf(stderr, "Error getting file information: %s\n", path);
            free(path);
            continue;
        }

        /* Add the file to the list */
        struct file_info* file = malloc(sizeof(struct file_info));
        file->name = path;
        file->size = statbuf.st_size;
        files[*num_files] = file;
        (*num_files)++;

        /* Recursively walk through subdirectories */
        if (S_ISDIR(statbuf.st_mode)) {
            walk_directory(path, files, num_files);
        }
    }

    /* Close the directory */
    closedir(dir);
}

/* Function to print the list of files and their sizes */
void print_files(struct file_info* files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%ld\n", files[i].name, files[i].size);
    }
}

int main(int argc, char* argv[]) {
    /* Check the number of arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    /* Walk through the directory and store the list of files and their sizes */
    struct file_info* files = NULL;
    int num_files = 0;
    walk_directory(argv[1], &files, &num_files);

    /* Print the list of files and their sizes */
    print_files(files, num_files);

    /* Free the memory */
    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return 0;
}