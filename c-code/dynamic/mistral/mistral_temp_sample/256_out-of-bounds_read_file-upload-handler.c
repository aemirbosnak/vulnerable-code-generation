#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Reading file: %s\n", filename);

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        printf("Data read: ");
        for (size_t i = 0; i < bytes_read; ++i) {
            printf("%c", buffer[i]);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
