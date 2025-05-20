//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define GHOSTS 3

int main() {
    srand(time(NULL));
    int rooms[ROOMS] = {1, 2, 3, 4, 5};
    int ghosts[GHOSTS] = {1, 2, 3};
    int player_room = 1;
    int player_lives = 3;
    int ghost_room = ghosts[0];

    printf("Welcome to the Haunted House!\n");
    printf("You have %d lives left.\n", player_lives);

    while (player_lives > 0) {
        printf("You are in room %d.\n", player_room);
        printf("The ghost is in room %d.\n", ghost_room);

        int choice;
        printf("What do you want to do?\n");
        printf("1. Move to another room\n");
        printf("2. Stay in this room\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int new_room;
            printf("Which room do you want to move to?\n");
            scanf("%d", &new_room);

            if (new_room == ghost_room) {
                printf("You encountered the ghost! You lose a life.\n");
                player_lives--;
            } else {
                printf("You moved to room %d.\n", new_room);
                player_room = new_room;
            }
        } else {
            printf("You stayed in room %d.\n", player_room);
        }

        if (player_lives == 0) {
            printf("You lost all your lives. Game over.\n");
            break;
        }

        int random_ghost = ghosts[rand() % GHOSTS];
        if (random_ghost!= ghost_room) {
            ghost_room = random_ghost;
        }
    }

    return 0;
}