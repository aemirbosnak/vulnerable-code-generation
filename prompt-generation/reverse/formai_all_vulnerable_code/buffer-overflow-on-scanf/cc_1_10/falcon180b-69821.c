//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10
#define MAX_DEVICES 10

// Sensor struct
typedef struct {
    char name[20];
    int value;
} Sensor;

// Device struct
typedef struct {
    char name[20];
    int status;
} Device;

int main() {
    int numSensors, numDevices;

    // Initialize sensor and device arrays
    Sensor sensors[MAX_SENSORS];
    Device devices[MAX_DEVICES];

    // Get number of sensors and devices
    printf("Enter the number of sensors: ");
    scanf("%d", &numSensors);
    printf("Enter the number of devices: ");
    scanf("%d", &numDevices);

    // Get sensor names and values
    printf("Enter sensor names and values:\n");
    for (int i = 0; i < numSensors; i++) {
        printf("Sensor %d name: ", i+1);
        scanf("%s", sensors[i].name);
        printf("Sensor %d value: ", i+1);
        scanf("%d", &sensors[i].value);
    }

    // Get device names and statuses
    printf("Enter device names and statuses:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("Device %d name: ", i+1);
        scanf("%s", devices[i].name);
        printf("Device %d status (0=off, 1=on): ", i+1);
        scanf("%d", &devices[i].status);
    }

    // Control devices based on sensor values
    for (int i = 0; i < numSensors; i++) {
        for (int j = 0; j < numDevices; j++) {
            if (strcmp(sensors[i].name, devices[j].name) == 0) {
                if (sensors[i].value > 50) {
                    devices[j].status = 1;
                } else {
                    devices[j].status = 0;
                }
            }
        }
    }

    // Print device statuses
    printf("Device statuses:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].status? "on" : "off");
    }

    return 0;
}