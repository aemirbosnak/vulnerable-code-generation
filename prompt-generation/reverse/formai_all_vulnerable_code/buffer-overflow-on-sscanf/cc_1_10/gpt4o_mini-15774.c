//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void controlLights(int state);
void controlThermostat(int temperature);
void controlSecurity(int state);
void showMenu();
void handleUserInput();
void processInput(char* input);

int main() {
    printf("Welcome to Smart Home Automation System\n");
    handleUserInput();
    return 0;
}

// Function to control lights
void controlLights(int state) {
    if (state == 1) {
        printf("Lights are turned ON.\n");
    } else if (state == 0) {
        printf("Lights are turned OFF.\n");
    } else {
        printf("Invalid input for lights.\n");
    }
}

// Function to control thermostat
void controlThermostat(int temperature) {
    if (temperature >= 60 && temperature <= 80) {
        printf("Thermostat set to %d degrees Fahrenheit.\n", temperature);
    } else {
        printf("Please set the temperature between 60 and 80 degrees Fahrenheit.\n");
    }
}

// Function to control security system
void controlSecurity(int state) {
    if (state == 1) {
        printf("Security system is ARMED.\n");
    } else if (state == 0) {
        printf("Security system is DISARMED.\n");
    } else {
        printf("Invalid input for security system.\n");
    }
}

// Function to show the menu
void showMenu() {
    printf("\nMenu:\n");
    printf("1. Control Lights (1: ON, 0: OFF)\n");
    printf("2. Control Thermostat (temperature between 60-80)\n");
    printf("3. Control Security System (1: ARMED, 0: DISARMED)\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

// Function to handle user input
void handleUserInput() {
    char input[50];
    showMenu();
    
    fgets(input, sizeof(input), stdin);
    processInput(input);
}

// Function to process user input
void processInput(char* input) {
    int choice;
    sscanf(input, "%d", &choice);

    if (choice == 1) {
        int state;
        printf("Enter 1 to turn ON or 0 to turn OFF the lights: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &state);
        controlLights(state);
        handleUserInput(); // Recursive call
    } else if (choice == 2) {
        int temperature;
        printf("Enter the desired temperature (60-80): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &temperature);
        controlThermostat(temperature);
        handleUserInput(); // Recursive call
    } else if (choice == 3) {
        int state;
        printf("Enter 1 to ARM or 0 to DISARM the security system: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &state);
        controlSecurity(state);
        handleUserInput(); // Recursive call
    } else if (choice == 4) {
        printf("Exiting Smart Home Automation System. Goodbye!\n");
        exit(0);
    } else {
        printf("Invalid choice. Please try again.\n");
        handleUserInput(); // Recursive call
    }
}