//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 100

struct Sample {
    double value;
    double timestamp;
};

void calculate_mean(struct Sample* samples, int num_samples, double* mean) {
    double sum = 0.0;
    for (int i = 0; i < num_samples; i++) {
        sum += samples[i].value;
    }
    *mean = sum / num_samples;
}

void calculate_variance(struct Sample* samples, int num_samples, double* variance) {
    double mean = 0.0;
    calculate_mean(samples, num_samples, &mean);

    double sum_squares = 0.0;
    for (int i = 0; i < num_samples; i++) {
        sum_squares += pow(samples[i].value - mean, 2.0);
    }

    *variance = sum_squares / num_samples;
}

void calculate_standard_deviation(double variance, double* std_dev) {
    *std_dev = sqrt(variance);
}

int main() {
    int num_samples = 0;
    struct Sample samples[MAX_SAMPLES];

    double mean = 0.0;
    double variance = 0.0;
    double std_dev = 0.0;

    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%lf %lf", &samples[num_samples].value, &samples[num_samples].timestamp) == 2) {
        num_samples++;
        if (num_samples >= MAX_SAMPLES) {
            break;
        }
    }

    calculate_mean(samples, num_samples, &mean);
    calculate_variance(samples, num_samples, &variance);
    calculate_standard_deviation(variance, &std_dev);

    printf("Mean: %lf\n", mean);
    printf("Variance: %lf\n", variance);
    printf("Standard deviation: %lf\n", std_dev);

    return 0;
}