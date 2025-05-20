//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5
#define MAX_ENEMIES 5

typedef struct {
    char name[50];
    int description;
    int item;
    int enemy;
} room;

room rooms[MAX_ROOMS];

void init_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].description = rand() % 100;
        rooms[i].item = rand() % 2;
        rooms[i].enemy = rand() % 2;
    }
}

void print_room(int room_num) {
    printf("You are in room %d.\n", room_num + 1);
    printf("Description: %s\n", rooms[room_num].name);
    if (rooms[room_num].item) {
        printf("You found an item!\n");
    } else {
        printf("You didn't find anything.\n");
    }
    if (rooms[room_num].enemy) {
        printf("An enemy appears!\n");
    } else {
        printf("No enemies in sight.\n");
    }
}

int main() {
    srand(time(NULL));
    init_rooms();

    int current_room = 0;

    while (1) {
        int choice;
        printf("What do you want to do?\n");
        printf("1. Move to the next room\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            current_room++;
            if (current_room > MAX_ROOMS - 1) {
                current_room = 0;
            }
            print_room(current_room);
        } else {
            break;
        }
    }

    return 0;
}