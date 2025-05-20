//FormAI DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>

// Function to perform convolution between two signals
void convolution(int input[], int output[], int input_len, int output_len, int kernel[], int kernel_len) {
    int i, j, k;

    // Pad input signal with zeroes
    int padded_input[input_len + kernel_len - 1];
    for (i = 0; i < input_len + kernel_len - 1; i++) {
        if (i < input_len) {
            padded_input[i] = input[i];
        } else {
            padded_input[i] = 0;
        }
    }

    // Perform convolution
    for (i = 0; i < output_len; i++) {
        output[i] = 0;
        for (j = 0; j < kernel_len; j++) {
            k = i + j;
            output[i] += padded_input[k] * kernel[kernel_len - 1 - j];
        }
    }
}

int main() {
    // Define input signal and kernel
    int input[] = {1, 2, 3, 4, 5};
    int kernel[] = {1, 2, 1};

    // Get the lengths of the input signal and kernel
    int input_len = sizeof(input) / sizeof(int);
    int kernel_len = sizeof(kernel) / sizeof(int);
    int output_len = input_len + kernel_len - 1;

    // Allocate memory for the output signal
    int output[output_len];

    // Perform convolution
    convolution(input, output, input_len, output_len, kernel, kernel_len);

    // Print output signal
    printf("Output signal: ");
    for (int i = 0; i < output_len; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}