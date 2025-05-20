//FormAI DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>

//Function prototypes
void showMenu();
void turnOnLights(int room);
void turnOffLights(int room);

//Global variables
int livingRoomLights = 0;
int kitchenLights = 0;
int bedroomLights = 0;

int main() {
    int choice, room;

    printf("\n*** Smart Home Light Control ***\n\n");

    do {
        showMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nWhich room?\n");
                printf("1. Living Room\n");
                printf("2. Kitchen\n");
                printf("3. Bedroom\n");
                printf("Enter your choice: ");
                scanf("%d", &room);
                turnOnLights(room);
                break;
            case 2:
                printf("\nWhich room?\n");
                printf("1. Living Room\n");
                printf("2. Kitchen\n");
                printf("3. Bedroom\n");
                printf("Enter your choice: ");
                scanf("%d", &room);
                turnOffLights(room);
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}

//Function to display the main menu
void showMenu() {
    printf("\n---Main Menu---\n\n");
    printf("1. Turn on Lights\n");
    printf("2. Turn off Lights\n");
    printf("3. Exit program\n\n");
}

//Function to turn on lights in a room
void turnOnLights(int room) {
    switch(room) {
        case 1:
            if(livingRoomLights == 1) {
                printf("\nLiving room lights are already on.\n");
            } else {
                livingRoomLights = 1;
                printf("\nLiving room lights turned on.\n");
            }
            break;
        case 2:
            if(kitchenLights == 1) {
                printf("\nKitchen lights are already on.\n");
            } else {
                kitchenLights = 1;
                printf("\nKitchen lights turned on.\n");
            }
            break;
        case 3:
            if(bedroomLights == 1) {
                printf("\nBedroom lights are already on.\n");
            } else {
                bedroomLights = 1;
                printf("\nBedroom lights turned on.\n");
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
    }
}

//Function to turn off lights in a room
void turnOffLights(int room) {
    switch(room) {
        case 1:
            if(livingRoomLights == 0) {
                printf("\nLiving room lights are already off.\n");
            } else {
                livingRoomLights = 0;
                printf("\nLiving room lights turned off.\n");
            }
            break;
        case 2:
            if(kitchenLights == 0) {
                printf("\nKitchen lights are already off.\n");
            } else {
                kitchenLights = 0;
                printf("\nKitchen lights turned off.\n");
            }
            break;
        case 3:
            if(bedroomLights == 0) {
                printf("\nBedroom lights are already off.\n");
            } else {
                bedroomLights = 0;
                printf("\nBedroom lights turned off.\n");
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
    }
}