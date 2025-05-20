//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAMPLES 1024
#define MAX_DELAY_MS 500

typedef struct {
    short int *buffer;
    int buffer_size;
    int read_index;
    int write_index;
    int delay_ms;
} audio_buffer_t;

void audio_buffer_init(audio_buffer_t *buffer, int buffer_size, int delay_ms) {
    buffer->buffer = (short int *)malloc(buffer_size * sizeof(short int));
    buffer->buffer_size = buffer_size;
    buffer->read_index = 0;
    buffer->write_index = 0;
    buffer->delay_ms = delay_ms;
}

void audio_buffer_free(audio_buffer_t *buffer) {
    free(buffer->buffer);
}

int audio_buffer_write(audio_buffer_t *buffer, short int sample) {
    if ((buffer->write_index + 1) % buffer->buffer_size == buffer->read_index) {
        return -1;
    }

    buffer->buffer[buffer->write_index] = sample;
    buffer->write_index = (buffer->write_index + 1) % buffer->buffer_size;

    return 0;
}

int audio_buffer_read(audio_buffer_t *buffer, short int *sample) {
    if (buffer->read_index == buffer->write_index) {
        return -1;
    }

    *sample = buffer->buffer[buffer->read_index];
    buffer->read_index = (buffer->read_index + 1) % buffer->buffer_size;

    return 0;
}

int audio_buffer_delay(audio_buffer_t *buffer, int delay_ms) {
    buffer->delay_ms = delay_ms;
}

int main() {
    audio_buffer_t buffer;
    audio_buffer_init(&buffer, MAX_SAMPLES, MAX_DELAY_MS);

    short int sample = 0;
    int i;

    for (i = 0; i < MAX_SAMPLES; i++) {
        audio_buffer_write(&buffer, sample);
        sample += 10;
    }

    for (i = 0; i < MAX_SAMPLES; i++) {
        audio_buffer_read(&buffer, &sample);
        printf("%d ", sample);
    }

    audio_buffer_free(&buffer);

    return 0;
}