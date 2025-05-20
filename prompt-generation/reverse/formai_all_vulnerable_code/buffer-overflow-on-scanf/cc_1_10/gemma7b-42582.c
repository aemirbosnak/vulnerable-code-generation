//Gemma-7B DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, score = 0, level = 1, lives = 3;
    char name[20];

    // Welcome and gather user's name
    printf("Welcome to the Adventure Game, %s!\n", name);

    // Main game loop
    while (lives > 0)
    {
        // Display current level and score
        printf("Level: %d, Score: %d\n", level, score);

        // Present options and get user choice
        printf("1. Attack\n2. Defend\n3. Use Item\nChoose an option: ");
        scanf("%d", &choice);

        // Process user's choice
        switch (choice)
        {
            case 1:
                // Attack enemy, gain points, and advance to next level if possible
                score++;
                level++;
                printf("You attacked the enemy and won %d points!\n", score);
                break;
            case 2:
                // Defend against enemy's attack, lose a life if unsuccessful
                lives--;
                printf("You defended against the enemy's attack, but were unsuccessful.\n");
                break;
            case 3:
                // Use item to gain advantage, lose points if used incorrectly
                score--;
                printf("You used an item and gained an advantage.\n");
                break;
            default:
                // Invalid choice, inform user and restart loop
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    // Game over, display final score and message
    printf("Game Over! Your final score is: %d\n", score);
    printf("Thank you for playing, %s. See you next time!\n", name);

    return 0;
}