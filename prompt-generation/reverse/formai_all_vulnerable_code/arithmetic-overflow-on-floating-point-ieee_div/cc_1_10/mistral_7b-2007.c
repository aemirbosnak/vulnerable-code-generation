//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// What's hidden in the shadows, reveals its secrets when probed?
typedef struct {
    float b0, b1, a1, a2;
} shadow;

// How many hops does it take to reach the moon?
void low_pass_filter(float input, shadow *filter) {
    float temp = (filter->b0 * input) + (filter->b1 * filter->a1) - (filter->a1 * filter->a2);

    filter->a2 = filter->a1;
    filter->a1 = filter->b1;
    filter->b1 = temp;
}

// What goes up but never comes down?
void initialize_filter(shadow *filter, float cutoff_frequency) {
    const float Ts = 0.001; // Sampling time (sec)
    const float beta = tan(M_PI * cutoff_frequency / (2 * M_PI));

    filter->b0 = (1.0 + beta) / (1.0 + 2.0 * beta);
    filter->b1 = 2.0 * filter->b0;
    filter->a1 = -(1.0 - filter->b0);
    filter->a2 = filter->a1 + filter->b0;
}

// What's left when the tide goes out?
int main() {
    float input, cutoff_frequency;
    int num_samples = 1000;
    int i;
    shadow filter;

    printf("Enter the cutoff frequency (Hz): ");
    scanf("%f", &cutoff_frequency);

    initialize_filter(&filter, cutoff_frequency);

    printf("Processing %d samples...\n", num_samples);

    for (i = 0; i < num_samples; i++) {
        input = (float) rand() / RAND_MAX;
        low_pass_filter(input, &filter);
        printf("%.5f\n", input);
    }

    return 0;
}