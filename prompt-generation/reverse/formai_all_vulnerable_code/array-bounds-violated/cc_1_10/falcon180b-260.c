//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 6
#define MAX_GHOSTS 3
#define MAX_ITEMS 5
#define MAX_PLAYERS 2

enum {
    GHOST = 'g',
    ITEM = 'i',
    PLAYER = 'p',
    EMPTY = '.'
};

struct Room {
    char map[3][3];
    int num_ghosts;
    int num_items;
    int player_x;
    int player_y;
};

void generate_map(struct Room *room) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            room->map[i][j] = EMPTY;
        }
    }
    room->num_ghosts = rand() % MAX_GHOSTS + 1;
    room->num_items = rand() % MAX_ITEMS + 1;
}

void print_map(struct Room *room) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", room->map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    struct Room rooms[ROOMS];
    int current_room = 0;
    int choice;

    while (current_room < ROOMS) {
        generate_map(&rooms[current_room]);
        print_map(&rooms[current_room]);
        printf("Press 1 to enter the room or 2 to skip:\n");
        scanf("%d", &choice);
        if (choice == 1) {
            int i, j;
            printf("Enter your starting position (row col):\n");
            scanf("%d %d", &i, &j);
            if (rooms[current_room].map[i][j] == EMPTY) {
                rooms[current_room].player_x = i;
                rooms[current_room].player_y = j;
            } else {
                printf("Invalid position, skipping room.\n");
            }
        }
        current_room++;
    }

    return 0;
}