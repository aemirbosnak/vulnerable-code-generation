//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct {
    char *name;
    int has_item;
} Room;

typedef struct {
    char *name;
    int power;
} Item;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS];

int current_room = 0;
int player_power = 1;
int treasure_found = 0;

void initialize_rooms() {
    rooms[0] = (Room){"Entrance Hall", 0};
    rooms[1] = (Room){"Dark Corridor", 0};
    rooms[2] = (Room){"Treasure Chamber", 1};
    rooms[3] = (Room){"Monster Lair", 0};
    rooms[4] = (Room){"Hidden Cave", 1};
    rooms[5] = (Room){"Ancient Library", 0};
    rooms[6] = (Room){"Control Room", 0};
    rooms[7] = (Room){"Throne Room", 0};
    rooms[8] = (Room){"Sacred Garden", 1};
    rooms[9] = (Room){"Exit", 0};
}

void initialize_items() {
    items[0] = (Item){"Magic Sword", 5};
    items[1] = (Item){"Healing Potion", 2};
    items[2] = (Item){"Gold Coin", 0};
    items[3] = (Item){"Mystic Amulet", 3};
    items[4] = (Item){"Crystal Ball", 1};
}

void print_current_room() {
    printf("You are in the %s.\n", rooms[current_room].name);
    
    if (rooms[current_room].has_item) {
        printf("You see a sparkly treasure!\n");
    } else {
        printf("The room is empty.\n");
    }
}

void move_room(int room) {
    if (room < 0 || room >= MAX_ROOMS) {
        printf("You can't go that way.\n");
    } else {
        current_room = room;
        printf("You move to the %s!\n", rooms[current_room].name);
    }
}

void find_treasure() {
    if (rooms[current_room].has_item) {
        treasure_found++;
        rooms[current_room].has_item = 0; // Remove treasure after collecting
        printf("You found a treasure! Total treasures found: %d\n", treasure_found);
        
        // Randomly equip an item if it's not a gold coin
        int item_index = rand() % MAX_ITEMS;
        if (items[item_index].power > 0) {
            player_power += items[item_index].power;
            printf("You found a %s! Your power increased to %d.\n", items[item_index].name, player_power);
        } else {
            printf("You found some Gold Coins! They have no power but look shiny.\n");
        }
    } else {
        printf("There's no treasure here.\n");
    }
}

void display_status() {
    printf("\n============================\n");
    printf("Current Room: %s\n", rooms[current_room].name);
    printf("Player Power: %d\n", player_power);
    printf("Treasures Found: %d\n", treasure_found);
    printf("============================\n\n");
}

int main() {
    srand(time(NULL)); // Seed for random treasure
    initialize_rooms();
    initialize_items();

    printf("Welcome to the Dungeon Adventure Game!\n");
    printf("Explore rooms, gather treasures, and fight monsters!\n");
    
    char command[20];

    while (1) {
        print_current_room();
        display_status();

        printf("What do you want to do? (go [room_num], search, exit): ");
        scanf("%s", command);

        if (command[0] == 'g') {
            int room_num;
            sscanf(command + 3, "%d", &room_num);
            move_room(room_num);
        } else if (command[0] == 's') {
            find_treasure();
        } else if (command[0] == 'e') {
            printf("Thanks for playing! You found %d treasures and your final power is %d.\n", treasure_found, player_power);
            exit(0);
        } else {
            printf("Invalid command! Try 'go', 'search' or 'exit'.\n");
        }
    }

    return 0;
}