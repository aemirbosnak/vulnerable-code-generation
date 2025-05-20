//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define GHOST_CHANCE 40
#define MAX_GHOSTS 3
#define ESCAPE_ROOM 7

int main() {
    int rooms[ROOMS];
    int ghosts = 0;
    int current_room = 0;
    srand(time(NULL));

    // Initialize rooms
    for (int i = 0; i < ROOMS; i++) {
        rooms[i] = i + 1;
    }

    // Shuffle rooms
    for (int i = 0; i < ROOMS; i++) {
        int j = rand() % ROOMS;
        int temp = rooms[i];
        rooms[i] = rooms[j];
        rooms[j] = temp;
    }

    // Game loop
    while (current_room != ESCAPE_ROOM) {
        printf("You are in room %d.\n", rooms[current_room]);

        // Check for ghost
        if ((rand() % 100) < GHOST_CHANCE) {
            printf("A ghost appeared!\n");
            ghosts++;

            // Check if too many ghosts
            if (ghosts >= MAX_GHOSTS) {
                printf("Too many ghosts! You lose!\n");
                return 0;
            }
        }

        // Move to next room
        printf("Move to (1) the next room or (2) a random room: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            current_room++;

            // Check if at end
            if (current_room == ROOMS) {
                printf("You reached the end, but there is no escape!\n");
                return 0;
            }
        } else if (choice == 2) {
            current_room = rand() % ROOMS;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    // Escaped!
    printf("You escaped the haunted house!\n");
    return 0;
}