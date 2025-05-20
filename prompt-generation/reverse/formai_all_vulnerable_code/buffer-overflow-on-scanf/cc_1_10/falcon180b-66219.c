//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 100

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureReading;

int main() {
    TemperatureReading temperatures[MAX_TEMPERATURES];
    int temperatureCount = 0;
    float averageTemperature = 0.0;

    printf("Welcome to the Sherlock Holmes Temperature Monitor!\n");
    printf("We shall be observing the temperature changes over time.\n");
    printf("Please enter the initial temperature (in Celsius): ");
    scanf("%f", &temperatures[temperatureCount].temperature);
    temperatures[temperatureCount].timestamp = time(NULL);
    temperatureCount++;

    while (1) {
        printf("\nEnter 't' to take a new temperature reading, or 'q' to quit: ");
        char input;
        scanf(" %c", &input);

        if (input == 't') {
            printf("Enter the current temperature (in Celsius): ");
            scanf("%f", &temperatures[temperatureCount].temperature);
            temperatures[temperatureCount].timestamp = time(NULL);
            temperatureCount++;
        } else if (input == 'q') {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("\nTemperature readings:\n");
    for (int i = 0; i < temperatureCount; i++) {
        printf("%s: %.2f°C\n", ctime(&temperatures[i].timestamp), temperatures[i].temperature);
    }

    averageTemperature = 0.0;
    for (int i = 0; i < temperatureCount; i++) {
        averageTemperature += temperatures[i].temperature;
    }
    averageTemperature /= temperatureCount;

    printf("\nAverage temperature over the monitoring period: %.2f°C\n", averageTemperature);

    return 0;
}