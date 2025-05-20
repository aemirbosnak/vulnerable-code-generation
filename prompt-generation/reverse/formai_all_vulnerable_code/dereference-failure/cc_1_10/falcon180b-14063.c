//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    int source_fd = open(argv[1], O_RDONLY);
    if(source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    int destination_fd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(destination_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = 0;
    while((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if(write(destination_fd, buffer, bytes_read)!= bytes_read) {
            fprintf(stderr, "Error writing to destination file\n");
            close(source_fd);
            close(destination_fd);
            exit(1);
        }
    }

    if(bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        close(source_fd);
        close(destination_fd);
        exit(1);
    }

    close(source_fd);
    close(destination_fd);

    fprintf(stdout, "File synchronization completed successfully!\n");
    return 0;
}