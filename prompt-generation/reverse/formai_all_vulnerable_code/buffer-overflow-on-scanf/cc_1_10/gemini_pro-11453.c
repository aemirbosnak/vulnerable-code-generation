//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10

typedef struct {
    int x, y;
    int visited;
} Room;

Room rooms[NUM_ROOMS];

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].x = rand() % 100;
        rooms[i].y = rand() % 100;
        rooms[i].visited = 0;
    }

    // Start the game
    int currentRoom = 0;
    while (1) {
        // Print the current room
        printf("You are in room %d\n", currentRoom);

        // Print the options
        printf("Options:\n");
        printf("1. Move north\n");
        printf("2. Move east\n");
        printf("3. Move south\n");
        printf("4. Move west\n");
        printf("5. Quit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                currentRoom = (currentRoom + 1) % NUM_ROOMS;
                break;
            case 2:
                currentRoom = (currentRoom + 2) % NUM_ROOMS;
                break;
            case 3:
                currentRoom = (currentRoom + 3) % NUM_ROOMS;
                break;
            case 4:
                currentRoom = (currentRoom + 4) % NUM_ROOMS;
                break;
            case 5:
                return 0;
        }

        // Mark the current room as visited
        rooms[currentRoom].visited = 1;
    }

    return 0;
}