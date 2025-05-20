//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Welcome message
    printf("Welcome to Smart Home Automation!\n");
    printf("==================================\n");
    printf("\n");

    // User input prompt
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);
    printf("\nHi %s! We are pleased to have you here.\n", name);

    // Menu display
    printf("\nHere are the options available to you:\n");
    printf("1. Turn on/off lights\n");
    printf("2. Adjust thermostat\n");
    printf("3. Open/close garage door\n");
    printf("4. Play music\n");

    // User choice prompt
    printf("\nWhat would you like to do? ");
    int choice;
    scanf("%d", &choice);
    printf("\n");

    // Switch statement to handle user choice
    switch (choice) {
        case 1:
            printf("Lights are currently off. Would you like to turn them on? ");
            char response[3];
            scanf("%s", response);
            printf("\n");
            if (strcmp(response, "yes") == 0) {
                printf("Lights are now on.\n");
            } else if (strcmp(response, "no") == 0) {
                printf("Lights remain off.\n");
            } else {
                printf("Invalid response. Lights remain off.\n");
            }
            break;

        case 2:
            printf("Current temperature is 72°F. Would you like to adjust the temperature? ");
            scanf("%s", response);
            printf("\n");
            if (strcmp(response, "yes") == 0) {
                printf("What temperature would you like to set? ");
                int temp;
                scanf("%d", &temp);
                printf("\nThermostat is now set to %d°F.\n", temp);
            } else if (strcmp(response, "no") == 0) {
                printf("Thermostat remains at 72°F.\n");
            } else {
                printf("Invalid response. Thermostat remains at 72°F.\n");
            }
            break;

        case 3:
            printf("Garage door is currently closed. Would you like to open it? ");
            scanf("%s", response);
            printf("\n");
            if (strcmp(response, "yes") == 0) {
                printf("Garage door is opening.\n");
            } else if (strcmp(response, "no") == 0) {
                printf("Garage door remains closed.\n");
            } else {
                printf("Invalid response. Garage door remains closed.\n");
            }
            break;

        case 4:
            printf("Currently not playing any music. Would you like to start playing music? ");
            scanf("%s", response);
            printf("\n");
            if (strcmp(response, "yes") == 0) {
                printf("Music is now playing.\n");
            } else if (strcmp(response, "no") == 0) {
                printf("Music remains muted.\n");
            } else {
                printf("Invalid response. Music remains muted.\n");
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    // Farewell message
    printf("\nThank you for using Smart Home Automation, %s! Have a nice day.\n", name);

    return 0;
}