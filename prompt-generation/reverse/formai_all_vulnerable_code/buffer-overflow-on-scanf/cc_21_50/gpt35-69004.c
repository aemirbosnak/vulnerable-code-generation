//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int choice;
    int ghosts = 0, bats = 0, skeletons = 0, zombies = 0;
    int flashlight = 1, key = 0, exit_unlocked = 0;
    int steps = 0, max_steps = 50;

    // Set seed for random numbers
    srand(time(NULL));

    // Haunted house simulator
    printf("Welcome to the Haunted House Simulator!\n\n");

    // Main loop
    while (steps < max_steps && !exit_unlocked)
    {
        printf("You are in a dark hallway. What do you do?\n");
        printf("1. Turn on flashlight\n");
        printf("2. Continue without flashlight\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Turn on flashlight
        if (choice == 1)
        {
            if (flashlight)
            {
                printf("You turn on the flashlight.\n");

                // Randomly generate ghosts, bats, skeletons, and zombies
                ghosts = rand() % 2;
                bats = rand() % 2;
                skeletons = rand() % 2;
                zombies = rand() % 2;

                // Display enemies
                if (ghosts)
                    printf("You see a ghost!\n");
                if (bats)
                    printf("You hear some bats!\n");
                if (skeletons)
                    printf("You see some skeletons!\n");
                if (zombies)
                    printf("You see some zombies!\n");
            }
            else
            {
                printf("You don't have a flashlight!\n");
            }
        }

        // Continue without flashlight
        else if (choice == 2)
        {
            printf("You continue without a flashlight.\n");

            // Randomly generate ghosts, bats, skeletons, and zombies
            ghosts = rand() % 2;
            bats = rand() % 2;
            skeletons = rand() % 2;
            zombies = rand() % 2;

            // Display enemies
            if (ghosts)
                printf("You feel a cold presence...\n");
            if (bats)
                printf("You hear some fluttering...\n");
            if (skeletons)
                printf("You hear some bones rattling...\n");
            if (zombies)
                printf("You smell something putrid...\n");
        }

        // Quit
        else if (choice == 3)
        {
            printf("Thanks for playing!\n");
            return 0;
        }

        // Invalid input
        else
        {
            printf("Invalid input!\n");
        }

        // Check for enemies
        if (ghosts || bats || skeletons || zombies)
        {
            printf("What do you do?\n");
            printf("1. Run\n");
            printf("2. Fight\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            // Run
            if (choice == 1)
            {
                printf("You run away from the enemies!\n");
            }

            // Fight
            else if (choice == 2)
            {
                printf("You fight the enemies!\n");

                // Randomly generate success or failure
                int success = rand() % 2;

                // Display outcome
                if (success)
                {
                    printf("You defeat the enemies!\n");
                }
                else
                {
                    printf("You lose the fight!\n");
                }
            }

            // Invalid input
            else
            {
                printf("Invalid input!\n");
            }
        }

        // Check for key
        if (!key)
        {
            int has_key = rand() % 2;

            if (has_key)
            {
                printf("You found a key!\n");
                key = 1;
            }
        }

        // Check for exit
        if (key && !exit_unlocked)
        {
            int unlock_exit = rand() % 2;

            if (unlock_exit)
            {
                printf("You unlocked the exit with the key!\n");
                exit_unlocked = 1;
            }
        }

        // Increment steps
        steps++;

        // End of loop
        printf("\n");
    }

    // Game over
    if (exit_unlocked)
    {
        printf("Congratulations! You escaped the haunted house!\n");
    }
    else
    {
        printf("Game over! You didn't escape the haunted house in time!\n");
    }

    return 0;
}