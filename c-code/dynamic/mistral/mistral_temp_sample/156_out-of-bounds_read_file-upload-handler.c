#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 100000

void handle_file(FILE *fp) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        // Deliberate out-of-bounds read vulnerability
        for (size_t i = bytes_read; i < BUFFER_SIZE; ++i) {
            printf("%c", buffer[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("File too large\n");
        fclose(file);
        return 3;
    }

    handle_file(file);
    fclose(file);
    return 0;
}
