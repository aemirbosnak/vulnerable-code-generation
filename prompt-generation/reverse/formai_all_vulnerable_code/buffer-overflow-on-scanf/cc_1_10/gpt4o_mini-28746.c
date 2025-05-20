//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 1024
#define PI 3.14159265358979323846

// Function prototypes
void generate_sine_wave(double frequency, double sample_rate, double duration, double *wave, int *length);
void generate_square_wave(double frequency, double sample_rate, double duration, double *wave, int *length);
void generate_triangle_wave(double frequency, double sample_rate, double duration, double *wave, int *length);
void apply_window(double *wave, int length, const char *window_type);
void print_wave(const double *wave, int length);

int main() {
    double sample_rate = 44100; // 44.1 kHz
    double frequency;
    double duration = 1.0; // 1 second
    char wave_type[20];
    char window_type[20];
    double wave[MAX_LENGTH];
    int length = 0;

    printf("Enter wave type (sine, square, triangle): ");
    scanf("%s", wave_type);

    printf("Enter frequency (Hz): ");
    scanf("%lf", &frequency);

    printf("Choose a window type (hamming, hanning, blackman, none): ");
    scanf("%s", window_type);

    if (strcmp(wave_type, "sine") == 0) {
        generate_sine_wave(frequency, sample_rate, duration, wave, &length);
    } else if (strcmp(wave_type, "square") == 0) {
        generate_square_wave(frequency, sample_rate, duration, wave, &length);
    } else if (strcmp(wave_type, "triangle") == 0) {
        generate_triangle_wave(frequency, sample_rate, duration, wave, &length);
    } else {
        printf("Invalid wave type. Exiting...\n");
        return -1;
    }

    apply_window(wave, length, window_type);

    print_wave(wave, length);

    return 0;
}

void generate_sine_wave(double frequency, double sample_rate, double duration, double *wave, int *length) {
    *length = (int)(sample_rate * duration);
    for (int i = 0; i < *length; i++) {
        wave[i] = sin(2 * PI * frequency * i / sample_rate);
    }
}

void generate_square_wave(double frequency, double sample_rate, double duration, double *wave, int *length) {
    *length = (int)(sample_rate * duration);
    for (int i = 0; i < *length; i++) {
        wave[i] = (sin(2 * PI * frequency * i / sample_rate) >= 0) ? 1.0 : -1.0;
    }
}

void generate_triangle_wave(double frequency, double sample_rate, double duration, double *wave, int *length) {
    *length = (int)(sample_rate * duration);
    double period = sample_rate / frequency;
    for (int i = 0; i < *length; i++) {
        double t = fmod(i, period) / period;
        wave[i] = (t < 0.5) ? (t * 4 - 1) : (1 - (t - 0.5) * 4);
    }
}

void apply_window(double *wave, int length, const char *window_type) {
    if (strcmp(window_type, "hamming") == 0) {
        for (int i = 0; i < length; i++) {
            wave[i] *= 0.54 - 0.46 * cos(2 * PI * i / (length - 1));
        }
    } else if (strcmp(window_type, "hanning") == 0) {
        for (int i = 0; i < length; i++) {
            wave[i] *= 0.5 * (1 - cos(2 * PI * i / (length - 1)));
        }
    } else if (strcmp(window_type, "blackman") == 0) {
        for (int i = 0; i < length; i++) {
            wave[i] *= 0.42 - 0.5 * cos(2 * PI * i / (length - 1)) + 0.08 * cos(4 * PI * i / (length - 1));
        }
    }
}

void print_wave(const double *wave, int length) {
    printf("Wave samples:\n");
    for (int i = 0; i < length; i++) {
        printf("%d: %lf\n", i, wave[i]);
    }
}