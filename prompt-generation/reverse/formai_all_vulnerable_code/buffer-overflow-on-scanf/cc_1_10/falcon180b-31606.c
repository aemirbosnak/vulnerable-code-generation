//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SENSORS 10
#define SENSOR_NAME_LENGTH 50

typedef struct {
    char name[SENSOR_NAME_LENGTH];
    int value;
} Sensor;

int main() {
    char input[100];
    int numSensors = 0;
    Sensor sensors[MAX_SENSORS];

    // Prompt the user for the number of sensors
    printf("How many temperature sensors do you want to monitor? ");
    scanf("%d", &numSensors);

    // Get the sensor names and initial values from the user
    for (int i = 0; i < numSensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
        printf("Enter the initial value of sensor %s: ", sensors[i].name);
        scanf("%d", &sensors[i].value);
    }

    // Start the temperature monitoring loop
    while (TRUE) {
        // Get the current time
        time_t now = time(NULL);

        // Print the current date and time
        printf("\nCurrent date and time: %s", ctime(&now));

        // Print the sensor values
        printf("\nTemperature values:\n");
        for (int i = 0; i < numSensors; i++) {
            printf("%s: %d\n", sensors[i].name, sensors[i].value);
        }

        // Wait for 5 seconds before updating the values again
        sleep(5);
    }

    return 0;
}