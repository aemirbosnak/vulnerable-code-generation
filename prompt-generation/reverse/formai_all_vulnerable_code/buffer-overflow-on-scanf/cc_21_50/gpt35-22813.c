//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main() {
    srand(time(NULL)); // initialize random seed
    bool hasGhost = false;
    int numRooms = 6;
    int currentRoom = rand() % numRooms + 1; // randomly select initial room

    printf("Welcome to the haunted house! There are %d rooms to explore.\n", numRooms);

    while (true) {
        if (currentRoom == 1) {
            printf("You are in the foyer. There are doors to the north, south, and west.\n");
        } else if (currentRoom == 2) {
            printf("You are in the dining room. There are doors to the east and south.\n");
        } else if (currentRoom == 3) {
            printf("You are in the kitchen. There is a door to the north.\n");
        } else if (currentRoom == 4) {
            printf("You are in the living room. There are doors to the north, east, and west.\n");
        } else if (currentRoom == 5) {
            printf("You are in the library. There are doors to the south and west.\n");
        } else if (currentRoom == 6) {
            printf("You are in the bedroom. There is a door to the east.\n");
        }

        if (currentRoom == 3 && !hasGhost) {
            printf("You hear a strange noise coming from the pantry...\n");
            hasGhost = true;
        } else if (currentRoom == 3 && hasGhost) {
            printf("You see a ghostly figure in the pantry! You panic and run out of the room.\n");
            currentRoom = 1; // teleport back to foyer
            hasGhost = false; // reset ghost status
            continue; // skip the rest of the loop
        }

        char input[10];
        printf("Which way do you want to go? (north, south, east, or west): ");
        scanf("%s", input);

        if (strcmp(input, "north") == 0) {
            if (currentRoom == 1) {
                printf("You move north and enter the library.\n");
                currentRoom = 5;
            } else if (currentRoom == 4) {
                printf("You move north and enter the kitchen.\n");
                currentRoom = 3;
            } else {
                printf("You cannot go north from here.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (currentRoom == 1) {
                printf("You move south and enter the dining room.\n");
                currentRoom = 2;
            } else if (currentRoom == 2) {
                printf("You move south and enter the foyer.\n");
                currentRoom = 1;
            } else if (currentRoom == 5) {
                printf("You move south and enter the foyer.\n");
                currentRoom = 1;
            } else {
                printf("You cannot go south from here.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            if (currentRoom == 1) {
                printf("You move east and enter the living room.\n");
                currentRoom = 4;
            } else if (currentRoom == 2) {
                printf("You cannot go east from here.\n");
            } else if (currentRoom == 6) {
                printf("You cannot go east from here.\n");
            } else {
                printf("You move east and enter the bedroom.\n");
                currentRoom = 6;
            }
        } else if (strcmp(input, "west") == 0) {
            if (currentRoom == 1) {
                printf("You move west and enter the kitchen.\n");
                currentRoom = 3;
            } else if (currentRoom == 4) {
                printf("You move west and enter the foyer.\n");
                currentRoom = 1;
            } else if (currentRoom == 5) {
                printf("You cannot go west from here.\n");
            } else {
                printf("You move west and enter the foyer.\n");
                currentRoom = 1;
            }
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}