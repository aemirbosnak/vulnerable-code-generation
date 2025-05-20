//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave with given frequency and amplitude
void generate_sine_wave(int freq, int amp, int duration, FILE *fp) {
    int i, n;
    double t, x;

    // Number of samples to generate
    n = duration * freq;

    // Loop through each sample
    for (i = 0; i < n; i++) {
        // Calculate time in seconds for current sample
        t = (double) i / freq;

        // Generate sine wave value for current sample
        x = amp * sin(2 * PI * t);

        // Write sample value to file
        fprintf(fp, "%d\n", (int) x);
    }
}

int main() {
    FILE *fp;
    int freq, amp, duration;

    // Get user input for frequency, amplitude, and duration
    printf("Enter frequency: ");
    scanf("%d", &freq);
    printf("Enter amplitude: ");
    scanf("%d", &amp);
    printf("Enter duration (in seconds): ");
    scanf("%d", &duration);

    // Open file for writing
    fp = fopen("sine_wave.txt", "w");

    // Check if file was successfully opened
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Generate sine wave and write to file
    generate_sine_wave(freq, amp, duration, fp);

    // Close file
    fclose(fp);

    printf("Sine wave generated and saved to sine_wave.txt.\n");

    return 0;
}