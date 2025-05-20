//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LENGTH 20
#define SENSOR_VALUE_LENGTH 10

typedef struct {
    char name[SENSOR_NAME_LENGTH];
    double value;
} Sensor;

void read_sensors(Sensor sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sensors[i].value = rand() % 100; // simulate random sensor readings
        printf("Sensor %s: %.2f\n", sensors[i].name, sensors[i].value);
    }
}

void monitor_temperature(Sensor sensors[], int num_sensors, double threshold) {
    for (int i = 0; i < num_sensors; i++) {
        if (sensors[i].value >= threshold) {
            printf("Warning: Sensor %s is above threshold (%.2f)\n", sensors[i].name, threshold);
        }
    }
}

int main() {
    Sensor sensors[MAX_SENSORS];
    int num_sensors = 0;

    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
    }

    read_sensors(sensors, num_sensors);

    printf("\nEnter the temperature threshold: ");
    double threshold;
    scanf("%lf", &threshold);

    monitor_temperature(sensors, num_sensors, threshold);

    return 0;
}