//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_SENSORS 10
#define MAX_SENSOR_NAME_LENGTH 50

typedef struct {
    char name[MAX_SENSOR_NAME_LENGTH];
    float temp;
    float threshold;
} temp_sensor_t;

void read_sensor_data(temp_sensor_t sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sensors[i].temp = rand() % 100; // simulate random temperature data
        if (sensors[i].temp > sensors[i].threshold) {
            sensors[i].temp = sensors[i].threshold; // cap temperature at threshold
        }
    }
}

void print_sensor_data(temp_sensor_t sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        printf("Sensor %s: %.2f°C\n", sensors[i].name, sensors[i].temp);
    }
}

int main() {
    srand(time(NULL));
    temp_sensor_t sensors[MAX_TEMP_SENSORS];
    int num_sensors = 0;

    while (num_sensors < MAX_TEMP_SENSORS) {
        printf("Enter name of temperature sensor (or press enter to finish): ");
        scanf("%s", sensors[num_sensors].name);
        if (strcmp(sensors[num_sensors].name, "") == 0) {
            break;
        }
        printf("Enter temperature threshold for %s (in °C): ", sensors[num_sensors].name);
        scanf("%f", &sensors[num_sensors].threshold);
        num_sensors++;
    }

    while (1) {
        read_sensor_data(sensors, num_sensors);
        print_sensor_data(sensors, num_sensors);
        sleep(1);
    }

    return 0;
}