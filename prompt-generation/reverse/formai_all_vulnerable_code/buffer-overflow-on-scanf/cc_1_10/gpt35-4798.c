//FormAI DATASET v1.0 Category: Smart home light control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn on/off bulb for specific room
void controlBulb(char room, bool state) {
    if(state) {
        printf("Bulb in room %c turned ON\n", room);
    } else {
        printf("Bulb in room %c turned OFF\n", room);
    }
}

int main() {
    char livingRoom, bedroom, kitchen;
    bool livingRoomLightStatus = false, bedroomLightStatus = false, kitchenLightStatus = false;

    printf("Welcome to Smart Home Light Control\n");

    while(true) {
        printf("\nEnter Room Number to control Light (L for Living Room, B for Bedroom, K for Kitchen): ");
        char roomToControl = getchar();
        getchar(); // Consume the newline character

        printf("\nDo you want to turn ON or OFF the Light (1 for ON, 0 for OFF): ");
        bool stateToSet; 
        scanf("%d", &stateToSet);
        getchar(); // Consume the newline character

        // Check the room selected and call controlBulb function accordingly
        switch(roomToControl) {
            case 'L':
            case 'l':
                controlBulb('L', stateToSet);
                livingRoomLightStatus = stateToSet;
                break;
            case 'B':
            case 'b':
                controlBulb('B', stateToSet);
                bedroomLightStatus = stateToSet;
                break;
            case 'K':
            case 'k':
                controlBulb('K', stateToSet);
                kitchenLightStatus = stateToSet;
                break;
            default:
                printf("Invalid Room selected. Please select again.\n");
        }

        printf("\nCurrent Light Status:\nLiving Room - %d\nBedroom - %d\nKitchen - %d\n", livingRoomLightStatus, bedroomLightStatus, kitchenLightStatus);
    }

    return 0;
}