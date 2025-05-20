//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: retro
// Behold, the Text Adventure of Yore!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A veritable lexicon of player commands.
#define COMMAND_LOOK  "look"
#define COMMAND_NORTH "north"
#define COMMAND_SOUTH "south"
#define COMMAND_EAST  "east"
#define COMMAND_WEST  "west"
#define COMMAND_TAKE  "take"
#define COMMAND_USE   "use"
#define COMMAND_QUIT  "quit"

// A tapestry of room descriptions.
char *roomDescriptions[] = {
    "You stand in a dimly lit room. A heavy wooden door to the north beckons you.",
    "You enter a grand hall, its walls adorned with ancient tapestries. A narrow staircase spirals upwards to the east.",
    "A musty library greets you, its shelves overflowing with dusty tomes. A large window looks out onto a sprawling garden to the west."
};

// A treasure trove of objects.
char *objects[] = {
    "a rusty key",
    "a shimmering amulet",
    "a golden goblet"
};

// The player's current location.
int currentRoom = 0;

// The player's inventory.
char **inventory = NULL;
int inventorySize = 0;

// The main function, where the adventure unfolds.
int main() {
    // Greetings to the valiant adventurer!
    printf("Welcome to the Text Adventure of Yore!\n");

    // The player's journey continues until they choose to depart.
    while (1) {
        // Display the current room's description.
        printf("%s\n", roomDescriptions[currentRoom]);

        // Prompt the player for their next move.
        char input[80];
        printf("> ");
        scanf("%s", input);

        // Parse the player's command.
        if (strcmp(input, COMMAND_LOOK) == 0) {
            // Describe the current room and its contents.
            printf("You look around the room.\n");
            for (int i = 0; i < inventorySize; i++) {
                printf("You see %s here.\n", inventory[i]);
            }
        } else if (strcmp(input, COMMAND_NORTH) == 0) {
            // Attempt to move north, if possible.
            if (currentRoom == 0) {
                currentRoom = 1;
                printf("You go north.\n");
            } else {
                printf("There is no door to the north.\n");
            }
        } else if (strcmp(input, COMMAND_SOUTH) == 0) {
            // Attempt to move south, if possible.
            if (currentRoom == 1) {
                currentRoom = 0;
                printf("You go south.\n");
            } else {
                printf("There is no door to the south.\n");
            }
        } else if (strcmp(input, COMMAND_EAST) == 0) {
            // Attempt to move east, if possible.
            if (currentRoom == 1) {
                currentRoom = 2;
                printf("You go east.\n");
            } else {
                printf("There is no staircase to the east.\n");
            }
        } else if (strcmp(input, COMMAND_WEST) == 0) {
            // Attempt to move west, if possible.
            if (currentRoom == 2) {
                currentRoom = 1;
                printf("You go west.\n");
            } else {
                printf("There is no window to the west.\n");
            }
        } else if (strcmp(input, COMMAND_TAKE) == 0) {
            // Attempt to take an object, if possible.
            char object[80];
            printf("What do you want to take? ");
            scanf("%s", object);

            int found = 0;
            for (int i = 0; i < inventorySize; i++) {
                if (strcmp(object, inventory[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                // Add the object to the player's inventory.
                inventory = realloc(inventory, sizeof(char *) * ++inventorySize);
                inventory[inventorySize - 1] = strdup(object);
                printf("You take %s.\n", object);
            } else {
                printf("There is no %s here.\n", object);
            }
        } else if (strcmp(input, COMMAND_USE) == 0) {
            // Attempt to use an object, if possible.
            char object[80];
            printf("What do you want to use? ");
            scanf("%s", object);

            int found = 0;
            for (int i = 0; i < inventorySize; i++) {
                if (strcmp(object, inventory[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                // Use the object.
                if (strcmp(object, "rusty key") == 0) {
                    if (currentRoom == 0) {
                        currentRoom = 1;
                        printf("You use the rusty key to unlock the door to the north.\n");
                    } else {
                        printf("There is no door here that can be unlocked with this key.\n");
                    }
                } else if (strcmp(object, "shimmering amulet") == 0) {
                    printf("You hold the shimmering amulet in your hand, feeling its warmth.\n");
                } else if (strcmp(object, "golden goblet") == 0) {
                    printf("You take a sip from the golden goblet, savoring its sweet nectar.\n");
                }
            } else {
                printf("You don't have a %s.\n", object);
            }
        } else if (strcmp(input, COMMAND_QUIT) == 0) {
            // Farewell to the intrepid adventurer!
            printf("Farewell, adventurer! May your future quests be filled with glory.\n");
            return 0;
        } else {
            // The player's command was not recognized.
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}