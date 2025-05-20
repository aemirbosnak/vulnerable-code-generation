//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to get the size of a file
long get_file_size(char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    return st.st_size;
}

// Function to get the size of a directory
long get_dir_size(char *path) {
    DIR *dir;
    struct dirent *entry;
    long size = 0;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            size += get_dir_size(full_path);
        } else {
            size += get_file_size(full_path);
        }

        free(full_path);
    }

    closedir(dir);

    return size;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <start_path> <end_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // The start directory is a 5 GB file named bigfile.txt
    long start_size = get_file_size(argv[1]);

    // The end directory is the root directory
    long end_size = get_dir_size(argv[2]);

    // The difference between the start and end directory sizes is the total size of the deleted files
    long deleted_size = end_size - start_size;

    printf("The total size of the deleted files is %ld bytes.\n", deleted_size);

    return EXIT_SUCCESS;
}