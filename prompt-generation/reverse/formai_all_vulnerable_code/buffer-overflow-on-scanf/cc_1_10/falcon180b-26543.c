//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10
#define MAX_COMMANDS 10
#define MAX_NPCS 10

typedef struct {
    char *name;
    char *description;
    int items[MAX_ITEMS];
    int npcs[MAX_NPCS];
} Room;

typedef struct {
    char *name;
    char *description;
} Item;

typedef struct {
    char *name;
    char *description;
} NPC;

int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOMS];
    Item items[MAX_ITEMS];
    NPC npcs[MAX_NPCS];

    int num_rooms = 0;
    int num_items = 0;
    int num_npcs = 0;

    Room *current_room = &rooms[0];
    current_room->name = "Starting Room";
    current_room->description = "You are in the starting room. There is a door to the east.";
    current_room->items[0] = 1; // Add an item to the room
    current_room->npcs[0] = 1; // Add an NPC to the room

    num_rooms++;
    num_items++;
    num_npcs++;

    int choice;
    while (1) {
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (current_room->items[0]) {
                printf("You picked up the item.\n");
                current_room->items[0] = 0;
            } else {
                printf("There is no item here.\n");
            }
            break;

        case 2:
            if (current_room->npcs[0]) {
                printf("You talked to the NPC.\n");
            } else {
                printf("There is no NPC here.\n");
            }
            break;

        case 3:
            if (num_rooms > 1) {
                if (current_room->npcs[0]) {
                    printf("The NPC tells you to go east.\n");
                } else {
                    printf("You decide to go east.\n");
                }
                current_room = &rooms[1];
            } else {
                printf("There is no door to the east.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}