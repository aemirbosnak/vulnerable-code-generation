//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SAMPLES 1000
#define SAMPLE_RATE 100

struct sample {
    double temperature;
    time_t timestamp;
};

void read_samples(struct sample samples[], int *count) {
    FILE *fp = fopen("samples.txt", "r");
    if (fp == NULL) {
        *count = 0;
        return;
    }

    int i = 0;
    while (fscanf(fp, "%lf %ld\n", &samples[i].temperature, &samples[i].timestamp) == 2) {
        i++;
        if (i >= MAX_SAMPLES) {
            break;
        }
    }

    *count = i;
    fclose(fp);
}

void write_samples(struct sample samples[], int count) {
    FILE *fp = fopen("samples.txt", "w");
    if (fp == NULL) {
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%lf %ld\n", samples[i].temperature, samples[i].timestamp);
    }

    fclose(fp);
}

double moving_average(struct sample samples[], int count, int window_size) {
    double sum = 0;
    int i;
    for (i = 0; i < count; i++) {
        sum += samples[i].temperature;
    }

    return sum / count;
}

void print_stats(struct sample samples[], int count, double avg_temp, double min_temp, double max_temp) {
    printf("Average temperature: %.2lf\n", avg_temp);
    printf("Minimum temperature: %.2lf\n", min_temp);
    printf("Maximum temperature: %.2lf\n", max_temp);
}

int main() {
    struct sample samples[MAX_SAMPLES];
    int sample_count = 0;

    read_samples(samples, &sample_count);

    double avg_temp = moving_average(samples, sample_count, 10);
    double min_temp = samples[0].temperature;
    double max_temp = samples[0].temperature;

    for (int i = 1; i < sample_count; i++) {
        if (samples[i].temperature < min_temp) {
            min_temp = samples[i].temperature;
        }
        if (samples[i].temperature > max_temp) {
            max_temp = samples[i].temperature;
        }
    }

    print_stats(samples, sample_count, avg_temp, min_temp, max_temp);

    write_samples(samples, sample_count);

    return 0;
}