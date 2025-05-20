//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 10
#define MAX_MONSTER 5

typedef struct {
    int id;
    char name[20];
    int hp;
    int x, y;
} Monster;

typedef struct {
    int id;
    char name[20];
    int x, y;
} Room;

Monster monsters[MAX_MONSTER];
Room rooms[MAX_ROOM];

void init() {
    int i;
    for (i = 0; i < MAX_MONSTER; i++) {
        monsters[i].id = i + 1;
        sprintf(monsters[i].name, "Monster %d", i + 1);
        monsters[i].hp = rand() % 10 + 1;
        monsters[i].x = rand() % MAX_ROOM;
        monsters[i].y = rand() % MAX_ROOM;
    }

    for (i = 0; i < MAX_ROOM; i++) {
        rooms[i].id = i + 1;
        sprintf(rooms[i].name, "Room %d", i + 1);
        rooms[i].x = i;
        rooms[i].y = i;
    }
}

void print_room(int x, int y) {
    Room *room = &rooms[x];
    printf("%s:\n", room->name);
    printf("X: %d, Y: %d\n", x, y);
    printf("Monsters:\n");
    int i;
    for (i = 0; i < MAX_MONSTER; i++) {
        Monster *monster = &monsters[i];
        if (monster->x == x && monster->y == y) {
            printf("%s (HP: %d)\n", monster->name, monster->hp);
        }
    }
}

int main() {
    srand(time(NULL));
    init();

    int command, x, y;
    while (1) {
        printf("Enter command (1: go to room, 2: print room, 0: exit): ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("Enter room X and Y: ");
                scanf("%d %d", &x, &y);
                print_room(x, y);
                break;
            case 2:
                print_room(0, 0);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}