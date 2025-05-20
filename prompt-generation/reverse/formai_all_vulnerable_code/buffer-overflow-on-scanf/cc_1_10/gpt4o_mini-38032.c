//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5
#define MAX_PLAYER_HEALTH 100

typedef struct {
    char name[20];
    char description[100];
    int item_count;
} Room;

typedef struct {
    char name[20];
    char description[100];
    int health;
} Player;

typedef struct {
    char name[20];
    char description[100];
} Item;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS];
Player player;
int current_room;
int game_over;

void init_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        snprintf(rooms[i].name, sizeof(rooms[i].name), "Room %d", i + 1);
        snprintf(rooms[i].description, sizeof(rooms[i].description), "This is the spooky Room %d.", i + 1);
        rooms[i].item_count = rand() % MAX_ITEMS;  // Randomly assign items to rooms
    }
}

void init_items() {
    // Define some items 
    snprintf(items[0].name, sizeof(items[0].name), "Old Key");
    snprintf(items[0].description, sizeof(items[0].description), "A rusted key that may open something.");
    
    snprintf(items[1].name, sizeof(items[1].name), "Ghostly Candle");
    snprintf(items[1].description, sizeof(items[1].description), "A candle that flickers even without wind.");
    
    snprintf(items[2].name, sizeof(items[2].name), "Mysterious Map");
    snprintf(items[2].description, sizeof(items[2].description), "Shows the layout of the haunted house.");
    
    snprintf(items[3].name, sizeof(items[3].name), "Ancient Potion");
    snprintf(items[3].description, sizeof(items[3].description), "A potion said to restore health.");
    
    snprintf(items[4].name, sizeof(items[4].name), "Spirit's Whistle");
    snprintf(items[4].description, sizeof(items[4].description), "A whistle that attracts spirits.");
}

void init_player() {
    snprintf(player.name, sizeof(player.name), "Ghost Hunter");
    snprintf(player.description, sizeof(player.description), "A brave soul ready to explore the haunted house.");
    player.health = MAX_PLAYER_HEALTH;
}

void print_room() {
    printf("\nYou are in %s.\n", rooms[current_room].name);
    printf("%s\n", rooms[current_room].description);
    printf("You see %d items in this room.\n", rooms[current_room].item_count);
}

void inspect_item() {
    if (rooms[current_room].item_count > 0) {
        printf("You found: %s - %s\n", items[rand() % MAX_ITEMS].name, items[rand() % MAX_ITEMS].description);
    } else {
        printf("No items found in this room!\n");
    }
}

void navigate() {
    int choice;
    printf("Choose a direction (1: Next Room, 2: Inspect Room): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        current_room++;
        if (current_room >= MAX_ROOMS) {
            current_room = 0; // Loop back to first room
            printf("You looped back to the start...\n");
        }
    } else if (choice == 2) {
        inspect_item();
    } else {
        printf("Invalid choice! Please choose again.\n");
    }
}

void check_game_over() {
    if (player.health <= 0) {
        game_over = 1;
        printf("You have encountered too many spirits! Game Over.\n");
    }
}

void game_loop() {
    while (!game_over) {
        print_room();
        navigate();
        player.health -= rand() % 20; // Random damage to player
        check_game_over();
    }
}

int main() {
    srand(time(NULL));
    current_room = 0;
    game_over = 0;

    init_rooms();
    init_items();
    init_player();

    printf("Welcome to the Haunted House Simulator!\n");
    game_loop();

    printf("Thanks for playing!\n");
    return 0;
}