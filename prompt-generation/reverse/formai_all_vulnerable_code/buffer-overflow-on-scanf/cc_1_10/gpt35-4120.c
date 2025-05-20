//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Procedural Space Adventure
    This is a text-based adventure game where the player is a space explorer
    trying to find their way back to Earth after crash landing on an unknown planet.
*/

int main() {
    // Initialize variables
    int fuelLevel = 75;
    int planetNum = 1;
    char name[20];
    int distance = 0;
    int choice = 0;

    // Get player name
    printf("Welcome to Procedural Space Adventure!\n");
    printf("What is your name, space explorer? ");
    scanf("%s", name);

    // Set seed for random number generation
    srand(time(NULL));

    // Loop through planets until player reaches Earth
    while (planetNum < 9) {
        printf("\n");
        printf("%s is currently on Planet %d\n", name, planetNum);
        printf("Fuel level: %d\n", fuelLevel);

        // Generate a random distance to the next planet
        distance = rand() % 500 + 1;

        printf("Planet %d is %d miles away.\n", planetNum + 1, distance);

        // Ask player what they want to do
        printf("What would you like to do?\n");
        printf("1. Refuel\n");
        printf("2. Travel to next planet\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle player's choice
        switch (choice) {
            case 1:
                // Refuel player's ship
                fuelLevel = 100;
                printf("Ship has been refueled!\n");
                break;
            case 2:
                // Check if player has enough fuel to travel
                if ((fuelLevel - distance) < 0) {
                    printf("Not enough fuel to make the trip!\n");
                    printf("Game Over.\n");
                    return 0;
                }
                else {
                    // Update fuel level and planet number
                    fuelLevel -= distance;
                    planetNum++;
                }
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    // Player has reached Earth
    printf("\n");
    printf("%s has successfully made it back to Earth!\n", name);
    printf("Congratulations, you have completed Procedural Space Adventure!\n");

    return 0;
}