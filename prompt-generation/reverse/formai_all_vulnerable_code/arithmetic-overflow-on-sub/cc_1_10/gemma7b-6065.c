//Gemma-7B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, score = 0;
    char board[6][6] = {{'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'},
                              {'0', '0', '0', '0', '0', '0'}};

    printf("Enter the number of players (2-4): ");
    scanf("%d", &n);

    printf("Enter the number of rounds (5-10): ");
    scanf("%d", &m);

    for (k = 0; k < m; k++)
    {
        for (i = 0; i < n; i++)
        {
            printf("Player %d, enter your move (row, column): ", i + 1);
            scanf("%d %d", &l, &j);

            if (board[l][j] == '0')
            {
                board[l][j] = 'X';

                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        if (board[i][j] == 'X')
                        {
                            score++;
                        }
                    }
                }

                if (score >= n - 1)
                {
                    printf("Player %d won!\n", i + 1);
                    break;
                }
            }
            else
            {
                printf("Invalid move.\n");
            }
        }

        if (score >= n - 1)
        {
            break;
        }

        printf("End of round.\n");
    }

    if (score < n - 1)
    {
        printf("No winner.\n");
    }

    return 0;
}