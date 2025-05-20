//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 4096

// The main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <source file> <destination file> <sync mode>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the source file
    int fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Open the destination file
    int fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dst == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get the sync mode
    int sync_mode = atoi(argv[3]);

    // Set the file offset
    if (lseek(fd_src, 0, SEEK_SET) == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }
    if (lseek(fd_dst, 0, SEEK_SET) == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    // Synchronize the files
    int bytes_read;
    char buf[BUFSIZE];
    while ((bytes_read = read(fd_src, buf, BUFSIZE)) > 0) {
        if (write(fd_dst, buf, bytes_read) != bytes_read) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Sync the destination file if necessary
        if (sync_mode == 1) {
            if (fsync(fd_dst) == -1) {
                perror("fsync");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Close the files
    if (close(fd_src) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    if (close(fd_dst) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}