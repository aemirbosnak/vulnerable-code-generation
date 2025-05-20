#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 65536

void decode_audio_stream(char *input) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned int i, offset = 0;

    while ((i = read(0, buffer, BUFFER_SIZE)) != 0) {
        for (int j = 0; j < i; ++j) {
            offset = (offset + 1) % 256;
            buffer[j] = buffer[j] + buffer[offset];
        }
        write(1, buffer, i);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) != 0) {
        decode_audio_stream(buffer);
    }

    fclose(fp);
    return 0;
}
