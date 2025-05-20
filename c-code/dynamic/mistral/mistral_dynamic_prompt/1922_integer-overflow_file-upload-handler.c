#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_SIZE 1048576

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    off_t file_size;
    int i;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("File size exceeds allowed limit\n");
        fclose(file);
        return 1;
    }

    printf("File size: %lld bytes\n", file_size);

    for (i = 0; i < file_size;) {
        bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
        if (bytes_read <= 0) break;

        // Integer overflow example
        // Increasing 'i' by the product of the bytes_read and the max value of unsigned char (255)
        i += bytes_read * 255;

        fwrite(buffer, 1, bytes_read, stdout);
    }

    fclose(file);
    printf("File read successfully\n");
    return 0;
}
