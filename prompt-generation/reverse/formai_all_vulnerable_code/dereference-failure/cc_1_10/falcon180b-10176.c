//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int fd, i;
    char *buf;
    int size;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <file_name> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open the input file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    // Get the size of the input file
    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    // Allocate buffer to hold file content
    buf = malloc(size);

    // Read the file content into the buffer
    if (read(fd, buf, size)!= size) {
        printf("Error reading file: %s\n", argv[1]);
        exit(1);
    }

    // Close the input file
    close(fd);

    // Open the output file
    fd = open(argv[2], O_WRONLY | O_CREAT);
    if (fd == -1) {
        printf("Error creating file: %s\n", argv[2]);
        exit(1);
    }

    // Write the file content to the output file
    for (i = 0; i < size; i += BUF_SIZE) {
        int to_write = BUF_SIZE;
        if (i + BUF_SIZE > size) {
            to_write = size - i;
        }
        if (write(fd, buf + i, to_write)!= to_write) {
            printf("Error writing file: %s\n", argv[2]);
            exit(1);
        }
    }

    // Close the output file
    close(fd);

    printf("File recovery successful!\n");
    return 0;
}