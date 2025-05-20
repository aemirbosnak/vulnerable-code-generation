//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_TEMPERATURE_SENSORS 10
#define TEMPERATURE_SENSOR_NAME_LENGTH 20
#define TEMPERATURE_SENSOR_DATA_LENGTH 50

struct temperature_sensor {
    char name[TEMPERATURE_SENSOR_NAME_LENGTH];
    double current_temperature;
    double last_temperature;
    time_t last_updated;
};

int main() {
    struct temperature_sensor temperature_sensors[MAX_TEMPERATURE_SENSORS];
    int num_temperature_sensors = 0;

    // Initialize temperature sensors
    for (int i = 0; i < MAX_TEMPERATURE_SENSORS; i++) {
        temperature_sensors[i].current_temperature = 0;
        temperature_sensors[i].last_temperature = 0;
        temperature_sensors[i].last_updated = 0;
    }

    // Prompt user to add temperature sensors
    while (1) {
        printf("Enter temperature sensor name (max %d characters): ", TEMPERATURE_SENSOR_NAME_LENGTH - 1);
        scanf("%s", temperature_sensors[num_temperature_sensors].name);

        if (num_temperature_sensors == MAX_TEMPERATURE_SENSORS) {
            printf("Maximum number of temperature sensors reached.\n");
            break;
        }

        num_temperature_sensors++;
    }

    // Main loop to monitor temperature sensors
    while (1) {
        for (int i = 0; i < num_temperature_sensors; i++) {
            printf("Temperature sensor %s: ", temperature_sensors[i].name);

            if (temperature_sensors[i].current_temperature > 0) {
                if (temperature_sensors[i].current_temperature > temperature_sensors[i].last_temperature) {
                    printf("Rising\n");
                } else if (temperature_sensors[i].current_temperature < temperature_sensors[i].last_temperature) {
                    printf("Falling\n");
                } else {
                    printf("Stable\n");
                }
            } else {
                printf("No data available\n");
            }
        }

        sleep(1);
    }

    return 0;
}