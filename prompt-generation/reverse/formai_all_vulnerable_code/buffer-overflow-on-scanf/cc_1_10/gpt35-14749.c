//FormAI DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function declaration
void monitorTemperature(int *temperature, int *maxTemperature, int *minTemperature);

int main()
{
    int temperature = 0;
    int maxTemperature = 70; // Default maximum temperature
    int minTemperature = 30; // Default minimum temperature

    printf("Welcome to the Temperature Monitor!\n");

    // Ask user to set the maximum temperature
    printf("Enter the maximum temperature (press enter to use default of 70): ");
    char maxTempInput[10];
    fgets(maxTempInput, 10, stdin);
    if (maxTempInput[0] != '\n') {
        maxTemperature = atoi(maxTempInput);
    }

    // Ask user to set the minimum temperature
    printf("Enter the minimum temperature (press enter to use default of 30): ");
    char minTempInput[10];
    fgets(minTempInput, 10, stdin);
    if (minTempInput[0] != '\n') {
        minTemperature = atoi(minTempInput);
    }

    // Prompt user to input temperature
    printf("Enter the current temperature: ");
    scanf("%d", &temperature);

    // Monitor temperature
    monitorTemperature(&temperature, &maxTemperature, &minTemperature);

    return 0;
}

void monitorTemperature(int *temperature, int *maxTemperature, int *minTemperature) {
    while (*temperature >= *minTemperature && *temperature <= *maxTemperature) {
        // Temperature is within acceptable range
        printf("Temperature is good. ");
        printf("Max temp: %d, Min temp: %d, Current temp: %d\n", *maxTemperature, *minTemperature, *temperature);

        // Prompt user to input temperature again
        printf("Enter the current temperature: ");
        scanf("%d", temperature);
    }

    // Temperature is outside acceptable range
    printf("Temperature outside range. ");
    printf("Max temp: %d, Min temp: %d, Current temp: %d\n", *maxTemperature, *minTemperature, *temperature);
}