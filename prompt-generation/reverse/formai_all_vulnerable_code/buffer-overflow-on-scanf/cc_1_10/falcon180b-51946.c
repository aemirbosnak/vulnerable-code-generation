//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10

typedef struct {
    char name[20];
    float temperature;
} Sensor;

int main() {
    int numSensors = 0;
    Sensor sensors[MAX_SENSORS];

    while (numSensors < MAX_SENSORS) {
        printf("Enter sensor name: ");
        scanf("%s", sensors[numSensors].name);
        printf("Enter temperature: ");
        scanf("%f", &sensors[numSensors].temperature);
        numSensors++;
    }

    int choice;
    while (1) {
        printf("\nTemperature Monitor\n");
        printf("1. Display all sensor temperatures\n");
        printf("2. Display a specific sensor temperature\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nAll sensor temperatures:\n");
            for (int i = 0; i < numSensors; i++) {
                printf("%s: %.2f\n", sensors[i].name, sensors[i].temperature);
            }
            break;

        case 2:
            printf("\nEnter sensor name: ");
            char sensorName[20];
            scanf("%s", sensorName);

            for (int i = 0; i < numSensors; i++) {
                if (strcmp(sensors[i].name, sensorName) == 0) {
                    printf("%s temperature: %.2f\n", sensors[i].name, sensors[i].temperature);
                    break;
                }
            }

            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}