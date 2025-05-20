//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_SENSORS 4
#define MAX_TEMPERATURES 1000

struct temperature_data {
    int sensor_id;
    double temperature;
};

void add_temperature_data(struct temperature_data *temp_data, int sensor_id, double temperature) {
    if (temp_data->sensor_id == -1) {
        temp_data->sensor_id = sensor_id;
        temp_data->temperature = temperature;
        return;
    }

    for (int i = 0; i < NUM_SENSORS; i++) {
        if (temp_data[i].sensor_id == sensor_id) {
            temp_data[i].temperature = temperature;
            return;
        }
    }
}

void display_temperature_data(struct temperature_data *temp_data) {
    printf("Sensor ID | Temperature\n");
    for (int i = 0; i < NUM_SENSORS; i++) {
        if (temp_data[i].sensor_id!= -1) {
            printf("%d | %.2f\n", temp_data[i].sensor_id, temp_data[i].temperature);
        }
    }
}

int main() {
    struct temperature_data temp_data[NUM_SENSORS];
    for (int i = 0; i < NUM_SENSORS; i++) {
        temp_data[i].sensor_id = -1;
    }

    int choice;
    do {
        printf("1. Add Temperature Data\n");
        printf("2. Display Temperature Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Sensor ID: ");
                int sensor_id;
                scanf("%d", &sensor_id);
                printf("Enter Temperature: ");
                double temperature;
                scanf("%lf", &temperature);
                add_temperature_data(temp_data, sensor_id, temperature);
                break;
            case 2:
                display_temperature_data(temp_data);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}