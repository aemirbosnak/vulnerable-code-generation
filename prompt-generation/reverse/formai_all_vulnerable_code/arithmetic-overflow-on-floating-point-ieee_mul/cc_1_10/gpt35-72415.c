//FormAI DATASET v1.0 Category: Digital signal processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359 // Define the value of PI

int main() {
    
    // Declare the variables
    float input_signal[100], output_signal[100], omega, phase_shift, amplitude;
    int i, j, length;
    
    // Prompt the user to enter the length of the signal
    printf("Enter the length of the signal (maximum 100): ");
    scanf("%d", &length);
    
    // Prompt the user to enter the input signal
    printf("Enter the input signal: \n");
    
    // Read the input signal
    for (i = 0; i < length; i++) {
        scanf("%f", &input_signal[i]);
    }
    
    // Prompt the user to enter the cutoff frequency
    printf("Enter the cutoff frequency (in Hz): ");
    scanf("%f", &omega);
    
    // Convert the cutoff frequency to radians
    omega = omega * 2 * PI;
    
    // Prompt the user to enter the phase shift
    printf("Enter the phase shift (in degrees): ");
    scanf("%f", &phase_shift);
    
    // Convert the phase shift to radians
    phase_shift = phase_shift * PI / 180;
    
    // Prompt the user to enter the amplitude
    printf("Enter the amplitude: ");
    scanf("%f", &amplitude);
    
    // Apply the low-pass filter
    for (i = 0; i < length; i++) {
        output_signal[i] = 0;
        for (j = 0; j <= i; j++) {
            output_signal[i] += input_signal[j] * amplitude * sin(omega * (i - j) + phase_shift);
        }
    }
    
    // Display the output signal
    printf("The output signal is: \n");
    for (i = 0; i < length; i++) {
        printf("%f\n", output_signal[i]);
    }
    
    return 0; // Exit the program
}