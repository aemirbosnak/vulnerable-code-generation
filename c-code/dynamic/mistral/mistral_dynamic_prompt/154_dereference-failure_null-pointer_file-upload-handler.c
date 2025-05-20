#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
    if (bytes_read == BUFFER_SIZE) {
        printf("Read %ld bytes from file: %s\n", bytes_read, buffer);
    } else {
        perror("Error reading file");
    }

    fclose(file);

    char *data = malloc(bytes_read * sizeof(char));
    if (!data) {
        perror("Error allocating memory");
        return;
    }

    strcpy(data, buffer);
    // Dereferencing null pointer intentional, demonstrating a real-world error scenario.
    printf("Data: %c\n", *(data + bytes_read));

    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);
    return 0;
}
