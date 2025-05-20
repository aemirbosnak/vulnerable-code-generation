//FormAI DATASET v1.0 Category: Temperature monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TEMP_LOW 0            // minimum temperature
#define TEMP_HIGH 100         // maximum temperature
#define TEMP_THRESHOLD 70     // threshold temperature for warning message

bool isTemperatureValid(float temperature) {
    // Check if temperature is within valid range
    if (temperature < TEMP_LOW || temperature > TEMP_HIGH) {
        return false;
    }
    return true;
}

void displayTemperatureWarning(float temperature) {
    // Display a warning message if temperature is above the threshold
    if (temperature > TEMP_THRESHOLD) {
        printf("WARNING: Temperature is above threshold.\n");
    }
}

int main() {
    float temperature;        // temperature variable to store user input
    bool isTempValid = false; // flag to check if temperature entered is valid

    // Loop until user enters a valid temperature
    while (!isTempValid) {
        printf("Enter current temperature (between 0-100 C): ");
        // Read user input as float
        if (scanf("%f", &temperature) != 1) {
            // Handle non-numeric input properly
            printf("Invalid input. Try again.\n");
            // Clear the input buffer
            while(getchar() != '\n');
        }
        else if (!isTemperatureValid(temperature)) {
            printf("Temperature is out of range. Try again.\n");
        }
        else {
            isTempValid = true;
        }
    }

    // Display the temperature and any relevant warnings
    printf("Current temperature is %f C.\n", temperature);
    displayTemperatureWarning(temperature);

    return 0;
}