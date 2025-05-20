//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#define SAMPLE_RATE 1000.0
#define FILTER_SIZE 11
#define BUFFER_SIZE (FILTER_SIZE / 2 + 1)

typedef struct {
    double data[FILTER_SIZE];
    int index;
} moving_average;

void read_data(const char *input_file, double *buffer, int size) {
    FILE *fp;
    int i;
    fp = fopen(input_file, "r");

    for (i = 0; i < size; i++) {
        fscanf(fp, "%lf", &buffer[i]);
    }

    fclose(fp);
}

void write_data(const char *output_file, double *buffer, int size) {
    FILE *fp;
    int i;
    fp = fopen(output_file, "w");

    for (i = 0; i < size; i++) {
        fprintf(fp, "%.16f ", buffer[i]);
    }

    fclose(fp);
}

void moving_average_filter(double input_data[], moving_average *filter) {
    double sum = 0.0;
    int i;

    filter->index = (filter->index + 1) % FILTER_SIZE;
    filter->data[filter->index] = input_data[0];

    if (filter->index > 0) {
        for (i = 0; i < FILTER_SIZE; i++) {
            sum += filter->data[i];
        }

        filter->data[0] = sum / FILTER_SIZE;
    }
}

int main() {
    double input_data[BUFFER_SIZE];
    double output_data[BUFFER_SIZE];
    moving_average ma_filter;
    ma_filter.index = 0;

    read_data("input.txt", input_data, BUFFER_SIZE);

    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        moving_average_filter(&input_data[i], &ma_filter);
        output_data[i] = ma_filter.data[0];
    }

    write_data("output.txt", output_data, BUFFER_SIZE);

    return 0;
}