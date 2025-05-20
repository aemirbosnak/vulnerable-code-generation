//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define MIN_TEMP -273.15
#define MAX_TEMP 1000.0

struct temperature_sensor {
    double current_temperature;
    double min_temperature;
    double max_temperature;
};

void initialize_temperature_sensor(struct temperature_sensor* sensor) {
    sensor->current_temperature = 0.0;
    sensor->min_temperature = MIN_TEMP;
    sensor->max_temperature = MAX_TEMP;
}

void update_temperature_sensor(struct temperature_sensor* sensor, double new_temperature) {
    sensor->current_temperature = new_temperature;
    if (sensor->current_temperature < sensor->min_temperature) {
        sensor->min_temperature = sensor->current_temperature;
    }
    if (sensor->current_temperature > sensor->max_temperature) {
        sensor->max_temperature = sensor->current_temperature;
    }
}

void print_temperature_sensor_status(struct temperature_sensor* sensor) {
    printf("Current temperature: %.2f\n", sensor->current_temperature);
    printf("Minimum temperature: %.2f\n", sensor->min_temperature);
    printf("Maximum temperature: %.2f\n", sensor->max_temperature);
}

int main() {
    struct temperature_sensor sensor;
    initialize_temperature_sensor(&sensor);

    int choice;
    do {
        printf("Temperature sensor menu:\n");
        printf("1. Update temperature\n");
        printf("2. Print temperature status\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new temperature: ");
                double new_temperature;
                scanf("%lf", &new_temperature);
                update_temperature_sensor(&sensor, new_temperature);
                break;
            case 2:
                print_temperature_sensor_status(&sensor);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}