//Falcon-180B DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

int main() {
    int fd;
    char filename[50] = "example.txt";
    char buffer[BUF_SIZE];
    int bytes_read;
    int bytes_written;

    // Open the file for writing
    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    // Write some data to the file
    strcpy(buffer, "This is a test file\n");
    bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written == -1) {
        printf("Error writing to file: %s\n", strerror(errno));
        exit(1);
    }

    // Close the file
    close(fd);

    // Open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    // Read the data from the file
    bytes_read = read(fd, buffer, BUF_SIZE);
    if (bytes_read == -1) {
        printf("Error reading from file: %s\n", strerror(errno));
        exit(1);
    }

    // Print the data read from the file
    printf("Data read from file:\n%s", buffer);

    // Close the file
    close(fd);

    return 0;
}