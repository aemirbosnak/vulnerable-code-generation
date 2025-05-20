//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numOfRooms = 10;
    int numOfStairs = 5;
    int numOfDoors = 8;
    int numOfWindows = 7;
    int numOfItems = 15;

    int rooms[numOfRooms];
    int stairs[numOfStairs];
    int doors[numOfDoors];
    int windows[numOfWindows];
    int items[numOfItems];

    for(int i = 0; i < numOfRooms; i++) {
        rooms[i] = i + 1;
    }
    for(int i = 0; i < numOfStairs; i++) {
        stairs[i] = i + 1;
    }
    for(int i = 0; i < numOfDoors; i++) {
        doors[i] = i + 1;
    }
    for(int i = 0; i < numOfWindows; i++) {
        windows[i] = i + 1;
    }
    for(int i = 0; i < numOfItems; i++) {
        items[i] = i + 1;
    }

    // Create the Haunted House Simulator
    int maxRoom = rooms[numOfRooms-1];
    int maxStair = stairs[numOfStairs-1];
    int maxDoor = doors[numOfDoors-1];
    int maxWindow = windows[numOfWindows-1];
    int maxItem = items[numOfItems-1];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("This Haunted House has %d rooms, %d stairs, %d doors, %d windows, and %d items.\n", maxRoom, maxStair, maxDoor, maxWindow, maxItem);

    int currentRoom = 1;
    int currentStair = 1;
    int currentDoor = 1;
    int currentWindow = 1;
    int currentItem = 1;

    while(currentRoom <= maxRoom) {
        printf("Room %d:\n", currentRoom);
        printf("- Stair %d: %s\n", currentStair, stairs[currentStair]);
        printf("- Door %d: %s\n", currentDoor, doors[currentDoor]);
        printf("- Window %d: %s\n", currentWindow, windows[currentWindow]);
        printf("- Item %d: %s\n", currentItem, items[currentItem]);

        currentRoom++;
        currentStair++;
        currentDoor++;
        currentWindow++;
        currentItem++;
    }

    printf("\n\n");

    int direction;
    do {
        printf("Where do you want to go next? (1-%d): ", maxRoom);
        scanf("%d", &direction);

        if(direction <= 0 || direction > maxRoom) {
            printf("Invalid direction.\n");
        } else {
            currentRoom = direction;
            currentStair = 1;
            currentDoor = 1;
            currentWindow = 1;
            currentItem = 1;
        }
    } while(direction!= -1);

    printf("You have reached the end of the Haunted House!\n");

    return 0;
}