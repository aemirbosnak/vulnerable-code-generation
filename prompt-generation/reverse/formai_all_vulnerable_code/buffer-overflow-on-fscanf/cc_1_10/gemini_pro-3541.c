//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>

// Define the temperature sensor's resolution and range
#define TEMP_RES 0.0625
#define TEMP_MIN -55.0
#define TEMP_MAX 125.0

// Define the number of temperature readings to take
#define NUM_READINGS 100

// Main program loop
int main(void) {
    // Initialize variables
    int i;
    float temp_raw, temp_celsius, temp_fahrenheit;
    
    // Print a header
    printf("Temperature Monitor\n");
    printf("---------------------\n");

    // Open the temperature sensor file
    FILE *temp_file = fopen("/sys/bus/iio/devices/iio:device0/in_temp0_raw", "r");
    if (temp_file == NULL) {
        perror("Error opening temperature sensor file");
        return EXIT_FAILURE;
    }
    
    // Take and print temperature readings
    for (i = 0; i < NUM_READINGS; i++) {
        // Read the raw temperature value
        fscanf(temp_file, "%f", &temp_raw);
        
        // Convert the raw temperature value to Celsius
        temp_celsius = TEMP_MIN + (temp_raw * TEMP_RES);
        
        // Convert the Celsius temperature value to Fahrenheit
        temp_fahrenheit = (temp_celsius * 9.0 / 5.0) + 32.0;
        
        // Print the temperature readings
        printf("Reading %d: %.2f C (%.2f F)\n", i + 1, temp_celsius, temp_fahrenheit);
        
        // Sleep for 1 second
        sleep(1);
    }
    
    // Close the temperature sensor file
    fclose(temp_file);
    
    // Return success
    return EXIT_SUCCESS;
}