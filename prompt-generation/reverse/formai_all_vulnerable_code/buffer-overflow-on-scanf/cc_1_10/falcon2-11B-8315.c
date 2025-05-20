//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numOfRooms = 10; // Number of rooms in the house
    int numOfHaunted = 5; // Number of rooms that are haunted
    int numOfCorridors = 10; // Number of corridors in the house

    int room[numOfRooms]; // Array to store the rooms
    int corridor[numOfCorridors]; // Array to store the corridors
    int haunted[numOfHaunted]; // Array to store the haunted rooms

    int i, j;

    for(i = 0; i < numOfRooms; i++) {
        room[i] = rand() % 2; // Each room has a 50% chance of being haunted
    }

    for(i = 0; i < numOfCorridors; i++) {
        corridor[i] = rand() % 2; // Each corridor has a 50% chance of being haunted
    }

    for(i = 0; i < numOfHaunted; i++) {
        haunted[i] = rand() % 2; // Each haunted room is randomly selected
    }

    // Print out the number of rooms, corridors, and haunted rooms
    printf("Number of Rooms: %d\n", numOfRooms);
    printf("Number of Corridors: %d\n", numOfCorridors);
    printf("Number of Haunted Rooms: %d\n", numOfHaunted);

    // Print out the details of each room and corridor
    for(i = 0; i < numOfRooms; i++) {
        if(room[i] == 1) {
            printf("Room %d is Haunted!\n", i+1);
        } else {
            printf("Room %d is Safe!\n", i+1);
        }
    }

    for(i = 0; i < numOfCorridors; i++) {
        if(corridor[i] == 1) {
            printf("Corridor %d is Haunted!\n", i+1);
        } else {
            printf("Corridor %d is Safe!\n", i+1);
        }
    }

    // Print out the details of each haunted room
    for(i = 0; i < numOfHaunted; i++) {
        printf("Haunted Room %d is in Room %d\n", i+1, haunted[i]+1);
    }

    // Prompt the user to continue or exit
    printf("Press any key to continue or 'q' to exit.\n");
    char c;
    scanf("%c", &c);

    return 0;
}