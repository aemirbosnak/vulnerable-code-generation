#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1000000

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *filename;
    long file_size;
    long bytes_read;

    if (argc != 3) {
        printf("Usage: %s <filename> <file_size>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    file_size = atol(argv[2]);

    file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, file_size, SEEK_SET);
    printf("Writing to file...\n");

    while (file_size > BUFFER_SIZE) {
        bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
        fwrite(buffer, 1, bytes_read, stdout);
        file_size -= bytes_read;
    }

    bytes_read = fread(buffer, 1, file_size, file);
    fwrite(buffer, 1, bytes_read, stdout);

    fclose(file);
    printf("File upload completed.\n");

    return 0;
}
