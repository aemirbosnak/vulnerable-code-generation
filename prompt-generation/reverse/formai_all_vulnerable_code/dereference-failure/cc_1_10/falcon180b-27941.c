//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int capacity;
    int size;
} Buffer;

void buffer_init(Buffer *buffer, int capacity) {
    buffer->data = malloc(capacity * sizeof(float));
    buffer->capacity = capacity;
    buffer->size = 0;
}

void buffer_free(Buffer *buffer) {
    free(buffer->data);
}

void buffer_clear(Buffer *buffer) {
    memset(buffer->data, 0, buffer->capacity * sizeof(float));
    buffer->size = 0;
}

void buffer_push(Buffer *buffer, float value) {
    if (buffer->size >= buffer->capacity) {
        printf("Buffer overflow\n");
        return;
    }
    buffer->data[buffer->size++] = value;
}

float buffer_pop(Buffer *buffer) {
    if (buffer->size == 0) {
        printf("Buffer underflow\n");
        return 0;
    }
    return buffer->data[--buffer->size];
}

void process_audio(Buffer *input, Buffer *output) {
    int i;
    for (i = 0; i < BUFFER_SIZE; ++i) {
        float sample = buffer_pop(input);
        float processed_sample = sample * 2;
        buffer_push(output, processed_sample);
    }
}

int main() {
    Buffer input, output;
    buffer_init(&input, BUFFER_SIZE);
    buffer_init(&output, BUFFER_SIZE);

    while (1) {
        int num_samples = fread(input.data, sizeof(float), BUFFER_SIZE, stdin);
        if (num_samples!= BUFFER_SIZE) {
            printf("Error reading input\n");
            break;
        }
        process_audio(&input, &output);
        fwrite(output.data, sizeof(float), BUFFER_SIZE, stdout);
    }

    buffer_free(&input);
    buffer_free(&output);
    return 0;
}