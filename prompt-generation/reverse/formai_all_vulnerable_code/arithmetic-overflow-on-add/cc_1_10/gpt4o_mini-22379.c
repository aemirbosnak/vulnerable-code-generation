//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10

typedef struct {
    char name[30];
    int status; // 0 - off, 1 - on
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void initializeDevices() {
    strcpy(devices[0].name, "Living Room Light");
    devices[0].status = 0;

    strcpy(devices[1].name, "Thermostat");
    devices[1].status = 0;

    strcpy(devices[2].name, "Front Door");
    devices[2].status = 0;

    device_count = 3;
}

void listDevices() {
    printf("== Smart Home Device List ==\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d. %s - %s\n", i + 1, devices[i].name, devices[i].status ? "On" : "Off");
    }
    printf("===========================\n");
}

void toggleDevice(int index) {
    devices[index].status = !devices[index].status;
    printf("%s has been turned %s.\n", devices[index].name, devices[index].status ? "On" : "Off");
}

void setThermostat(int temperature) {
    if (temperature < 15 || temperature > 30) {
        printf("Error: Temperature must be between 15 and 30 degrees Celsius.\n");
    } else {
        devices[1].status = 1;
        printf("Thermostat set to %d degrees Celsius.\n", temperature);
    }
}

void securityAlert() {
    printf("!Security Alert! Unusual movement detected! Check your premises immediately!\n");
}

void enchantWithTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("It's a mystical %02d:%02d:%02d on %04d-%02d-%02d\n", 
            tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

int main() {
    int choice, temp;

    initializeDevices();
    enchantWithTime(); // Print the initial time status

    while (1) {
        listDevices(); // Display devices
        printf("Choose a device to toggle (1-%d), Set Thermostat (4), Security Alert (5), Exit (6): ", device_count);
        scanf("%d", &choice);

        if (choice == 6) {
            printf("The smart home wishes you good luck!\n");
            break;
        }
        
        switch (choice) {
            case 1: case 2: case 3:
                toggleDevice(choice - 1);
                break;

            case 4:
                printf("Enter desired temperature (15-30): ");
                scanf("%d", &temp);
                setThermostat(temp);
                break;

            case 5:
                securityAlert();
                break;

            default:
                printf("Invalid choice, wander back to the right path!\n");
                break;
        }

        enchantWithTime(); // Enrich the experience with current time
    }

    return 0;
}