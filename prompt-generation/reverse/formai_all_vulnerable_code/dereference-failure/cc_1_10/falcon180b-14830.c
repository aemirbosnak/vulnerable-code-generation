//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define NUM_ITEMS 10

typedef struct {
    char *name;
    int value;
} Item;

typedef struct {
    char *description;
    int num_items;
    Item *items;
} Room;

void create_room(Room *room, char *description) {
    room->description = description;
    room->num_items = rand() % NUM_ITEMS + 1; // Randomly assign number of items in each room
    room->items = malloc(sizeof(Item) * room->num_items);
    int i;
    for (i = 0; i < room->num_items; i++) {
        room->items[i].name = malloc(sizeof(char) * 20);
        sprintf(room->items[i].name, "Item %d", i+1);
        room->items[i].value = rand() % 100;
    }
}

void print_room(Room *room) {
    printf("You are in the %s.\n", room->description);
    int i;
    for (i = 0; i < room->num_items; i++) {
        printf("There is a %s here worth %d points.\n", room->items[i].name, room->items[i].value);
    }
}

int main() {
    srand(time(0));
    Room rooms[NUM_ROOMS];
    char *room_descriptions[] = {"Spooky Entrance", "Creaky Hallway", "Dark Chamber", "Mysterious Library", "Haunted Attic"};
    int i;
    for (i = 0; i < NUM_ROOMS; i++) {
        create_room(&rooms[i], room_descriptions[i]);
    }
    int current_room = 0;
    while (1) {
        print_room(&rooms[current_room]);
        printf("Where do you want to go? ");
        scanf("%d", &current_room);
        if (current_room < 0 || current_room >= NUM_ROOMS) {
            printf("Invalid room number.\n");
        } else {
            break;
        }
    }
    return 0;
}