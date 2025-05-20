//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
/*
 * Adventure Game in C - Retro Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_LEN 256

// Struct to represent a room
struct room {
    char name[256];
    char description[256];
    int north;
    int south;
    int east;
    int west;
};

// Struct to represent the player
struct player {
    char name[256];
    int health;
    int gold;
    int xp;
};

// Array of rooms
struct room rooms[] = {
    {"Town Square", "You are standing in the middle of a bustling town square. There is a sign that says \"Welcome, adventurer!\"", -1, 1, 2, 3},
    {"Forest", "You are standing in the middle of a dense forest. There are trees all around you.", 0, -1, 4, 5},
    {"Cave Entrance", "You are standing at the entrance of a dark cave. There is a torch on the ground.", 1, -1, -1, -1},
    {"Cave", "You are standing in the middle of a dark cave. There are bats flying around you.", -1, -1, -1, -1},
    {"Mountain Peak", "You are standing on the top of a mountain peak. There is a treasure chest in front of you.", -1, -1, -1, -1},
};

// Function to print the current room's description
void print_room_description(int room_id) {
    printf("%s\n", rooms[room_id].description);
}

// Function to print the available exits
void print_available_exits(int room_id) {
    printf("Available exits: ");
    if (rooms[room_id].north != -1) {
        printf("North ");
    }
    if (rooms[room_id].south != -1) {
        printf("South ");
    }
    if (rooms[room_id].east != -1) {
        printf("East ");
    }
    if (rooms[room_id].west != -1) {
        printf("West ");
    }
    printf("\n");
}

// Function to move the player to a new room
void move_to_room(int room_id) {
    int new_room_id = rooms[room_id].north;
    if (new_room_id == -1) {
        printf("You can't go that way.\n");
    } else {
        printf("You are now in %s.\n", rooms[new_room_id].name);
        print_room_description(new_room_id);
        print_available_exits(new_room_id);
    }
}

// Function to handle player input
void handle_input(int room_id) {
    char input[MAX_INPUT_LEN];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "north") == 0) {
        move_to_room(rooms[room_id].north);
    } else if (strcmp(input, "south") == 0) {
        move_to_room(rooms[room_id].south);
    } else if (strcmp(input, "east") == 0) {
        move_to_room(rooms[room_id].east);
    } else if (strcmp(input, "west") == 0) {
        move_to_room(rooms[room_id].west);
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    // Set the starting room
    int current_room_id = 0;

    // Print the starting room's description
    print_room_description(current_room_id);

    // Print the available exits
    print_available_exits(current_room_id);

    // Handle player input
    handle_input(current_room_id);

    return 0;
}