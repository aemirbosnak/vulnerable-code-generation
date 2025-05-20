//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Function to read a file and print its contents
void read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read = read(fd, buffer, MAX_BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("Error reading from file");
        close(fd);
        return;
    }

    buffer[bytes_read] = '\0';
    printf("File contents: %s\n", buffer);

    close(fd);
}

// Function to write a file and print its contents
void write_file(const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    gets(buffer); // Read input from user

    size_t bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return;
    }

    printf("File contents written: %s\n", buffer);

    close(fd);
}

int main() {
    // Example usage of read_file and write_file functions
    char filename[MAX_FILE_NAME_LENGTH];

    // Read a file and print its contents
    read_file("example.txt");

    // Create a new file and write some contents to it
    write_file("new_file.txt");

    // Read the contents of the new file and print them
    read_file("new_file.txt");

    return 0;
}