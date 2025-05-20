//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <assert.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_MAX_LEN 20
#define TEMP_THRESHOLD 50.0

struct sensor {
    char name[SENSOR_NAME_MAX_LEN];
    double temp;
    time_t last_update;
};

void update_sensor_temp(struct sensor *sensor, double new_temp) {
    sensor->temp = new_temp;
    sensor->last_update = time(NULL);
}

void print_sensor_info(struct sensor *sensor) {
    printf("Sensor name: %s\n", sensor->name);
    printf("Current temperature: %.2f\n", sensor->temp);
    printf("Last updated: %s\n", ctime(&sensor->last_update));
}

int main() {
    int num_sensors;
    printf("Enter the number of sensors to monitor (max %d): ", MAX_SENSORS);
    scanf("%d", &num_sensors);

    struct sensor sensors[MAX_SENSORS];

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter sensor name for sensor %d: ", i + 1);
        scanf(" %[^\n]", sensors[i].name);
        sensors[i].temp = 0.0;
        sensors[i].last_update = 0;
    }

    while (1) {
        for (int i = 0; i < num_sensors; i++) {
            double new_temp = rand() % 100; // Simulate random temperature changes
            update_sensor_temp(&sensors[i], new_temp);

            if (new_temp > TEMP_THRESHOLD) {
                printf("WARNING: Sensor %s has exceeded temperature threshold of %.2f degrees!\n", sensors[i].name, TEMP_THRESHOLD);
            }
        }

        printf("\nCurrent sensor information:\n");
        for (int i = 0; i < num_sensors; i++) {
            print_sensor_info(&sensors[i]);
        }

        sleep(5); // Wait for 5 seconds before updating again
    }

    return 0;
}