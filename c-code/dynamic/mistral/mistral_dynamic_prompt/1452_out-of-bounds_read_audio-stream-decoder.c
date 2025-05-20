#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

void read_and_decode_audio_stream(FILE *input_file) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char *data = malloc(BUFFER_SIZE * 3); // 3 bytes per sample for simplicity
    unsigned int bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (unsigned int i = 0; i < bytes_read; i++) {
            unsigned short sample = buffer[i];
            unsigned char left = sample & 0x00FF;
            unsigned char right = (sample & 0xFF00) >> 8;

            data[(i * 3)] = left;
            data[(i * 3) + 1] = right;
            data[(i * 3) + 2] = buffer[i]; // OOB read
        }
    }

    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_audio_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 2;
    }

    read_and_decode_audio_stream(input_file);
    fclose(input_file);

    return 0;
}
