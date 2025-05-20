//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int status; // 0 for OFF, 1 for ON
} Light;

typedef struct {
    int currentTemp;
    int desiredTemp;
} Thermostat;

typedef struct {
    int armed; // 0 for disarmed, 1 for armed
} SecuritySystem;

void toggleLight(Light *light) {
    light->status = !light->status;
    printf("%s is now %s\n", light->name, light->status ? "ON" : "OFF");
}

void setThermostat(Thermostat *thermostat, int temp) {
    thermostat->desiredTemp = temp;
    printf("Thermostat set to %d degrees.\n", thermostat->desiredTemp);
}

void toggleSecurity(SecuritySystem *security) {
    security->armed = !security->armed;
    printf("Security system is now %s\n", security->armed ? "ARMED" : "DISARMED");
}

void displayMenu() {
    printf("\nSmart Home Automation System\n");
    printf("1. Toggle Light\n");
    printf("2. Set Thermostat\n");
    printf("3. Toggle Security System\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    // Initialization
    Light livingRoomLight = {1, "Living Room Light", 0};
    Light kitchenLight = {2, "Kitchen Light", 0};
    Thermostat thermostat = {22, 22}; // Current and Desired temperature
    SecuritySystem security = {0};

    int choice = 0;
    while (choice != 4) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Select light:\n1. Living Room Light\n2. Kitchen Light\n");
                int lightChoice;
                scanf("%d", &lightChoice);
                if (lightChoice == 1) {
                    toggleLight(&livingRoomLight);
                } else if (lightChoice == 2) {
                    toggleLight(&kitchenLight);
                } else {
                    printf("Invalid choice!\n");
                }
                break;
            }
            case 2: {
                int temp;
                printf("Enter desired temperature: ");
                scanf("%d", &temp);
                setThermostat(&thermostat, temp);
                break;
            }
            case 3:
                toggleSecurity(&security);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}