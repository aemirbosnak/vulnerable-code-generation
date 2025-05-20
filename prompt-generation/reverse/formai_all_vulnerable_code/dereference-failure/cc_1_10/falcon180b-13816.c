//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// Function to read temperature sensor
double read_temperature() {
    double temperature = 0.0;
    // Code to read temperature from sensor
    return temperature;
}

// Function to calculate average temperature
double calculate_average_temperature(double *temperatures, int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += temperatures[i];
    }
    return sum / count;
}

// Function to print temperature report
void print_temperature_report(double temperature, double average_temperature) {
    printf("Current temperature: %.2f\n", temperature);
    printf("Average temperature: %.2f\n", average_temperature);
}

// Function to monitor temperature
void monitor_temperature(double *temperatures, int count, double threshold) {
    for (int i = 0; i < count; i++) {
        if (temperatures[i] > threshold) {
            printf("Temperature exceeded threshold: %.2f\n", temperatures[i]);
        }
    }
}

int main() {
    int count = 10;
    double threshold = 25.0;
    double *temperatures = (double *)malloc(count * sizeof(double));

    // Initialize temperature array
    for (int i = 0; i < count; i++) {
        temperatures[i] = read_temperature();
    }

    // Monitor temperature
    monitor_temperature(temperatures, count, threshold);

    // Calculate average temperature
    double average_temperature = calculate_average_temperature(temperatures, count);

    // Print temperature report
    print_temperature_report(temperatures[count - 1], average_temperature);

    free(temperatures);
    return 0;
}