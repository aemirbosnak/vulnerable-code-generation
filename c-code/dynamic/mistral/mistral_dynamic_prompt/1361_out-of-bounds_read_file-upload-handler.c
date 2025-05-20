#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    char *data = malloc(BUFFER_SIZE);
    size_t bytes_read;

    if (!file) {
        perror("Error opening file");
        return;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        strcpy(data, buffer);
        printf("Processed %ld bytes from file %s\n", bytes_read, filename);

        // Out of bounds read vulnerability: the buffer is overwritten without proper handling of the data size
        printf("%s", data + bytes_read);
    }

    free(data);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
