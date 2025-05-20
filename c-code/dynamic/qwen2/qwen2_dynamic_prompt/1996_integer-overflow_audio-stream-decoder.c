#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char *audio_data, int data_size) {
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    int i, j;
    for (i = 0; i < data_size; i++) {
        buffer[i % BUFFER_SIZE] += audio_data[i];
    }

    for (j = 0; j < BUFFER_SIZE; j++) {
        printf("%d ", buffer[j]);
    }
    printf("\n");

    free(buffer);
}

int main() {
    unsigned char audio_data[BUFFER_SIZE * 2];
    for (int k = 0; k < BUFFER_SIZE * 2; k++) {
        audio_data[k] = k % 256;
    }

    decode_audio(audio_data, BUFFER_SIZE * 2);

    return 0;
}
