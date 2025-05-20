//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10

typedef struct room {
    char *name;
    char *description;
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
} room;

room *create_room(char *name, char *description) {
    room *new_room = malloc(sizeof(room));
    new_room->name = name;
    new_room->description = description;
    new_room->north = NULL;
    new_room->east = NULL;
    new_room->south = NULL;
    new_room->west = NULL;
    return new_room;
}

void connect_rooms(room *room1, room *room2, char direction) {
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

room *create_haunted_house() {
    // Create the rooms
    room *entrance = create_room("Entrance", "You enter the haunted house through a creaky old door.");
    room *living_room = create_room("Living Room", "The living room is dimly lit and furnished with antique furniture.");
    room *dining_room = create_room("Dining Room", "The dining room is large and has a long, wooden table with chairs.");
    room *kitchen = create_room("Kitchen", "The kitchen is small and has a cast iron stove and a sink.");
    room *bedroom = create_room("Bedroom", "The bedroom is small and has a single bed and a dresser.");
    room *bathroom = create_room("Bathroom", "The bathroom is small and has a toilet, sink, and shower.");
    room *library = create_room("Library", "The library is large and has shelves full of books.");
    room *study = create_room("Study", "The study is small and has a desk and a chair.");
    room *secret_room = create_room("Secret Room", "The secret room is hidden behind a bookcase in the study.");
    room *attic = create_room("Attic", "The attic is large and has a lot of old furniture and boxes.");

    // Connect the rooms
    connect_rooms(entrance, living_room, 'n');
    connect_rooms(living_room, dining_room, 'e');
    connect_rooms(dining_room, kitchen, 'e');
    connect_rooms(kitchen, living_room, 'w');
    connect_rooms(living_room, bedroom, 'n');
    connect_rooms(bedroom, bathroom, 'e');
    connect_rooms(bathroom, living_room, 'w');
    connect_rooms(living_room, library, 's');
    connect_rooms(library, study, 'e');
    connect_rooms(study, secret_room, 'n');
    connect_rooms(secret_room, study, 's');
    connect_rooms(study, library, 'w');
    connect_rooms(library, living_room, 'n');
    connect_rooms(living_room, attic, 'u');

    // Return the entrance room
    return entrance;
}

void play_game(room *current_room) {
    // Print the description of the current room
    printf("%s\n", current_room->description);

    // Get the user's input
    char input[80];
    printf("> ");
    fgets(input, 80, stdin);

    // Parse the user's input
    char command[80];
    char direction[80];
    sscanf(input, "%s %s", command, direction);

    // Execute the user's command
    if (strcmp(command, "go") == 0) {
        // Move the player to the specified room
        if (strcmp(direction, "north") == 0) {
            if (current_room->north != NULL) {
                current_room = current_room->north;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(direction, "east") == 0) {
            if (current_room->east != NULL) {
                current_room = current_room->east;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(direction, "south") == 0) {
            if (current_room->south != NULL) {
                current_room = current_room->south;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(direction, "west") == 0) {
            if (current_room->west != NULL) {
                current_room = current_room->west;
            } else {
                printf("You can't go that way.\n");
            }
        } else {
            printf("Invalid direction.\n");
        }
    } else if (strcmp(command, "look") == 0) {
        // Print the description of the current room
        printf("%s\n", current_room->description);
    } else if (strcmp(command, "quit") == 0) {
        // Exit the game
        exit(0);
    } else {
        printf("Invalid command.\n");
    }

    // Play the game again
    play_game(current_room);
}

int main() {
    // Create the haunted house
    room *haunted_house = create_haunted_house();

    // Start the game
    play_game(haunted_house);

    return 0;
}