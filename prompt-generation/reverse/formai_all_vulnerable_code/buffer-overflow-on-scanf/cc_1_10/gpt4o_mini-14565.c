//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_ENCOUNTERS 3

typedef struct {
    char *name;
    int health;
} Creature;

typedef struct {
    char *name;
    int count;
} Item;

Creature creatures[MAX_ENCOUNTERS] = {
    {"Calm Deer", 15},
    {"Wise Owl", 10},
    {"Gentle Fox", 12}
};

Item inventory[MAX_ITEMS];
int item_count = 0;

void print_welcome() {
    printf("Welcome to the Tranquil Forest Adventure!\n");
    printf("Explore the serene forest filled with gentle creatures and hidden treasures.\n");
    printf("Collect items along the way, but tread carefully.\n");
}

void print_inventory() {
    printf("\nYour inventory:\n");
    if (item_count == 0) {
        printf("You have no items collected.\n");
    } else {
        for (int i = 0; i < item_count; i++) {
            printf("- %s (x%d)\n", inventory[i].name, inventory[i].count);
        }
    }
}

void add_item(const char *item_name) {
    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            inventory[i].count++;
            return;
        }
    }
    if (item_count < MAX_ITEMS) {
        inventory[item_count].name = strdup(item_name);
        inventory[item_count].count = 1;
        item_count++;
    } else {
        printf("Inventory full! Could not collect %s.\n", item_name);
    }
}

void encounter_creature() {
    srand(time(NULL));
    int index = rand() % MAX_ENCOUNTERS;
    Creature encountered = creatures[index];
    printf("\nYou encounter a %s.\n", encountered.name);
    printf("Health of the creature: %d\n", encountered.health);

    char action[10];
    printf("Do you want to 'observe' or 'run' away? ");
    scanf("%s", action);

    if (strcmp(action, "observe") == 0) {
        printf("You watch the creature calmly.\n");
        printf("It seems to be unbothered by your presence.\n");
        add_item("Tranquility Feather");
    } else if (strcmp(action, "run") == 0) {
        printf("You quietly back away without disturbing the creature.\n");
    } else {
        printf("That's not a valid action. The creature disappears into the woods.\n");
    }
}

void explore_forest() {
    char choice[10];
    while (1) {
        printf("\nYou stand in the tranquil forest. You can 'explore', 'check inventory', or 'exit'.\n");
        printf("What would you like to do? ");
        scanf("%s", choice);

        if (strcmp(choice, "explore") == 0) {
            encounter_creature();
        } else if (strcmp(choice, "check") == 0) {
            print_inventory();
        } else if (strcmp(choice, "exit") == 0) {
            printf("Thank you for playing the Tranquil Forest Adventure! Farewell.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    print_welcome();
    explore_forest();
    
    // Free allocated memory for inventory items
    for (int i = 0; i < item_count; i++) {
        free(inventory[i].name);
    }

    return 0;
}