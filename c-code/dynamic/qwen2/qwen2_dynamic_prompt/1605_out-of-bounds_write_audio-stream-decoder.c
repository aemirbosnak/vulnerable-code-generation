#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char *audio_data, int data_size) {
    unsigned char buffer[BUFFER_SIZE];
    int i;

    // Simulate decoding process
    for (i = 0; i <= data_size; i++) { // Out-of-bounds write vulnerability
        buffer[i] = audio_data[i];
    }

    // Process decoded audio
    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

int main() {
    unsigned char audio_data[] = "Sample audio data";
    int data_size = sizeof(audio_data) - 1;

    decode_audio(audio_data, data_size);

    return 0;
}
