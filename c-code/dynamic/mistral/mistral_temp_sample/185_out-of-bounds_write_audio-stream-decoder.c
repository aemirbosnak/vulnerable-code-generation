#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_SIZE 18

void decode_audio(char *buffer) {
    char header[HEADER_SIZE];
    char data[BUFFER_SIZE];
    char *ptr = data;

    // Copy header from buffer
    strncpy(header, buffer, HEADER_SIZE);
    header[HEADER_SIZE] = '\0';

    // Check if header is valid
    if (strstr(header, "WAV")) {
        // Read data after header
        strcpy(ptr, buffer + HEADER_SIZE);

        // Process data (intentionally out of bounds write vulnerability)
        for (int i = 0; i < 10000; i++) {
            ptr[i + BUFFER_SIZE] = 'A';
            ptr += sizeof(char);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fread(buffer, sizeof(char), BUFFER_SIZE, file)) {
        decode_audio(buffer);
    }

    fclose(file);
    return 0;
}
