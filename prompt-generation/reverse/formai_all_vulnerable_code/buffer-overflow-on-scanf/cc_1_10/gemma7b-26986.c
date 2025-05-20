//Gemma-7B DATASET v1.0 Category: Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0;
    int level = 1;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome to the game, %s! Let's see how much you can score!\n", name);

    while (score < 100)
    {
        int attempt = 0;
        int guess;

        printf("Level %d: Guess a number between 1 and 10: ", level);
        scanf("%d", &guess);

        while (attempt < 3)
        {
            if (guess < 1 || guess > 10)
            {
                printf("Invalid input. Please try again: ");
                scanf("%d", &guess);
            }
            else
            {
                break;
            }
            attempt++;
        }

        if (guess == level)
        {
            score++;
            level++;
            printf("Congratulations! You guessed the number and moved to the next level!\n");
        }
        else
        {
            printf("Sorry, you didn't guess the number. Try again next time.\n");
        }
    }

    printf("Thank you for playing, %s. Your final score is: %d\n", name, score);

    return 0;
}