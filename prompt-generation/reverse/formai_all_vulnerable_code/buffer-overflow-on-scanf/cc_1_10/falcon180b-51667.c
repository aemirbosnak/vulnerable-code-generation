//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SENSORS 10
#define MAX_TEMP_SENSOR_NAME_LEN 20
#define MIN_TEMP -273.15 // Celsius
#define MAX_TEMP 1000.0 // Celsius

typedef struct temp_sensor {
    char name[MAX_TEMP_SENSOR_NAME_LEN];
    double temp;
} temp_sensor_t;

int main() {
    int num_sensors = 0;
    temp_sensor_t sensors[MAX_TEMP_SENSORS];
    char input[MAX_TEMP_SENSOR_NAME_LEN];
    double temp;

    // Initialize all sensors to invalid values
    for (int i = 0; i < MAX_TEMP_SENSORS; i++) {
        sensors[i].temp = NAN;
    }

    // Prompt user for number of temperature sensors
    printf("Enter the number of temperature sensors: ");
    scanf("%d", &num_sensors);

    if (num_sensors > MAX_TEMP_SENSORS) {
        printf("Error: Maximum number of temperature sensors is %d\n", MAX_TEMP_SENSORS);
        exit(1);
    }

    // Loop through each temperature sensor
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of temperature sensor %d: ", i + 1);
        scanf("%s", input);
        strncpy(sensors[i].name, input, MAX_TEMP_SENSOR_NAME_LEN);

        // Prompt user for initial temperature
        printf("Enter the initial temperature of %s: ", sensors[i].name);
        scanf("%lf", &temp);

        // Check if temperature is within valid range
        if (temp < MIN_TEMP || temp > MAX_TEMP) {
            printf("Error: Temperature must be between %lf and %lf degrees Celsius\n", MIN_TEMP, MAX_TEMP);
            exit(1);
        }

        sensors[i].temp = temp;
    }

    // Main loop
    while (1) {
        printf("\nTemperature Monitor\n");
        printf("--------------------\n");
        printf("Sensor Name\t\tTemperature\n");
        printf("--------------------\n");

        for (int i = 0; i < num_sensors; i++) {
            printf("%-20s %lf\n", sensors[i].name, sensors[i].temp);
        }

        printf("\n");
        sleep(5); // Wait for 5 seconds before updating temperature readings
    }

    return 0;
}