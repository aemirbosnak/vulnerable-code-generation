//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the signal processing function
void signal_process(float *signal, int length) {
    int i;
    float sum = 0.0;

    // Calculate the sum of the signal
    for (i = 0; i < length; i++) {
        sum += signal[i];
    }

    // Calculate the average of the signal
    float average = sum / length;

    // Calculate the standard deviation of the signal
    float variance_sum = 0.0;
    for (i = 0; i < length; i++) {
        variance_sum += pow(signal[i] - average, 2.0);
    }
    float variance = variance_sum / length;
    float std_deviation = sqrt(variance);

    // Print the results
    printf("Signal length: %d\n", length);
    printf("Signal average: %f\n", average);
    printf("Signal standard deviation: %f\n", std_deviation);
}

// Define the main function
int main() {
    int length;
    float *signal;

    // Get the length of the signal from the user
    printf("Enter the length of the signal: ");
    scanf("%d", &length);

    // Allocate memory for the signal
    signal = (float *)malloc(length * sizeof(float));

    // Get the signal from the user
    printf("Enter the signal: ");
    for (int i = 0; i < length; i++) {
        scanf("%f", &signal[i]);
    }

    // Process the signal
    signal_process(signal, length);

    // Free the memory allocated for the signal
    free(signal);

    return 0;
}