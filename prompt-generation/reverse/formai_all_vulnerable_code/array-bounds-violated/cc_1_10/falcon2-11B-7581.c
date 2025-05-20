//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialization
    int door = 1;
    int ghost = 1;
    int step = 1;
    int prev_step = 0;
    int n_ghosts = 3;
    int n_doors = 3;
    int n_rooms = 3;

    // Variable declarations
    char* room_names[] = {"Room 1", "Room 2", "Room 3"};
    char* door_names[] = {"Door 1", "Door 2", "Door 3"};
    char* ghost_names[] = {"Ghost 1", "Ghost 2", "Ghost 3"};
    int room_pos[] = {1, 2, 3};
    int door_pos[] = {1, 2, 3};
    int ghost_pos[] = {1, 2, 3};

    // Randomization
    srand(time(NULL));

    // Loop
    while (door <= n_doors && ghost <= n_ghosts) {
        // Print room name
        printf("\nRoom: %s\n", room_names[room_pos[step] - 1]);

        // Randomly choose a door
        int door_rand = rand() % n_doors;
        printf("Door: %s\n", door_names[door_rand]);

        // Randomly choose a ghost
        int ghost_rand = rand() % n_ghosts;
        printf("Ghost: %s\n", ghost_names[ghost_rand]);

        // Decide the next step
        if (door == door_rand) {
            if (ghost == ghost_rand) {
                printf("The door leads to a dead end and you meet a ghost.\n");
                printf("You are scared and decide to go back to the previous room.\n");
            } else {
                printf("The door leads to a room with a ghost.\n");
                printf("You decide to go back to the previous room.\n");
            }
        } else {
            if (ghost == ghost_rand) {
                printf("You open the door and enter the room.\n");
            } else {
                printf("You decide to go back to the previous room.\n");
            }
        }

        // Increment step
        step++;
        door++;
        ghost++;

        // Reset if step is greater than n_rooms
        if (step > n_rooms) {
            step = 1;
            door = 1;
            ghost = 1;
        }
    }

    return 0;
}