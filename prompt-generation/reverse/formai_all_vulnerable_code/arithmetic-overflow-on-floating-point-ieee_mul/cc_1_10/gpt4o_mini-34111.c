//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of samples
#define SAMPLE_RATE 100
#define CUTOFF_FREQ 5.0
#define ALPHA 0.1

// Function to apply an IIR low-pass filter to an input signal
void low_pass_filter(double* input, double* output, int num_samples) {
    output[0] = input[0]; // Initialize the first sample

    for (int i = 1; i < num_samples; ++i) {
        output[i] = ALPHA * input[i] + (1 - ALPHA) * output[i - 1]; // Apply the filter equation
    }
}

// Function to generate a sine wave signal for testing
void generate_sine_wave(double* signal, int num_samples, double frequency) {
    for (int i = 0; i < num_samples; ++i) {
        signal[i] = sin((2 * M_PI * frequency * i) / SAMPLE_RATE);
    }
}

// Function to print the signal values
void print_signal(const char* title, double* signal, int num_samples) {
    printf("%s:\n", title);
    for (int i = 0; i < num_samples; ++i) {
        printf("%d: %.4f\n", i, signal[i]);
    }
}

int main() {
    double input_signal[SAMPLE_RATE];
    double output_signal[SAMPLE_RATE];

    double frequency;

    // User input for frequency
    printf("Enter the frequency of the sine wave (0 - %d): ", SAMPLE_RATE / 2);
    scanf("%lf", &frequency);

    // Generate the sine wave input signal
    generate_sine_wave(input_signal, SAMPLE_RATE, frequency);
    print_signal("Input Signal", input_signal, SAMPLE_RATE);

    // Apply the low-pass filter to the input signal
    low_pass_filter(input_signal, output_signal, SAMPLE_RATE);
    print_signal("Filtered Signal (Low-pass)", output_signal, SAMPLE_RATE);

    return 0;
}