//Code Llama-13B DATASET v1.0 Category: File handling ; Style: safe
/*
 * A safe file handling example program in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

int main(int argc, char *argv[]) {
    char *file_name;
    int fd;
    char buffer[1024];
    size_t count;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    file_name = argv[1];

    // Create a new file if it does not exist
    if ((fd = open(file_name, O_CREAT | O_EXCL, FILE_MODE)) == -1) {
        perror("open");
        return 1;
    }

    // Write data to the file
    count = sprintf(buffer, "Hello, world!\n");
    if (write(fd, buffer, count) != count) {
        perror("write");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    // Read data from the file
    if ((fd = open(file_name, O_RDONLY)) == -1) {
        perror("open");
        return 1;
    }
    count = read(fd, buffer, sizeof(buffer));
    if (count == -1) {
        perror("read");
        close(fd);
        return 1;
    }
    buffer[count] = '\0';
    printf("File contents: %s\n", buffer);

    // Close the file
    close(fd);

    return 0;
}