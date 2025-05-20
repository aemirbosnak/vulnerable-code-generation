//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SECRETS_FILE "secrets.txt"

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void) {
    int fd;
    struct stat st;

    _Pragma("GCC diagnostic push")
    _Pragma("GCC diagnostic ignored \"-Wold-style-declaration\"")
    fd = open(SECRETS_FILE, O_RDONLY);
    _Pragma("GCC diagnostic pop")

    if (fd < 0) {
        die("Could not open file.");
    }

    if (fstat(fd, &st) < 0) {
        die("Error getting file status.");
    }

    if (st.st_size <= 0) {
        close(fd);
        die("File is empty or not a regular file!");
    }

    char *buf = malloc(st.st_size + 1);
    if (buf == NULL) {
        close(fd);
        die("Could not allocate memory for buffer.");
    }

    ssize_t bytes_read = read(fd, buf, st.st_size);
    if (bytes_read < 0) {
        free(buf);
        close(fd);
        die("Error reading file.");
    }

    buf[bytes_read] = '\0';

    printf("Contents of %s:\n", SECRETS_FILE);
    puts(buf);

    free(buf);
    close(fd);

    return EXIT_SUCCESS;
}