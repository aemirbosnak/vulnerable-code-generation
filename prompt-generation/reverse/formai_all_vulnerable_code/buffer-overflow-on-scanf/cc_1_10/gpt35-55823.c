//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//initialize smart home features
bool lights = false;
bool thermostat = false;
bool security_system = false;

//function to turn on/off lights
void toggleLights() {
    if (lights == false) {
        lights = true;
        printf("Lights turned on\n");
    }
    else {
        lights = false;
        printf("Lights turned off\n");
    }
}

//function to turn on/off thermostat
void toggleThermostat() {
    if (thermostat == false) {
        thermostat = true;
        printf("Thermostat turned on\n");
    }
    else {
        thermostat = false;
        printf("Thermostat turned off\n");
    }
}

//function to turn on/off security system
void toggleSecuritySystem() {
    if (security_system == false) {
        security_system = true;
        printf("Security system turned on\n");
    }
    else {
        security_system = false;
        printf("Security system turned off\n");
    }
}

int main() {
    int choice;

    while (true) {
        printf("What would you like to control?\n");
        printf("1. Lights\n2. Thermostat\n3. Security system\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleLights();
                break;
            case 2:
                toggleThermostat();
                break;
            case 3:
                toggleSecuritySystem();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}