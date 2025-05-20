//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROOMS 5
#define GHOSTS 3

// Function to simulate a random number generator
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Define the haunted house
    bool rooms[ROOMS] = {true, true, true, true, true};
    bool ghosts[GHOSTS] = {true, true, true};
    int playerPos = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently in room 1.\n");

    while (true) {
        printf("Which direction would you like to go? (n/s/e/w): ");
        char direction;
        scanf(" %c", &direction);

        int newRoom;
        switch (direction) {
            case 'n':
                if (playerPos == 0) {
                    printf("You can't go that way!\n");
                    continue;
                }
                newRoom = playerPos - 1;
                break;
            case 's':
                if (playerPos == ROOMS - 1) {
                    printf("You can't go that way!\n");
                    continue;
                }
                newRoom = playerPos + 1;
                break;
            case 'e':
                newRoom = playerPos;
                break;
            case 'w':
                newRoom = getRandomNumber(0, ROOMS - 1);
                break;
            default:
                printf("Invalid direction!\n");
                continue;
        }

        playerPos = newRoom;
        printf("You are now in room %d.\n", playerPos + 1);

        // Check if there are any ghosts in the current room
        bool foundGhost = false;
        for (int i = 0; i < GHOSTS; i++) {
            if (ghosts[i] && playerPos == getRandomNumber(0, ROOMS - 1)) {
                printf("Oh no! You've encountered a ghost in room %d!\n", playerPos + 1);
                ghosts[i] = false;
                foundGhost = true;
                break;
            }
        }
        if (!foundGhost) {
            printf("This room is safe... for now.\n");
        }

        // Check if there are any rooms left to explore
        bool allRoomsExplored = true;
        for (int i = 0; i < ROOMS; i++) {
            if (rooms[i]) {
                allRoomsExplored = false;
                break;
            }
        }
        if (allRoomsExplored) {
            printf("Congratulations! You've explored all the rooms in the haunted house.\n");
            break;
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}