//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// Function to synchronize files
void synchronize_files(char *source_file, char *destination_file) {
    int source_fd, destination_fd;
    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    // Open source file for reading
    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    // Open destination file for writing
    destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC);
    if (destination_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    // Get source file size
    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error getting source file size: %s\n", strerror(errno));
        exit(1);
    }

    // Set destination file size to source file size
    if (ftruncate(destination_fd, source_stat.st_size) == -1) {
        printf("Error setting destination file size: %s\n", strerror(errno));
        exit(1);
    }

    // Synchronize file contents
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    // Close files
    close(source_fd);
    close(destination_fd);

    printf("Files synchronized successfully!\n");
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    // Call function to synchronize files
    synchronize_files(argv[1], argv[2]);

    return 0;
}