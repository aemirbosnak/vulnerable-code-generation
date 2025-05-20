//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SAMPLE_RATE 1000 // Sample rate in milliseconds
#define MAX_SAMPLES 10 // Maximum number of samples to store
#define MIN_TEMP -40 // Minimum temperature in Celsius
#define MAX_TEMP 85 // Maximum temperature in Celsius

typedef struct {
    time_t timestamp;
    double temperature;
} Sample;

void print_samples(Sample samples[], int num_samples) {
    printf("Temperature samples:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%s: %.2f°C\n", ctime(&samples[i].timestamp), samples[i].temperature);
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator with current time

    Sample samples[MAX_SAMPLES]; // Array to store temperature samples
    int num_samples = 0; // Number of samples stored

    // Initialize temperature range
    double temp_range = MAX_TEMP - MIN_TEMP;

    // Initialize temperature to a random value within the range
    double current_temp = MIN_TEMP + rand() % (int)(temp_range * 1000) / 1000.0;

    // Start an infinite loop to continuously monitor temperature
    while (1) {
        // Wait for SAMPLE_RATE milliseconds
        usleep(SAMPLE_RATE * 1000);

        // Generate a new temperature value within the range
        current_temp += rand() % 2? -0.1 : 0.1; // Randomly increase or decrease temperature

        // Store the temperature sample if the array is not full
        if (num_samples < MAX_SAMPLES) {
            samples[num_samples].timestamp = time(NULL);
            samples[num_samples].temperature = current_temp;
            num_samples++;
        } else { // Otherwise, remove the oldest sample and add the new one
            for (int i = 0; i < MAX_SAMPLES - 1; i++) {
                samples[i] = samples[i + 1];
            }
            samples[MAX_SAMPLES - 1].timestamp = time(NULL);
            samples[MAX_SAMPLES - 1].temperature = current_temp;
        }

        // Print the temperature samples every 10 seconds
        if (num_samples >= MAX_SAMPLES && (int)(time(NULL) - samples[0].timestamp) >= 10) {
            print_samples(samples, num_samples);
        }
    }

    return 0;
}