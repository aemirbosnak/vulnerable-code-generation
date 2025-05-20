#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char *audio_data, int data_size) {
    unsigned char buffer[BUFFER_SIZE];
    int i, j;

    for (i = 0; i < data_size; i++) {
        buffer[i % BUFFER_SIZE] += audio_data[i];
    }

    for (j = 0; j < BUFFER_SIZE; j++) {
        printf("%d ", buffer[j]);
    }
}

int main() {
    unsigned char audio_data[] = {0x80, 0x7F, 0x00};
    int data_size = sizeof(audio_data);

    decode_audio(audio_data, data_size);

    return 0;
}
