//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define MAX_ITEMS 10
#define MAX_ROOM_SIZE 20
#define MAX_ITEMS_PER_ROOM 3

typedef struct {
    char name[MAX_ROOM_SIZE];
    int items[MAX_ITEMS];
    int num_items;
} Room;

void generate_room(Room *room) {
    srand(time(NULL));
    room->num_items = rand() % MAX_ITEMS_PER_ROOM + 1;
    for (int i = 0; i < room->num_items; i++) {
        room->items[i] = rand() % MAX_ITEMS;
    }
    printf("You enter the %s.\n", room->name);
    for (int i = 0; i < room->num_items; i++) {
        printf("You see %d.\n", room->items[i]);
    }
}

int main() {
    Room rooms[ROOMS];
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].num_items = 0;
    }

    int current_room = 0;
    while (1) {
        generate_room(&rooms[current_room]);

        printf("You can go to:\n");
        for (int i = 0; i < ROOMS; i++) {
            if (i!= current_room) {
                printf("%d) %s\n", i + 1, rooms[i].name);
            }
        }

        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > ROOMS) {
            printf("Invalid choice.\n");
        } else {
            current_room = choice - 1;
        }
    }

    return 0;
}