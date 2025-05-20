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
    size_t bytes_read;

    if (!file) {
        perror("Error opening file");
        return;
    }

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        printf("Read %ld bytes from file: %s\n", bytes_read, buffer);

        // Intentionally read past the end of the buffer
        printf("%c", buffer[BUFFER_SIZE]);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);
    return 0;
}
