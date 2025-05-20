//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define MAX_SENSOR_VALUE 100
#define MAX_SENSORS 10

// Define the structure for each sensor
typedef struct {
    char *name;
    float value;
    int enabled;
} Sensor;

// Define the structure for the smart home system
typedef struct {
    Sensor sensors[MAX_SENSORS];
    int numSensors;
} SmartHome;

// Initialize the smart home system
void initSmartHome(SmartHome *sh) {
    sh->numSensors = 0;
}

// Add a new sensor to the smart home system
void addSensor(SmartHome *sh, char *name, float value, int enabled) {
    Sensor *sensor = &sh->sensors[sh->numSensors];
    strcpy(sensor->name, name);
    sensor->value = value;
    sensor->enabled = enabled;
    sh->numSensors++;
}

// Print the current state of all sensors
void printSensors(SmartHome *sh) {
    printf("Current sensor readings:\n");
    for (int i = 0; i < sh->numSensors; i++) {
        Sensor *sensor = &sh->sensors[i];
        if (sensor->enabled) {
            printf("%s: %.2f\n", sensor->name, sensor->value);
        }
    }
}

// Main loop for the smart home system
void loop(SmartHome *sh) {
    printSensors(sh);
    usleep(100000); // Sleep for 100ms
}

// Example usage of the smart home system
int main() {
    SmartHome sh;
    initSmartHome(&sh);

    addSensor(&sh, "Temperature", 23.5, 1);
    addSensor(&sh, "Humidity", 45.6, 0);
    addSensor(&sh, "Light", 50.0, 1);

    loop(&sh);

    return 0;
}