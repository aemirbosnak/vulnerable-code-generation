//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 100.0
#define MIN_TEMPERATURE 0.0
#define MAX_TIME 24.0

int main() {
    float temperature;
    float time_elapsed = 0.0;

    // Get initial temperature
    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temperature);

    // Check if temperature is within range
    if (temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE) {
        printf("Error: Temperature is not within the valid range of 0 to 100 Celsius.\n");
        return 1;
    }

    // Keep updating temperature for 24 hours
    while (time_elapsed < MAX_TIME) {
        // Generate random temperature change
        srand(time(NULL));
        float change = ((float) rand() / (RAND_MAX)) * 10 - 5;  // -5 to 5 degree Celsius change
        
        // Update temperature
        temperature += change;

        // Check if temperature is within range
        if (temperature < MIN_TEMPERATURE) {
            temperature = MIN_TEMPERATURE;
        } else if (temperature > MAX_TEMPERATURE) {
            temperature = MAX_TEMPERATURE;
        }

        // Print current temperature
        printf("Current temperature: %.2f Celsius\n", temperature);

        // Sleep for 1 hour
        printf("Waiting for 1 hour...\n");
        sleep(3600);  // 3600 seconds = 1 hour
        time_elapsed += 1.0;
    }

    printf("24 hours has passed. Temperature monitoring is complete.\n");

    return 0;
}