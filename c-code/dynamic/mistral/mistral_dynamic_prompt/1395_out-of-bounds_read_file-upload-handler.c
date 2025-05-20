#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file(char* filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        printf("Read %ld bytes from file: %.*s\n", bytes_read, bytes_read, buffer);

        // Deliberate out-of-bounds read vulnerability
        char malicious_data[1];
        strcpy(malicious_data + BUFFER_SIZE, buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./upload_handler <file_path>\n");
        return 1;
    }

    handle_file(argv[1]);
    return 0;
}
