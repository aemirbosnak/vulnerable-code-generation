//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the player's current location
enum location {
    FOREST,
    CAVE,
    MOUNTAIN,
    LAKE,
    END
};

// Define the player's current state
enum state {
    ALIVE,
    DEAD
};

// Define the player's inventory
char *inventory[10];
int inventory_size = 0;

// Define the game's world
char *world[5][5] = {
    {"Forest", "Cave", "Mountain", "Lake", "End"},
    {"Forest", "Cave", "Mountain", "Lake", "End"},
    {"Forest", "Cave", "Mountain", "Lake", "End"},
    {"Forest", "Cave", "Mountain", "Lake", "End"},
    {"Forest", "Cave", "Mountain", "Lake", "End"}
};

// Define the player's current location
enum location current_location = FOREST;

// Define the player's current state
enum state current_state = ALIVE;

// Define the player's input
char input[100];

// Main game loop
int main() {
    // Print the game's intro
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a lone adventurer, lost in a strange and dangerous world.\n");
    printf("Your goal is to find the End and escape.\n");

    // Main game loop
    while (current_state == ALIVE) {
        // Get the player's input
        printf("> ");
        scanf("%s", input);

        // Process the player's input
        if (strcmp(input, "north") == 0) {
            // Move the player north
            if (current_location == FOREST) {
                current_location = CAVE;
            } else if (current_location == CAVE) {
                current_location = MOUNTAIN;
            } else if (current_location == MOUNTAIN) {
                current_location = LAKE;
            } else if (current_location == LAKE) {
                current_location = END;
            }
        } else if (strcmp(input, "south") == 0) {
            // Move the player south
            if (current_location == CAVE) {
                current_location = FOREST;
            } else if (current_location == MOUNTAIN) {
                current_location = CAVE;
            } else if (current_location == LAKE) {
                current_location = MOUNTAIN;
            } else if (current_location == END) {
                current_location = LAKE;
            }
        } else if (strcmp(input, "east") == 0) {
            // Move the player east
            if (current_location == FOREST) {
                current_location = MOUNTAIN;
            } else if (current_location == CAVE) {
                current_location = LAKE;
            } else if (current_location == MOUNTAIN) {
                current_location = END;
            } else if (current_location == LAKE) {
                current_location = FOREST;
            }
        } else if (strcmp(input, "west") == 0) {
            // Move the player west
            if (current_location == FOREST) {
                current_location = LAKE;
            } else if (current_location == CAVE) {
                current_location = FOREST;
            } else if (current_location == MOUNTAIN) {
                current_location = CAVE;
            } else if (current_location == LAKE) {
                current_location = MOUNTAIN;
            }
        } else if (strcmp(input, "look") == 0) {
            // Look around the current location
            printf("You are in the %s.\n", world[current_location][current_location]);
        } else if (strcmp(input, "inventory") == 0) {
            // Display the player's inventory
            printf("Your inventory:\n");
            for (int i = 0; i < inventory_size; i++) {
                printf(" - %s\n", inventory[i]);
            }
        } else if (strcmp(input, "quit") == 0) {
            // Quit the game
            current_state = DEAD;
        } else {
            // Invalid input
            printf("Invalid input.\n");
        }

        // Check if the player has reached the End
        if (current_location == END) {
            // The player has won!
            printf("Congratulations! You have reached the End.\n");
            current_state = DEAD;
        }
    }

    // Print the game's outro
    printf("Thank you for playing the Text-Based Adventure Game!\n");

    return 0;
}