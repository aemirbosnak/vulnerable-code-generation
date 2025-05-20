//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 10
#define SAMPLE_INTERVAL_SECONDS 1

// Function to get current temperature in Celsius
double get_temperature() {
    FILE *fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    double temp;
    if (fp == NULL) {
        printf("Error: Unable to open temperature file.\n");
        exit(1);
    }
    if (fscanf(fp, "%lf", &temp)!= 1) {
        printf("Error: Unable to read temperature data.\n");
        exit(1);
    }
    fclose(fp);
    return temp / 1000.0;
}

// Function to calculate average temperature over a number of samples
double calculate_average_temperature(double temperatures[], int num_samples) {
    double sum = 0.0;
    for (int i = 0; i < num_samples; i++) {
        sum += temperatures[i];
    }
    return sum / num_samples;
}

// Function to print temperature data
void print_temperature_data(double temperatures[], int num_samples) {
    printf("Temperature data:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("Sample %d: %.2f°C\n", i + 1, temperatures[i]);
    }
    printf("Average temperature: %.2f°C\n", calculate_average_temperature(temperatures, num_samples));
}

int main() {
    double temperatures[NUM_SAMPLES];
    srand(time(NULL));

    // Take initial temperature reading
    double initial_temperature = get_temperature();
    printf("Initial temperature: %.2f°C\n", initial_temperature);

    // Take additional samples at regular intervals
    for (int i = 0; i < NUM_SAMPLES - 1; i++) {
        double temperature = get_temperature();
        temperatures[i] = temperature;
        printf("Sample %d: %.2f°C\n", i + 1, temperature);
        sleep(SAMPLE_INTERVAL_SECONDS);
    }

    // Print temperature data
    print_temperature_data(temperatures, NUM_SAMPLES);

    return 0;
}