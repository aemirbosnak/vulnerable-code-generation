#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define BITS_PER_SAMPLE 16
#define NUM_CHANNELS 2
#define FRAMES_PER_BUFFER 2048

typedef uint16_t sample_t;

void decode_audio_stream(void) {
    sample_t *buffer = NULL;
    size_t buffer_size = FRAMES_PER_BUFFER * NUM_CHANNELS * BITS_PER_SAMPLE / 8;

    buffer = (sample_t *)malloc(buffer_size);

    FILE *input_file = fopen("audio_stream.raw", "rb");

    if (input_file == NULL) {
        printf("Failed to open audio file.\n");
        return;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, buffer_size, input_file)) > 0) {
        size_t i, j;
        for (i = 0, j = bytes_read; i < j; ++i, ++buffer) {
            printf("%d ", *buffer);
        }
        printf("\n");
    }

    fclose(input_file);

    free(buffer);
}

int main() {
    decode_audio_stream();

    return 0;
}
