//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10

typedef struct {
    char *name;
    char *description;
} Room;

typedef struct {
    char *name;
    char *description;
    int value;
} Item;

Room rooms[MAX_ROOMS];
Item items[MAX_ITEMS];

int num_rooms = 0;
int num_items = 0;

void generate_rooms() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].name = (char *)malloc(10 * sizeof(char));
        rooms[i].description = (char *)malloc(100 * sizeof(char));
        sprintf(rooms[i].name, "Room %d", i + 1);
        sprintf(rooms[i].description, "You are in Room %d. There is a door to the north.", i + 1);
        num_rooms++;
    }
}

void generate_items() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name = (char *)malloc(10 * sizeof(char));
        items[i].description = (char *)malloc(100 * sizeof(char));
        items[i].value = rand() % 100;
        sprintf(items[i].name, "Item %d", i + 1);
        sprintf(items[i].description, "You found Item %d. It is worth %d points.", i + 1, items[i].value);
        num_items++;
    }
}

void print_room(Room room) {
    printf("%s\n", room.description);
}

void print_item(Item item) {
    printf("You found %s. It is worth %d points.\n", item.name, item.value);
}

int main() {
    generate_rooms();
    generate_items();

    int room_index = 0;
    while (1) {
        print_room(rooms[room_index]);

        printf("What do you want to do? ");
        char action[10];
        scanf("%s", action);

        if (strcmp(action, "go north") == 0) {
            if (room_index < num_rooms - 1) {
                room_index++;
            } else {
                printf("You reached the end of the game.\n");
                break;
            }
        } else if (strcmp(action, "pick up") == 0) {
            int item_index = rand() % num_items;
            printf("You picked up %s.\n", items[item_index].name);
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}