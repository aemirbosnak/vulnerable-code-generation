//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SENSORS 3

struct sensor {
    char name[20];
    float current_temp;
    float min_temp;
    float max_temp;
};

void init_sensors(struct sensor sensors[NUM_SENSORS]) {
    int i;
    for (i = 0; i < NUM_SENSORS; i++) {
        sensors[i].current_temp = 0;
        sensors[i].min_temp = 100;
        sensors[i].max_temp = -100;
    }
}

void print_sensor_info(struct sensor sensor) {
    printf("Sensor name: %s\n", sensor.name);
    printf("Current temperature: %.2f\n", sensor.current_temp);
    printf("Minimum temperature: %.2f\n", sensor.min_temp);
    printf("Maximum temperature: %.2f\n", sensor.max_temp);
    printf("\n");
}

void update_sensor_temp(struct sensor *sensor, float new_temp) {
    if (new_temp < sensor->min_temp) {
        sensor->min_temp = new_temp;
    }
    if (new_temp > sensor->max_temp) {
        sensor->max_temp = new_temp;
    }
    sensor->current_temp = new_temp;
}

int main() {
    struct sensor sensors[NUM_SENSORS];
    init_sensors(sensors);

    int choice;
    do {
        printf("Temperature Monitor\n");
        printf("1. View sensor info\n");
        printf("2. Update sensor temp\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sensor name: ");
                scanf("%s", sensors[0].name);
                print_sensor_info(sensors[0]);
                break;
            case 2:
                printf("Enter sensor name: ");
                scanf("%s", sensors[0].name);
                printf("Enter new temperature: ");
                scanf("%f", &sensors[0].current_temp);
                update_sensor_temp(&sensors[0], sensors[0].current_temp);
                print_sensor_info(sensors[0]);
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