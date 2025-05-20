//Gemma-7B DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, score, highscore = 0;
    char name[20];

    printf("Welcome to the Magical Quiz Game!");
    printf("\nPlease enter your name:");
    scanf("%s", name);

    printf("\nCongratulations, %s! Let's play!", name);

    // Game Loop
    while (1)
    {
        // Question and Answer
        printf("\nWhat is the capital of France?");
        scanf("%d", &n);

        if (n == 14)
        {
            score = 10;
            highscore = score;
            printf("\nExcellent! You have scored %d points!", score);
        }
        else
        {
            score = 0;
            printf("\nSorry, that is not the answer. The answer is 14.");
        }

        // Check if the player wants to continue
        printf("\nDo you want to continue playing? (Y/N)");
        scanf(" %c", &n);

        if (n == 'Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }

    // End Game
    printf("\nThank you for playing, %s. You have scored a total of %d points.", name, highscore);

    return 0;
}