//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURE_SENSORS 10
#define SENSOR_NAME_LENGTH 20

// Structure to hold temperature sensor data
typedef struct {
    char name[SENSOR_NAME_LENGTH];
    double temperature;
    double threshold;
} temperature_sensor_t;

// Function prototypes
void initialize_sensors(temperature_sensor_t sensors[]);
void read_sensor_data(temperature_sensor_t sensors[]);
void monitor_sensors(temperature_sensor_t sensors[]);

int main() {
    temperature_sensor_t sensors[MAX_TEMPERATURE_SENSORS];

    // Initialize temperature sensors
    initialize_sensors(sensors);

    // Read sensor data and print to console
    read_sensor_data(sensors);

    // Monitor temperature sensors and send alert if temperature exceeds threshold
    monitor_sensors(sensors);

    return 0;
}

// Initialize temperature sensors with default values
void initialize_sensors(temperature_sensor_t sensors[]) {
    int i;
    for (i = 0; i < MAX_TEMPERATURE_SENSORS; i++) {
        sensors[i].temperature = 0.0;
        sensors[i].threshold = 0.0;
    }
}

// Read temperature data from sensors
void read_sensor_data(temperature_sensor_t sensors[]) {
    int i;
    for (i = 0; i < MAX_TEMPERATURE_SENSORS; i++) {
        printf("Enter temperature for sensor %d: ", i+1);
        scanf("%lf", &sensors[i].temperature);
    }
}

// Monitor temperature sensors and send alert if temperature exceeds threshold
void monitor_sensors(temperature_sensor_t sensors[]) {
    int i;
    for (i = 0; i < MAX_TEMPERATURE_SENSORS; i++) {
        if (sensors[i].temperature > sensors[i].threshold) {
            printf("Alert: Sensor %s temperature exceeded threshold of %.2lf degrees Celsius.\n", sensors[i].name, sensors[i].threshold);
        }
    }
}