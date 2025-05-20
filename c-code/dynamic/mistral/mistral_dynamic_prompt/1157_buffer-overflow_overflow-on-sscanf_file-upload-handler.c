#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 50000

void process_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    unsigned int bytes_read;
    unsigned int total_bytes = 0;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        total_bytes += bytes_read;

        if (total_bytes > MAX_FILE_SIZE) {
            fprintf(stderr, "Error: File %s exceeds the maximum allowed size of %d bytes.\n", filename, MAX_FILE_SIZE);
            fclose(file);
            return;
        }

        // Here lies the deliberate buffer overflow vulnerability
        char size[10];
        sscanf(buffer, "%s%n", size, &bytes_read);
        printf("File size: %s bytes\n", size);
        // Process file content...
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);
    return 0;
}
