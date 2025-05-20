//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMPERATURES 100
#define MAX_TEMPERATURE_NAME_LENGTH 20

typedef struct {
    char name[MAX_TEMPERATURE_NAME_LENGTH];
    double value;
    time_t timestamp;
} Temperature;

int main() {
    Temperature temperatures[MAX_TEMPERATURES];
    int numTemperatures = 0;
    double currentTemperature = 0.0;
    char input[MAX_TEMPERATURE_NAME_LENGTH];
    double temperatureValue;
    time_t currentTime;

    // Get the current time
    time(&currentTime);

    // Loop until the user decides to quit
    while (1) {
        // Print the current temperature
        printf("Current temperature: %.2f\n", currentTemperature);

        // Get user input
        printf("Enter temperature name: ");
        scanf("%s", input);

        // Check if the input is a number
        if (sscanf(input, "%lf", &temperatureValue) == 1) {
            // Add the temperature to the list
            temperatures[numTemperatures].name[0] = '\0';
            strncat(temperatures[numTemperatures].name, input, MAX_TEMPERATURE_NAME_LENGTH - 1);
            temperatures[numTemperatures].value = temperatureValue;
            temperatures[numTemperatures].timestamp = currentTime;
            numTemperatures++;
        } else {
            // Display an error message
            printf("Invalid input. Please enter a temperature value.\n");
        }
    }

    return 0;
}