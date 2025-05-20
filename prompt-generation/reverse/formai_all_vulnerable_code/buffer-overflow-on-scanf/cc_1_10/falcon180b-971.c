//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10
#define MAX_SENSOR_NAME_LENGTH 20

typedef struct {
    char name[MAX_SENSOR_NAME_LENGTH];
    double current_temperature;
    double min_temperature;
    double max_temperature;
} TemperatureSensor;

int main() {
    int num_sensors;
    TemperatureSensor sensors[MAX_SENSORS];

    // Initialize sensors
    for (int i = 0; i < MAX_SENSORS; i++) {
        sensors[i].current_temperature = 0;
        sensors[i].min_temperature = -273.15; // Absolute zero
        sensors[i].max_temperature = 1000; // Arbitrary high value
    }

    // Read number of sensors from user input
    printf("Enter number of sensors (1 to %d): ", MAX_SENSORS);
    scanf("%d", &num_sensors);

    // Read sensor names and initialize min/max temperatures
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter sensor %d name: ", i+1);
        scanf("%s", sensors[i].name);
        sensors[i].min_temperature = sensors[i].current_temperature;
        sensors[i].max_temperature = sensors[i].current_temperature;
    }

    // Main monitoring loop
    while (1) {
        for (int i = 0; i < num_sensors; i++) {
            // Read current temperature from user input
            printf("Enter temperature for sensor %s: ", sensors[i].name);
            scanf("%lf", &sensors[i].current_temperature);

            // Update min/max temperatures
            if (sensors[i].current_temperature < sensors[i].min_temperature) {
                sensors[i].min_temperature = sensors[i].current_temperature;
            }
            if (sensors[i].current_temperature > sensors[i].max_temperature) {
                sensors[i].max_temperature = sensors[i].current_temperature;
            }
        }

        // Print current temperatures and min/max temperatures
        printf("\nCurrent temperatures:\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("%s: %.2lf C\n", sensors[i].name, sensors[i].current_temperature);
        }
        printf("\nMin/Max temperatures:\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("%s: Min %.2lf C, Max %.2lf C\n", sensors[i].name, sensors[i].min_temperature, sensors[i].max_temperature);
        }

        // Wait for 1 second before updating again
        sleep(1);
    }

    return 0;
}