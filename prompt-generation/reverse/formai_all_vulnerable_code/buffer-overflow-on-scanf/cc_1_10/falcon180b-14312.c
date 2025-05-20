//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENSORS 10
#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 1 // seconds

typedef struct {
    float temperature;
    time_t timestamp;
} SensorReading;

int main() {
    int numSensors = 0;
    float temperatures[MAX_SENSORS];
    SensorReading readings[MAX_SENSORS][MAX_SAMPLES];
    char sensorNames[MAX_SENSORS][20];

    while (numSensors < MAX_SENSORS) {
        printf("Enter name for sensor %d: ", numSensors + 1);
        scanf("%s", sensorNames[numSensors]);
        printf("Enter initial temperature for %s: ", sensorNames[numSensors]);
        scanf("%f", &temperatures[numSensors]);
        numSensors++;
    }

    for (int i = 0; i < numSensors; i++) {
        readings[i][0].temperature = temperatures[i];
        readings[i][0].timestamp = time(NULL);
    }

    while (1) {
        for (int i = 0; i < numSensors; i++) {
            float currentTemp = 0;
            int numReadings = 0;

            for (int j = 0; j < MAX_SAMPLES; j++) {
                if (readings[i][j].timestamp > 0) {
                    currentTemp += readings[i][j].temperature;
                    numReadings++;
                }
            }

            if (numReadings > 0) {
                currentTemp /= numReadings;
                printf("%s: %.2f\n", sensorNames[i], currentTemp);
            }
        }

        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}