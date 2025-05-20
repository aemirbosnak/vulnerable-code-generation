//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct stat input_stat;
    if (fstat(input_fd, &input_stat) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    char *buffer = malloc(input_stat.st_size);
    if (buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (read(input_fd, buffer, input_stat.st_size) != input_stat.st_size) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(input_fd);

    // Scan the buffer for deleted files
    int offset = 0;
    while (offset < input_stat.st_size) {
        // Check if the current block is a deleted file
        if (buffer[offset] == 0xE5) {
            // Read the file size
            int file_size = 0;
            for (int i = 0; i < 4; i++) {
                file_size |= (buffer[offset + i + 1] << (8 * i));
            }

            // Read the file name
            char file_name[256];
            memset(file_name, 0, sizeof(file_name));
            for (int i = 0; i < 256; i++) {
                file_name[i] = buffer[offset + i + 5];
                if (buffer[offset + i + 5] == 0) {
                    break;
                }
            }

            // Write the file to the output file
            if (write(output_fd, buffer + offset, file_size) != file_size) {
                perror("write");
                return EXIT_FAILURE;
            }

            // Update the offset
            offset += file_size;
        } else {
            // Skip the current block
            offset += 512;
        }
    }

    close(output_fd);

    free(buffer);

    return EXIT_SUCCESS;
}