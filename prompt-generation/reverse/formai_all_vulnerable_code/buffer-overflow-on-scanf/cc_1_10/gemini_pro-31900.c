//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game world
#define NUM_ROOMS 5
char* room_names[] = {"The Forest", "The Cave", "The Castle", "The Dungeon", "The Treasure Room"};
int room_connections[NUM_ROOMS][NUM_ROOMS] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0}
};

// Define the player's inventory
#define MAX_INVENTORY_SIZE 10
char* inventory[MAX_INVENTORY_SIZE];
int inventory_size = 0;

// Define the game state
int current_room = 0;
int game_over = 0;

// Function to print the game introduction
void print_intro() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You find yourself in a dark forest. You have no idea how you got here, but you know you need to find a way out.\n\n");
    printf("As you walk through the forest, you come to a cave. Do you want to enter the cave (y/n)?\n");
}

// Function to get the player's input
char get_input() {
    char input;
    scanf(" %c", &input);
    return input;
}

// Function to process the player's input
void process_input(char input) {
    switch (input) {
        case 'y':
            if (room_connections[current_room][1]) {
                current_room = 1;
                printf("You enter the cave.\n\n");
                printf("The cave is dark and damp. You can hear the sound of dripping water. You see a faint light in the distance.\n\n");
                printf("Do you want to follow the light (y/n)?\n");
            } else {
                printf("You cannot go that way.\n\n");
            }
            break;
        case 'n':
            printf("You decide to stay in the forest.\n\n");
            printf("You wander around the forest for a while, but you soon get lost.\n\n");
            printf("You are now lost in the forest. Game over.\n");
            game_over = 1;
            break;
        default:
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            break;
    }
}

// Main game loop
int main() {
    // Print the game introduction
    print_intro();

    // Get the player's input
    char input = get_input();

    // Process the player's input
    process_input(input);

    // While the game is not over, continue the game loop
    while (!game_over) {
        // Get the player's input
        input = get_input();

        // Process the player's input
        process_input(input);
    }

    return 0;
}