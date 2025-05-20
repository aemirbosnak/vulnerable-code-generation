//FormAI DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool livingRoomLight = false;
    bool bedroomLight = false;
    bool kitchenLight = false;
    bool bathroomLight = false;
    int temperature = 72;

    printf("Welcome to your smart home.\n");

    while (1) {
        printf("\nWhat would you like to do? Type 'help' for commands. ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "help") == 0) {
            printf("\nCommands: \n");
            printf("'status' - view the current status of all devices.\n");
            printf("'toggle <device>' - toggle the status of a device.\n");
            printf("'set temperature <x>' - set the temperature to 'x'.\n");
        } else if (strncmp(command, "toggle", 6) == 0) {
            char device[20];
            scanf("%s", device);
            if (strcmp(device, "livingroomlight") == 0) {
                livingRoomLight = !livingRoomLight;
                printf("Living room light toggled.\n");
            } else if (strcmp(device, "bedroomlight") == 0) {
                bedroomLight = !bedroomLight;
                printf("Bedroom light toggled.\n");
            } else if (strcmp(device, "kitchenlight") == 0) {
                kitchenLight = !kitchenLight;
                printf("Kitchen light toggled.\n");
            } else if (strcmp(device, "bathroomlight") == 0) {
                bathroomLight = !bathroomLight;
                printf("Bathroom light toggled.\n");
            } else {
                printf("Device not found.\n");
            }
        } else if (strncmp(command, "set temperature", 15) == 0) {
            char tempStr[20];
            scanf("%s", tempStr);
            int newTemp = atoi(tempStr);
            if (newTemp > 90 || newTemp < 60) {
                printf("Temperature out of range. Please choose between 60-90 degrees.\n");
            } else {
                temperature = newTemp;
                printf("Temperature set to %d.\n", temperature);
            }
        } else if (strcmp(command, "status") == 0) {
            printf("\nLiving Room Light: %s\n", livingRoomLight ? "On" : "Off" );
            printf("Bedroom Light: %s\n", bedroomLight ? "On" : "Off" );
            printf("Kitchen Light: %s\n", kitchenLight ? "On" : "Off" );
            printf("Bathroom Light: %s\n", bathroomLight ? "On" : "Off" );
            printf("Current Temperature: %d degrees.\n", temperature);
        } else {
            printf("Command not found. Type 'help' for commands.\n");
        }
    }

    return 0;
}