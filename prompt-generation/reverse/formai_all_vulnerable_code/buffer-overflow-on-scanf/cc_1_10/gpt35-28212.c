//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Scientific Adventure Game!\n");

    // Defining the variables and setting the random seed
    int distance = 0;
    int energy = 100;
    int robot_pos = 0;
    int alien_pos = 10;
    srand(time(0));

    // The game loop
    while (1) {
        printf("--------------------------------------------------------------\n");
        printf("You are currently at position %d and the alien is at position %d.\n", robot_pos, alien_pos);
        printf("You currently have %d energy left.\n", energy);
        printf("Enter a number between 1 and 5 to advance towards the alien: ");
        int steps;
        scanf("%d", &steps);

        // Checking if the input is valid
        if (steps < 1 || steps > 5) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            continue;
        }

        // Updating the variables based on the input
        energy -= steps;
        distance += steps;
        robot_pos += steps;

        // Generating a random number between 1 and 5 for the alien to move
        int alien_steps = rand() % 5 + 1;
        alien_pos += alien_steps;

        // Checking if the distance is less than or equal to 0
        if (distance <= 0) {
            printf("You have successfully captured the alien and saved the world!\n");
            break;
        }

        // Checking if the energy is less than or equal to 0
        if (energy <= 0) {
            printf("You have run out of energy and lost the game.\n");
            break;
        }

        // Checking if the robot and the alien have collided
        if (robot_pos == alien_pos) {
            printf("You have encountered the alien and lost the game.\n");
            break;
        }
    }

    printf("Thanks for playing the Scientific Adventure Game!\n");
    return 0;
}