//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void encrypt_file(const char* input_file, const char* output_file, int key) {
    int input_fd, output_fd;
    char buffer[BUF_SIZE];
    size_t bytes_read, bytes_written;

    input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        exit(1);
    }

    output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (output_fd == -1) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        close(input_fd);
        exit(1);
    }

    while ((bytes_read = read(input_fd, buffer, BUF_SIZE)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "Error writing to output file: %s\n", strerror(errno));
            close(input_fd);
            close(output_fd);
            unlink(output_file);
            exit(1);
        }
    }

    close(input_fd);
    close(output_fd);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    int key = atoi(argv[3]);
    encrypt_file(argv[1], argv[2], key);

    return 0;
}