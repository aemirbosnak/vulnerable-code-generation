//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LEN 50
#define BUFFER_SIZE 100

typedef struct {
    char name[SENSOR_NAME_LEN];
    double current_temperature;
    double min_temperature;
    double max_temperature;
    time_t last_update;
} Sensor;

void update_sensor(Sensor* sensor, double temperature) {
    sensor->current_temperature = temperature;
    sensor->last_update = time(NULL);
    if (temperature < sensor->min_temperature) {
        sensor->min_temperature = temperature;
    }
    if (temperature > sensor->max_temperature) {
        sensor->max_temperature = temperature;
    }
}

void print_sensor_info(Sensor* sensor) {
    printf("Sensor name: %s\n", sensor->name);
    printf("Current temperature: %.2f\n", sensor->current_temperature);
    printf("Minimum temperature: %.2f\n", sensor->min_temperature);
    printf("Maximum temperature: %.2f\n", sensor->max_temperature);
    printf("Last update: %s", ctime(&sensor->last_update));
}

int main() {
    int num_sensors;
    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    if (num_sensors < 1 || num_sensors > MAX_SENSORS) {
        printf("Invalid number of sensors.\n");
        return 1;
    }

    Sensor sensors[MAX_SENSORS];
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i + 1);
        scanf("%s", sensors[i].name);
        sensors[i].current_temperature = 0.0;
        sensors[i].min_temperature = 1000.0;
        sensors[i].max_temperature = -1000.0;
        sensors[i].last_update = 0;
    }

    while (1) {
        printf("\nTemperature Monitor\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("Sensor %d: %s\n", i + 1, sensors[i].name);
            printf("Current temperature: %.2f\n", sensors[i].current_temperature);
            printf("Minimum temperature: %.2f\n", sensors[i].min_temperature);
            printf("Maximum temperature: %.2f\n", sensors[i].max_temperature);
            printf("Last update: %s", ctime(&sensors[i].last_update));
        }

        printf("\nEnter 'q' to quit, or's' to update a sensor: ");
        char command;
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        } else if (command =='s') {
            int sensor_index;
            printf("Enter the index of the sensor to update (1-%d): ", num_sensors);
            scanf("%d", &sensor_index);

            if (sensor_index < 1 || sensor_index > num_sensors) {
                printf("Invalid sensor index.\n");
            } else {
                printf("Enter the new temperature for sensor %d: ", sensor_index);
                double temperature;
                scanf("%lf", &temperature);
                update_sensor(&sensors[sensor_index - 1], temperature);
            }
        }
    }

    return 0;
}