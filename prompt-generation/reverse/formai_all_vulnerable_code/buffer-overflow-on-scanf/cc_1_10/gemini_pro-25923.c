//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appliance states
typedef enum {
    OFF,
    ON,
} ApplianceState;

// Appliance types
typedef enum {
    LIGHT,
    FAN,
    AC,
} ApplianceType;

// Appliance structure
typedef struct {
    char name[32];
    ApplianceType type;
    ApplianceState state;
    int power_consumption; // in watts
} Appliance;

// List of appliances
Appliance appliances[] = {
    {"Living Room Light", LIGHT, OFF, 100},
    {"Bedroom Fan", FAN, OFF, 50},
    {"Kitchen AC", AC, OFF, 1500},
};

// Number of appliances
int num_appliances = sizeof(appliances) / sizeof(Appliance);

// Function to turn an appliance on or off
void appliance_toggle(Appliance *appliance, ApplianceState state) {
    appliance->state = state;
    if (state == ON) {
        printf("%s turned ON\n", appliance->name);
    } else {
        printf("%s turned OFF\n", appliance->name);
    }
}

// Function to print the status of all appliances
void print_appliance_status() {
    printf("\nAppliance Status:\n");
    for (int i = 0; i < num_appliances; i++) {
        Appliance *appliance = &appliances[i];
        printf("%s: ", appliance->name);
        if (appliance->state == ON) {
            printf("ON (%d watts)\n", appliance->power_consumption);
        } else {
            printf("OFF\n");
        }
    }
}

// Main function
int main() {
    // Initialize appliances
    for (int i = 0; i < num_appliances; i++) {
        appliances[i].state = OFF;
    }

    // Command loop
    while (1) {
        char command[32];
        printf("> ");
        scanf("%s", command);

        // Turn on an appliance
        if (strcmp(command, "on") == 0) {
            char appliance_name[32];
            scanf("%s", appliance_name);
            for (int i = 0; i < num_appliances; i++) {
                Appliance *appliance = &appliances[i];
                if (strcmp(appliance->name, appliance_name) == 0) {
                    appliance_toggle(appliance, ON);
                    break;
                }
            }
        }

        // Turn off an appliance
        else if (strcmp(command, "off") == 0) {
            char appliance_name[32];
            scanf("%s", appliance_name);
            for (int i = 0; i < num_appliances; i++) {
                Appliance *appliance = &appliances[i];
                if (strcmp(appliance->name, appliance_name) == 0) {
                    appliance_toggle(appliance, OFF);
                    break;
                }
            }
        }

        // Print appliance status
        else if (strcmp(command, "status") == 0) {
            print_appliance_status();
        }

        // Quit
        else if (strcmp(command, "quit") == 0) {
            break;
        }

        // Unknown command
        else {
            printf("Unknown command\n");
        }
    }

    return 0;
}