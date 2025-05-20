//Gemma-7B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, score = 0, lives = 3;
    char name[20];

    printf("Welcome, traveler! Please enter your name:");
    scanf("%s", name);

    printf("Prepare for a journey of epic proportions, %s! Are you ready?", name);
    printf("\n");

    // Game loop
    while (lives > 0)
    {
        // Level selection
        printf("Choose a level of difficulty (1-3): ");
        scanf("%d", &n);

        // Challenge the level
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 5; j++)
            {
                // Puzzle solving
                printf("Solve this riddle: What has a neck but no head, and a body but no arms?\n");
                scanf("%d", &score);

                if (score == 1)
                {
                    printf("Congratulations! You have solved the riddle!\n");
                }
                else
                {
                    printf("Sorry, the answer is incorrect. You lose a life.\n");
                    lives--;
                }
            }
        }

        // Check if the player won or lost
        if (score == 3)
        {
            printf("Congratulations, %s! You have won the game!\n", name);
        }
        else if (lives == 0)
        {
            printf("Game over, %s. Better luck next time.\n", name);
        }
    }

    return 0;
}