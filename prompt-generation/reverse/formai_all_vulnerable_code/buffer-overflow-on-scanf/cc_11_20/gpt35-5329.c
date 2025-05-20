//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ephemeral
/* A guitar tuner program using digital signal processing */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BASE_FREQUENCY 440
#define BUFFER_SIZE 512

int main() {
    float *buffer = (float*) malloc(sizeof(float) * BUFFER_SIZE);
    float freq_ratio = pow(2, 1/12.0); // frequency ratio for a half step increment

    float base_frequency = BASE_FREQUENCY;
    float current_frequency = base_frequency;
    float target_frequency = base_frequency; // start with base frequency

    int i, j;

    // Infinite loop until user closes the program
    while (1) {
        // Read audio input from microphone or another source
        for (i = 0; i < BUFFER_SIZE; i++) {
            scanf("%f", &buffer[i]);
        }

        // Calculate the pitch of the input using a Fast Fourier Transform (FFT)
        int nyquist = BUFFER_SIZE / 2;
        float max_magnitude = 0;
        int max_index = 0;

        for (i = 0; i < nyquist; i++) {
            float real = 0;
            float imag = 0;

            for (j = 0; j < BUFFER_SIZE; j++) {
                float angle = 2 * M_PI * i * j / BUFFER_SIZE;
                real += buffer[j] * cos(angle);
                imag -= buffer[j] * sin(angle);
            }

            float magnitude = sqrt(real * real + imag * imag);

            if (magnitude > max_magnitude) {
                max_magnitude = magnitude;
                max_index = i;
            }
        }

        float pitch = SAMPLE_RATE * max_index / BUFFER_SIZE;
        current_frequency = pitch;

        // Adjust the current frequency towards the target frequency
        if (current_frequency < target_frequency) {
            current_frequency *= freq_ratio;
        } else if (current_frequency > target_frequency) {
            current_frequency /= freq_ratio;
        }

        // Output the tuning results
        float difference = current_frequency - target_frequency;
        printf("Target frequency: %f\n", target_frequency);
        printf("Current frequency: %f\n", current_frequency);
        printf("Difference: %f\n", difference);

        if (difference < 0.5 && difference > -0.5) {
            printf("In tune!\n");
        } else if (difference > 0) {
            printf("Too sharp\n");
        } else {
            printf("Too flat\n");
        }

        // Wait for a short amount of time before reading the next input
        usleep(10000);
    }

    return 0;
}