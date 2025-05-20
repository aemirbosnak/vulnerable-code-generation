//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

int main() {
    // Open a file in read-write mode
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write some data to the file
    char buffer[1024];
    memset(buffer, 'A', 1024);
    write(fd, buffer, 1024);

    // Get the file's current size
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1) {
        perror("Error seeking to end of file");
        return 1;
    }

    // Set the file's size to 2x the current size
    if (ftruncate(fd, file_size * 2) == -1) {
        perror("Error resizing file");
        return 1;
    }

    // Map the file into memory
    void* map = mmap(NULL, file_size * 2, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("Error mapping file");
        return 1;
    }

    // Fill the mapped memory with a pattern
    char* pattern = "This is a test";
    memcpy(map, pattern, strlen(pattern));

    // Unmap the file from memory
    munmap(map, file_size * 2);

    // Close the file
    close(fd);

    // Open the file again in read-only mode
    fd = open("example.txt", O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the contents of the file
    char buffer2[1024];
    read(fd, buffer2, 1024);

    // Print the contents of the file
    printf("Contents of file: %s\n", buffer2);

    // Close the file
    close(fd);

    return 0;
}