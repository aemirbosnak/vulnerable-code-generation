//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int room_x, room_y;
char current_room[100];

// Function to read input from the user
void read_input(char *prompt) {
    printf("%s", prompt);
    fgets(current_room, 100, stdin);
    current_room[strlen(current_room) - 1] = '\0';
}

// Function to print the current room
void print_room() {
    printf("You are in a dark room. There is a door to the north, a door to the south, and a door to the east.\n");
}

// Function to move the player to the north
void move_north() {
    printf("You move north through the door.\n");
    room_x++;
}

// Function to move the player to the south
void move_south() {
    printf("You move south through the door.\n");
    room_x--;
}

// Function to move the player to the east
void move_east() {
    printf("You move east through the door.\n");
    room_y++;
}

// Function to move the player to the west
void move_west() {
    printf("You move west through the door.\n");
    room_y--;
}

int main() {
    // Initialize global variables
    room_x = 0;
    room_y = 0;

    // Print the current room
    print_room();

    // Main game loop
    while (1) {
        // Read input from the user
        read_input("Enter direction (north, south, east, west): ");

        // Parse input and move player accordingly
        if (strcmp(current_room, "north") == 0) {
            move_north();
        } else if (strcmp(current_room, "south") == 0) {
            move_south();
        } else if (strcmp(current_room, "east") == 0) {
            move_east();
        } else if (strcmp(current_room, "west") == 0) {
            move_west();
        }

        // Print the updated room
        print_room();
    }

    // End of game
    printf("You have won!\n");

    return 0;
}