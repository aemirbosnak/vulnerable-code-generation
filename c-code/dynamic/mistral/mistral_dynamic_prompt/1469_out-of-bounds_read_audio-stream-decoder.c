#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PACKET_SIZE 256

void decode_wav(char* data, size_t size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    char* buffer = (char*) malloc(BUFFER_SIZE);
    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, file);

    if (bytes_read > BUFFER_SIZE) {
        printf("Oversized buffer while reading file\n");
        return 1;
    }

    decode_wav(buffer, bytes_read);
    free(buffer);

    fclose(file);
    return 0;
}

void decode_wav(char* data, size_t size) {
    size_t packet_index = 0;
    while (packet_index + PACKET_SIZE <= size) {
        // Out of bounds read vulnerability occurs here
        printf("%.*s\n", PACKET_SIZE, data + packet_index);
        packet_index += PACKET_SIZE;
    }
}
