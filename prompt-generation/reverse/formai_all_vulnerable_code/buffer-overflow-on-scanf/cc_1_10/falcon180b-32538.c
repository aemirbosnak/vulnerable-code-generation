//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SENSORS 10
#define TEMP_SENSOR_NAME_LENGTH 20
#define TEMP_THRESHOLD 50.0

typedef struct {
    char name[TEMP_SENSOR_NAME_LENGTH];
    double temperature;
    double threshold;
    int is_overheated;
} TempSensor;

int main() {
    int num_sensors;
    TempSensor sensors[MAX_TEMP_SENSORS];

    printf("Enter the number of temperature sensors: ");
    scanf("%d", &num_sensors);

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i + 1);
        scanf("%s", sensors[i].name);
        sensors[i].temperature = 0.0;
        sensors[i].threshold = TEMP_THRESHOLD;
        sensors[i].is_overheated = 0;
    }

    while (1) {
        printf("\nCurrent temperature readings:\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("%s: %.2f C\n", sensors[i].name, sensors[i].temperature);
        }

        printf("\nEnter 'q' to quit or 't' to set a temperature threshold for a sensor:\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == 't') {
            int sensor_index;
            printf("Enter the index of the sensor to set a threshold for: ");
            scanf("%d", &sensor_index);

            if (sensor_index >= 0 && sensor_index < num_sensors) {
                printf("Enter the new temperature threshold for %s: ", sensors[sensor_index].name);
                scanf("%lf", &sensors[sensor_index].threshold);
            } else {
                printf("Invalid sensor index.\n");
            }
        }
    }

    return 0;
}