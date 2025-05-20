//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define DOORS 4
#define GHOST_CHANCE 3
#define GHOST_SPEED 2

typedef struct {
    char name[50];
    int x, y;
    int has_ghost;
} Room;

void init_room(Room *room) {
    room->has_ghost = 0;
    sprintf(room->name, "Room %d", rand() % ROOMS + 1);
    room->x = rand() % DOORS;
    room->y = rand() % DOORS;
}

int main() {
    srand(time(NULL));

    Room rooms[ROOMS];
    for (int i = 0; i < ROOMS; i++) {
        init_room(&rooms[i]);
    }

    int player_x = 0, player_y = 0;
    int ghost_x = 0, ghost_y = 0;

    while (1) {
        system("clear");
        printf("Welcome to the Haunted House!\n");
        printf("You are currently in Room %s\n", rooms[player_x + player_y * ROOMS].name);

        if (rooms[player_x + player_y * ROOMS].has_ghost) {
            printf("A ghost appears!\n");
            return 1;
        }

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &move);

        int new_x = player_x;
        int new_y = player_y;

        switch (move) {
            case 'w':
                new_y--;
                break;
            case 'a':
                new_x--;
                break;
            case's':
                new_y++;
                break;
            case 'd':
                new_x++;
                break;
            default:
                printf("Invalid move.\n");
                continue;
        }

        if (new_x < 0 || new_x >= ROOMS || new_y < 0 || new_y >= ROOMS) {
            printf("You hit a wall.\n");
            continue;
        }

        if (rooms[new_x + new_y * ROOMS].has_ghost) {
            printf("You encounter a ghost!\n");
            return 1;
        }

        player_x = new_x;
        player_y = new_y;
    }

    return 0;
}