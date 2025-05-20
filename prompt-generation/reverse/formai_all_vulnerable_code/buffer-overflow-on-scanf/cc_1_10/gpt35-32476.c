//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

/* Define the configurable options for the smart home automation system*/
#define LIGHT_SWITCH 1
#define THERMOSTAT 2
#define SECURITY_SYSTEM 3
#define CONFIGURATIONS_LENGTH 3

int main()
{
    // Define the smart home configuration
    bool configurations[CONFIGURATIONS_LENGTH];

    // Set each configuration to false by default
    for(int i = 0; i < CONFIGURATIONS_LENGTH; i++)
    {
        configurations[i] = false;
    }

    // Print out the list of configuration options
    printf("List of configurable options:\n");
    printf("%d - Light Switch\n", LIGHT_SWITCH);
    printf("%d - Thermostat\n", THERMOSTAT);
    printf("%d - Security System\n", SECURITY_SYSTEM);

    // Ask the user which configuration they would like to set
    int option;
    printf("\nEnter the option number to set the configuration: ");
    scanf("%d", &option);

    // Validate the user's selection
    if(option < 1 || option > CONFIGURATIONS_LENGTH)
    {
        printf("Invalid option selected.\n");
        return 1;
    }

    // Set the selected configuration to true
    configurations[option - 1] = true;
    printf("\nConfiguration %d set to true.\n", option);

    // Print out the final configuration settings
    printf("Final Configuration Settings:\n");
    printf("Light Switch: %s\n", configurations[LIGHT_SWITCH - 1] ? "true" : "false");
    printf("Thermostat: %s\n", configurations[THERMOSTAT - 1] ? "true" : "false");
    printf("Security System: %s\n", configurations[SECURITY_SYSTEM - 1] ? "true" : "false");

    return 0;
}