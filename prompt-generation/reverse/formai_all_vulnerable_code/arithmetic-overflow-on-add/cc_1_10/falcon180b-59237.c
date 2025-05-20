//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage:./program <filename> <output_file>\n");
        return 1;
    }

    char *filename = argv[1];
    char *output_file = argv[2];

    int fd_in = open(filename, O_RDONLY);
    if (fd_in == -1) {
        printf("Error opening input file: %s\n", filename);
        return 1;
    }

    struct stat stat_buf;
    if (fstat(fd_in, &stat_buf) == -1) {
        printf("Error getting file size: %s\n", filename);
        close(fd_in);
        return 1;
    }

    size_t file_size = stat_buf.st_size;

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        close(fd_in);
        return 1;
    }

    int fd_out = open(output_file, O_CREAT | O_WRONLY, 0644);
    if (fd_out == -1) {
        printf("Error opening output file: %s\n", output_file);
        free(buffer);
        close(fd_in);
        return 1;
    }

    int bytes_read = 0;
    while (bytes_read < file_size) {
        int bytes_to_read = file_size - bytes_read;
        if (bytes_to_read > BUFFER_SIZE) {
            bytes_to_read = BUFFER_SIZE;
        }

        int bytes_written = write(fd_out, buffer, bytes_to_read);
        if (bytes_written == -1) {
            printf("Error writing to output file: %s\n", output_file);
            free(buffer);
            close(fd_in);
            close(fd_out);
            return 1;
        }

        bytes_read += bytes_written;
    }

    free(buffer);
    close(fd_in);
    close(fd_out);

    printf("File %s successfully recovered to %s\n", filename, output_file);

    return 0;
}