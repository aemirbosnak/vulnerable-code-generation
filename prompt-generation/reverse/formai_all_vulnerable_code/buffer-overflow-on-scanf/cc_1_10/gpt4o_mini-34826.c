//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int lightsOn;
    float thermostatTemperature;
    int securityArmed;
} SmartHome;

// Function declarations
void displayMenu();
void controlLights(SmartHome *home);
void adjustThermostat(SmartHome *home);
void toggleSecurity(SmartHome *home);
void displayStatus(SmartHome home);

int main() {
    SmartHome myHome = {0, 22.0, 0}; // Initial state: lights off, 22°C, security off
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights(&myHome);
                break;
            case 2:
                adjustThermostat(&myHome);
                break;
            case 3:
                toggleSecurity(&myHome);
                break;
            case 4:
                displayStatus(myHome);
                break;
            case 5:
                printf("Exiting the Smart Home Control System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Smart Home Automation Menu ===\n");
    printf("1. Control Lights\n");
    printf("2. Adjust Thermostat\n");
    printf("3. Toggle Security System\n");
    printf("4. Display Current Status\n");
    printf("5. Exit\n");
}

void controlLights(SmartHome *home) {
    if (home->lightsOn) {
        printf("Turning off the lights...\n");
        home->lightsOn = 0;
    } else {
        printf("Turning on the lights...\n");
        home->lightsOn = 1;
    }
}

void adjustThermostat(SmartHome *home) {
    float newTemperature;
    printf("Current temperature: %.1f°C\n", home->thermostatTemperature);
    printf("Enter new temperature: ");
    scanf("%f", &newTemperature);
    if (newTemperature < 10.0 || newTemperature > 30.0) {
        printf("Temperature must be between 10.0°C and 30.0°C!\n");
    } else {
        printf("Adjusting thermostat from %.1f°C to %.1f°C...\n", home->thermostatTemperature, newTemperature);
        home->thermostatTemperature = newTemperature;
    }
}

void toggleSecurity(SmartHome *home) {
    if (home->securityArmed) {
        printf("Disarming the security system...\n");
        home->securityArmed = 0;
    } else {
        printf("Arming the security system...\n");
        home->securityArmed = 1;
    }
}

void displayStatus(SmartHome home) {
    printf("\n=== Current Home Status ===\n");
    printf("Lights: %s\n", home.lightsOn ? "On" : "Off");
    printf("Thermostat: %.1f°C\n", home.thermostatTemperature);
    printf("Security System: %s\n", home.securityArmed ? "Armed" : "Disarmed");
}