//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH_LEN 256
#define MAX_FILENAME_LEN 256

typedef struct {
    char path[MAX_PATH_LEN];
    char filename[MAX_FILENAME_LEN];
    struct stat st;
} FileInfo;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Get source and destination paths
    char *source = argv[1];
    char *destination = argv[2];

    // Open source directory
    DIR *source_dir = opendir(source);
    if (!source_dir) {
        printf("Error: Unable to open source directory: %s\n", strerror(errno));
        return 1;
    }

    // Open destination directory
    DIR *destination_dir = opendir(destination);
    if (!destination_dir) {
        printf("Error: Unable to open destination directory: %s\n", strerror(errno));
        return 1;
    }

    // Iterate over files in source directory
    FileInfo file_info;
    struct dirent *entry;
    while ((entry = readdir(source_dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get file information
        snprintf(file_info.path, MAX_PATH_LEN, "%s/%s", source, entry->d_name);
        if (stat(file_info.path, &file_info.st) != 0) {
            printf("Error: Unable to get file information: %s\n", strerror(errno));
            continue;
        }

        // Check if file is a regular file
        if (!S_ISREG(file_info.st.st_mode)) {
            continue;
        }

        // Copy file to destination directory
        char destination_path[MAX_PATH_LEN];
        snprintf(destination_path, MAX_PATH_LEN, "%s/%s", destination, entry->d_name);
        if (copy_file(file_info.path, destination_path) != 0) {
            printf("Error: Unable to copy file: %s\n", strerror(errno));
            continue;
        }
    }

    // Close directories
    closedir(source_dir);
    closedir(destination_dir);

    return 0;
}

int copy_file(char *source, char *destination) {
    // Open source file
    int source_fd = open(source, O_RDONLY);
    if (source_fd < 0) {
        return -1;
    }

    // Open destination file
    int destination_fd = open(destination, O_WRONLY | O_CREAT, 0644);
    if (destination_fd < 0) {
        close(source_fd);
        return -1;
    }

    // Copy file contents
    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        if (write(destination_fd, buffer, bytes_read) != bytes_read) {
            close(source_fd);
            close(destination_fd);
            return -1;
        }
    }

    // Close files
    close(source_fd);
    close(destination_fd);

    return 0;
}