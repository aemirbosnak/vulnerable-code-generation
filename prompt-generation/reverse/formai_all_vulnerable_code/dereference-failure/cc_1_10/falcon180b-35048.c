//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SAMPLES 10000
#define MAX_FILTER_SIZE 1000
#define MAX_OUTPUT_SIZE 100000

typedef struct {
    int size;
    double *data;
} Signal;

typedef struct {
    int size;
    double *data;
} Filter;

void generate_signal(Signal *signal) {
    int i;
    for (i = 0; i < signal->size; i++) {
        signal->data[i] = sin(i * 2 * M_PI / signal->size);
    }
}

void apply_filter(Filter *filter, Signal *signal, Signal *output) {
    int i, j;
    for (i = 0; i < signal->size; i++) {
        double sum = 0;
        for (j = 0; j < filter->size; j++) {
            sum += filter->data[j] * signal->data[(i - j + signal->size) % signal->size];
        }
        output->data[i] = sum;
    }
}

int main() {
    Signal signal;
    Filter filter;
    Signal output;

    signal.size = MAX_SAMPLES;
    signal.data = malloc(sizeof(double) * signal.size);
    generate_signal(&signal);

    filter.size = MAX_FILTER_SIZE;
    filter.data = malloc(sizeof(double) * filter.size);
    for (int i = 0; i < filter.size; i++) {
        filter.data[i] = 1;
    }

    output.size = MAX_OUTPUT_SIZE;
    output.data = malloc(sizeof(double) * output.size);

    apply_filter(&filter, &signal, &output);

    free(signal.data);
    free(filter.data);
    free(output.data);

    return 0;
}