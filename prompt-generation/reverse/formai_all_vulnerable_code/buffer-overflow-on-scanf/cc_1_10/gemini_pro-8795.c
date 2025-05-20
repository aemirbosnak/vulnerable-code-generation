//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char* name;
    char* description;
    int num_exits;
    int* exits;
} Room;

Room rooms[MAX_ROOMS];

int current_room;

void init_game() {
    // Create the rooms
    rooms[0] = (Room) { .name = "The foyer", .description = "You are in the foyer of a large house. There is a door to the north and a door to the east." };
    rooms[1] = (Room) { .name = "The living room", .description = "You are in the living room of the house. There is a door to the south and a door to the west." };
    rooms[2] = (Room) { .name = "The dining room", .description = "You are in the dining room of the house. There is a door to the north and a door to the east." };
    rooms[3] = (Room) { .name = "The kitchen", .description = "You are in the kitchen of the house. There is a door to the south and a door to the west." };
    rooms[4] = (Room) { .name = "The library", .description = "You are in the library of the house. There is a door to the north and a door to the east." };
    rooms[5] = (Room) { .name = "The master bedroom", .description = "You are in the master bedroom of the house. There is a door to the south and a door to the west." };
    rooms[6] = (Room) { .name = "The guest bedroom", .description = "You are in the guest bedroom of the house. There is a door to the north and a door to the east." };
    rooms[7] = (Room) { .name = "The bathroom", .description = "You are in the bathroom of the house. There is a door to the south and a door to the west." };
    rooms[8] = (Room) { .name = "The attic", .description = "You are in the attic of the house. There is a door to the south." };
    rooms[9] = (Room) { .name = "The basement", .description = "You are in the basement of the house. There is a door to the north." };

    // Set the current room to the foyer
    current_room = 0;
}

void print_room() {
    // Print the room's name and description
    printf("%s\n", rooms[current_room].name);
    printf("%s\n", rooms[current_room].description);

    // Print the room's exits
    printf("Exits:");
    for (int i = 0; i < rooms[current_room].num_exits; i++) {
        printf(" %s", rooms[rooms[current_room].exits[i]].name);
    }
    printf("\n");
}

void move(char* direction) {
    // Get the room's exits
    int* exits = rooms[current_room].exits;
    int num_exits = rooms[current_room].num_exits;

    // Find the exit in the given direction
    int exit = -1;
    for (int i = 0; i < num_exits; i++) {
        if (strcmp(rooms[exits[i]].name, direction) == 0) {
            exit = exits[i];
            break;
        }
    }

    // If the exit was found, move to the new room
    if (exit != -1) {
        current_room = exit;
    } else {
        printf("You can't go that way.\n");
    }
}

void play_game() {
    // Print the welcome message
    printf("Welcome to the text-based adventure game!\n");

    // Initialize the game
    init_game();

    // Print the current room
    print_room();

    // Get the player's input
    char input[100];
    while (1) {
        printf("> ");
        scanf("%s", input);

        // Parse the input
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "north") == 0) {
            move("north");
        } else if (strcmp(input, "south") == 0) {
            move("south");
        } else if (strcmp(input, "east") == 0) {
            move("east");
        } else if (strcmp(input, "west") == 0) {
            move("west");
        } else {
            printf("I don't understand that command.\n");
        }

        // Print the current room
        print_room();
    }
}

int main() {
    play_game();
    return 0;
}