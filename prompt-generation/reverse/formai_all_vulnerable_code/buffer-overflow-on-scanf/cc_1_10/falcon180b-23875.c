//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SENSORS 10
#define MAX_SENSOR_NAME_LENGTH 15
#define MAX_SENSOR_VALUE_LENGTH 8
#define MAX_SENSOR_VALUE_PRECISION 2

typedef struct {
    char name[MAX_SENSOR_NAME_LENGTH];
    double value;
    char value_string[MAX_SENSOR_VALUE_LENGTH + 1];
} Sensor;

void print_sensor(Sensor *sensor) {
    printf("%-15s | %s | %.2f\n", sensor->name, sensor->value_string, sensor->value);
}

int main() {
    int num_sensors;
    Sensor sensors[MAX_SENSORS];
    char input_buffer[1024];

    // Read number of sensors
    printf("Enter number of sensors (1-%d): ", MAX_SENSORS);
    if (scanf("%d", &num_sensors)!= 1 || num_sensors < 1 || num_sensors > MAX_SENSORS) {
        printf("Invalid number of sensors.\n");
        return 1;
    }

    // Read sensor information
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter sensor name (%d): ", i+1);
        fgets(input_buffer, sizeof(input_buffer), stdin);
        strncpy(sensors[i].name, input_buffer, MAX_SENSOR_NAME_LENGTH);
        sensors[i].name[MAX_SENSOR_NAME_LENGTH-1] = '\0';

        printf("Enter sensor value: ");
        if (scanf("%lf", &sensors[i].value)!= 1) {
            printf("Invalid sensor value.\n");
            return 1;
        }
        sprintf(sensors[i].value_string, "%.2f", sensors[i].value);
    }

    // Print initial sensor values
    printf("\nInitial sensor values:\n");
    for (int i = 0; i < num_sensors; i++) {
        print_sensor(&sensors[i]);
    }

    // Monitor sensors
    while (1) {
        sleep(5); // Update every 5 seconds

        printf("\n\nCurrent sensor values:\n");
        for (int i = 0; i < num_sensors; i++) {
            print_sensor(&sensors[i]);
        }
    }

    return 0;
}