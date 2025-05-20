//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_SIZE 5

typedef struct {
    float data[WINDOW_SIZE];
    float sum;
    int index;
} MovingAverageFilter;

void init_filter(MovingAverageFilter* filter) {
    for (int i = 0; i < WINDOW_SIZE; i++) {
        filter->data[i] = 0.0f;
    }
    filter->sum = 0.0f;
    filter->index = 0;
}

void push(MovingAverageFilter* filter, float sample) {
    filter->data[filter->index] = sample;
    filter->sum += sample;

    if (++filter->index >= WINDOW_SIZE) {
        filter->index = 0;
    }
}

float pop(MovingAverageFilter* filter) {
    float avg = filter->sum / WINDOW_SIZE;
    float sample = filter->data[filter->index];
    filter->sum -= sample;

    if (++filter->index >= WINDOW_SIZE) {
        filter->index = 0;
    }

    return avg;
}

int main(int argc, char* argv[]) {
    int samples = 20;
    float input_signal[samples];
    float filtered_signal[samples];
    MovingAverageFilter ma_filter;

    init_filter(&ma_filter);

    printf("Enter %d input signal samples:\n", samples);

    for (int i = 0; i < samples; i++) {
        scanf("%f", &input_signal[i]);
        push(&ma_filter, input_signal[i]);
        filtered_signal[i] = pop(&ma_filter);
        printf("Input sample %d: %.2f\nFiltered sample %d: %.2f\n", i, input_signal[i], i, filtered_signal[i]);
    }

    free(input_signal);
    free(filtered_signal);

    return 0;
}