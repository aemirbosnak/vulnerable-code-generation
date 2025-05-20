//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_SENSORS 10
#define SENSOR_NAME_LENGTH 10
#define TEMPERATURE_THRESHOLD 50

typedef struct {
    char name[SENSOR_NAME_LENGTH];
    double temperature;
} Sensor;

int main() {
    int numSensors;
    Sensor sensors[MAX_SENSORS];
    char input[SENSOR_NAME_LENGTH];
    double temperature;

    printf("Enter the number of temperature sensors: ");
    scanf("%d", &numSensors);

    for (int i = 0; i < numSensors; i++) {
        printf("Enter the name of sensor %d: ", i + 1);
        scanf("%s", sensors[i].name);
        sensors[i].temperature = 0;
    }

    while (TRUE) {
        printf("Enter the temperature for sensor %s: ", sensors[0].name);
        scanf("%lf", &temperature);

        if (temperature >= TEMPERATURE_THRESHOLD) {
            printf("Warning: Temperature for %s is too high! ", sensors[0].name);
        }

        sensors[0].temperature = temperature;

        for (int i = 1; i < numSensors; i++) {
            printf("Enter the temperature for sensor %s: ", sensors[i].name);
            scanf("%lf", &temperature);

            sensors[i].temperature = temperature;
        }

        printf("\n");

        for (int i = 0; i < numSensors; i++) {
            printf("Sensor %s: %.2f\n", sensors[i].name, sensors[i].temperature);
        }

        printf("\n");
    }

    return 0;
}