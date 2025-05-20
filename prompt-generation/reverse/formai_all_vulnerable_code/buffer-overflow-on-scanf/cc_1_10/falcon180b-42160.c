//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LENGTH 20

typedef struct {
    char name[SENSOR_NAME_LENGTH];
    double temperature;
    time_t last_update_time;
} Sensor;

int main() {
    int num_sensors = 0;
    Sensor sensors[MAX_SENSORS];

    printf("Welcome to the Temperature Monitor!\n");

    while (1) {
        printf("Current Sensors:\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("%s: %.2f\n", sensors[i].name, sensors[i].temperature);
        }

        printf("\nEnter 'a' to add a sensor, 'd' to delete a sensor, or 'q' to quit:\n");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                if (num_sensors >= MAX_SENSORS) {
                    printf("Maximum number of sensors reached.\n");
                } else {
                    printf("Enter sensor name (up to %d characters):\n", SENSOR_NAME_LENGTH - 1);
                    scanf("%s", sensors[num_sensors].name);
                    sensors[num_sensors].temperature = 0;
                    sensors[num_sensors].last_update_time = time(NULL);
                    num_sensors++;
                }
                break;
            case 'd':
                printf("Enter sensor name to delete:\n");
                scanf("%s", sensors[num_sensors - 1].name);
                num_sensors--;
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}