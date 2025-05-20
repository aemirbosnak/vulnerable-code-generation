//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_SAMPLES 1000

int main(int argc, char *argv[]) {
    double input_signal[MAX_SAMPLES];
    double output_signal[MAX_SAMPLES];
    int i, n;
    double sampling_rate;
    double low_cutoff_frequency, high_cutoff_frequency;
    double gain;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the %d-th sample: ", i + 1);
        scanf("%lf", &input_signal[i]);
    }

    printf("Enter the sampling rate: ");
    scanf("%lf", &sampling_rate);

    printf("Enter the low cutoff frequency: ");
    scanf("%lf", &low_cutoff_frequency);

    printf("Enter the high cutoff frequency: ");
    scanf("%lf", &high_cutoff_frequency);

    printf("Enter the gain: ");
    scanf("%lf", &gain);

    for (i = 0; i < n; i++) {
        output_signal[i] = input_signal[i] * gain;
    }

    printf("Input Signal:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", input_signal[i]);
    }

    printf("Output Signal:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", output_signal[i]);
    }

    return 0;
}