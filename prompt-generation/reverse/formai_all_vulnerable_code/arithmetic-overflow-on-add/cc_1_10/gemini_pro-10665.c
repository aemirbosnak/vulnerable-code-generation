//GEMINI-pro DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define DELIM_SIZE 3
#define MAX_SUBSTR_SIZE 1024

int main(int argc, char *argv[]) {
    // Validate arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Get file size
    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        fprintf(stderr, "Error getting file size: %s\n", strerror(errno));
        close(fd);
        return EXIT_FAILURE;
    }

    // Allocate buffer for file contents
    char *buf = malloc(statbuf.st_size + DELIM_SIZE);
    if (buf == NULL) {
        fprintf(stderr, "Error allocating buffer: %s\n", strerror(errno));
        close(fd);
        return EXIT_FAILURE;
    }

    // Read file contents into buffer
    ssize_t bytes_read = read(fd, buf, statbuf.st_size);
    if (bytes_read == -1) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        free(buf);
        close(fd);
        return EXIT_FAILURE;
    }

    // Close file
    close(fd);

    // Append delimiter to buffer
    memcpy(buf + bytes_read, "\n", DELIM_SIZE);

    // Allocate buffer for substrings
    char *substr = malloc(MAX_SUBSTR_SIZE);
    if (substr == NULL) {
        fprintf(stderr, "Error allocating buffer: %s\n", strerror(errno));
        free(buf);
        return EXIT_FAILURE;
    }

    // Tokenize buffer and print substrings
    char *p = buf;
    while (*p != '\0') {
        // Find next delimiter
        char *q = strchr(p, '\n');
        if (q == NULL) {
            q = p + strlen(p);
        }

        // Extract substring
        size_t substr_len = q - p;
        if (substr_len > MAX_SUBSTR_SIZE) {
            fprintf(stderr, "Error: Substring too long: %lu\n", substr_len);
            free(buf);
            free(substr);
            return EXIT_FAILURE;
        }
        memcpy(substr, p, substr_len);
        substr[substr_len] = '\0';

        // Print substring
        printf("%s\n", substr);

        // Advance pointer to next delimiter
        p = q + 1;
    }

    // Free buffers
    free(buf);
    free(substr);

    return EXIT_SUCCESS;
}