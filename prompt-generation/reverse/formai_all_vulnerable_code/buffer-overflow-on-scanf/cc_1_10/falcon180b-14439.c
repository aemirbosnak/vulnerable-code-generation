//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10
#define MAX_SENSOR_NAME_LENGTH 50

// Struct to hold sensor data
typedef struct {
    char name[MAX_SENSOR_NAME_LENGTH];
    int temperature;
} sensor_t;

// Function to initialize a sensor
void init_sensor(sensor_t* sensor, char* name) {
    strcpy(sensor->name, name);
    sensor->temperature = 0;
}

// Function to read temperature from a sensor
int read_sensor(sensor_t* sensor) {
    printf("Reading temperature from %s...\n", sensor->name);
    fflush(stdout);
    // Simulate reading temperature from sensor
    return rand() % 100;
}

// Function to display sensor data
void display_sensor(sensor_t* sensor) {
    printf("Sensor name: %s\n", sensor->name);
    printf("Temperature: %d\n", sensor->temperature);
}

// Function to update all sensors
void update_sensors(sensor_t sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sensors[i].temperature = read_sensor(&sensors[i]);
    }
}

int main() {
    int num_sensors;
    printf("Enter number of sensors: ");
    scanf("%d", &num_sensors);

    sensor_t sensors[MAX_SENSORS];

    // Initialize sensors
    for (int i = 0; i < num_sensors; i++) {
        char name[MAX_SENSOR_NAME_LENGTH];
        printf("Enter sensor name: ");
        scanf("%s", name);
        init_sensor(&sensors[i], name);
    }

    // Main loop
    while (1) {
        update_sensors(sensors, num_sensors);

        // Display sensor data
        for (int i = 0; i < num_sensors; i++) {
            display_sensor(&sensors[i]);
        }

        printf("\nPress any key to update sensors...\n");
        getchar();
    }

    return 0;
}