//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: peaceful
// Title: A Peaceful Moving Average Digital Filter
// Description: This program processes an input signal using a moving average filter,
//              aiming for a calm and serene output.

#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_RATE 1000
#define FILTER_ORDER 10
#define NUM_SAMPLES 10000

typedef struct {
    float data[NUM_SAMPLES];
    int index;
} CircularBuffer;

void moving_average_filter(CircularBuffer* buffer, float* output, float* input, int sample_rate, int filter_order) {
    int i;
    float sum = 0;

    buffer->index = (buffer->index + 1) % NUM_SAMPLES;
    buffer->data[buffer->index] = *input;

    for (i = 0; i < filter_order; i++)
        sum += buffer->data[(buffer->index - i) % NUM_SAMPLES];

    *output = sum / filter_order;
}

int main() {
    CircularBuffer input_buffer, output_buffer;
    float input_sample, output_sample;
    int i;

    input_buffer.index = 0;
    output_buffer.index = 0;

    printf("Initializing input and output buffers...\n");

    for (i = 0; i < NUM_SAMPLES; i++) {
        scanf("%f", &input_sample);
        input_buffer.data[i] = input_sample;
    }

    printf("Processing input signal using moving average filter...\n");

    for (i = 0; i < NUM_SAMPLES; i++) {
        moving_average_filter(&input_buffer, &output_sample, &input_buffer.data + i, SAMPLE_RATE, FILTER_ORDER);
        output_buffer.data[i] = output_sample;

        printf("Sample %d: Input = %.2f, Output = %.2f\n", i + 1, input_buffer.data[i], output_sample);
    }

    printf("Processing completed. Press enter to exit...\n");
    getchar();

    return 0;
}