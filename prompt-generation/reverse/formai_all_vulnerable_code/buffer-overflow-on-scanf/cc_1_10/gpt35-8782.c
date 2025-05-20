//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

/* Function to generate random number between min and max (inclusive) */
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    /* Setting up the plot of the haunted house */
    int numberOfRooms = 5;
    char rooms[][20] = {"Kitchen", "Living Room", "Bedroom", "Bathroom", "Attic"};

    /* Initializing variables */
    int currentPlayerRoom = 0;
    int ghostPosition = generateRandomNumber(1, numberOfRooms); // Randomly generated ghost position
    int flashlightBattery = 3; // Maximum 3 batteries

    /* Starting the game */
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are in the %s.\n", rooms[currentPlayerRoom]);
    printf("The ghost is somewhere in the house...\n\n");

    /* Main game loop */
    while (currentPlayerRoom != ghostPosition) {
        printf("What do you want to do? (Enter 1, 2, or 3)\n");
        printf("1. Move to another room\n");
        printf("2. Check for ghost\n");
        printf("3. Turn on/off flashlight\n");

        int choice;
        scanf("%d", &choice);

        /* Moving to another room */
        if (choice == 1) {
            int newRoom = generateRandomNumber(0, numberOfRooms - 1);
            while (newRoom == currentPlayerRoom) { // Player cannot move to the same room
                newRoom = generateRandomNumber(0, numberOfRooms - 1);
            }
            currentPlayerRoom = newRoom;
            printf("You are now in the %s.\n", rooms[currentPlayerRoom]);

        /* Checking for ghost */
        } else if (choice == 2) {
            if (currentPlayerRoom == ghostPosition) { // Player has found the ghost
                printf("You have found the ghost! You lose!\n");
                return 0;
            } else {
                printf("There is no ghost in this room.\n");
            }

        /* Turning on/off flashlight */
        } else if (choice == 3) {
            if (flashlightBattery <= 0) { // Player cannot turn on flashlight if batteries are exhausted
                printf("Your flashlight has no batteries left.\n");
            } else {
                flashlightBattery--;
                printf("You have turned on your flashlight.\n");
                if (generateRandomNumber(1, 10) > 5) { // 50% chance of finding the ghost
                    printf("You have found the ghost! You lose!\n");
                    return 0;
                } else {
                    printf("There is no ghost in this room.\n");
                }
            }

        } else { // Invalid input
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    /* Player has found the ghost */
    printf("Congratulations! You have found the ghost!\n");
    return 0;
}