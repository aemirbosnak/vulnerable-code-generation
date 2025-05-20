//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int has_item;
} Room;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int collected;
} Item;

void initialize_rooms(Room rooms[]) {
    const char *room_names[MAX_ROOMS] = {
        "Abandoned Living Room",
        "Creepy Basement",
        "Sinister Kitchen",
        "Haunted Bedroom",
        "Spooky Attic",
        "Ghostly Hallway",
        "Mysterious Bathroom",
        "Eerie Library",
        "Dark Cellar",
        "Terrifying Garden"
    };
    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(rooms[i].name, "%s", room_names[i]);
        rooms[i].has_item = rand() % 2; // Randomly set has_item
    }
}

void initialize_items(Item items[]) {
    const char *item_names[MAX_ITEMS] = {
        "Ancient Key",
        "Ghostly Whisper",
        "Cursed Doll",
        "Wicked Candle",
        "Phantom Mirror"
    };
    for (int i = 0; i < MAX_ITEMS; i++) {
        sprintf(items[i].name, "%s", item_names[i]);
        items[i].collected = 0;
    }
}

void display_rooms(Room rooms[]) {
    printf("\nYou are in a haunted house. The available rooms are:\n");
    for (int i = 0; i < MAX_ROOMS; i++)
        printf("%d. %s\n", i + 1, rooms[i].name);
}

void explore_room(Room *room, Item items[]) {
    printf("You entered the %s.\n", room->name);
    if (room->has_item) {
        int item_index = rand() % MAX_ITEMS;
        printf("You found a %s!\n", items[item_index].name);
        items[item_index].collected = 1;
        room->has_item = 0; // The item is no longer here
    } else {
        printf("The room is empty. Better luck next time!\n");
    }
}

void display_collected_items(Item items[]) {
    printf("\nCollected Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].collected) {
            printf("- %s\n", items[i].name);
        }
    }
}

int main() {
    srand(time(NULL));
    Room rooms[MAX_ROOMS];
    Item items[MAX_ITEMS];
    int choice, keep_game_playing = 1;

    initialize_rooms(rooms);
    initialize_items(items);

    while (keep_game_playing) {
        display_rooms(rooms);
        printf("Choose a room to explore (1-%d) or 0 to quit: ", MAX_ROOMS);
        scanf("%d", &choice);
        
        if (choice == 0) {
            keep_game_playing = 0;
            continue;
        }
        
        if (choice < 1 || choice > MAX_ROOMS) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        explore_room(&rooms[choice-1], items);
        display_collected_items(items);
    }

    printf("\nThanks for playing the Haunted House Simulator!\n");
    return 0;
}