//Gemma-7B DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, score = 0, highScore = 0;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Round %d:\n", i + 1);

        // Game logic here
        m = rand() % 6 + 1;
        k = rand() % 6 + 1;
        l = rand() % 6 + 1;

        printf("The numbers are: %d, %d, %d\n", m, k, l);

        // Player's turn
        printf("Enter the number you want to guess: ");
        scanf("%d", &j);

        if (j == m || j == k || j == l)
        {
            score++;
            printf("You guessed the number!\n");
        }
        else
        {
            printf("Sorry, you did not guess the number.\n");
        }

        // High score update
        if (score > highScore)
        {
            highScore = score;
            printf("Your high score is: %d\n", highScore);
        }
    }

    printf("Thank you for playing, %s! Your final score is: %d\n", name, score);

    return 0;
}