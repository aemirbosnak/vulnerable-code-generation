//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define global variables
int current_location = 0; // Starting location
int current_health = 100; // Starting health
bool is_alive = true; // Player starts alive

// Define function prototypes
void display_location();
void display_help();
void display_inventory();
void display_stats();
void move(char direction[]);
void loot();

// Define structures
struct item {
    char* name;
    int value;
    bool is_lootable;
};

struct location {
    char* name;
    char* description;
    struct item* items;
    int num_items;
    int north;
    int south;
    int east;
    int west;
};

struct location locations[] = {
    {"Abandoned Warehouse", "A large, empty warehouse. There's some debris on the ground.", NULL, 0, 1, -1, -1, -1},
    {"Desolate Street", "A quiet street that appears to have been abandoned for years. There's a building to the north.", NULL, 0, 2, 0, -1, -1},
    {"Old Apartment Building", "An old, run-down apartment building. There could be something inside.", NULL, 1, -1, 1, 3, -1},
    {"Abandoned Hospital", "A creepy, abandoned hospital. There's a weird smell coming from inside.", NULL, 0, -1, -1, 2, 4},
    {"Radio Tower", "An old radio tower. Could be a good place to radio for help.", NULL, 1, -1, -1, 3, -1}
};

struct item items[] = {
    {"Medkit", 50, true},
    {"Ammo", 25, true},
    {"Water Bottle", 10, true},
    {"Rusty Pipe", 5, true},
    {"Gold Coin", 100, true},
    {"Radio", 50, true}
};

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Display the game intro
    printf("Welcome to the post-apocalyptic adventure game!\n");
    printf("You start with 100 health. Good luck!\n\n");
    
    // Game loop
    while (is_alive) {
        // Display current location and options
        display_location();
        
        // Get player input
        char input[20];
        printf("\n> ");
        fgets(input, 20, stdin);
        input[strlen(input)-1] = '\0';
        
        // Parse player input
        if (strcmp(input, "help") == 0) {
            display_help();
        }
        else if (strcmp(input, "inventory") == 0) {
            display_inventory();
        }
        else if (strcmp(input, "stats") == 0) {
            display_stats();
        }
        else if (strcmp(input, "north") == 0 || strcmp(input, "south") == 0 || strcmp(input, "east") == 0 || strcmp(input, "west") == 0) {
            move(input);
            if (is_alive) {
                loot();
            }
        }
        else {
            printf("\nInvalid input. Type 'help' for a list of commands.\n");
        }
    }
    
    // Exit message
    printf("Thanks for playing!\n");
    
    return 0;
}

void display_location() {
    // Display location name and description
    printf("You are at the %s.\n", locations[current_location].name);
    printf("%s\n", locations[current_location].description);
    
    // Display available directions
    printf("You can go: ");
    if (locations[current_location].north != -1) {
        printf("north ");
    }
    if (locations[current_location].south != -1) {
        printf("south ");
    }
    if (locations[current_location].east != -1) {
        printf("east ");
    }
    if (locations[current_location].west != -1) {
        printf("west ");
    }
    printf("\n");
}

void display_help() {
    // Display list of commands
    printf("\nCommands:\n");
    printf("north, south, east, west - move in that direction\n");
    printf("inventory - list your current items\n");
    printf("stats - show your current health\n");
    printf("help - display this list of commands\n");
}

void display_inventory() {
    // Display player's current inventory
    printf("\nInventory:\n");
    int i;
    for (i = 0; i < sizeof(items) / sizeof(struct item); i++) {
        if (items[i].value != 0) {
            printf("%s\n", items[i].name);
        }
    }
}

void display_stats() {
    // Display player's current health
    printf("\nHealth: %d\n", current_health);
}

void move(char direction[]) {
    // Move player in the specified direction
    if (strcmp(direction, "north") == 0) {
        current_location = locations[current_location].north;
    }
    else if (strcmp(direction, "south") == 0) {
        current_location = locations[current_location].south;
    }
    else if (strcmp(direction, "east") == 0) {
        current_location = locations[current_location].east;
    }
    else if (strcmp(direction, "west") == 0) {
        current_location = locations[current_location].west;
    }
    printf("\nYou move %s.\n", direction);
}

void loot() {
    // Check if there are items to loot
    if (locations[current_location].items == NULL || locations[current_location].num_items == 0) {
        return;
    }
    
    // Loop through the items and randomly add them to the player's inventory
    printf("You find some items!\n");
    int i;
    for (i = 0; i < locations[current_location].num_items; i++) {
        if (rand() % 100 < 50 && locations[current_location].items[i].is_lootable) {
            printf("You found a %s!\n", locations[current_location].items[i].name);
            int j;
            for (j = 0; j < sizeof(items) / sizeof(struct item); j++) {
                if (strcmp(locations[current_location].items[i].name, items[j].name) == 0) {
                    items[j].value += locations[current_location].items[i].value;
                    break;
                }
            }
        }
    }
    
    // Remove all items from the location
    locations[current_location].items = NULL;
    locations[current_location].num_items = 0;
}