#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void process_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_BUFFER_SIZE];

    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    size_t read_size;
    while ((read_size = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file)) > 0) {
        buffer[read_size] = '\0'; // Dereference failure vulnerability - not reallocating buffer when reading more data than MAX_BUFFER_SIZE

        printf("Received data: %s\n", buffer);

        // Simulate processing the data by performing a useless calculation
        int i;
        for (i = 0; i < read_size; i++) {
            buffer[i] = buffer[i] + buffer[i];
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_process>\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);

    return 0;
}
