//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_usage() {
    printf("Usage:./recover <file_name> <output_file>\n");
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    char *file_name = argv[1];
    char *output_file = argv[2];

    int fd_in, fd_out;
    char *buffer = malloc(BUF_SIZE);

    fd_in = open(file_name, O_RDONLY);
    if (fd_in == -1) {
        printf("Error: File not found\n");
        return 1;
    }

    fd_out = open(output_file, O_WRONLY | O_CREAT, 0644);
    if (fd_out == -1) {
        printf("Error: File creation failed\n");
        return 1;
    }

    int bytes_read = 0;
    int bytes_written = 0;

    while ((bytes_read = read(fd_in, buffer, BUF_SIZE)) > 0) {
        if (bytes_read % 512 == 0) {
            printf("Recovered %d sectors\n", bytes_read / 512);
        }
        if (write(fd_out, buffer, bytes_read)!= bytes_read) {
            printf("Error: File write failed\n");
            return 1;
        }
        bytes_written += bytes_read;
    }

    printf("Recovered %d sectors, %d bytes written\n", bytes_read / 512, bytes_written);

    close(fd_in);
    close(fd_out);

    return 0;
}