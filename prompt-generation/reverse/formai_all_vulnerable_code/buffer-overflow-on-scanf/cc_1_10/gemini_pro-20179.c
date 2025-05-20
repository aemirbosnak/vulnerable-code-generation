//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a room
typedef struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

// Function to create a new room
Room* createRoom(char* name, char* description) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->name = name;
    newRoom->description = description;
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;
    return newRoom;
}

// Function to connect two rooms
void connectRooms(Room* room1, Room* room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

// Function to print the description of a room
void printRoomDescription(Room* room) {
    printf("%s\n\n", room->description);
}

// Function to get the user's input
char getInput() {
    char input;
    scanf("%c", &input);
    return input;
}

// Function to play the game
void playGame() {
    // Create the rooms
    Room* foyer = createRoom("Foyer", "You are in the foyer of a large, dark house. The air is heavy with the smell of dust and decay.");
    Room* livingRoom = createRoom("Living Room", "You are in a large, dimly lit living room. The furniture is covered in sheets and the walls are lined with dusty portraits.");
    Room* diningRoom = createRoom("Dining Room", "You are in a large, formal dining room. The table is set for a feast, but the food is long gone.");
    Room* kitchen = createRoom("Kitchen", "You are in a large, well-equipped kitchen. The stove is cold and the counters are covered in grime.");
    Room* bedroom = createRoom("Bedroom", "You are in a large, dark bedroom. The bed is unmade and the curtains are drawn shut.");
    Room* bathroom = createRoom("Bathroom", "You are in a small, windowless bathroom. The tub is dirty and the mirror is cracked.");

    // Connect the rooms
    connectRooms(foyer, livingRoom, 'n');
    connectRooms(livingRoom, diningRoom, 'e');
    connectRooms(diningRoom, kitchen, 's');
    connectRooms(kitchen, foyer, 'w');
    connectRooms(foyer, bedroom, 'e');
    connectRooms(bedroom, bathroom, 'n');

    // Set the current room to the foyer
    Room* currentRoom = foyer;

    // Play the game loop
    while (1) {
        // Print the description of the current room
        printRoomDescription(currentRoom);

        // Get the user's input
        char input = getInput();

        // Check if the user wants to quit
        if (input == 'q') {
            break;
        }

        // Move the player to the next room
        switch (input) {
            case 'n':
                if (currentRoom->north != NULL) {
                    currentRoom = currentRoom->north;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 's':
                if (currentRoom->south != NULL) {
                    currentRoom = currentRoom->south;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 'e':
                if (currentRoom->east != NULL) {
                    currentRoom = currentRoom->east;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 'w':
                if (currentRoom->west != NULL) {
                    currentRoom = currentRoom->west;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
        }
    }
}

// Main function
int main() {
    srand(time(NULL));
    playGame();
    return 0;
}