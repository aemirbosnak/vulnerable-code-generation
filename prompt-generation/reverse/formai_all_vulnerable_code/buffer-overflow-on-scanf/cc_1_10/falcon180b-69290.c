//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SENSORS 10
#define MAX_SENSOR_NAME_LENGTH 20
#define MAX_SENSOR_VALUE_LENGTH 10

typedef struct {
    char name[MAX_SENSOR_NAME_LENGTH];
    double value;
} Sensor;

int main() {
    int numSensors = 0;
    Sensor sensors[MAX_SENSORS];
    char input[MAX_SENSOR_VALUE_LENGTH];
    double temperature;

    // Initialize sensors
    for (int i = 0; i < MAX_SENSORS; i++) {
        sensors[i].value = 0.0;
    }

    // Add sensors
    char choice;
    do {
        printf("Do you want to add a sensor? (y/n): ");
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Enter sensor name: ");
            scanf("%s", sensors[numSensors].name);
            numSensors++;
        }
    } while (choice == 'y' || choice == 'Y');

    // Monitor sensors
    while (1) {
        for (int i = 0; i < numSensors; i++) {
            printf("Enter value for %s: ", sensors[i].name);
            scanf("%s", input);
            temperature = atof(input);
            sensors[i].value = temperature;
            printf("The temperature for %s is %.2f degrees Celsius.\n", sensors[i].name, temperature);
        }
        sleep(5); // Wait for 5 seconds before monitoring again
    }

    return 0;
}