//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    FILE *source_file = fopen(argv[1], "rb");
    if (source_file == NULL) {
        printf("Error: Could not open source file.\n");
        exit(1);
    }

    FILE *destination_file = fopen(argv[2], "wb");
    if (destination_file == NULL) {
        printf("Error: Could not open destination file.\n");
        exit(1);
    }

    struct stat source_stat;
    if (fstat(fileno(source_file), &source_stat) == -1) {
        printf("Error: Could not get source file size.\n");
        exit(1);
    }

    long file_size = source_stat.st_size;
    char buffer[BUFFER_SIZE];

    while (file_size > 0) {
        long bytes_to_read = file_size > BUFFER_SIZE? BUFFER_SIZE : file_size;
        long bytes_read = fread(buffer, 1, bytes_to_read, source_file);
        if (bytes_read!= bytes_to_read) {
            printf("Error: Could not read source file.\n");
            exit(1);
        }

        long bytes_written = fwrite(buffer, 1, bytes_read, destination_file);
        if (bytes_written!= bytes_read) {
            printf("Error: Could not write destination file.\n");
            exit(1);
        }

        file_size -= bytes_read;
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File synchronization completed successfully.\n");
    return 0;
}