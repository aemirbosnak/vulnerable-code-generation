//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SENSORS 10
#define MAX_SENSOR_NAME_LEN 20

// Sensor structure
typedef struct {
    char name[MAX_SENSOR_NAME_LEN];
    double temp;
} Sensor;

// Function to initialize the sensor array
void initSensors(Sensor *sensors) {
    int i;
    for (i = 0; i < MAX_SENSORS; i++) {
        sensors[i].temp = 0.0;
        strcpy(sensors[i].name, "Sensor");
        sensors[i].name[6] = '0' + i;
    }
}

// Function to read sensor data from a file
void readSensorData(Sensor *sensors, FILE *fp) {
    char line[80];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %lf", sensors[0].name, &sensors[0].temp);
    }
}

// Function to display sensor data
void displaySensorData(Sensor *sensors) {
    int i;
    for (i = 0; i < MAX_SENSORS; i++) {
        printf("Sensor %d: %s\n", i, sensors[i].name);
        printf("Temperature: %.2lf C\n\n", sensors[i].temp);
    }
}

// Function to monitor sensor data
void monitorSensors(Sensor *sensors) {
    int i;
    for (i = 0; i < MAX_SENSORS; i++) {
        if (sensors[i].temp > 80.0) {
            printf("Warning! Sensor %d temperature is %.2lf C\n", i, sensors[i].temp);
        }
    }
}

int main() {
    FILE *fp;
    Sensor sensors[MAX_SENSORS];
    initSensors(sensors);

    // Open sensor data file
    fp = fopen("sensor_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening sensor data file!\n");
        exit(1);
    }

    // Read sensor data from file
    readSensorData(sensors, fp);

    // Display sensor data
    displaySensorData(sensors);

    // Monitor sensor data
    monitorSensors(sensors);

    // Close sensor data file
    fclose(fp);

    return 0;
}