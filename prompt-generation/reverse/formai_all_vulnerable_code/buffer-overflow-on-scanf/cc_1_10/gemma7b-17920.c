//Gemma-7B DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x = 0, y = 0, z = 0, w = 0, n = 0, score = 0, round = 1;

    char board[10][10] = {
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    };

    system("clear");

    printf("Welcome to the C Table Game!\n");

    printf("Round: %d\n", round);

    printf("Score: %d\n", score);

    printf("Enter move (x, y): ");

    scanf("%d %d", &x, &y);

    if (board[x][y] != 'A')
    {
        printf("Invalid move.\n");
    }
    else
    {
        board[x][y] = 'O';

        n = 0;
        for (z = 0; z < 10; z++)
        {
            for (w = 0; w < 10; w++)
            {
                if (board[z][w] == 'O')
                {
                    n++;
                }
            }
        }

        if (n == 5)
        {
            score++;
            round++;

            printf("You won! Congratulations!\n");

            printf("Round: %d\n", round);

            printf("Score: %d\n", score);
        }
        else
        {
            printf("Move taken.\n");

            printf("Enter move (x, y): ");

            scanf("%d %d", &x, &y);
        }
    }

    return 0;
}