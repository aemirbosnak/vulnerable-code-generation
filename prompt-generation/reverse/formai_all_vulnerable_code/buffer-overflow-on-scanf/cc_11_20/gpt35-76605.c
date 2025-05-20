//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed for generating random events in the game
    srand(time(NULL));

    // Declare and initialize game variables
    int health = 100;
    int fuel = 100;
    int ammo = 50;
    int alien_spacecraft_health = 100;
    int event;
    int player_choice;
    int game_over = 0;

    printf("Welcome to the Space Adventure Game!\n\n");

    // Game loop
    while (!game_over)
    {
        printf("You are currently at full health, fuel, and ammo.\n\n");

        // Generate random events
        event = rand() % 3;

        switch (event)
        {
            case 0:
                printf("No event occurred.\n");
                break;

            case 1:
                printf("You encountered an Alien Spacecraft! Choose what to do:\n");
                printf("1. Attack with your ammo.\n");
                printf("2. Flee the area.\n");
                printf("Enter your choice (1 or 2): ");
                scanf("%d", &player_choice);

                if (player_choice == 1)
                {
                    // Attack the Alien Spacecraft
                    alien_spacecraft_health -= 25;

                    if (alien_spacecraft_health <= 0)
                    {
                        printf("\nYou destroyed the Alien Spacecraft!\n\n");
                        printf("You gained 50 fuel and 10 ammo.\n");
                        fuel += 50;
                        ammo += 10;
                        alien_spacecraft_health = 100;
                    }
                    else
                    {
                        printf("\nThe Alien Spacecraft still has %d health.\n", alien_spacecraft_health);
                        // Alien Spacecraft attack
                        health -= 20;
                        printf("You lost 20 health.\n");
                    }
                }
                else if (player_choice == 2)
                {
                    printf("You fled the area.\n\n");
                }
                else
                {
                    printf("Invalid choice. No action taken.\n\n");
                }
                break;

            case 2:
                printf("You found a planet with resources!\n");
                printf("You gained 50 fuel and 10 ammo.\n\n");
                fuel += 50;
                ammo += 10;
                break;

            default:
                break;
        }

        // Check player health and fuel
        if (health <= 0)
        {
            printf("You ran out of health! GAME OVER.\n");
            game_over = 1;
        }
        else if (fuel <= 0)
        {
            printf("You ran out of fuel! GAME OVER.\n");
            game_over = 1;
        }

        // Prompt player to continue or exit
        if (!game_over)
        {
            printf("Your current health: %d\n", health);
            printf("Your current fuel: %d\n", fuel);
            printf("Your current ammo: %d\n", ammo);
            printf("Do you want to continue? (1 for Yes, 0 for No): ");
            scanf("%d", &player_choice);

            if (player_choice == 0)
            {
                printf("\nThank you for playing the Space Adventure Game!\n");
                break;
            }
            else
            {
                printf("\n");
                // Decrease fuel
                fuel -= 10;
            }
        }
    }

    return 0;
}