//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The main room of the haunted house
struct room {
    char *description; // A description of the room
    struct room *north; // The room to the north
    struct room *east; // The room to the east
    struct room *south; // The room to the south
    struct room *west; // The room to the west
};

// Create a new room
struct room *create_room(char *description) {
    struct room *room = malloc(sizeof(struct room));
    room->description = description;
    room->north = NULL;
    room->east = NULL;
    room->south = NULL;
    room->west = NULL;
    return room;
}

// Connect two rooms
void connect_rooms(struct room *room1, struct room *room2, char direction) {
    switch (direction) {
        case 'n':
            room1->north = room2;
            room2->south = room1;
            break;
        case 'e':
            room1->east = room2;
            room2->west = room1;
            break;
        case 's':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'w':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

// Print the description of a room
void print_room(struct room *room) {
    printf("%s\n", room->description);
}

// Get a random room from a list of rooms
struct room *get_random_room(struct room *rooms[], int num_rooms) {
    return rooms[rand() % num_rooms];
}

// The player's current room
struct room *current_room;

// The list of all rooms in the haunted house
struct room *rooms[10];

// Initialize the haunted house
void init_haunted_house() {
    // Create the rooms
    rooms[0] = create_room("You are in a dark and musty hallway. The walls are lined with cobwebs and the air is thick with the smell of decay.");
    rooms[1] = create_room("You enter a grand ballroom. The floor is covered in a thick layer of dust and the chandeliers are hanging from the ceiling.");
    rooms[2] = create_room("You walk into a small library. The bookshelves are lined with dusty old books and the air is filled with the smell of paper.");
    rooms[3] = create_room("You enter a creepy bedroom. The bed is unmade and the sheets are covered in blood.");
    rooms[4] = create_room("You walk into a large kitchen. The stove is on and the air is filled with the smell of cooking food.");
    rooms[5] = create_room("You enter a small bathroom. The sink is full of dirty water and the mirror is cracked.");
    rooms[6] = create_room("You enter a large living room. The furniture is covered in dust and the air is filled with the smell of smoke.");
    rooms[7] = create_room("You enter a small study. The desk is covered in papers and the air is filled with the smell of ink.");
    rooms[8] = create_room("You enter a small attic. The floor is covered in old boxes and the air is filled with the smell of dust.");
    rooms[9] = create_room("You enter a large basement. The floor is covered in dirt and the air is filled with the smell of mildew.");

    // Connect the rooms
    connect_rooms(rooms[0], rooms[1], 'n');
    connect_rooms(rooms[0], rooms[2], 'e');
    connect_rooms(rooms[0], rooms[3], 's');
    connect_rooms(rooms[0], rooms[4], 'w');
    connect_rooms(rooms[1], rooms[5], 'e');
    connect_rooms(rooms[1], rooms[6], 's');
    connect_rooms(rooms[1], rooms[7], 'w');
    connect_rooms(rooms[2], rooms[8], 'n');
    connect_rooms(rooms[2], rooms[9], 's');
    connect_rooms(rooms[3], rooms[10], 'n');
    connect_rooms(rooms[3], rooms[11], 's');
    connect_rooms(rooms[4], rooms[12], 'n');
    connect_rooms(rooms[4], rooms[13], 's');
    connect_rooms(rooms[5], rooms[14], 'n');
    connect_rooms(rooms[5], rooms[15], 's');
    connect_rooms(rooms[6], rooms[16], 'n');
    connect_rooms(rooms[6], rooms[17], 's');
    connect_rooms(rooms[7], rooms[18], 'n');
    connect_rooms(rooms[7], rooms[19], 's');
    connect_rooms(rooms[8], rooms[20], 'n');
    connect_rooms(rooms[8], rooms[21], 's');
    connect_rooms(rooms[9], rooms[22], 'n');
    connect_rooms(rooms[9], rooms[23], 's');

    // Set the player's current room
    current_room = rooms[0];
}

// The main game loop
void game_loop() {
    while (1) {
        // Print the current room's description
        print_room(current_room);

        // Get the player's input
        char input[100];
        printf("> ");
        scanf("%s", input);

        // Parse the player's input
        if (strcmp(input, "n") == 0) {
            // Move north
            if (current_room->north != NULL) {
                current_room = current_room->north;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "e") == 0) {
            // Move east
            if (current_room->east != NULL) {
                current_room = current_room->east;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "s") == 0) {
            // Move south
            if (current_room->south != NULL) {
                current_room = current_room->south;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "w") == 0) {
            // Move west
            if (current_room->west != NULL) {
                current_room = current_room->west;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "quit") == 0) {
            // Quit the game
            break;
        }
    }
}

// The main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the haunted house
    init_haunted_house();

    // Start the game loop
    game_loop();

    return 0;
}