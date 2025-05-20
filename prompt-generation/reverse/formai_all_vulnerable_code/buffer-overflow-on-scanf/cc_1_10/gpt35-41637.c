//FormAI DATASET v1.0 Category: Smart home automation ; Style: protected
#include <stdio.h>
#include <stdbool.h>

// This program demonstrates a smart home automation system
// that controls various home appliances based on user inputs.

// Constants
#define LIGHT_OFF 0
#define LIGHT_ON 1

#define HVAC_OFF 0
#define HVAC_COOL 1
#define HVAC_HEAT 2

// Function prototypes
void turnOnLight(bool* lightStatus);
void turnOffLight(bool* lightStatus);
void setHVAC(int* hvacStatus, int temperature, int desiredTemp);
void printHVACStatus(int hvacStatus);

int main(void) {
    // Initial values for light and HVAC status
    bool lightStatus = LIGHT_OFF;
    int hvacStatus = HVAC_OFF;
    
    // User input variables
    char input;
    int temperature;
    int desiredTemp = 68; // Default desired temperature
    
    // Main program loop
    while (true) {
        // Print menu options to user
        printf("Menu\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Set desired temperature (current: %d)\n", desiredTemp);
        printf("4. Quit\n");
        
        // Get user input
        printf("Enter choice: ");
        scanf(" %c", &input);
        
        // User choice logic
        if (input == '1') {
            turnOnLight(&lightStatus);
        } else if (input == '2') {
            turnOffLight(&lightStatus);
        } else if (input == '3') {
            printf("Enter desired temperature: ");
            scanf(" %d", &desiredTemp);
        } else if (input == '4') {
            break; // Quit program
        } else {
            printf("Invalid choice, try again.\n");
        }
        
        // HVAC control logic
        if (desiredTemp <= 60) {
            setHVAC(&hvacStatus, temperature, desiredTemp);
        } else if (desiredTemp >= 80) {
            setHVAC(&hvacStatus, temperature, desiredTemp);
        } else {
            // Turn off HVAC if in desired temperature range
            hvacStatus = HVAC_OFF;
        }
        
        // Print current status
        printf("Current light status: %s\n", lightStatus ? "ON" : "OFF");
        printHVACStatus(hvacStatus);
        printf("\n");
    }
    
    return 0;
}

// Turns on the light
void turnOnLight(bool* lightStatus) {
    *lightStatus = LIGHT_ON;
}

// Turns off the light
void turnOffLight(bool* lightStatus) {
    *lightStatus = LIGHT_OFF;
}

// Sets the HVAC to heat or cool based on desired temperature
void setHVAC(int* hvacStatus, int temperature, int desiredTemp) {
    if (desiredTemp < temperature) {
        *hvacStatus = HVAC_HEAT;
    } else if (desiredTemp > temperature) {
        *hvacStatus = HVAC_COOL;
    }
}

// Prints the current HVAC status
void printHVACStatus(int hvacStatus) {
    if (hvacStatus == HVAC_OFF) {
        printf("HVAC: OFF\n");
    } else if (hvacStatus == HVAC_COOL) {
        printf("HVAC: COOLING\n");
    } else if (hvacStatus == HVAC_HEAT) {
        printf("HVAC: HEATING\n");
    }
}