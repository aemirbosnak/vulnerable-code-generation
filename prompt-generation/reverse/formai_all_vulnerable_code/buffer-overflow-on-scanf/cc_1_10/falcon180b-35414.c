//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void intro(void);
void game(void);
void outro(void);

int main(void)
{
    intro();
    game();
    outro();

    return 0;
}

// Introduction
void intro(void)
{
    printf("Welcome to the C Procedural Space Adventure!\n");
    printf("In this game, you will be navigating through space and encountering different obstacles.\n");
    printf("Your mission is to collect as many points as possible and reach the end of the game.\n");
    printf("Are you ready to begin your adventure? (Y/N)\n");

    // Get user input
    char input;
    scanf("%c", &input);

    // Check if user wants to play
    if (input == 'Y' || input == 'y')
    {
        game();
    }
    else
    {
        printf("Exiting game...\n");
        exit(0);
    }
}

// Game
void game(void)
{
    int points = 0;
    int choice;
    char input;

    // Loop until game is over
    while (1)
    {
        // Display current score
        printf("Current score: %d\n", points);

        // Display options
        printf("What would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Shoot laser\n");
        printf("3. Collect points\n");
        printf("4. Quit\n");

        // Get user input
        scanf("%d", &choice);

        // Perform action based on choice
        switch (choice)
        {
            case 1:
                // Move forward
                points += 10;
                printf("You moved forward and collected 10 points!\n");
                break;

            case 2:
                // Shoot laser
                points += 20;
                printf("You shot a laser and collected 20 points!\n");
                break;

            case 3:
                // Collect points
                points += 50;
                printf("You collected 50 points!\n");
                break;

            case 4:
                // Quit game
                printf("Thanks for playing! Your final score is %d.\n", points);
                exit(0);

            default:
                // Invalid choice
                printf("Invalid choice. Try again.\n");
        }
    }
}

// Outro
void outro(void)
{
    printf("Thanks for playing the C Procedural Space Adventure!\n");
}