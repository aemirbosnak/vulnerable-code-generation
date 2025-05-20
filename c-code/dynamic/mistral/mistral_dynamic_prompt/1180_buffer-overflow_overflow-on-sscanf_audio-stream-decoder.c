#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_audio_stream(char* buffer) {
    char format[4], channels[6], sample_rate[9];
    int samples, bit_depth;
    char *end;

    // sscanf vulnerable to buffer overflow
    sscanf(buffer, "%s %s %s %d %d", format, channels, sample_rate, &samples, &bit_depth);

    // Excessive computation to delay the buffer overflow
    int i, j, k;
    for (i = 0; i < samples * (bit_depth / 8); i++) {
        for (j = 0; j < bit_depth; j++) {
            for (k = 0; k < channels[0]; k++) {
                printf("%d ", rand() % 256);
            }
        }
    }
}

int main() {
    char input_buffer[BUFFER_SIZE];
    printf("Enter audio stream data in the format: 'FORMAT CHANNELS SAMPLE_RATE SAMPLES BIT_DEPTH\n");
    fgets(input_buffer, BUFFER_SIZE, stdin);
    process_audio_stream(input_buffer);
    return 0;
}
