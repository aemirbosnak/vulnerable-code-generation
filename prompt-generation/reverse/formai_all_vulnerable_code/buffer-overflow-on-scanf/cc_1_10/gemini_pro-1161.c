//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Thank you for using my Haunted House Simulator! This program will generate a random haunted house for you to explore.

// Define the structure of a room.
typedef struct room {
    int north; // The room to the north.
    int south; // The room to the south.
    int east; // The room to the east.
    int west; // The room to the west.
    char *description; // A description of the room.
} room;

// Create the haunted house.
room *create_house() {
    // Allocate memory for the haunted house.
    room *house = malloc(sizeof(room) * 10);

    // Set the description of each room.
    house[0].description = "You are in the foyer. There is a door to the north and a door to the east.";
    house[1].description = "You are in the living room. There is a door to the south and a door to the west.";
    house[2].description = "You are in the dining room. There is a door to the north and a door to the east.";
    house[3].description = "You are in the kitchen. There is a door to the south and a door to the west.";
    house[4].description = "You are in the library. There is a door to the north and a door to the east.";
    house[5].description = "You are in the master bedroom. There is a door to the south and a door to the west.";
    house[6].description = "You are in the guest bedroom. There is a door to the north and a door to the east.";
    house[7].description = "You are in the bathroom. There is a door to the south and a door to the west.";
    house[8].description = "You are in the attic. There is a door to the south.";
    house[9].description = "You are in the basement. There is a door to the north.";

    // Set the connections between the rooms.
    house[0].north = 1;
    house[0].south = -1;
    house[0].east = 2;
    house[0].west = -1;

    house[1].north = -1;
    house[1].south = 0;
    house[1].east = -1;
    house[1].west = 3;

    house[2].north = 1;
    house[2].south = -1;
    house[2].east = 4;
    house[2].west = -1;

    house[3].north = -1;
    house[3].south = 0;
    house[3].east = -1;
    house[3].west = 1;

    house[4].north = 1;
    house[4].south = -1;
    house[4].east = 6;
    house[4].west = 5;

    house[5].north = -1;
    house[5].south = 4;
    house[5].east = -1;
    house[5].west = 1;

    house[6].north = 1;
    house[6].south = -1;
    house[6].east = 7;
    house[6].west = -1;

    house[7].north = -1;
    house[7].south = 4;
    house[7].east = -1;
    house[7].west = 6;

    house[8].north = -1;
    house[8].south = 9;
    house[8].east = -1;
    house[8].west = -1;

    house[9].north = 8;
    house[9].south = -1;
    house[9].east = -1;
    house[9].west = -1;

    // Return the haunted house.
    return house;
}

// Explore the haunted house.
void explore_house(room *house) {
    // Start in the foyer.
    int current_room = 0;

    // Keep exploring until the user quits.
    while (1) {
        // Print the description of the current room.
        printf("%s\n", house[current_room].description);

        // Get the user's input.
        char input[10];
        printf("Which direction would you like to go? (n/s/e/w/q to quit) ");
        scanf("%s", input);

        // Quit if the user enters 'q'.
        if (input[0] == 'q') {
            break;
        }

        // Move to the next room.
        switch (input[0]) {
            case 'n':
                current_room = house[current_room].north;
                break;
            case 's':
                current_room = house[current_room].south;
                break;
            case 'e':
                current_room = house[current_room].east;
                break;
            case 'w':
                current_room = house[current_room].west;
                break;
        }
    }
}

// Free the memory allocated for the haunted house.
void free_house(room *house) {
    free(house);
}

// Main function.
int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Create the haunted house.
    room *house = create_house();

    // Explore the haunted house.
    explore_house(house);

    // Free the memory allocated for the haunted house.
    free_house(house);

    return 0;
}