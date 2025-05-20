//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_MAX_LENGTH 20
#define TEMP_THRESHOLD 100
#define TEMP_SENSOR_ERROR 0.1

typedef struct {
    char name[SENSOR_NAME_MAX_LENGTH];
    float temperature;
    float threshold;
    int error;
} TempSensor;

void init_sensor(TempSensor* sensor, char* name, float threshold) {
    strncpy(sensor->name, name, SENSOR_NAME_MAX_LENGTH);
    sensor->temperature = 0.0;
    sensor->threshold = threshold;
    sensor->error = 0;
}

int is_valid_sensor(TempSensor* sensor) {
    return (sensor->temperature >= -273.15 && sensor->temperature <= 1000.0 && sensor->threshold >= -273.15 && sensor->threshold <= 1000.0 && sensor->error >= 0.0 && sensor->error <= 1.0);
}

int main() {
    TempSensor sensors[MAX_SENSORS];
    int num_sensors = 0;
    char input[100];
    float temperature;
    float threshold;
    int error;

    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", input);
        strncpy(sensors[i].name, input, SENSOR_NAME_MAX_LENGTH);

        printf("Enter the temperature threshold for sensor %s: ", sensors[i].name);
        scanf("%f", &threshold);
        sensors[i].threshold = threshold;

        printf("Enter the temperature error for sensor %s: ", sensors[i].name);
        scanf("%f", &error);
        sensors[i].error = error;
    }

    while (1) {
        for (int i = 0; i < num_sensors; i++) {
            printf("Enter the temperature for sensor %s: ", sensors[i].name);
            scanf("%f", &temperature);

            sensors[i].temperature = temperature;
            sensors[i].error += TEMP_SENSOR_ERROR;

            if (temperature >= sensors[i].threshold - sensors[i].error && temperature <= sensors[i].threshold + sensors[i].error) {
                printf("Sensor %s is within threshold.\n", sensors[i].name);
            } else {
                printf("Sensor %s is out of threshold.\n", sensors[i].name);
            }
        }

        sleep(1);
    }

    return 0;
}