//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        printf("Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        printf("Error creating output file: %s\n", strerror(errno));
        close(input_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = 0;
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        int bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to output file: %s\n", strerror(errno));
            close(input_fd);
            close(output_fd);
            unlink(argv[2]);
            return 1;
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from input file: %s\n", strerror(errno));
        close(input_fd);
        close(output_fd);
        unlink(argv[2]);
        return 1;
    }

    close(input_fd);
    close(output_fd);

    printf("Data recovery successful!\n");
    return 0;
}