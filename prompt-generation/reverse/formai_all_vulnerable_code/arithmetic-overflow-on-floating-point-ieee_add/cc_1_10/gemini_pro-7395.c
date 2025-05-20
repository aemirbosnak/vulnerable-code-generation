//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Initialize global variables
double temperature_start = 0.0;
double temperature_end = 0.0;
double temperature_step = 0.0;
char *temperature_unit = NULL;
bool temperature_reached = false;

// Initialize function prototypes
void temperature_monitor(double temperature_start, double temperature_end, double temperature_step, char *temperature_unit);
bool is_temperature_reached(double temperature, double temperature_end);

int main(int argc, char *argv[]) {
    // Check for valid command-line arguments
    if (argc != 5) {
        printf("Usage: %s <temperature_start> <temperature_end> <temperature_step> <temperature_unit>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    temperature_start = atof(argv[1]);
    temperature_end = atof(argv[2]);
    temperature_step = atof(argv[3]);
    temperature_unit = argv[4];

    // Check for valid temperature range and step
    if (temperature_start >= temperature_end) {
        printf("Error: Temperature range must be valid (start < end).\n");
        return 1;
    }
    if (temperature_step <= 0.0) {
        printf("Error: Temperature step must be positive.\n");
        return 1;
    }

    // Start monitoring temperature
    temperature_monitor(temperature_start, temperature_end, temperature_step, temperature_unit);

    // Check if temperature has reached the end point
    if (!temperature_reached) {
        printf("Error: Temperature did not reach the end point (%f %s).\n", temperature_end, temperature_unit);
        return 1;
    }

    // Exit successfully
    return 0;
}

void temperature_monitor(double temperature_start, double temperature_end, double temperature_step, char *temperature_unit) {
    // Initialize temperature
    double temperature = temperature_start;

    // Continuously monitor temperature until it reaches the end point
    while (!is_temperature_reached(temperature, temperature_end)) {
        // Display current temperature
        printf("Current temperature: %f %s\n", temperature, temperature_unit);

        // Increment temperature
        temperature += temperature_step;
    }

    // Set temperature_reached flag to true
    temperature_reached = true;
}

bool is_temperature_reached(double temperature, double temperature_end) {
    // Check if temperature is within a tolerance of the end point
    double tolerance = 0.01;
    return fabs(temperature - temperature_end) < tolerance;
}