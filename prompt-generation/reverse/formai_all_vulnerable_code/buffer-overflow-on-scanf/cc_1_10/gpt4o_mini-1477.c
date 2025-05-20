//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int isOn;
} Device;

Device lights[MAX_DEVICES];
Device thermostat;

int lightCount = 0;

// Function to initialize devices
void initializeDevices() {
    // Initialize lights
    for (int i = 0; i < MAX_DEVICES; i++) {
        snprintf(lights[i].name, MAX_NAME_LENGTH, "Light %d", i + 1);
        lights[i].isOn = 0; // Initially off
    }
    
    // Initialize thermostat
    snprintf(thermostat.name, MAX_NAME_LENGTH, "Thermostat");
    thermostat.isOn = 0; // Initially off
}

// Function to display the status of all lights
void displayLightsStatus() {
    printf("\nLight Status:\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].isOn ? "ON" : "OFF");
    }
}

// Function to turn on/off a light
void controlLight(int index, int state) {
    if (index >= 0 && index < lightCount) {
        lights[index].isOn = state;
        printf("%s is now %s.\n", lights[index].name, state ? "ON" : "OFF");
    } else {
        printf("Invalid light index!\n");
    }
}

// Function to control thermostat
void controlThermostat(int state) {
    thermostat.isOn = state;
    printf("%s is now %s.\n", thermostat.name, state ? "ON" : "OFF");
}

// Display menu options
void displayMenu() {
    printf("\nSmart Home Automation Menu:\n");
    printf("1. Turn ON a light\n");
    printf("2. Turn OFF a light\n");
    printf("3. Check light status\n");
    printf("4. Turn ON thermostat\n");
    printf("5. Turn OFF thermostat\n");
    printf("6. Exit\n");
}

// Main function
int main() {
    initializeDevices();

    lightCount = 3; // Initialize with 3 lights for demonstration

    int choice, index;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light index to turn ON (1 to %d): ", lightCount);
                scanf("%d", &index);
                controlLight(index - 1, 1);
                break;
            
            case 2:
                printf("Enter light index to turn OFF (1 to %d): ", lightCount);
                scanf("%d", &index);
                controlLight(index - 1, 0);
                break;

            case 3:
                displayLightsStatus();
                break;

            case 4:
                controlThermostat(1);
                break;

            case 5:
                controlThermostat(0);
                break;

            case 6:
                printf("Exiting Smart Home Automation...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}