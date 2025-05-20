//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000 // Maximum size of the signal
#define PI 3.14159265358979323846 // Value of pi

int main() {
    int size;
    float signal[MAX_SIZE];
    float freq;
    float phase;
    float t;
    float dt;
    float time_step;
    int i;
    int n;
    float x;
    float y;
    float real;
    float imag;
    float mag;
    float phase_diff;

    // Prompt user for signal size
    printf("Enter signal size: ");
    scanf("%d", &size);

    // Prompt user for signal frequency
    printf("Enter signal frequency: ");
    scanf("%f", &freq);

    // Prompt user for signal phase
    printf("Enter signal phase: ");
    scanf("%f", &phase);

    // Generate signal
    for (i = 0; i < size; i++) {
        t = (float)i / freq;
        signal[i] = sin(2 * PI * freq * t + phase);
    }

    // Prompt user for time step
    printf("Enter time step: ");
    scanf("%f", &dt);

    // Set up time vector
    time_step = dt;
    n = size / time_step;
    for (i = 0; i < n; i++) {
        t = i * time_step;
        x = sin(2 * PI * freq * t + phase);
        y = cos(2 * PI * freq * t + phase);
        real = x;
        imag = y;
        mag = sqrt(pow(x, 2) + pow(y, 2));
        phase_diff = atan2(y, x);
        printf("%.4f %.4f %.4f %.4f\n", real, imag, mag, phase_diff);
    }

    return 0;
}