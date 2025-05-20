//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("------------------------\n");

    // Create a character named "Hero"
    char hero_name[20];
    printf("What is your hero's name? ");
    scanf("%s", hero_name);

    // Define the hero's inventory
    int hero_inventory[5] = {0, 0, 0, 0, 0};

    // Define the game map
    int map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                              {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                            };

    // Main Game Loop
    while (1)
    {
        // Display the game map
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                if (map[y][x] == 1)
                {
                    printf("O ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }

        // Get the hero's move
        char move;
        printf("What direction do you want to go (N, S, E, W)? ");
        scanf("%c", &move);

        // Move the hero
        switch (move)
        {
            case 'N':
                map[hero_inventory[2]][hero_inventory[3]] = 1;
                hero_inventory[2]++;
                break;
            case 'S':
                map[hero_inventory[2]][hero_inventory[3]] = 1;
                hero_inventory[2]--;
                break;
            case 'E':
                map[hero_inventory[2]][hero_inventory[3]] = 1;
                hero_inventory[3]++;
                break;
            case 'W':
                map[hero_inventory[2]][hero_inventory[3]] = 1;
                hero_inventory[3]--;
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        // Check if the hero has won
        if (map[hero_inventory[2]][hero_inventory[3]] == 3)
        {
            printf("Congratulations, %s! You have won the game!\n", hero_name);
            break;
        }
    }

    return 0;
}