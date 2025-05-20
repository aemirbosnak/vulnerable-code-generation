//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50.0
#define MIN_TEMPERATURE -10.0

void simulateTemperature(float *currentTemperature) {
    // Simulating temperature between the defined maximum and minimum
    *currentTemperature = ((float)rand() / RAND_MAX) * (MAX_TEMPERATURE - MIN_TEMPERATURE) + MIN_TEMPERATURE;
}

int main() {
    float currentTemperature;
    float thresholdTemperature;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please set the temperature threshold for alerts (between %.1f and %.1f degrees): ", MIN_TEMPERATURE, MAX_TEMPERATURE);
    
    // Input the threshold temperature from the user
    while (1) {
        scanf("%f", &thresholdTemperature);
        if (thresholdTemperature >= MIN_TEMPERATURE && thresholdTemperature <= MAX_TEMPERATURE) {
            break;
        } else {
            printf("Invalid input. Please enter a value between %.1f and %.1f degrees: ", MIN_TEMPERATURE, MAX_TEMPERATURE);
        }
    }

    printf("Threshold set to %.1f degrees.\n", thresholdTemperature);

    // Start monitoring the temperature
    do {
        // Simulate temperature reading
        simulateTemperature(&currentTemperature);
        printf("Current Temperature: %.1f degrees\n", currentTemperature);

        // Check if current temperature exceeds the threshold
        if (currentTemperature > thresholdTemperature) {
            printf("ALERT! Current temperature %.1f degrees exceeds threshold of %.1f degrees!\n", currentTemperature, thresholdTemperature);
        }

        // Ask user if they want to continue monitoring
        printf("Do you want to continue monitoring? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Temperature Monitor. Goodbye!\n");
    return 0;
}