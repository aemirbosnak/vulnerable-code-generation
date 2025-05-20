//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_path> <output_file>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    char *output_file = argv[2];

    int fd_in = open(file_path, O_RDONLY);
    if (fd_in == -1) {
        printf("Error opening input file.\n");
        return 1;
    }

    struct stat stat_buf;
    fstat(fd_in, &stat_buf);
    int file_size = stat_buf.st_size;

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    FILE *fd_out = fopen(output_file, "wb");
    if (fd_out == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    int bytes_read = 0;
    while (bytes_read < file_size) {
        int bytes_to_read = BUFFER_SIZE;
        if (bytes_to_read > file_size - bytes_read) {
            bytes_to_read = file_size - bytes_read;
        }

        int bytes_written = 0;
        while (bytes_written < bytes_to_read) {
            int result = read(fd_in, buffer + bytes_written, bytes_to_read - bytes_written);
            if (result == -1) {
                printf("Error reading input file.\n");
                return 1;
            }

            if (result == 0) {
                break;
            }

            bytes_written += result;
        }

        if (bytes_written == 0) {
            break;
        }

        int result = fwrite(buffer, bytes_written, 1, fd_out);
        if (result!= 1) {
            printf("Error writing output file.\n");
            return 1;
        }

        bytes_read += bytes_written;
    }

    fclose(fd_out);
    free(buffer);
    close(fd_in);

    printf("Data recovery successful!\n");
    return 0;
}