//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int num1, num2, guess, round = 1, winner = 0;
    char name1[20], name2[20];

    printf("Enter the name of player 1:");
    scanf("%s", name1);

    printf("Enter the name of player 2:");
    scanf("%s", name2);

    srand(time(NULL));

    while (round <= MAX_NUM && winner == 0)
    {
        num1 = rand() % MAX_NUM + 1;
        num2 = rand() % MAX_NUM + 1;

        printf("%s has chosen %d.\n", name1, num1);
        printf("%s has chosen %d.\n", name2, num2);

        guess = 0;

        while (guess != num1 && guess != num2)
        {
            printf("Guess the number:");
            scanf("%d", &guess);

            if (guess == num1)
            {
                winner = 1;
                printf("%s has won!\n", name1);
            }
            else if (guess == num2)
            {
                winner = 1;
                printf("%s has won!\n", name2);
            }
            else
            {
                printf("Incorrect guess.\n");
            }
        }

        round++;
    }

    if (winner == 0)
    {
        printf("It's a draw!\n");
    }

    return 0;
}