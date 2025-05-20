//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize the random number generator

    int position = 0, speed = 0, time = 0;

    printf("Welcome to the Remote Control Vehicle Simulation Program!\n\n");

    while (true) {

        printf("Enter a speed (in mph) for the vehicle: ");
        scanf("%d", &speed);

        if (speed < 0) {
            printf("\nYou have entered a negative speed. The vehicle cannot move backwards. Try again!\n\n");
            continue; // Start over from the beginning of the loop
        }

        printf("Enter a time (in seconds) to travel at that speed: ");
        scanf("%d", &time);

        if (time <= 0) {
            printf("\nYou have entered an invalid time. Please enter a positive number of seconds.\n\n");
            continue; // Start over from the beginning of the loop
        }

        int distance = speed * time; // Calculate the distance traveled

        printf("\nThe vehicle has traveled %d feet in %d seconds, at a speed of %d mph.\n", distance, time, speed);

        if (distance > position) {
            printf("The vehicle has moved forward %d feet.\n", distance - position);
            position = distance;
        } else if (distance < position) {
            printf("The vehicle has moved backward %d feet.\n", position - distance);
            position = distance;
        } else {
            printf("The vehicle did not move from its previous position.\n");
        }

        int random = rand() % 2; // Generate a random number of 0 or 1

        if (random == 0) {
            printf("The vehicle has encountered an obstacle and must stop.\n");
            break; // Exit the loop
        }
    }

    printf("\nThe simulation program has ended. Thank you for playing!");

    return 0;
}