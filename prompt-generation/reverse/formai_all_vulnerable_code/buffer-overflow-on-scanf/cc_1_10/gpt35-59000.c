//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Introduction to the game
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are a space explorer on a mission to explore a new planet.\n\n");

    // Define variables
    int planet_distance = (rand() % 500) + 500;
    int fuel = 1000;
    int planet_number = 1;
    int planet_counter = 0;

    // Loop through the planets until fuel runs out or 5 planets have been visited
    while (fuel > 0 && planet_number <= 5)
    {
        // Display planet information
        printf("You are currently %d kilometers away from planet #%d.\n", planet_distance, planet_number);
        printf("You have %d units of fuel remaining.\n\n", fuel);

        // Ask the user what action to take
        int action;
        printf("What would you like to do?\n");
        printf("1. Travel to the planet\n");
        printf("2. Refuel your spaceship\n");
        scanf("%d", &action);

        // Handle the user's action
        switch (action)
        {
            case 1:
                // Travel to the planet
                fuel -= planet_distance / 10;
                planet_counter++;

                if (fuel <= 0)
                {
                    printf("You have run out of fuel and can't travel to the planet.\n");
                    break;
                }

                if (planet_distance < 50)
                {
                    printf("Congratulations! You have successfully landed on planet #%d.\n", planet_number);
                    planet_distance = (rand() % 500) + 500;
                    planet_number++;
                    break;
                }

                printf("You traveled %d kilometers and are now %d kilometers away from the planet.\n", planet_distance / 10, planet_distance - (planet_distance / 10));
                planet_distance -= planet_distance / 10;
                break;

            case 2:
                // Refuel the spaceship
                fuel += (rand() % 100) + 100;
                printf("You refueled your spaceship and now have %d units of fuel.\n", fuel);
                break;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    // Display the final results
    printf("\nYou visited %d planet(s) before running out of fuel.\n", planet_counter);
    printf("Game over!\n");

    return 0;
}