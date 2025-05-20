//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

// This is the main function of the program.
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments.
    if (argc < 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Get the source and destination directories.
    char *source = argv[1];
    char *destination = argv[2];

    // Open the source directory.
    DIR *source_dir = opendir(source);
    if (source_dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Create the destination directory if it doesn't exist.
    if (mkdir(destination, 0755) == -1) {
        perror("mkdir");
        return 1;
    }

    // Iterate over the files in the source directory.
    struct dirent *entry;
    while ((entry = readdir(source_dir)) != NULL) {
        // Skip the current and parent directories.
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the source and destination paths.
        char *source_path = malloc(strlen(source) + strlen(entry->d_name) + 2);
        sprintf(source_path, "%s/%s", source, entry->d_name);
        char *destination_path = malloc(strlen(destination) + strlen(entry->d_name) + 2);
        sprintf(destination_path, "%s/%s", destination, entry->d_name);

        // Check if the source file is a regular file.
        struct stat statbuf;
        if (lstat(source_path, &statbuf) == -1) {
            perror("lstat");
            return 1;
        }
        if (!S_ISREG(statbuf.st_mode)) {
            free(source_path);
            free(destination_path);
            continue;
        }

        // Open the source file.
        int source_fd = open(source_path, O_RDONLY);
        if (source_fd == -1) {
            perror("open");
            return 1;
        }

        // Create the destination file.
        int destination_fd = open(destination_path, O_WRONLY | O_CREAT | O_TRUNC, statbuf.st_mode);
        if (destination_fd == -1) {
            perror("open");
            return 1;
        }

        // Copy the data from the source file to the destination file.
        char buffer[4096];
        ssize_t bytes_read;
        while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
            if (write(destination_fd, buffer, bytes_read) == -1) {
                perror("write");
                return 1;
            }
        }

        // Close the source and destination files.
        close(source_fd);
        close(destination_fd);

        // Free the allocated memory.
        free(source_path);
        free(destination_path);
    }

    // Close the source directory.
    closedir(source_dir);

    return 0;
}