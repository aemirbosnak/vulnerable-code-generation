//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, bingo_num, count = 0;
    char board[20][20];

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    printf("Enter the number of bingo numbers: ");
    scanf("%d", &k);

    // Allocate memory for the bingo numbers
    int *bingo_arr = (int *)malloc(k * sizeof(int));

    // Get the bingo numbers
    printf("Enter the bingo numbers: ");
    for (i = 0; i < k; i++)
    {
        scanf("%d", &bingo_arr[i]);
    }

    // Create the bingo card
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Mark the bingo numbers on the card
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (l = 0; l < m; l++)
            {
                if (board[j][l] == bingo_arr[i])
                {
                    board[j][l] = 'x';
                }
            }
        }
    }

    // Check if the player has won
    for (i = 0; i < n; i++)
    {
        if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x')
        {
            bingo_num = bingo_arr[i];
            count++;
        }
    }

    // Check if the player has won in the columns
    for (j = 0; j < m; j++)
    {
        if (board[0][j] == 'x' && board[1][j] == 'x' && board[2][j] == 'x')
        {
            bingo_num = bingo_arr[j];
            count++;
        }
    }

    // Check if the player has won in the diagonal
    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
    {
        bingo_num = bingo_arr[k];
        count++;
    }

    // Print the winning number
    if (count > 0)
    {
        printf("Congratulations! You have won with number %d.", bingo_num);
    }
    else
    {
        printf("Sorry, you have not won.");
    }

    return 0;
}