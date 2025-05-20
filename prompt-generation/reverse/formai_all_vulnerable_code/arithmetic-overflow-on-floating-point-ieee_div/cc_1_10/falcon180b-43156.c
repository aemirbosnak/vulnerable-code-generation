//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Function to generate a sine wave */
void generate_sine_wave(int n, float *wave, float amplitude, float frequency) {
    int i;
    float t, phase;

    phase = 0.0;
    for (i = 0; i < n; i++) {
        t = (float)i / (float)n * 2.0 * PI * frequency;
        wave[i] = amplitude * sin(t + phase);
    }
}

/* Function to apply a low-pass filter */
void low_pass_filter(int n, float *wave, float cutoff_frequency) {
    int i;
    float b = 2.0 * cutoff_frequency / (float)n;

    for (i = 0; i < n; i++) {
        wave[i] = wave[i] + (wave[i-1] - wave[i]) / b;
    }
}

/* Function to apply a high-pass filter */
void high_pass_filter(int n, float *wave, float cutoff_frequency) {
    int i;
    float b = 2.0 * cutoff_frequency / (float)n;

    for (i = 0; i < n; i++) {
        wave[i] = wave[i] - (wave[i-1] - wave[i]) / b;
    }
}

int main() {
    int n, i;
    float *sine_wave, *filtered_wave;
    float amplitude, frequency, cutoff_frequency;

    /* Get user input for wave parameters */
    printf("Enter the number of samples: ");
    scanf("%d", &n);
    printf("Enter the amplitude: ");
    scanf("%f", &amplitude);
    printf("Enter the frequency: ");
    scanf("%f", &frequency);

    /* Allocate memory for the sine wave and filtered wave */
    sine_wave = (float *)malloc(n * sizeof(float));
    filtered_wave = (float *)malloc(n * sizeof(float));

    /* Generate the sine wave */
    generate_sine_wave(n, sine_wave, amplitude, frequency);

    /* Apply low-pass filter */
    printf("Enter the cutoff frequency for low-pass filter: ");
    scanf("%f", &cutoff_frequency);
    low_pass_filter(n, sine_wave, cutoff_frequency);

    /* Save the filtered wave to a file */
    printf("Enter the filename to save the filtered wave: ");
    scanf("%s", "filtered_wave.txt");
    FILE *fp = fopen("filtered_wave.txt", "w");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%f\n", sine_wave[i]);
    }
    fclose(fp);

    return 0;
}