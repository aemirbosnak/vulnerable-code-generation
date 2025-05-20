//Gemma-7B DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int score = 0, lives = 3, choice, difficulty = 1;
    char name[20];

    // Get the player's name
    printf("What is your name, adventurer?\n");
    scanf("%s", name);

    // Display the game title
    printf("Welcome to the Quest for the Crystal Ball, %s!\n", name);

    // Game loop
    while (lives > 0 && score < 100)
    {
        // Show the available options
        printf("\nWhat would you like to do?\n1. Attack\n2. Defend\n3. Cast Spell\n");

        // Get the player's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the player's choice
        switch (choice)
        {
            case 1:
                score += difficulty * 2;
                printf("You attacked the enemy and dealt %d damage!\n", difficulty * 2);
                break;
            case 2:
                lives++;
                printf("You defended and gained a life!\n");
                break;
            case 3:
                score += difficulty * 3;
                printf("You cast a spell and dealt %d damage!\n", difficulty * 3);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Check if the player has won or lost
        if (score >= 100)
        {
            printf("Congratulations, %s! You have won the Crystal Ball!\n", name);
        }
        else if (lives == 0)
        {
            printf("Game over, %s. You have run out of lives.\n", name);
        }
    }

    // End the game
    return 0;
}