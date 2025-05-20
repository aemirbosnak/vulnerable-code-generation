//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to store room information
typedef struct Room {
    char *description;    // Description of the room
    int north;           // Index of the north neighbor, or -1 if none
    int south;           // Index of the south neighbor, or -1 if none
    int east;            // Index of the east neighbor, or -1 if none
    int west;            // Index of the west neighbor, or -1 if none
} Room;

// Array of rooms
Room rooms[10];

// Initialize the rooms
void init_rooms() {
    // Room 0: Entrance
    rooms[0].description = "You are standing in the entrance of a dark and dilapidated house. The air is heavy with the smell of decay and the sound of dripping water. To the north is a hallway that leads deeper into the house.";
    rooms[0].north = 1;
    rooms[0].south = -1;
    rooms[0].east = -1;
    rooms[0].west = -1;

    // Room 1: Hallway
    rooms[1].description = "You are standing in a dark and narrow hallway. The walls are lined with peeling wallpaper and cobwebs hang from the ceiling. To the north is a door that leads to a living room, to the south is the entrance, to the east is a bedroom, and to the west is a kitchen.";
    rooms[1].north = 2;
    rooms[1].south = 0;
    rooms[1].east = 3;
    rooms[1].west = 4;

    // Room 2: Living Room
    rooms[2].description = "You are standing in a spacious living room. The furniture is covered in dust and cobwebs, and the windows are boarded up. There is a fireplace in the center of the room, and a door to the south leads back to the hallway.";
    rooms[2].north = -1;
    rooms[2].south = 1;
    rooms[2].east = -1;
    rooms[2].west = -1;

    // Room 3: Bedroom
    rooms[3].description = "You are standing in a small and stuffy bedroom. The bed is unmade, and there is a dresser and a nightstand in the corner. There is a door to the west that leads back to the hallway.";
    rooms[3].north = -1;
    rooms[3].south = -1;
    rooms[3].east = -1;
    rooms[3].west = 1;

    // Room 4: Kitchen
    rooms[4].description = "You are standing in a small and dingy kitchen. The cupboards are empty, and the appliances are covered in rust. There is a door to the east that leads back to the hallway.";
    rooms[4].north = -1;
    rooms[4].south = -1;
    rooms[4].east = 1;
    rooms[4].west = -1;

    // Room 5: Basement
    rooms[5].description = "You are standing in a dark and damp basement. The walls are lined with shelves, and there is a workbench in the center of the room. There is a ladder that leads to the ground floor.";
    rooms[5].north = -1;
    rooms[5].south = 6;
    rooms[5].east = -1;
    rooms[5].west = -1;

    // Room 6: Underground Passage
    rooms[6].description = "You are standing in a narrow and dimly lit underground passage. The walls are lined with pipes, and there is a faint smell of sewage. To the north is a door that leads to the basement, and to the south is a door that leads to the outside.";
    rooms[6].north = 5;
    rooms[6].south = 7;
    rooms[6].east = -1;
    rooms[6].west = -1;

    // Room 7: Outside
    rooms[7].description = "You are standing outside the house. The sky is dark and overcast, and the ground is covered in rubble and debris. There is a road to the north that leads to the city.";
    rooms[7].north = -1;
    rooms[7].south = -1;
    rooms[7].east = -1;
    rooms[7].west = -1;

    // Room 8: Attic
    rooms[8].description = "You are standing in a dusty and cobwebbed attic. There are several old trunks and boxes stored in the corner, and there is a window that looks out over the city.";
    rooms[8].north = -1;
    rooms[8].south = -1;
    rooms[8].east = -1;
    rooms[8].west = -1;

    // Room 9: Secret Room
    rooms[9].description = "You are standing in a small and hidden room. The walls are covered in strange symbols, and there is a large pentagram drawn on the floor. There is a door to the north that leads back to the attic.";
    rooms[9].north = 8;
    rooms[9].south = -1;
    rooms[9].east = -1;
    rooms[9].west = -1;
}

// Play the game
void play_game() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the player in the entrance
    int current_room = 0;

    // Loop until the player quits
    while (1) {
        // Display the current room description
        printf("%s\n", rooms[current_room].description);

        // Get the player's input
        printf("What do you want to do? (n/s/e/w/q): ");
        char input[2];
        scanf("%s", input);

        // Check if the player wants to quit
        if (input[0] == 'q') {
            break;
        }

        // Check if the player's input is valid
        int next_room = -1;
        switch (input[0]) {
            case 'n':
                next_room = rooms[current_room].north;
                break;
            case 's':
                next_room = rooms[current_room].south;
                break;
            case 'e':
                next_room = rooms[current_room].east;
                break;
            case 'w':
                next_room = rooms[current_room].west;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Move the player to the next room
        if (next_room != -1) {
            current_room = next_room;
        }
    }
}

// Main function
int main() {
    // Initialize the rooms
    init_rooms();

    // Play the game
    play_game();

    return 0;
}