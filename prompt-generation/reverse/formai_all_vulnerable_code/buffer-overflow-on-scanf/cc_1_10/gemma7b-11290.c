//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000

int main()
{
    int num, i, j, k, prime = 1, count = 0, player1, player2;
    char message[200];

    srand(time(NULL));

    printf("Enter the number of players: ");
    scanf("%d", &player1);

    printf("Enter the number of players: ");
    scanf("%d", &player2);

    for (i = 0; i < player1; i++)
    {
        num = rand() % MAX_NUM + 1;
        for (j = 2; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime)
        {
            count++;
            printf("Prime number generated: %d\n", num);
        }
    }

    for (k = 0; k < player2; k++)
    {
        num = rand() % MAX_NUM + 1;
        for (j = 2; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime)
        {
            count++;
            printf("Prime number generated: %d\n", num);
        }
    }

    printf("Total number of prime numbers generated: %d\n", count);

    return 0;
}