//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_ROOM 10
#define MAX_TRAP 5
#define MAX_MONSTER 3
#define MAX_GOLD 100

typedef struct {
    int num;
    char name[10];
    int trap;
    int monster;
    int gold;
} Room;

void create_house(Room *rooms) {
    srand(time(NULL));

    for (int i = 0; i < MAX_ROOM; i++) {
        rooms[i].num = i + 1;
        strcpy(rooms[i].name, "Room");
        rooms[i].trap = rand() % 3 + 1;
        rooms[i].monster = rand() % 3 + 1;
        rooms[i].gold = rand() % (MAX_GOLD + 1);
    }
}

void print_room(Room room) {
    printf("\n%s:\n", room.name);
    printf("Traps: %d\n", room.trap);
    printf("Monster: %d\n", room.monster);
    printf("Gold: %d\n", room.gold);
}

void enter_room(Room *rooms, int *current_room) {
    int choice;

    print_room(rooms[*current_room]);

    printf("\nDo you want to enter the next room? (1 - Yes, 0 - No)\n");
    scanf("%d", &choice);

    if (choice == 1) {
        (*current_room)++;

        if (*current_room >= MAX_ROOM) {
            printf("\nCongratulations! You have finished the Haunted House.\n");
            exit(0);
        }
    }
}

int main() {
    Room rooms[MAX_ROOM];
    int current_room = 0;

    create_house(rooms);

    while (1) {
        enter_room(rooms, &current_room);
    }

    return 0;
}