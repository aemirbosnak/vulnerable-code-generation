//Falcon-180B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    int fd = 0;
    char *filename = argv[1];
    char buffer[MAX_LINE_SIZE];
    ssize_t bytes_read;
    int new_fd;
    char new_filename[MAX_LINE_SIZE];
    int count = 1;

    // Open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // Loop through the file, reading lines and writing them to a new file
    while ((bytes_read = read(fd, buffer, MAX_LINE_SIZE)) > 0) {
        buffer[bytes_read - 1] = '\0';
        printf("Original line: %s\n", buffer);

        // Create a new filename with a suffix indicating the line number
        sprintf(new_filename, "%s_%d.txt", filename, count);

        // Open the new file for writing
        new_fd = open(new_filename, O_WRONLY | O_CREAT, 0644);
        if (new_fd == -1) {
            printf("Error creating file: %s\n", strerror(errno));
            return 1;
        }

        // Write the line to the new file
        if (write(new_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error writing to file: %s\n", strerror(errno));
            return 1;
        }

        // Close the new file
        close(new_fd);

        // Increment the line count
        count++;
    }

    // Close the original file
    close(fd);

    return 0;
}