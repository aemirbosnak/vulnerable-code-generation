//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SENSORS 10
#define ALERT_THRESHOLD 75.0

typedef struct {
    char name[50];
    float *readings;
    int count;
    int capacity;
} Sensor;

void initializeSensor(Sensor *sensor, const char *name) {
    strncpy(sensor->name, name, 50);
    sensor->readings = malloc(sizeof(float) * 5); // initial capacity of 5
    sensor->count = 0;
    sensor->capacity = 5;
}

void addReading(Sensor *sensor, float reading) {
    if (sensor->count >= sensor->capacity) {
        // Resize the readings array
        sensor->capacity *= 2;
        sensor->readings = realloc(sensor->readings, sizeof(float) * sensor->capacity);
    }
    sensor->readings[sensor->count] = reading;
    sensor->count++;
}

float calculateAverage(Sensor *sensor) {
    float sum = 0.0;
    for (int i = 0; i < sensor->count; i++) {
        sum += sensor->readings[i];
    }
    return (sensor->count > 0) ? sum / sensor->count : 0.0;
}

void checkForAlerts(Sensor *sensor) {
    for (int i = 0; i < sensor->count; i++) {
        if (sensor->readings[i] > ALERT_THRESHOLD) {
            printf("Alert! %s recorded a high temperature: %.2f\n", sensor->name, sensor->readings[i]);
        }
    }
}

void report(Sensor *sensor) {
    printf("\n--- Report for Sensor: %s ---\n", sensor->name);
    printf("Total Readings: %d\n", sensor->count);
    printf("Average Temperature: %.2f\n", calculateAverage(sensor));
    checkForAlerts(sensor);
    printf("-----------------------------\n");
}

void cleanup(Sensor *sensor) {
    free(sensor->readings);
}

int main() {
    int numSensors;
    Sensor sensors[MAX_SENSORS];

    printf("Enter number of temperature sensors (max %d): ", MAX_SENSORS);
    scanf("%d", &numSensors);
    
    if (numSensors > MAX_SENSORS || numSensors <= 0) {
        printf("Invalid number of sensors. Please run the program again.\n");
        return 1;
    }

    for (int i = 0; i < numSensors; i++) {
        char sensorName[50];
        printf("Enter name for sensor %d: ", i + 1);
        scanf("%s", sensorName);
        initializeSensor(&sensors[i], sensorName);
    }

    for (int i = 0; i < numSensors; i++) {
        printf("\nEntering readings for sensor: %s\n", sensors[i].name);
        printf("How many readings would you like to enter? ");
        int numReadings;
        scanf("%d", &numReadings);

        for (int j = 0; j < numReadings; j++) {
            float temperature;
            printf("Enter temperature reading %d: ", j + 1);
            scanf("%f", &temperature);
            addReading(&sensors[i], temperature);
        }
    }

    for (int i = 0; i < numSensors; i++) {
        report(&sensors[i]);
        cleanup(&sensors[i]);
    }

    return 0;
}