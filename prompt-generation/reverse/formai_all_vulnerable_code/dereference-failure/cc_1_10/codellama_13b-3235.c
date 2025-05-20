//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_NAME_LENGTH 256

struct file_info {
    char name[MAX_FILE_NAME_LENGTH];
    struct stat stat;
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    char *source_dir = argv[1];
    char *dest_dir = argv[2];

    DIR *dir = opendir(source_dir);
    if (!dir) {
        fprintf(stderr, "Error opening directory %s: %s\n", source_dir, strerror(errno));
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char file_path[BUFFER_SIZE];
        snprintf(file_path, BUFFER_SIZE, "%s/%s", source_dir, entry->d_name);

        struct stat stat;
        if (lstat(file_path, &stat) != 0) {
            fprintf(stderr, "Error getting file info for %s: %s\n", file_path, strerror(errno));
            continue;
        }

        if (S_ISDIR(stat.st_mode)) {
            // ignore directories
            continue;
        }

        // create destination file
        char dest_file_path[BUFFER_SIZE];
        snprintf(dest_file_path, BUFFER_SIZE, "%s/%s", dest_dir, entry->d_name);
        int dest_fd = open(dest_file_path, O_CREAT | O_WRONLY, 0644);
        if (dest_fd == -1) {
            fprintf(stderr, "Error creating file %s: %s\n", dest_file_path, strerror(errno));
            continue;
        }

        // copy file contents
        int source_fd = open(file_path, O_RDONLY);
        if (source_fd == -1) {
            fprintf(stderr, "Error opening file %s: %s\n", file_path, strerror(errno));
            close(dest_fd);
            continue;
        }

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
            write(dest_fd, buffer, bytes_read);
        }

        close(source_fd);
        close(dest_fd);
    }

    closedir(dir);
    return 0;
}