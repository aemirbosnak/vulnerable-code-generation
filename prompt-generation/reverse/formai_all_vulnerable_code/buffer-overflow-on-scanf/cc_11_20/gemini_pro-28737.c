//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room descriptions
char *rooms[7] = {
    "You are standing in a dark and gloomy forest.",
    "You are standing in a clearing. There is a path to the east and west.",
    "You are standing in a small village. There are houses all around you.",
    "You are standing in a castle. There is a throne room to the north.",
    "You are standing in a throne room. There is a king sitting on a throne.",
    "You are standing in a dungeon. There is a door to the north.",
    "You are standing in a secret room. There is a treasure chest in the middle of the room."
};

// Room connections
int connections[7][4] = {
    {1, 2, -1, -1},
    {0, 3, -1, -1},
    {1, 4, -1, -1},
    {2, 5, -1, -1},
    {3, -1, -1, -1},
    {4, -1, -1, -1},
    {-1, -1, -1, -1}
};

// Item descriptions
char *items[3] = {
    "sword",
    "key",
    "treasure"
};

// Item locations
int itemLocations[3] = {
    3,
    5,
    6
};

// Player inventory
char *inventory[10];
int inventorySize = 0;

// Player location
int location = 0;

// Game loop
int main() {
    // Print welcome message
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    // Game loop
    while (1) {
        // Print room description
        printf("%s\n", rooms[location]);

        // Print possible actions
        printf("What do you want to do?\n");
        printf("1. Go north\n");
        printf("2. Go east\n");
        printf("3. Go south\n");
        printf("4. Go west\n");
        printf("5. Examine\n");
        printf("6. Quit\n");

        // Get player input
        int choice;
        scanf("%d", &choice);

        // Process player choice
        switch (choice) {
            case 1:
                // Go north
                if (connections[location][0] != -1) {
                    location = connections[location][0];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 2:
                // Go east
                if (connections[location][1] != -1) {
                    location = connections[location][1];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 3:
                // Go south
                if (connections[location][2] != -1) {
                    location = connections[location][2];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 4:
                // Go west
                if (connections[location][3] != -1) {
                    location = connections[location][3];
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 5:
                // Examine
                printf("You are carrying the following items:\n");
                for (int i = 0; i < inventorySize; i++) {
                    printf("%s\n", inventory[i]);
                }
                break;
            case 6:
                // Quit
                printf("Goodbye!\n");
                return 0;
        }
    }

    return 0;
}