//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("Welcome to Smart Home Automation!\n");

    // Create variables for different appliances in the house
    bool lights_on = false;
    int temperature = 70;
    bool tv_on = false;
    bool door_locked = true;
    bool AC_on = false;
    int humidity = 50;
    bool security_system_on = true;
    bool blinds_open = true;

    // Display the current status of the house
    printf("\nCurrent status of the house:\n");
    printf("Lights: %s\n", lights_on ? "On" : "Off");
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("TV: %s\n", tv_on ? "On" : "Off");
    printf("Door: %s\n", door_locked ? "Locked" : "Unlocked");
    printf("AC: %s\n", AC_on ? "On" : "Off");
    printf("Humidity: %d%%\n", humidity);
    printf("Security system: %s\n", security_system_on ? "On" : "Off");
    printf("Blinds: %s\n", blinds_open ? "Open" : "Closed");

    // Let user interact with the smart home system
    char choice;
    do {
        printf("\nSelect an option:\n");
        printf("a) Turn the lights on/off\n");
        printf("b) Adjust the temperature\n");
        printf("c) Turn the TV on/off\n");
        printf("d) Lock/unlock the door\n");
        printf("e) Turn the AC on/off\n");
        printf("f) Adjust the humidity\n");
        printf("g) Turn the security system on/off\n");
        printf("h) Open/close the blinds\n");
        printf("i) Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                lights_on = !lights_on;
                printf("Lights are now %s\n", lights_on ? "on" : "off");
                break;
            case 'b':
                printf("Enter the new temperature: ");
                scanf("%d", &temperature);
                printf("Temperature is now %d degrees Fahrenheit\n", temperature);
                break;
            case 'c':
                tv_on = !tv_on;
                printf("TV is now %s\n", tv_on ? "on" : "off");
                break;
            case 'd':
                door_locked = !door_locked;
                printf("Door is now %s\n", door_locked ? "locked" : "unlocked");
                break;
            case 'e':
                AC_on = !AC_on;
                printf("AC is now %s\n", AC_on ? "on" : "off");
                break;
            case 'f':
                printf("Enter the new humidity: ");
                scanf("%d", &humidity);
                printf("Humidity is now %d%%\n", humidity);
                break;
            case 'g':
                security_system_on = !security_system_on;
                printf("Security system is now %s\n", security_system_on ? "on" : "off");
                break;
            case 'h':
                blinds_open = !blinds_open;
                printf("Blinds are now %s\n", blinds_open ? "open" : "closed");
                break;
            case 'i':
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }

    } while (choice != 'i');

    printf("\nExiting Smart Home Automation...\n");

    return 0;
}