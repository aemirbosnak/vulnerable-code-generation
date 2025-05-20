//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool frontDoor = false;
bool backDoor = false;
bool livingRoomLight = false;
bool kitchenLight = false;
bool bedroomLight = false;

void openDoor(bool *door) {
    *door = true;
    printf("Door has been opened.\n");
}

void closeDoor(bool *door) {
    *door = false;
    printf("Door has been closed.\n");
}

void turnOnLight(bool *light) {
    *light = true;
    printf("Light has been turned on.\n");
}

void turnOffLight(bool *light) {
    *light = false;
    printf("Light has been turned off.\n");
}

int main() {
    int option;
    while (true) {
        printf("\n");
        printf("Smart Home Automation\n");
        printf("---------------------\n");
        printf("1. Open front door\n");
        printf("2. Close front door\n");
        printf("3. Open back door\n");
        printf("4. Close back door\n");
        printf("5. Turn on living room light\n");
        printf("6. Turn off living room light\n");
        printf("7. Turn on kitchen light\n");
        printf("8. Turn off kitchen light\n");
        printf("9. Turn on bedroom light\n");
        printf("10. Turn off bedroom light\n");
        printf("Enter option (0 to exit): ");
        scanf("%d", &option);

        switch(option) {
            case 0:
                printf("Exiting program...\n");
                exit(0);
            case 1:
                openDoor(&frontDoor);
                break;
            case 2:
                closeDoor(&frontDoor);
                break;
            case 3:
                openDoor(&backDoor);
                break;
            case 4:
                closeDoor(&backDoor);
                break;
            case 5:
                turnOnLight(&livingRoomLight);
                break;
            case 6:
                turnOffLight(&livingRoomLight);
                break;
            case 7:
                turnOnLight(&kitchenLight);
                break;
            case 8:
                turnOffLight(&kitchenLight);
                break;
            case 9:
                turnOnLight(&bedroomLight);
                break;
            case 10:
                turnOffLight(&bedroomLight);
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}