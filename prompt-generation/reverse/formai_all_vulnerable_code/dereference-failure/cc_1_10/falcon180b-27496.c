//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

void generate_sine_wave(double freq, int duration, int sampling_rate, double *wave) {
    int i;
    double t = 0;
    double period = 1 / freq;
    int num_samples = duration * sampling_rate;

    for(i = 0; i < num_samples; i++) {
        wave[i] = sin(2 * PI * t * freq);
        t += period;
    }
}

void apply_low_pass_filter(double *input, double *output, int size, double cutoff_freq, double sampling_rate) {
    int i;
    double a = 2 * cutoff_freq / sampling_rate;
    double b = 1 - a;
    double x1, x2, y1, y2;

    for(i = 0; i < size; i++) {
        x1 = input[i];
        x2 = input[i+1];
        y1 = b * x1 + a * x2;
        y2 = b * x2 + a * x1;
        output[i] = y1;
    }
}

int main() {
    int i;
    double freq = 440;
    int duration = 5;
    int sampling_rate = 44100;
    double cutoff_freq = 1000;

    double *sine_wave = malloc(MAX_SIZE * sizeof(double));
    double *filtered_wave = malloc(MAX_SIZE * sizeof(double));

    generate_sine_wave(freq, duration, sampling_rate, sine_wave);

    apply_low_pass_filter(sine_wave, filtered_wave, MAX_SIZE, cutoff_freq, sampling_rate);

    for(i = 0; i < MAX_SIZE; i++) {
        printf("%lf\n", filtered_wave[i]);
    }

    free(sine_wave);
    free(filtered_wave);

    return 0;
}