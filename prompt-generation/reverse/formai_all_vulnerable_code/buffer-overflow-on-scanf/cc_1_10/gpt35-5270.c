//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random generator
    int room_choice = 0;
    int ghost_choice = 0;
    int room_visited[5] = {0, 0, 0, 0, 0};
    int num_rooms_visited = 0;
    int num_ghosts_encountered = 0;
    int num_ghosts_defeated = 0;
    int num_ghosts_escape = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing outside a spooky old house.\n");
    printf("Do you dare to enter? (1 for yes, 0 for no) ");
    scanf("%d", &room_choice);

    if (room_choice == 0) {
        printf("You chicken out and run away. Game over!\n");
        return 0;
    }

    while (num_rooms_visited < 5) {
        room_choice = rand() % 5; // choose a random room to enter
        if (room_visited[room_choice] == 0) { // if you haven't been there before
            printf("\nYou enter room %d...", room_choice);

            ghost_choice = rand() % 3; // choose whether there's a ghost or not
            if (ghost_choice == 0) {
                printf("\nOh no! You encounter a ghost...\n");
                printf("Do you fight? (1 for yes, 0 for no) ");
                scanf("%d", &ghost_choice);

                if (ghost_choice == 1) {
                    printf("You defeat the ghost!\n");
                    num_ghosts_defeated++;
                } else {
                    printf("You run away from the ghost!\n");
                    num_ghosts_escape++;
                }

                num_ghosts_encountered++;
            } else {
                printf("\nPhew! No ghosts in this room.\n");
            }

            room_visited[room_choice] = 1; // mark room as visited
            num_rooms_visited++;
        }
    }

    printf("\nCongratulations, you've explored all the rooms in the haunted house!\n");
    printf("You encountered %d ghosts in total.\n", num_ghosts_encountered);
    printf("You defeated %d ghosts.\n", num_ghosts_defeated);
    printf("You escaped from %d ghosts.\n", num_ghosts_escape);

    return 0;
}