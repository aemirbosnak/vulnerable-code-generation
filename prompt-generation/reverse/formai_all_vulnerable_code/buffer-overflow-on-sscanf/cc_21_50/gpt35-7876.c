//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

// Define a struct for the adventure game item
typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int location;
} Item;

int main() {
    // Initialize random number generator using time
    srand((unsigned int) time(NULL));

    // Define the possible adventure game items with their descriptions and locations
    Item items[] = {
        {"Key", "A shiny gold key", 0},
        {"Sword", "A sharp sword with a jeweled hilt", 2},
        {"Scroll", "An ancient scroll with mysterious writing", 1},
        {"Goblet", "A bronze goblet with intricate engravings", 4},
        {"Gem", "A sparkling blue gemstone", 3}
    };
    int num_items = sizeof(items) / sizeof(Item);

    // Define the possible locations and their descriptions
    char locations[][MAX_DESC_LEN] = {
        "You are standing in a dark room. There is a door to the north.",
        "You are in a dusty library. There is a bookshelf to the east.",
        "You are in a damp cave. There is a path to the south.",
        "You are in a sparkling cavern. There is a tunnel to the west.",
        "You are in a grand hall. There are stairs to the north."
    };
    int num_locations = sizeof(locations) / sizeof(char[MAX_DESC_LEN]);

    // Initialize player location and backpack
    int player_location = 0;
    Item backpack[num_items];
    int num_items_in_backpack = 0;

    // Print game introduction
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark room with little light.\n");
    printf("Your objective is to find the treasure room and collect as many valuable items as possible.\n");
    printf("You can move around by typing 'north', 'south', 'east', or 'west'.\n");
    printf("You can take an item by typing 'take' followed by the item name.\n");
    printf("You can check your backpack by typing 'backpack'.\n");
    printf("Good luck!\n\n");

    // Main game loop
    while (player_location < num_locations - 1) {  // Loop until player reaches treasure room
        // Print location description and possible actions
        printf("%s\n", locations[player_location]);
        printf("Possible actions: ");
        if (player_location > 0) printf("north, ");
        if (player_location < num_locations - 2) printf("south, ");
        if (player_location == 1) printf("east, ");
        if (player_location == 3) printf("west, ");
        printf("take, backpack\n");

        // Get user input
        char input[MAX_NAME_LEN + 5];  // Add some space for "take " or "drop " prefix
        printf("> ");
        fgets(input, MAX_NAME_LEN + 5, stdin);

        // Parse user input
        char action[MAX_NAME_LEN];
        char arg[MAX_NAME_LEN];
        sscanf(input, "%s %[^\n]", action, arg);

        // Handle user actions
        if (strcmp(action, "north") == 0) {
            if (player_location > 0) {
                player_location--;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(action, "south") == 0) {
            if (player_location < num_locations - 2) {
                player_location++;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(action, "east") == 0) {
            if (player_location == 1) {
                player_location++;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(action, "west") == 0) {
            if (player_location == 3) {
                player_location--;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(action, "take") == 0) {
            int item_found = 0;
            for (int i = 0; i < num_items; i++) {
                if (strcmp(arg, items[i].name) == 0 && items[i].location == player_location) {
                    // Add item to backpack
                    memcpy(&backpack[num_items_in_backpack], &items[i], sizeof(Item));
                    num_items_in_backpack++;
                    // Remove item from game
                    items[i].location = -1;
                    item_found = 1;
                    printf("You take the %s.\n", arg);
                    break;
                }
            }
            if (!item_found) {
                printf("There is no %s here.\n", arg);
            }
        } else if (strcmp(action, "backpack") == 0) {
            if (num_items_in_backpack > 0) {
                printf("Backpack contents:\n");
                for (int i = 0; i < num_items_in_backpack; i++) {
                    printf("  %s - %s\n", backpack[i].name, backpack[i].description);
                }
            } else {
                printf("Your backpack is empty.\n");
            }
        } else {
            printf("I don't understand what you mean.\n");
        }
    }

    // Player has reached treasure room - calculate score
    int score = 0;
    for (int i = 0; i < num_items_in_backpack; i++) {
        score += rand() % 101;  // Add a random value to each item
    }
    printf("Congratulations, you have reached the treasure room!\n");
    printf("Your score is %d.\n", score);

    return 0;
}