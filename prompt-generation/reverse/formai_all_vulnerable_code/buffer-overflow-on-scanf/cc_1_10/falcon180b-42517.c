//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURES 100

typedef struct {
    time_t timestamp;
    double temperature;
} TemperatureReading;

int main() {
    int i, numReadings;
    TemperatureReading readings[MAX_TEMPERATURES];
    double average, min, max;
    char input[32];

    printf("Welcome to the Temperature Monitor!\n");
    printf("How many temperature readings would you like to take? ");
    scanf("%d", &numReadings);

    for (i = 0; i < numReadings; i++) {
        printf("Please enter the temperature in Celsius: ");
        scanf("%s", input);
        readings[i].temperature = atof(input);
        readings[i].timestamp = time(NULL);
    }

    printf("\nTemperature Readings:\n");
    for (i = 0; i < numReadings; i++) {
        printf("%.2f Celsius at %s\n", readings[i].temperature, ctime(&readings[i].timestamp));
    }

    average = 0.0;
    min = max = readings[0].temperature;

    for (i = 0; i < numReadings; i++) {
        average += readings[i].temperature;
        if (readings[i].temperature < min) {
            min = readings[i].temperature;
        }
        if (readings[i].temperature > max) {
            max = readings[i].temperature;
        }
    }

    average /= numReadings;

    printf("\nAverage temperature: %.2f Celsius\n", average);
    printf("Minimum temperature: %.2f Celsius\n", min);
    printf("Maximum temperature: %.2f Celsius\n", max);

    return 0;
}