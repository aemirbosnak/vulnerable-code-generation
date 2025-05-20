//FormAI DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

bool livingRoomLight = false;
bool kitchenLight = false;
bool bedroomLight = false;
bool bathroomLight = false;
bool garageDoor = false;

void toggleLight(bool *light) {
    *light = !(*light);
}

void openGarageDoor() {
    if (!garageDoor) {
        printf("Garage door is opening.\n");
        garageDoor = true;
    } else {
        printf("Garage door is already open.\n");
    }
}

void closeGarageDoor() {
    if (garageDoor) {
        printf("Garage door is closing.\n");
        garageDoor = false;
    } else {
        printf("Garage door is already closed.\n");
    }
}

int main() {
    printf("Welcome to Smart Home Automation!\n");

    int option = -1;

    while (option != 0) {
        printf("\nPlease choose an option:\n");
        printf("1. Toggle living room light.\n");
        printf("2. Toggle kitchen light.\n");
        printf("3. Toggle bedroom light.\n");
        printf("4. Toggle bathroom light.\n");
        printf("5. Open garage door.\n");
        printf("6. Close garage door.\n");
        printf("0. Quit program.\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                toggleLight(&livingRoomLight);
                printf("Living room light is now %s.\n", livingRoomLight ? "on" : "off");
                break;
            case 2:
                toggleLight(&kitchenLight);
                printf("Kitchen light is now %s.\n", kitchenLight ? "on" : "off");
                break;
            case 3:
                toggleLight(&bedroomLight);
                printf("Bedroom light is now %s.\n", bedroomLight ? "on" : "off");
                break;
            case 4:
                toggleLight(&bathroomLight);
                printf("Bathroom light is now %s.\n", bathroomLight ? "on" : "off");
                break;
            case 5:
                openGarageDoor();
                break;
            case 6:
                closeGarageDoor();
                break;
            case 0:
                printf("Exiting Smart Home Automation.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}