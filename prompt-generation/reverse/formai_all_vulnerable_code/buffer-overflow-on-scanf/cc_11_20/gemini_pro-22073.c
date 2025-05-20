//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Haunted house simulator in a medieval style

// Define the room names
const char *roomNames[] = {
    "The Great Hall",
    "The Library",
    "The Kitchen",
    "The Master Bedroom",
    "The Dungeon"
};

// Define the room descriptions
const char *roomDescriptions[] = {
    "A vast and echoing hall, with a high vaulted ceiling and a cold stone floor. A large fireplace crackles in the corner, casting a warm glow on the tapestries that adorn the walls.",
    "A cozy and comfortable room, with shelves lined with books old and new. A large window looks out over the garden, and a soft breeze rustles the leaves in the trees.",
    "A busy and bustling room, with a large hearth where food is cooked over an open fire. The smell of bread and roasting meat fills the air.",
    "A large and luxurious room, with a four-poster bed draped in velvet curtains. A large mirror hangs on the wall, and a dressing table is covered with cosmetics.",
    "A dark and gloomy room, with rough stone walls and a heavy iron door. A small window high up in the wall lets in a faint glimmer of light."
};

// Define the room connections
const int roomConnections[][5] = {
    {1, 2, 3, 4, 5},
    {0, 2, 3, 4, 5},
    {0, 1, 3, 4, 5},
    {0, 1, 2, 4, 5},
    {0, 1, 2, 3, 5}
};

// Define the room events
const char *roomEvents[] = {
    "You hear a creaking sound behind you.",
    "You see a shadow move in the corner of your eye.",
    "You feel a cold breeze on your neck.",
    "You hear a whisper in your ear.",
    "You see a ghost!"
};

// Define the player's stats
int playerHealth = 100;
int playerSanity = 100;

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the player
    printf("Welcome to the Haunted House Simulator. What is your name?\n");
    char playerName[256];
    scanf("%s", playerName);

    // Start the game
    int currentRoom = 0;
    while (playerHealth > 0 && playerSanity > 0) {
        // Display the room description
        printf("%s\n", roomDescriptions[currentRoom]);

        // Get the player's input
        printf("What do you want to do?\n");
        char input[256];
        scanf("%s", input);

        // Parse the player's input
        if (strcmp(input, "n") == 0) {
            // Go north
            currentRoom = roomConnections[currentRoom][0];
        } else if (strcmp(input, "s") == 0) {
            // Go south
            currentRoom = roomConnections[currentRoom][1];
        } else if (strcmp(input, "e") == 0) {
            // Go east
            currentRoom = roomConnections[currentRoom][2];
        } else if (strcmp(input, "w") == 0) {
            // Go west
            currentRoom = roomConnections[currentRoom][3];
        } else if (strcmp(input, "u") == 0) {
            // Go up
            currentRoom = roomConnections[currentRoom][4];
        } else if (strcmp(input, "d") == 0) {
            // Go down
            currentRoom = roomConnections[currentRoom][5];
        } else if (strcmp(input, "q") == 0) {
            // Quit the game
            break;
        }

        // Handle the room event
        int event = rand() % 5;
        printf("%s\n", roomEvents[event]);

        // Update the player's stats
        if (event == 4) {
            // The player saw a ghost!
            playerSanity -= 10;
        }
    }

    // End the game
    if (playerHealth <= 0) {
        printf("You died.\n");
    } else if (playerSanity <= 0) {
        printf("You went insane.\n");
    }

    return 0;
}