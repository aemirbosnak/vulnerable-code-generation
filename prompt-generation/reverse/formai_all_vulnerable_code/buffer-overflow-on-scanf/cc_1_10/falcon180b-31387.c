//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURES 1000
#define MAX_SENSOR_NAMES 100

typedef struct {
    char name[MAX_SENSOR_NAMES];
    double temperature;
} TemperatureSensor;

void add_sensor(TemperatureSensor *sensors, int num_sensors, char *name, double temperature) {
    int i;
    for (i = 0; i < num_sensors; i++) {
        if (strcmp(sensors[i].name, name) == 0) {
            sensors[i].temperature = temperature;
            return;
        }
    }
    if (num_sensors >= MAX_TEMPERATURES) {
        printf("Error: maximum number of sensors reached.\n");
        return;
    }
    strcpy(sensors[num_sensors].name, name);
    sensors[num_sensors].temperature = temperature;
    num_sensors++;
}

void remove_sensor(TemperatureSensor *sensors, int num_sensors, char *name) {
    int i;
    for (i = 0; i < num_sensors; i++) {
        if (strcmp(sensors[i].name, name) == 0) {
            memmove(&sensors[i], &sensors[i+1], (num_sensors - i - 1) * sizeof(TemperatureSensor));
            num_sensors--;
            return;
        }
    }
    printf("Error: sensor not found.\n");
}

void print_sensors(TemperatureSensor *sensors, int num_sensors) {
    int i;
    for (i = 0; i < num_sensors; i++) {
        printf("%s: %.2f\n", sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    TemperatureSensor sensors[MAX_TEMPERATURES];
    int num_sensors = 0;
    char name[MAX_SENSOR_NAMES];
    double temperature;
    while (1) {
        printf("Enter a sensor name (or 'q' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) {
            break;
        }
        printf("Enter the temperature for %s: ", name);
        scanf("%lf", &temperature);
        add_sensor(sensors, num_sensors, name, temperature);
    }
    printf("List of sensors:\n");
    print_sensors(sensors, num_sensors);
    while (1) {
        printf("Enter a sensor name to remove (or 'q' to quit): ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) {
            break;
        }
        remove_sensor(sensors, num_sensors, name);
    }
    printf("List of sensors after removing:\n");
    print_sensors(sensors, num_sensors);
    return 0;
}