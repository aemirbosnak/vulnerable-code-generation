//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Create a structure to represent the disks
    typedef struct {
        int size;
        char name[10];
    } Disk;

    // Create an array of disks
    Disk disks[3] = {
        {3, "A"},
        {2, "B"},
        {1, "C"}
    };

    // Create an array of strings representing the poles
    char poles[4][10] = {
        "Start", "Middle", "End", "End"
    };

    // Create an array of strings representing the moves
    char moves[4][10] = {
        "Move A to Middle", "Move B to End", "Move C to Middle", "Move A to Start"
    };

    // Print the initial state of the game
    printf("\nInitial State:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", poles[i], disks[i].name);
    }

    // Loop until all disks have been moved to the start pole
    while (strcmp(disks[0].name, "Start")!= 0 || strcmp(disks[1].name, "Start")!= 0 || strcmp(disks[2].name, "Start")!= 0) {
        // Print the current state of the game
        printf("\nCurrent State:\n");
        for (int i = 0; i < 3; i++) {
            printf("%s: %s\n", poles[i], disks[i].name);
        }

        // Get the player's move
        char move[10];
        printf("Enter your move (e.g. Move A to Middle): ");
        scanf("%s", move);

        // Validate the move
        if (strcmp(move, "Move A to Middle") == 0 || strcmp(move, "Move A to Start") == 0 || strcmp(move, "Move B to End") == 0 || strcmp(move, "Move B to Start") == 0 || strcmp(move, "Move C to Middle") == 0 || strcmp(move, "Move C to Start") == 0) {
            // Move the disk to the specified pole
            if (strcmp(move, "Move A to Middle") == 0) {
                disks[0].size += disks[1].size;
                disks[1].size = 0;
                strcpy(disks[0].name, "A");
                strcpy(disks[1].name, "B");
                strcpy(poles[2], "Middle");
                strcpy(poles[1], "End");
            } else if (strcmp(move, "Move A to Start") == 0) {
                disks[0].size += disks[2].size;
                disks[2].size = 0;
                strcpy(disks[0].name, "A");
                strcpy(disks[1].name, "B");
                strcpy(disks[2].name, "C");
                strcpy(poles[0], "Start");
            } else if (strcmp(move, "Move B to End") == 0) {
                disks[1].size += disks[2].size;
                disks[2].size = 0;
                strcpy(disks[0].name, "A");
                strcpy(disks[1].name, "B");
                strcpy(disks[2].name, "C");
                strcpy(poles[3], "End");
            } else if (strcmp(move, "Move B to Start") == 0) {
                disks[0].size += disks[1].size;
                disks[1].size = 0;
                strcpy(disks[0].name, "A");
                strcpy(disks[1].name, "B");
                strcpy(poles[0], "Start");
            } else if (strcmp(move, "Move C to Middle") == 0) {
                disks[2].size += disks[0].size;
                disks[0].size = 0;
                strcpy(disks[2].name, "C");
                strcpy(disks[0].name, "A");
                strcpy(poles[3], "Middle");
                strcpy(poles[2], "End");
            } else if (strcmp(move, "Move C to Start") == 0) {
                disks[2].size += disks[1].size;
                disks[1].size = 0;
                strcpy(disks[2].name, "C");
                strcpy(disks[1].name, "B");
                strcpy(poles[2], "Start");
            }
        } else {
            printf("Invalid move!\n");
        }

        // Print the new state of the game
        printf("\nNew State:\n");
        for (int i = 0; i < 3; i++) {
            printf("%s: %s\n", poles[i], disks[i].name);
        }

        // Get the player's next move
        char nextMove[10];
        printf("Enter your next move (e.g. Move A to Middle): ");
        scanf("%s", nextMove);
    }

    // Print the final state of the game
    printf("\nFinal State:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", poles[i], disks[i].name);
    }

    return 0;
}