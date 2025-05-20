//FormAI DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>

#define MAX_SAMPLES 10000

float data[MAX_SAMPLES];
float filtered_data[MAX_SAMPLES];

void low_pass_filter(float *data, float *filtered_data, int length, float cutoff_freq, float sample_rate) {
    // Calculate filter coefficients
    float RC = 1.0 / (cutoff_freq * 2 * 3.14);
    float dt = 1.0 / sample_rate;
    float alpha = dt / (RC + dt);

    // Filter data
    float previous_output = 0;
    for (int i = 0; i < length; i++) {
        filtered_data[i] = alpha * data[i] + (1 - alpha) * previous_output;
        previous_output = filtered_data[i];
    }
}

int main() {
    int num_samples;
    float sample_rate, cutoff_freq;

    // Read input parameters
    printf("Enter number of samples: ");
    scanf("%d", &num_samples);
    printf("Enter sample rate: ");
    scanf("%f", &sample_rate);
    printf("Enter cutoff frequency: ");
    scanf("%f", &cutoff_freq);

    // Read data
    printf("Enter data:\n");
    for (int i = 0; i < num_samples; i++) {
        scanf("%f", &data[i]);
    }

    // Filter data
    low_pass_filter(data, filtered_data, num_samples, cutoff_freq, sample_rate);

    // Print filtered data
    printf("Filtered data:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%f\n", filtered_data[i]);
    }

    return 0;
}