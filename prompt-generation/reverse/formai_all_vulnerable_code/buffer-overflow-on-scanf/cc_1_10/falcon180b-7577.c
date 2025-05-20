//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP_SENSORS 10
#define SENSOR_NAME_MAX_LENGTH 20

typedef struct {
    char name[SENSOR_NAME_MAX_LENGTH];
    double current_temperature;
    double threshold;
} temperature_sensor_t;

int main() {
    int num_sensors;
    temperature_sensor_t sensors[MAX_TEMP_SENSORS];

    // Initialize all sensors to default values
    for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
        strcpy(sensors[i].name, "Sensor ");
        sprintf(&sensors[i].name[7], "%d", i + 1);
        sensors[i].current_temperature = 0.0;
        sensors[i].threshold = 0.0;
    }

    printf("Enter the number of temperature sensors: ");
    scanf("%d", &num_sensors);

    // Read in sensor names and threshold temperatures
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i + 1);
        scanf("%s", sensors[i].name);

        printf("Enter the threshold temperature for sensor %s: ", sensors[i].name);
        scanf("%lf", &sensors[i].threshold);
    }

    // Main monitoring loop
    while (1) {
        printf("\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("Sensor %s: %.2lf C\n", sensors[i].name, sensors[i].current_temperature);
        }
        printf("\n");

        sleep(5); // Sleep for 5 seconds before updating temperatures

        // Update sensor temperatures
        for (int i = 0; i < num_sensors; i++) {
            sensors[i].current_temperature += 1.0;

            if (sensors[i].current_temperature >= sensors[i].threshold) {
                printf("Warning: Sensor %s has exceeded threshold temperature of %.2lf C!\n", sensors[i].name, sensors[i].threshold);
            }
        }
    }

    return 0;
}