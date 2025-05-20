//FormAI DATASET v1.0 Category: Digital signal processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 128

float input[N], output[N], freq, theta;

int main() {
    int i;

    printf("Enter frequency between 0Hz and 64Hz: ");
    scanf("%f", &freq);

    theta = 2.0 * M_PI * freq / N;

    for (i=0; i<N; i++) {
        input[i] = sin(theta * i);
    }

    float mean = 0.0;

    for (i=0; i<N; i++) {
        mean += input[i];
    }

    mean /= N;

    printf("Mean of input: %f\n", mean);

    float variance = 0.0;

    for (i=0; i<N; i++) {
        variance += pow(input[i] - mean, 2);
    }

    variance /= N;

    printf("Variance of input: %f\n", variance);

    float std_dev = sqrt(variance);

    printf("Standard deviation of input: %f\n", std_dev);

    for (i=0; i<N; i++) {
        output[i] = (input[i] - mean) / std_dev;
    }

    printf("Normalized input:\n");

    for (i=0; i<N; i++) {
        printf("%f ", output[i]);
    }

    printf("\n");

    return 0;
}