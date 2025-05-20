//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SENSORS 10
#define TEMP_SENSOR_NAME_LENGTH 20

typedef struct {
    char name[TEMP_SENSOR_NAME_LENGTH];
    double temperature;
    double threshold;
    char *threshold_unit;
} TemperatureSensor;

void print_sensor_info(TemperatureSensor *sensor) {
    printf("Sensor name: %s\n", sensor->name);
    printf("Temperature: %.2f %s\n", sensor->temperature, sensor->threshold_unit);
    printf("Threshold: %.2f %s\n\n", sensor->threshold, sensor->threshold_unit);
}

int main() {
    int num_sensors;
    printf("Enter the number of temperature sensors: ");
    scanf("%d", &num_sensors);

    TemperatureSensor sensors[MAX_TEMP_SENSORS];
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter sensor %d name: ", i+1);
        scanf("%s", sensors[i].name);

        printf("Enter temperature unit (C/F): ");
        char unit;
        scanf(" %c", &unit);
        sensors[i].threshold_unit = unit == 'C'? "C" : "F";

        printf("Enter threshold temperature: ");
        scanf("%lf", &sensors[i].threshold);
    }

    while (1) {
        printf("\nCurrent temperature readings:\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("Sensor %d:\n", i+1);
            print_sensor_info(&sensors[i]);
        }

        printf("\nEnter Q to quit or any other key to continue...\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'Q' || choice == 'q') {
            break;
        }
    }

    return 0;
}