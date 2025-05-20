//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10

// Room struct
typedef struct {
    int north;
    int south;
    int east;
    int west;
    char* description;
} Room;

// Player struct
typedef struct {
    int location;
    int health;
} Player;

// Create the rooms
Room rooms[NUM_ROOMS];

// Create the player
Player player;

// Initialize the rooms
void init_rooms() {
    // Set the room descriptions
    rooms[0].description = "You are in the foyer. The door to the outside is to the north.";
    rooms[1].description = "You are in the living room. There is a door to the north and a door to the east.";
    rooms[2].description = "You are in the dining room. There is a door to the south and a door to the west.";
    rooms[3].description = "You are in the kitchen. There is a door to the north and a door to the east.";
    rooms[4].description = "You are in the library. There is a door to the south and a door to the west.";
    rooms[5].description = "You are in the master bedroom. There is a door to the north and a door to the east.";
    rooms[6].description = "You are in the guest bedroom. There is a door to the south and a door to the west.";
    rooms[7].description = "You are in the bathroom. There is a door to the north and a door to the west.";
    rooms[8].description = "You are in the attic. There is a door to the south.";
    rooms[9].description = "You are in the basement. There is a door to the north.";

    // Set the room connections
    rooms[0].north = 1;
    rooms[1].north = 2;
    rooms[1].east = 3;
    rooms[2].south = 1;
    rooms[2].west = 4;
    rooms[3].north = 4;
    rooms[3].east = 5;
    rooms[4].south = 3;
    rooms[4].west = 6;
    rooms[5].north = 6;
    rooms[5].east = 7;
    rooms[6].south = 5;
    rooms[6].west = 8;
    rooms[7].north = 8;
    rooms[8].south = 7;
    rooms[9].north = 0;
}

// Initialize the player
void init_player() {
    // Set the player's location to the foyer
    player.location = 0;

    // Set the player's health to 100
    player.health = 100;
}

// Print the room description
void print_room_description() {
    // Get the current room
    Room room = rooms[player.location];

    // Print the room description
    printf("%s\n", room.description);
}

// Get user input
int get_user_input() {
    // Get the user's input
    char input[10];
    printf("> ");
    scanf("%s", input);

    // Convert the input to an integer
    int choice = atoi(input);

    // Return the choice
    return choice;
}

// Move the player
void move_player(int direction) {
    // Get the current room
    Room room = rooms[player.location];

    // Move the player in the specified direction
    switch (direction) {
        case 0: // North
            if (room.north != -1) {
                player.location = room.north;
            }
            break;
        case 1: // South
            if (room.south != -1) {
                player.location = room.south;
            }
            break;
        case 2: // East
            if (room.east != -1) {
                player.location = room.east;
            }
            break;
        case 3: // West
            if (room.west != -1) {
                player.location = room.west;
            }
            break;
    }
}

// Main game loop
int main() {
    // Initialize the rooms
    init_rooms();

    // Initialize the player
    init_player();

    // Main game loop
    while (1) {
        // Print the room description
        print_room_description();

        // Get user input
        int choice = get_user_input();

        // Move the player
        move_player(choice);
    }

    return 0;
}