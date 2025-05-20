//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Game states
enum state {
    START,
    ROOM1,
    ROOM2,
    ROOM3,
    WIN,
    LOSE
};

// Room descriptions
char *room_descriptions[] = {
    "You are in a dark and damp cave. The only light comes from a small torch on the wall.",
    "You are in a small, windowless room. There is a door to the north and a door to the east.",
    "You are in a large, open room. There is a door to the south and a door to the west.",
    "You are in a small, dark room. There is a door to the east.",
    "You have found the treasure! You win!",
    "You have fallen into a trap! You lose."
};

// Available actions in each room
char *room_actions[][5] = {
    {"look", "north", "south", "east", "west"},
    {"look", "north", "east"},
    {"look", "south", "west"},
    {"look", "east"},
    {},
    {}
};

// Game logic
int game_logic(enum state *state, char *input) {
    // Check if the input is a valid action
    int action_found = 0;
    for (int i = 0; room_actions[*state][i] != NULL; i++) {
        if (strcmp(input, room_actions[*state][i]) == 0) {
            action_found = 1;
            break;
        }
    }

    // If the input is not a valid action, print an error message
    if (!action_found) {
        printf("Invalid action. Please enter a valid action.\n");
        return 0;
    }

    // Update the game state based on the input
    if (strcmp(input, "look") == 0) {
        printf("%s\n", room_descriptions[*state]);
    } else if (strcmp(input, "north") == 0) {
        *state = ROOM1;
    } else if (strcmp(input, "south") == 0) {
        *state = ROOM2;
    } else if (strcmp(input, "east") == 0) {
        *state = ROOM3;
    } else if (strcmp(input, "west") == 0) {
        *state = ROOM2;
    }

    // Check if the player has won or lost
    if (*state == WIN) {
        printf("You have won the game!\n");
        return 1;
    } else if (*state == LOSE) {
        printf("You have lost the game.\n");
        return 1;
    }

    // Return 0 to continue the game
    return 0;
}

// Main game loop
int main() {
    // Initialize the game state
    enum state state = START;

    // Game loop
    while (1) {
        // Print the current room description
        printf("%s\n", room_descriptions[state]);

        // Get the player's input
        char input[100];
        printf("> ");
        scanf("%s", input);

        // Update the game state based on the player's input
        int game_over = game_logic(&state, input);

        // Check if the game is over
        if (game_over) {
            break;
        }
    }

    return 0;
}