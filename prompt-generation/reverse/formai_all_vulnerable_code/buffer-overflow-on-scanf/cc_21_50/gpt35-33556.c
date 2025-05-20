//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANET_NAME_LENGTH 20
#define MAX_ITEMS_INVENTORY 10

typedef struct {
    char name[MAX_PLANET_NAME_LENGTH];
    int distance_from_earth;
    int danger_level;
} Planet;

typedef struct {
    char name[MAX_PLANET_NAME_LENGTH];
    char description[100];
    int rarity_level;
} Item;

typedef struct {
    Item inventory[MAX_ITEMS_INVENTORY];
    int num_items;
} Inventory;

int main() {
    // Welcome message
    printf("Welcome to Paranoid Procedural Space Adventure!\n\n");
    printf("You are in charge of a spaceship and are travelling through the galaxy.\n");

    // Create planets
    Planet earth = {"Earth", 0, 0};
    Planet alpha_centauri = {"Alpha Centauri", 4.37, 7};
    Planet proxima_centauri = {"Proxima Centauri", 4.24, 9};
    Planet sirius = {"Sirius", 8.6, 6};

    // Create inventory
    Inventory inventory = {{0}, 0};

    // Generate items
    Item anti_gravity_boots = {"Anti-gravity boots", "Allows you to jump over obstacles", 5};
    Item laser_gun = {"Laser gun", "Allows you to defend yourself against aliens", 7};
    Item oxygen_tank = {"Oxygen tank", "Allows you to breathe on planets without oxygen", 8};

    // Variables to keep track of game state
    Planet current_planet = earth;
    int quitting = 0;
    int num_aliens = 0;
    int alien_attack_chance = 0;

    // Game loop
    while (!quitting) {
        // Display current planet information
        printf("You are currently on %s, which is %d light years away from Earth.\n", current_planet.name, current_planet.distance_from_earth);
        printf("The danger level on this planet is %d out of 10.\n", current_planet.danger_level);

        // Display inventory
        printf("Your inventory:\n");
        if (inventory.num_items == 0) {
            printf("Empty\n");
        } else {
            for (int i = 0; i < inventory.num_items; i++) {
                printf("  %s: %s\n", inventory.inventory[i].name, inventory.inventory[i].description);
            }
        }

        // Options menu
        printf("What would you like to do?\n");
        printf("1. Travel to a new planet\n");
        printf("2. Search for items on current planet\n");
        printf("3. Use an item from your inventory\n");
        printf("4. Check for alien attacks\n");
        printf("5. Quit game\n");
        int choice;
        scanf("%d", &choice);

        // Perform action based on choice
        switch(choice) {
            case 1:
                // Choose a new planet to travel to
                printf("Which planet would you like to travel to?\n");
                printf("1. Alpha Centauri\n");
                printf("2. Proxima Centauri\n");
                printf("3. Sirius\n");
                int planet_choice;
                scanf("%d", &planet_choice);
                switch(planet_choice) {
                    case 1:
                        current_planet = alpha_centauri;
                        break;
                    case 2:
                        current_planet = proxima_centauri;
                        break;
                    case 3:
                        current_planet = sirius;
                        break;
                }
                break;
            case 2:
                // Search for items on current planet
                printf("You are searching for items on %s...\n", current_planet.name);
                if (current_planet.danger_level <= 5) {
                    printf("There are no items to be found on this planet.\n");
                } else {
                    printf("You found an item!\n");
                    if (inventory.num_items >= MAX_ITEMS_INVENTORY) {
                        printf("But your inventory is full.\n");
                    } else {
                        // Add item to inventory
                        printf("You added %s to your inventory.\n", anti_gravity_boots.name);
                        inventory.inventory[inventory.num_items] = anti_gravity_boots;
                        inventory.num_items++;
                    }
                }
                break;
            case 3:
                // Use an item from your inventory
                printf("Which item would you like to use?\n");
                if (inventory.num_items == 0) {
                    printf("Your inventory is empty.\n");
                } else {
                    for (int i = 0; i < inventory.num_items; i++) {
                        printf("%d. %s\n", i+1, inventory.inventory[i].name);
                    }
                    int item_choice;
                    scanf("%d", &item_choice);
                    if (item_choice < 1 || item_choice > inventory.num_items) {
                        printf("Invalid choice.\n");
                    } else {
                        // Use item
                        printf("You used %s.\n", inventory.inventory[item_choice-1].name);
                        // Remove item from inventory
                        for (int i = item_choice-1; i < inventory.num_items-1; i++) {
                            inventory.inventory[i] = inventory.inventory[i+1];
                        }
                        inventory.num_items--;
                    }
                }
                break;
            case 4:
                // Check for alien attack
                alien_attack_chance++;
                if (alien_attack_chance % 3 == 0 && num_aliens == 0) {
                    printf("Aliens are attacking your spaceship!\n");
                    num_aliens = rand() % (current_planet.danger_level + 1);
                    printf("There are %d aliens.\n", num_aliens);
                } else if (num_aliens > 0) {
                    printf("You are being attacked by aliens!\n");
                    num_aliens--;
                    if (num_aliens == 0) {
                        printf("The aliens have been defeated.\n");
                    }
                } else {
                    printf("No alien attacks detected.\n");
                }
                break;
            case 5:
                // Quit the game
                quitting = 1;
                break;
            default:
                // Invalid choice
                printf("Invalid choice.\n");
                break;
        }

        // Check if player has died
        if (num_aliens > current_planet.danger_level || rand() % 10 == 0) {
            printf("You have died.\n");
            quitting = 1;
        }
    }

    // Game over
    printf("Game over.\n");

    return 0;
}