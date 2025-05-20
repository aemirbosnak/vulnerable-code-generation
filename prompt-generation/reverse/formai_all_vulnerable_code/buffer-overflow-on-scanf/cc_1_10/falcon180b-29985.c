//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_SENSORS 10
#define SENSOR_NAME_LEN 20
#define SENSOR_VALUE_LEN 10

typedef struct {
    char name[SENSOR_NAME_LEN];
    char value[SENSOR_VALUE_LEN];
} temperature_sensor_t;

void init_sensors(temperature_sensor_t sensors[]) {
    for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
        sensors[i].name[0] = '\0';
        sensors[i].value[0] = '\0';
    }
}

void update_sensor_value(temperature_sensor_t sensors[], int sensor_index, char value[]) {
    strncpy(sensors[sensor_index].value, value, SENSOR_VALUE_LEN);
}

void print_sensors(temperature_sensor_t sensors[]) {
    printf("Sensor Name\t| Sensor Value\n");
    for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
        if (sensors[i].name[0]!= '\0') {
            printf("%-20s\t| %s\n", sensors[i].name, sensors[i].value);
        }
    }
}

int main() {
    temperature_sensor_t sensors[MAX_TEMP_SENSORS];
    init_sensors(sensors);

    while (1) {
        time_t now = time(0);
        struct tm *tm = localtime(&now);
        printf("\nCurrent date and time: %s", asctime(tm));

        printf("\n\nEnter sensor name (leave blank to skip): ");
        char name[SENSOR_NAME_LEN];
        scanf("%s", name);

        if (name[0] == '\0') {
            continue;
        }

        printf("Enter sensor value: ");
        char value[SENSOR_VALUE_LEN];
        scanf("%s", value);

        update_sensor_value(sensors, 0, value);
        print_sensors(sensors);
    }

    return 0;
}