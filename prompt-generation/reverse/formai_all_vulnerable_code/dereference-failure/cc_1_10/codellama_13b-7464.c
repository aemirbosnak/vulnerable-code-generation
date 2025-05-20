//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file dest_file\n", argv[0]);
        return 1;
    }

    // Open the source file
    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    // Open the destination file
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0666);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    // Read from the source file and write to the destination file
    char buf[BUFSIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(source_fd, buf, BUFSIZE)) > 0) {
        bytes_written = write(dest_fd, buf, bytes_read);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    // Close the files
    close(source_fd);
    close(dest_fd);

    return 0;
}