//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURES 1000
#define TEMPERATURE_INTERVAL_SECONDS 5

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureReading;

int main() {
    TemperatureReading readings[MAX_TEMPERATURES];
    int numReadings = 0;
    FILE *temperatureFile = NULL;

    if ((temperatureFile = fopen("temperature.csv", "a")) == NULL) {
        printf("Error opening temperature file\n");
        exit(1);
    }

    while (1) {
        TemperatureReading currentReading;
        if (fscanf(temperatureFile, "%ld,%f\n", &currentReading.timestamp, &currentReading.temperature)!= 2) {
            printf("Error reading temperature file\n");
            exit(1);
        }

        if (numReadings >= MAX_TEMPERATURES) {
            numReadings = 0;
        }

        readings[numReadings++] = currentReading;

        if (numReadings == 1) {
            printf("First temperature reading: %.2f C at %s\n", currentReading.temperature, ctime(&currentReading.timestamp));
        } else if ((currentReading.timestamp - readings[numReadings - 2].timestamp) >= (TEMPERATURE_INTERVAL_SECONDS * 1000000)) {
            float avgTemperature = 0.0;
            int numAvgTemperatures = 0;

            for (int i = 0; i < numReadings - 1; i++) {
                avgTemperature += readings[i].temperature;
                numAvgTemperatures++;
            }

            avgTemperature /= numAvgTemperatures;

            printf("Average temperature over the last %d seconds: %.2f C\n", TEMPERATURE_INTERVAL_SECONDS, avgTemperature);
        }
    }

    return 0;
}