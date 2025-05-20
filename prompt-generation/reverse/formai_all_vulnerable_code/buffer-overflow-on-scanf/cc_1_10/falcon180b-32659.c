//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SAMPLES 10000
#define SAMPLE_RATE 44100
#define FILTER_TYPE_LOW_PASS 0
#define FILTER_TYPE_HIGH_PASS 1
#define FILTER_TYPE_BAND_PASS 2
#define FILTER_TYPE_BAND_STOP 3

typedef struct {
    int type;
    double cutoff_frequency;
    double gain;
} Filter;

void apply_filter(double* input, int input_size, Filter* filter, double* output) {
    int i;
    double a0, a1, a2, b1, b2;
    double xn, yn;

    a0 = 1.0;
    a1 = -2.0 * cos(2.0 * M_PI * filter->cutoff_frequency / SAMPLE_RATE);
    a2 = 1.0;

    b1 = 2.0 * a1;
    b2 = -a2;

    xn = 0.0;
    yn = 0.0;

    for (i = 0; i < input_size; i++) {
        xn = input[i];
        yn = (a0 * xn) + (a1 * yn) + (a2 * yn) - (b1 * yn) - (b2 * yn);
        output[i] = yn * filter->gain;
    }
}

int main() {
    int i;
    double input[MAX_SAMPLES];
    double output[MAX_SAMPLES];
    Filter filter;

    printf("Enter filter type (0 - low-pass, 1 - high-pass, 2 - band-pass, 3 - band-stop): ");
    scanf("%d", &filter.type);

    printf("Enter cutoff frequency: ");
    scanf("%lf", &filter.cutoff_frequency);

    printf("Enter gain: ");
    scanf("%lf", &filter.gain);

    for (i = 0; i < MAX_SAMPLES; i++) {
        input[i] = sin(2.0 * M_PI * i / SAMPLE_RATE);
    }

    apply_filter(input, MAX_SAMPLES, &filter, output);

    printf("Filtered signal:\n");
    for (i = 0; i < MAX_SAMPLES; i++) {
        printf("%lf\n", output[i]);
    }

    return 0;
}