//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Set seed for random number generator

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You're trapped inside a haunted house. Can you find your way out?\n");

    int roomNumber = 1; // Start in room 1

    while (roomNumber != 0) { // Continue until the player reaches room 0 (escape)
        printf("You are in room %d.\n", roomNumber);

        // Generate a random event
        int event = rand() % 3;
        if (event == 0) {
            printf("You hear a strange noise...\n");
        } else if (event == 1) {
            printf("The room is cold and drafty...\n");
        } else {
            printf("You feel a chill run down your spine...\n");
        }

        printf("What do you do? (1: go left, 2: go right, 3: go straight, 0: escape the house)\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("You made it out of the haunted house! Congratulations!\n");
                roomNumber = 0;
                break;
            case 1:
                if (roomNumber == 1) {
                    printf("You can't go left from here.\n");
                } else if (roomNumber == 2) {
                    printf("You encounter a scary ghost. You quickly run back to the previous room.\n");
                    roomNumber = 1;
                } else {
                    printf("You find a key! You continue moving left.\n");
                    roomNumber--;
                }
                break;
            case 2:
                if (roomNumber == 3) {
                    printf("You can't go right from here.\n");
                } else if (roomNumber == 1) {
                    printf("You find a spooky painting. You continue moving right.\n");
                    roomNumber++;
                } else {
                    printf("You enter a dark basement. You fumble around and end up back in the previous room.\n");
                    roomNumber--;
                }
                break;
            case 3:
                if (roomNumber == 2) {
                    printf("You can't go straight from here.\n");
                } else if (roomNumber == 1) {
                    printf("You enter a dusty library. You find a clue and continue moving straight.\n");
                    roomNumber++;
                } else {
                    printf("You stumble into a trap and fall down a pit. You end up back in the previous room.\n");
                    roomNumber--;
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}