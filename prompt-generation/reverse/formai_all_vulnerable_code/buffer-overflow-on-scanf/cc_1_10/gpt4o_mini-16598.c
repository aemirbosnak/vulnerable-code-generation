//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILTER_ORDER 4
#define SIGNAL_LENGTH 10

// FIR filter coefficients (example: moving average)
double fir_coeffs[FILTER_ORDER + 1] = {0.2, 0.2, 0.2, 0.2, 0.2};

// Function to apply FIR filter to input signal
void apply_fir_filter(double *input, double *output, int input_length){
    for (int n = 0; n < input_length; n++) {
        output[n] = 0.0; // Initialize the output sample
        // Perform the convolution
        for (int k = 0; k <= FILTER_ORDER; k++) {
            if (n - k >= 0) {
                output[n] += fir_coeffs[k] * input[n - k];
            }
        }
    }
}

// Function to display arrays
void display_array(const char *title, double *array, int length) {
    printf("%s: ", title);
    for (int i = 0; i < length; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    double input_signal[SIGNAL_LENGTH];
    double output_signal[SIGNAL_LENGTH] = {0};

    // Input: Getting the signal from the user
    printf("Enter %d signal samples:\n", SIGNAL_LENGTH);
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        printf("Sample %d: ", i + 1);
        scanf("%lf", &input_signal[i]);
    }

    // Display the input signal
    display_array("Input Signal", input_signal, SIGNAL_LENGTH);

    // Apply the FIR filter to the input signal
    apply_fir_filter(input_signal, output_signal, SIGNAL_LENGTH);

    // Display the filtered output signal
    display_array("Filtered Output Signal", output_signal, SIGNAL_LENGTH);

    return 0;
}