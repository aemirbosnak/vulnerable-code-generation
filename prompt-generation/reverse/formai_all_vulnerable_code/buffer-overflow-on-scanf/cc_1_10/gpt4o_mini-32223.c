//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[50];
    int status; // 1 for ON, 0 for OFF
} Device;

Device lights[MAX_DEVICES];
Device fans[MAX_DEVICES];
Device thermostat;
int lightCount = 0;
int fanCount = 0;

void initializeDevices() {
    strcpy(lights[0].name, "Living Room Light");
    strcpy(lights[1].name, "Bedroom Light");
    lightCount = 2;

    strcpy(fans[0].name, "Living Room Fan");
    strcpy(fans[1].name, "Bedroom Fan");
    fanCount = 2;

    strcpy(thermostat.name, "Home Thermostat");
    thermostat.status = 0; // Initially OFF
}

void toggleDevice(Device *device) {
    device->status = !device->status;
    printf("%s is now %s\n", device->name, device->status ? "ON" : "OFF");
}

void controlLight() {
    printf("Select the light to control:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%d. %s (%s)\n", i + 1, lights[i].name, lights[i].status ? "ON" : "OFF");
    }

    int choice;
    printf("Enter your choice (1-%d): ", lightCount);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= lightCount) {
        toggleDevice(&lights[choice - 1]);
    } else {
        printf("Invalid choice!\n");
    }
}

void controlFan() {
    printf("Select the fan to control:\n");
    for (int i = 0; i < fanCount; i++) {
        printf("%d. %s (%s)\n", i + 1, fans[i].name, fans[i].status ? "ON" : "OFF");
    }

    int choice;
    printf("Enter your choice (1-%d): ", fanCount);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= fanCount) {
        toggleDevice(&fans[choice - 1]);
    } else {
        printf("Invalid choice!\n");
    }
}

void controlThermostat() {
    printf("The %s is currently set to %s\n", thermostat.name, thermostat.status ? "ON" : "OFF");
    toggleDevice(&thermostat);
}

void showMenu() {
    printf("\n=== Smart Home Automation ===\n");
    printf("1. Control Lights\n");
    printf("2. Control Fans\n");
    printf("3. Control Thermostat\n");
    printf("4. Exit\n");
    printf("============================\n");
    printf("Choose an option: ");
}

int main() {
    initializeDevices();

    int choice;
    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLight();
                break;
            case 2:
                controlFan();
                break;
            case 3:
                controlThermostat();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}