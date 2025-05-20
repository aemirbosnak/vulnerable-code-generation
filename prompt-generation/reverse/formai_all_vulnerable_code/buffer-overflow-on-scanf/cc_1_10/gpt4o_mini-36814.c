//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home components
typedef struct {
    int lights;
    int heating;
    int security;
} SmartHome;

// Function declarations
void initializeSmartHome(SmartHome *home);
void displayStatus(SmartHome *home);
void controlLights(SmartHome *home, int command);
void controlHeating(SmartHome *home, int command);
void controlSecurity(SmartHome *home, int command);

// Main function
int main() {
    SmartHome home;
    int command, option;

    initializeSmartHome(&home);

    while (1) {
        printf("Welcome to Smart Home Automation System\n");
        printf("Select an option:\n");
        printf("1. Control Lights\n");
        printf("2. Control Heating\n");
        printf("3. Control Security\n");
        printf("4. Display Status\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter command (1 for ON, 0 for OFF): ");
                scanf("%d", &command);
                controlLights(&home, command);
                break;
            case 2:
                printf("Enter command (1 for ON, 0 for OFF): ");
                scanf("%d", &command);
                controlHeating(&home, command);
                break;
            case 3:
                printf("Enter command (1 for ARMED, 0 for DISARMED): ");
                scanf("%d", &command);
                controlSecurity(&home, command);
                break;
            case 4:
                displayStatus(&home);
                break;
            case 5:
                printf("Exiting the Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// Function to initialize smart home components
void initializeSmartHome(SmartHome *home) {
    home->lights = 0;     // 0 = OFF, 1 = ON
    home->heating = 0;    // 0 = OFF, 1 = ON
    home->security = 0;   // 0 = DISARMED, 1 = ARMED
}

// Function to display current status of smart home components
void displayStatus(SmartHome *home) {
    printf("Current Status of Smart Home:\n");
    printf("Lights: %s\n", home->lights ? "ON" : "OFF");
    printf("Heating: %s\n", home->heating ? "ON" : "OFF");
    printf("Security System: %s\n", home->security ? "ARMED" : "DISARMED");
}

// Function to control lights
void controlLights(SmartHome *home, int command) {
    if (command == 1) {
        home->lights = 1;
        printf("Lights turned ON.\n");
    } else if (command == 0) {
        home->lights = 0;
        printf("Lights turned OFF.\n");
    } else {
        printf("Invalid command for lights.\n");
    }
}

// Function to control heating
void controlHeating(SmartHome *home, int command) {
    if (command == 1) {
        home->heating = 1;
        printf("Heating turned ON.\n");
    } else if (command == 0) {
        home->heating = 0;
        printf("Heating turned OFF.\n");
    } else {
        printf("Invalid command for heating.\n");
    }
}

// Function to control security system
void controlSecurity(SmartHome *home, int command) {
    if (command == 1) {
        home->security = 1;
        printf("Security System ARMED.\n");
    } else if (command == 0) {
        home->security = 0;
        printf("Security System DISARMED.\n");
    } else {
        printf("Invalid command for security system.\n");
    }
}