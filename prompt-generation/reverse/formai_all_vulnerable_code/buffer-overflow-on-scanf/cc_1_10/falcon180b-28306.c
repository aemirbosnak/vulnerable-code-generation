//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SENSORS 10
#define SENSOR_COUNTER 0

int main() {
    int sensor_values[MAX_SENSORS];
    int sensor_count = 0;
    char sensor_names[MAX_SENSORS][20];
    int i;

    printf("Welcome to the Temperature Monitor 3000!\n");

    // Initialize sensor values to 0
    for (i = 0; i < MAX_SENSORS; i++) {
        sensor_values[i] = 0;
    }

    // Get sensor names from user
    printf("Enter the names of the sensors (up to %d):\n", MAX_SENSORS);
    for (i = 0; i < MAX_SENSORS; i++) {
        scanf("%s", sensor_names[i]);
    }

    // Get sensor values from user
    printf("Enter the initial temperatures for the sensors:\n");
    for (i = 0; i < MAX_SENSORS; i++) {
        scanf("%d", &sensor_values[i]);
    }

    // Start monitoring temperatures
    while (1) {
        // Print current temperatures
        printf("\nCurrent temperatures:\n");
        for (i = 0; i < sensor_count; i++) {
            printf("%s: %d\n", sensor_names[i], sensor_values[i]);
        }

        // Check if any sensors have exceeded threshold
        int threshold_exceeded = 0;
        printf("\nChecking for threshold exceedances...\n");
        for (i = 0; i < sensor_count; i++) {
            if (sensor_values[i] > 100) {
                printf("%s has exceeded the threshold of 100 degrees!\n", sensor_names[i]);
                threshold_exceeded = 1;
            }
        }

        // Sleep for 5 seconds before checking again
        if (threshold_exceeded) {
            printf("\nAlerting maintenance crew...\n");
        }
        sleep(5);
    }

    return 0;
}