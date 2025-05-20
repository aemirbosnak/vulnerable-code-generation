//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10
#define MAX_DATA_POINTS 1000

typedef struct {
    char name[64];
    double last_temperature;
    int data_count;
    double *data;
} Sensor;

void init_sensor(Sensor *sensor, const char *name) {
    strcpy(sensor->name, name);
    sensor->last_temperature = 0;
    sensor->data_count = 0;
    sensor->data = (double *)malloc(MAX_DATA_POINTS * sizeof(double));
    memset(sensor->data, 0, MAX_DATA_POINTS * sizeof(double));
}

void add_temperature_data(Sensor *sensor, double temperature) {
    if (sensor->data_count >= MAX_DATA_POINTS) {
        printf("Warning: Data buffer full for sensor %s\n", sensor->name);
        return;
    }
    sensor->data[sensor->data_count++] = temperature;
    sensor->last_temperature = temperature;
}

void print_sensor_data(Sensor *sensor) {
    printf("Sensor: %s\n", sensor->name);
    printf("Last temperature: %.2f\n", sensor->last_temperature);
    printf("Data points:\n");
    for (int i = 0; i < sensor->data_count; i++) {
        printf("%.2f\n", sensor->data[i]);
    }
}

int main() {
    Sensor sensors[MAX_SENSORS];
    int sensor_count = 0;

    init_sensor(&sensors[sensor_count++], "CPU");
    init_sensor(&sensors[sensor_count++], "GPU");
    init_sensor(&sensors[sensor_count++], "Motherboard");

    while (1) {
        for (int i = 0; i < sensor_count; i++) {
            double temperature = rand() % 100; // Simulate random temperature data
            add_temperature_data(&sensors[i], temperature);
            printf("Added temperature data for sensor %s: %.2f\n", sensors[i].name, temperature);
        }
        sleep(1);
    }

    return 0;
}