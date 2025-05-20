//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int lightsOn;
    int thermostatTemp;
    int securityCameraOn;
} SmartHome;

void initializeHome(SmartHome *home) {
    home->lightsOn = 0; // Off by default
    home->thermostatTemp = 22; // Default temperature in Celsius
    home->securityCameraOn = 0; // Off by default
}

void toggleLights(SmartHome *home) {
    home->lightsOn = !home->lightsOn;
    printf("The lights are now %s.\n", home->lightsOn ? "ON" : "OFF");
}

void setThermostat(SmartHome *home, int temp) {
    if (temp >= 15 && temp <= 30) {
        home->thermostatTemp = temp;
        printf("Thermostat is set to %d°C.\n", home->thermostatTemp);
    } else {
        printf("Please set a temperature between 15°C and 30°C.\n");
    }
}

void toggleCamera(SmartHome *home) {
    home->securityCameraOn = !home->securityCameraOn;
    printf("The security camera is now %s.\n", home->securityCameraOn ? "ON" : "OFF");
}

void displayStatus(SmartHome *home) {
    printf("\nSmart Home Status:\n");
    printf("-------------------\n");
    printf("Lights: %s\n", home->lightsOn ? "ON" : "OFF");
    printf("Thermostat: %d°C\n", home->thermostatTemp);
    printf("Security Camera: %s\n", home->securityCameraOn ? "ON" : "OFF");
    printf("-------------------\n");
}

void displayMenu() {
    printf("\nWelcome to your Smart Home!\n");
    printf("1. Toggle Lights\n");
    printf("2. Set Thermostat Temperature\n");
    printf("3. Toggle Security Camera\n");
    printf("4. Display Current Status\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    SmartHome home;
    initializeHome(&home);
    
    int choice, temp;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                toggleLights(&home);
                break;
            case 2:
                printf("Enter desired temperature (15-30°C): ");
                scanf("%d", &temp);
                setThermostat(&home, temp);
                break;
            case 3:
                toggleCamera(&home);
                break;
            case 4:
                displayStatus(&home);
                break;
            case 5:
                printf("Thank you for using the Smart Home automation system. Have a peaceful day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}