//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define GHOSTS 3

struct room {
    int x;
    int y;
    char name[50];
};

struct ghost {
    int x;
    int y;
    int speed;
};

struct room rooms[ROOMS] = {
    {0, 0, "Entrance"},
    {5, 0, "Kitchen"},
    {10, 0, "Living Room"},
    {15, 0, "Bedroom"},
    {20, 0, "Bathroom"}
};

struct ghost ghosts[GHOSTS] = {
    {0, 0, 1},
    {10, 10, 2},
    {20, 20, 3}
};

void draw_room(int room_num) {
    printf("You are in the %s.\n", rooms[room_num].name);
}

void move_ghosts() {
    for (int i = 0; i < GHOSTS; i++) {
        ghosts[i].x += ghosts[i].speed;
        if (ghosts[i].x >= 25) {
            ghosts[i].x = 0;
        }
    }
}

int main() {
    srand(time(NULL));

    int player_x = 0;
    int player_y = 0;

    while (1) {
        system("clear");

        draw_room(player_y);

        move_ghosts();

        for (int i = 0; i < GHOSTS; i++) {
            if (ghosts[i].x == player_x && ghosts[i].y == player_y) {
                printf("You've been caught by a ghost!\n");
                return 0;
            }
        }

        int choice;
        printf("What would you like to do?\n");
        printf("1. Move up\n");
        printf("2. Move down\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        if (choice == 1 && player_y > 0) {
            player_y--;
        } else if (choice == 2 && player_y < 4) {
            player_y++;
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}