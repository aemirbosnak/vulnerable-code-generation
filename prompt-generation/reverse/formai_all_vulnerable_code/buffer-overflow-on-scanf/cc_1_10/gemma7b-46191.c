//Gemma-7B DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, score, highscore = 0;
    char name[20];

    printf("Prepare for a shock, my friend!\n");
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Let's play a game of C Table Tennis. You vs. The Computer!\n");
    printf("Would you like to serve first? (Y/N): ");
    scanf("%c", &k);

    n = 0;
    while (n < 10)
    {
        i = rand() % 6;
        j = rand() % 6;

        if (i == j)
        {
            printf("Oops, that's not a valid move. Try again.\n");
            n--;
        }
        else
        {
            printf("Your turn, %s. You hit the ball at %d and %d. Is it in the court? (Y/N): ", name, i, j);
            scanf("%c", &l);

            if (l == 'Y')
            {
                score = 10;
            }
            else
            {
                score = 0;
            }

            if (score > highscore)
            {
                highscore = score;
            }

            printf("Your score is %d. The high score is %d.\n", score, highscore);
            n++;
        }
    }

    printf("Thanks for playing, %s. See you next time.\n", name);

    return 0;
}