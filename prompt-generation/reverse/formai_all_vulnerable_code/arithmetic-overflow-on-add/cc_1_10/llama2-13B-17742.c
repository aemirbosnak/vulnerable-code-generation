//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Function to read a file into a memory block
void read_file(const char *filename, char **buffer) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Get the file size
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Error getting file size");
        close(fd);
        return;
    }

    // Calculate the memory block size
    size_t mem_size = file_stat.st_size + BUFFER_SIZE;
    void *mem_block = mmap(NULL, mem_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mem_block == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        return;
    }

    // Successfully read the file into memory
    *buffer = (char *)mem_block;
    close(fd);
}

// Function to write a file from a memory block
void write_file(const char *filename, const char *buffer) {
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Write the memory block to the file
    size_t written = write(fd, buffer, strlen(buffer));
    if (written == -1) {
        perror("Error writing to file");
        close(fd);
        return;
    }

    // Successfully wrote the file
    close(fd);
}

int main() {
    char *buffer;
    read_file("example.txt", &buffer);
    printf("Read file contents: %s\n", buffer);

    char new_buffer[] = "New file contents\n";
    write_file("example.txt", new_buffer);

    return 0;
}