//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_ITEMS 5

enum {
    ROOM_EMPTY = 0,
    ROOM_ITEM,
    ROOM_GHOST
};

struct room {
    int type;
    int item;
};

int main() {
    srand(time(NULL));

    struct room haunted_house[NUM_ROOMS] = {{ROOM_EMPTY}};

    for (int i = 0; i < NUM_ITEMS; i++) {
        int room_idx = rand() % NUM_ROOMS;
        haunted_house[room_idx].type = ROOM_ITEM;
        haunted_house[room_idx].item = i + 1;
    }

    haunted_house[NUM_ROOMS - 1].type = ROOM_GHOST;

    int player_pos = 0;

    while (1) {
        system("clear");
        printf("You are in room %d.\n", player_pos + 1);

        if (haunted_house[player_pos].type == ROOM_ITEM) {
            printf("There is an item here.\n");
        } else if (haunted_house[player_pos].type == ROOM_GHOST) {
            printf("A ghost appears!\n");
            return 0;
        }

        char move;
        scanf(" %c", &move);

        switch (move) {
        case 'w':
            if (player_pos > 0 && haunted_house[player_pos - 1].type!= ROOM_GHOST) {
                player_pos--;
            } else {
                printf("You can't go that way.\n");
            }
            break;
        case's':
            if (player_pos < NUM_ROOMS - 1 && haunted_house[player_pos + 1].type!= ROOM_GHOST) {
                player_pos++;
            } else {
                printf("You can't go that way.\n");
            }
            break;
        case 'q':
            return 0;
        default:
            printf("Invalid move.\n");
        }
    }

    return 0;
}