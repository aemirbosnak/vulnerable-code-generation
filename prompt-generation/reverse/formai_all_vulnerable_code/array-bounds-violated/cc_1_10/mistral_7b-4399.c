//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1048576

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int is_valid_magic(int fd, char *magic) {
    char buffer[strlen(magic) + 1];
    ssize_t n = read(fd, buffer, strlen(magic) + 1);

    if (n <= 0) {
        return 0;
    }

    buffer[n] = '\0';

    if (strcmp(magic, buffer) != 0) {
        return 0;
    }

    return 1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input output\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input = argv[1];
    char *output = argv[2];

    int input_fd = open(input, O_RDONLY);

    if (input_fd < 0) {
        die("Failed to open input file");
    }

    int output_fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (output_fd < 0) {
        die("Failed to create output file");
    }

    char magic[] = {"MY_MAGIC_NUMBER"};

    if (!is_valid_magic(input_fd, magic)) {
        close(input_fd);
        close(output_fd);
        unlink(output);
        fprintf(stderr, "Input file is not valid\n");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    ssize_t n;

    while ((n = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(output_fd, buffer, n) != n) {
            die("Failed to write to output file");
        }
    }

    if (n < 0) {
        die("Failed to read from input file");
    }

    close(input_fd);
    close(output_fd);

    printf("Data recovery successful\n");

    return EXIT_SUCCESS;
}