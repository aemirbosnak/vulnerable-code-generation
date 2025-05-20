//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SENSORS 10
#define MAX_SENSOR_NAME_LENGTH 20

typedef struct {
    char name[MAX_SENSOR_NAME_LENGTH];
    float temperature;
    time_t last_updated;
} Sensor;

int main() {
    int num_sensors = 0;
    Sensor sensors[MAX_SENSORS];

    while (num_sensors < MAX_SENSORS) {
        printf("Enter name of sensor (or enter 'done' to finish): ");
        char name[MAX_SENSOR_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        strcpy(sensors[num_sensors].name, name);
        sensors[num_sensors].temperature = 0.0;
        sensors[num_sensors].last_updated = 0;
        num_sensors++;
    }

    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_sensors; i++) {
            if (current_time - sensors[i].last_updated >= 5) {
                printf("Reading temperature from %s...\n", sensors[i].name);
                sensors[i].temperature = (float)rand() / RAND_MAX * 100;
                sensors[i].last_updated = current_time;
            }

            printf("Temperature of %s is %.2f degrees Celsius.\n", sensors[i].name, sensors[i].temperature);
        }

        sleep(5);
    }

    return 0;
}