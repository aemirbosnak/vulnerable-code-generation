//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096

struct file_info {
    char *filename;
    off_t file_size;
    off_t file_position;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Check if the file exists
    if (!access(argv[1], F_OK)) {
        // Open the file in read-only mode
        int fd = open(argv[1], O_RDONLY, 0);
        if (fd == -1) {
            perror("Error opening file");
            return 1;
        }

        // Get the file size
        struct stat stats;
        fstat(fd, &stats);
        off_t file_size = stats.st_size;

        // Calculate the file position based on the input argument
        off_t file_position = strtol(argv[2], NULL, 10);
        if (file_position > file_size) {
            file_position = file_size;
        }

        // Mmap the file to memory
        void *file_ptr = mmap(NULL, file_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, file_position);
        if (file_ptr == MAP_FAILED) {
            perror("Error mmapping file");
            close(fd);
            return 1;
        }

        // Print the file contents
        char buffer[BUFFER_SIZE];
        size_t bytes_read = read(fd, buffer, BUFFER_SIZE);
        while (bytes_read > 0) {
            printf("%s", buffer);
            bytes_read = read(fd, buffer, BUFFER_SIZE);
        }

        // Unmap the file from memory
        munmap(file_ptr, file_size);

        close(fd);
    } else {
        printf("Error: File not found\n");
    }

    return 0;
}