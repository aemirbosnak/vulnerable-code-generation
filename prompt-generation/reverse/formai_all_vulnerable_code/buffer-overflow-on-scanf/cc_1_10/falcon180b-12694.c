//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_TEMP_SENSORS 10
#define TEMP_SENSOR_NAME_LENGTH 50
#define TEMP_SENSOR_VALUE_LENGTH 20
#define TEMP_SENSOR_VALUE_FORMAT "%.2f"

typedef struct {
    char name[TEMP_SENSOR_NAME_LENGTH];
    double value;
    time_t timestamp;
} TempSensorData;

void initTempSensorData(TempSensorData *sensorData) {
    sensorData->value = 0.0;
    sensorData->timestamp = 0;
}

void updateTempSensorData(TempSensorData *sensorData, double newValue) {
    sensorData->value = newValue;
    sensorData->timestamp = time(NULL);
}

void printTempSensorData(TempSensorData *sensorData) {
    printf("%s: %.2f (updated at %s)\n", sensorData->name, sensorData->value, ctime(&sensorData->timestamp));
}

int main() {
    int numSensors = 0;
    TempSensorData sensors[MAX_TEMP_SENSORS];

    // Initialize temperature sensor data
    for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
        initTempSensorData(&sensors[i]);
    }

    // Get user input for temperature sensor names
    printf("Enter temperature sensor names (up to %d sensors):\n", MAX_TEMP_SENSORS);
    for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
        scanf("%s", sensors[i].name);
        numSensors++;
    }

    // Start monitoring temperature sensors
    while (1) {
        // Get user input for temperature values
        printf("Enter temperature values for each sensor (in Celsius):\n");
        for (int i = 0; i < numSensors; i++) {
            scanf("%s", sensors[i].name);
            double value;
            if (sscanf(sensors[i].name, "%lf", &value) == 1) {
                updateTempSensorData(&sensors[i], value);
            }
        }

        // Print temperature sensor data
        printf("Temperature sensor data:\n");
        for (int i = 0; i < numSensors; i++) {
            printTempSensorData(&sensors[i]);
        }

        // Wait for 10 seconds before monitoring again
        sleep(10);
    }

    return 0;
}