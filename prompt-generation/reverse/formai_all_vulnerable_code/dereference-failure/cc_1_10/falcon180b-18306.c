//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SENSORS 1000
#define MAX_SENSOR_NAME_LENGTH 32
#define MAX_SENSOR_VALUE_LENGTH 64

typedef struct {
    char name[MAX_SENSOR_NAME_LENGTH];
    char value[MAX_SENSOR_VALUE_LENGTH];
    double temperature;
} Sensor;

int num_sensors = 0;
Sensor sensors[MAX_SENSORS];

void add_sensor(const char* name, const char* value) {
    if (num_sensors >= MAX_SENSORS) {
        fprintf(stderr, "Error: Too many sensors.\n");
        return;
    }

    strncpy(sensors[num_sensors].name, name, MAX_SENSOR_NAME_LENGTH);
    strncpy(sensors[num_sensors].value, value, MAX_SENSOR_VALUE_LENGTH);

    sensors[num_sensors].temperature = atof(sensors[num_sensors].value);
    ++num_sensors;
}

void print_sensors() {
    for (int i = 0; i < num_sensors; ++i) {
        printf("%s: %.2f°C\n", sensors[i].name, sensors[i].temperature);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sensor_name> <sensor_value>\n", argv[0]);
        return 1;
    }

    add_sensor(argv[1], argv[2]);

    while (1) {
        print_sensors();
        sleep(5);
    }

    return 0;
}