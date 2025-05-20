//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10 // Maximum number of temperature sensors
#define SENSOR_NAME_LENGTH 20 // Maximum length of sensor name

typedef struct {
    char name[SENSOR_NAME_LENGTH]; // Name of the sensor
    double temperature; // Current temperature reading
} Sensor;

int main() {
    // Initialize sensor data
    Sensor sensors[MAX_SENSORS];
    int num_sensors = 0;

    // Read sensor data from a file
    FILE *fp = fopen("sensors.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open sensors.txt\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Sensor *sensor = &sensors[num_sensors++];
        if (num_sensors >= MAX_SENSORS) {
            fprintf(stderr, "Error: Too many sensors\n");
            exit(1);
        }

        char *name_start = strchr(line, ':');
        if (name_start == NULL) {
            fprintf(stderr, "Error: Invalid sensor data\n");
            exit(1);
        }

        strncpy(sensor->name, line, name_start - line);
        sensor->name[SENSOR_NAME_LENGTH - 1] = '\0';

        char *temp_start = strchr(name_start, ':');
        if (temp_start == NULL) {
            fprintf(stderr, "Error: Invalid sensor data\n");
            exit(1);
        }

        sensor->temperature = strtod(temp_start + 1, NULL);
    }

    fclose(fp);

    // Monitor sensor temperatures
    while (1) {
        for (int i = 0; i < num_sensors; i++) {
            Sensor *sensor = &sensors[i];

            double new_temp = 0.0;
            if (fscanf(stdin, "%lf:%s", &new_temp, sensor->name)!= 2) {
                fprintf(stderr, "Error: Invalid input\n");
                continue;
            }

            if (strcmp(sensor->name, sensor->name)!= 0) {
                fprintf(stderr, "Error: Sensor name mismatch\n");
                continue;
            }

            if (new_temp < -273.15 || new_temp > 1000.0) {
                fprintf(stderr, "Error: Invalid temperature reading\n");
                continue;
            }

            sensor->temperature = new_temp;
        }

        sleep(1); // Sleep for 1 second before checking again
    }

    return 0;
}