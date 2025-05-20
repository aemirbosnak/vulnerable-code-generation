//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1024 * 1024 * 50  // 50 MB
#define BUFFER_SIZE 1024 * 1024 * 2    // 2 MB

// Structure to hold file metadata
struct file_info {
    char *filename;
    size_t file_size;
    off_t file_position;
};

// Function to read a file and return its metadata
struct file_info read_file(const char *filename) {
    struct file_info fi;
    int fd;
    size_t bytes_read;

    // Open the file in read mode
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return fi;
    }

    // Read the file size
    bytes_read = read(fd, &fi.file_size, sizeof(fi.file_size));
    if (bytes_read != sizeof(fi.file_size)) {
        perror("Error reading file size");
        close(fd);
        return fi;
    }

    // Seek to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    // Read the file position
    bytes_read = read(fd, &fi.file_position, sizeof(fi.file_position));
    if (bytes_read != sizeof(fi.file_position)) {
        perror("Error reading file position");
        close(fd);
        return fi;
    }

    // Close the file
    close(fd);

    return fi;
}

// Function to write a file and update its metadata
void write_file(const char *filename, struct file_info fi) {
    int fd;
    size_t bytes_written;

    // Open the file in write mode
    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Write the file size
    bytes_written = write(fd, &fi.file_size, sizeof(fi.file_size));
    if (bytes_written != sizeof(fi.file_size)) {
        perror("Error writing file size");
        close(fd);
        return;
    }

    // Seek to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    // Write the file position
    bytes_written = write(fd, &fi.file_position, sizeof(fi.file_position));
    if (bytes_written != sizeof(fi.file_position)) {
        perror("Error writing file position");
        close(fd);
        return;
    }

    // Close the file
    close(fd);
}

int main() {
    // Get the file name from the user
    char filename[1024];
    printf("Enter the name of the file: ");
    fgets(filename, sizeof(filename), stdin);

    // Read the file and print its metadata
    struct file_info fi = read_file(filename);
    printf("File size: %zu bytes\n", fi.file_size);
    printf("File position: %ld bytes\n", fi.file_position);

    // Update the file metadata
    fi.file_size += 1024;  // Increase the file size by 1 KB
    fi.file_position += 1024;  // Increase the file position by 1 KB

    // Write the updated metadata to the file
    write_file(filename, fi);

    return 0;
}