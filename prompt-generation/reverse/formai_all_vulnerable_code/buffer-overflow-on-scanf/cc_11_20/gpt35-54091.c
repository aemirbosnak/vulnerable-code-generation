//FormAI DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdbool.h>

/* Define all the appliances in the house */
bool living_room_lights = false;
bool bedroom_lights = false;
bool kitchen_lights = false;
bool AC = false;
bool security_system = false;

int main()
{
    while (true) {
        printf("Welcome to Smart Home Automation!\n");
        printf("Select an option:\n");
        printf("1. Turn living room lights on/off\n");
        printf("2. Turn bedroom lights on/off\n");
        printf("3. Turn kitchen lights on/off\n");
        printf("4. Turn AC on/off\n");
        printf("5. Enable/disable security system\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                living_room_lights = !living_room_lights;
                printf("Living room lights are now %s\n", living_room_lights ? "on" : "off");
                break;
            case 2:
                bedroom_lights = !bedroom_lights;
                printf("Bedroom lights are now %s\n", bedroom_lights ? "on" : "off");
                break;
            case 3:
                kitchen_lights = !kitchen_lights;
                printf("Kitchen lights are now %s\n", kitchen_lights ? "on" : "off");
                break;
            case 4:
                AC = !AC;
                printf("AC is now %s\n", AC ? "on" : "off");
                break;
            case 5:
                security_system = !security_system;
                printf("Security system is now %s\n", security_system ? "enabled" : "disabled");
                break;
            default:
                printf("Invalid option selected, please try again.\n");
        }
    }

    return 0;
}