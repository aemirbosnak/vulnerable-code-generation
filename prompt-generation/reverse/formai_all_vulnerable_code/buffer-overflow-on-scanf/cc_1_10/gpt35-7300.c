//FormAI DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1

int livingRoomLight = LIGHT_OFF;
int bedroomLight = LIGHT_OFF;
int bathroomLight = LIGHT_OFF;
int kitchenLight = LIGHT_OFF;

void turnOffAllLights() {
    livingRoomLight = LIGHT_OFF;
    bedroomLight = LIGHT_OFF;
    bathroomLight = LIGHT_OFF;
    kitchenLight = LIGHT_OFF;
    printf("All lights have been turned off\n");
}

void turnOnAllLights() {
    livingRoomLight = LIGHT_ON;
    bedroomLight = LIGHT_ON;
    bathroomLight = LIGHT_ON;
    kitchenLight = LIGHT_ON;
    printf("All lights have been turned on\n");
}

void turnOnLight(char* room) {
    if (strcmp(room, "living room") == 0) {
        livingRoomLight = LIGHT_ON;
        printf("The living room light has been turned on\n");
    } else if (strcmp(room, "bedroom") == 0) {
        bedroomLight = LIGHT_ON;
        printf("The bedroom light has been turned on\n");
    } else if (strcmp(room, "bathroom") == 0) {
        bathroomLight = LIGHT_ON;
        printf("The bathroom light has been turned on\n");
    } else if (strcmp(room, "kitchen") == 0) {
        kitchenLight = LIGHT_ON;
        printf("The kitchen light has been turned on\n");
    } else {
        printf("Invalid room name. Please try again.\n");
    }
}

void turnOffLight(char* room) {
    if (strcmp(room, "living room") == 0) {
        livingRoomLight = LIGHT_OFF;
        printf("The living room light has been turned off\n");
    } else if (strcmp(room, "bedroom") == 0) {
        bedroomLight = LIGHT_OFF;
        printf("The bedroom light has been turned off\n");
    } else if (strcmp(room, "bathroom") == 0) {
        bathroomLight = LIGHT_OFF;
        printf("The bathroom light has been turned off\n");
    } else if (strcmp(room, "kitchen") == 0) {
        kitchenLight = LIGHT_OFF;
        printf("The kitchen light has been turned off\n");
    } else {
        printf("Invalid room name. Please try again.\n");
    }
}

int main() {
    int choice;
    char room[20];

    printf("Welcome to the smart home light control system!\n");

    do {
        printf("Please select an option:\n");
        printf("1. Turn on all lights\n");
        printf("2. Turn off all lights\n");
        printf("3. Turn on a specific light\n");
        printf("4. Turn off a specific light\n");
        printf("5. Quit the program\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turnOnAllLights();
                break;
            case 2:
                turnOffAllLights();
                break;
            case 3:
                printf("Enter the name of the room you want to turn on the light: ");
                scanf("%s", room);
                turnOnLight(room);
                break;
            case 4:
                printf("Enter the name of the room you want to turn off the light: ");
                scanf("%s", room);
                turnOffLight(room);
                break;
            case 5:
                printf("Thank you for using the smart home light control system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}