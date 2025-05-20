//FormAI DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int sample_rate, num_samples;
int *samples;

// Function to implement configurable noise reduction filter
void filter(int threshold) {
    // Loop through each sample
    for (int i = 0; i < num_samples; i++) {
        // If the sample value is less than the threshold, set it to 0
        if (samples[i] < threshold) {
            samples[i] = 0;
        }
    }
}

int main() {
    // Get user input for sample rate and number of samples
    printf("Enter the sample rate: ");
    scanf("%d", &sample_rate);
    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);

    // Allocate memory for the samples array
    samples = (int *)malloc(num_samples * sizeof(int));

    // Get user input for each sample value
    printf("Enter the sample values:\n");
    for (int i = 0; i < num_samples; i++) {
        scanf("%d", &samples[i]);
    }

    // Filter the samples based on user input for threshold
    int threshold;
    printf("Enter the threshold: ");
    scanf("%d", &threshold);
    filter(threshold);

    // Print output
    printf("Filtered samples:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%d\n", samples[i]);
    }

    // Free memory allocated for samples array
    free(samples);

    return 0;
}