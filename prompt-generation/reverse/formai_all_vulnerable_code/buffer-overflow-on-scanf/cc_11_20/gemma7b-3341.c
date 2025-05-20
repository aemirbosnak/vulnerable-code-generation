//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    char board[8][8] = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', 'O', '.', 'O', '.', 'O', '.', '.'},
                              {'.', '.', 'O', '.', 'O', 'O', '.', '.'},
                              {'.', '.', '.', 'O', 'O', 'O', '.', '.'},
                              {'.', '.', '.', '.', 'O', 'O', '.', '.'},
                              {'.', '.', 'O', 'O', 'O', 'O', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'}
                           };

    printf("Welcome to the Game of Life!\n");
    printf("-----------------------\n");

    // Game Loop
    while (1)
    {
        printf("Enter the move (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (x < 0 || x >= 8 || y < 0 || y >= 8)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the cell is alive
        if (board[x][y] == 'O')
        {
            printf("Cell is already alive.\n");
            continue;
        }

        // Calculate the number of alive neighbors
        int num_alive = 0;
        for (z = -1; z <= 1; z++)
        {
            for (int w = -1; w <= 1; w++)
            {
                if (board[x + z][y + w] == 'O')
                {
                    num_alive++;
                }
            }
        }

        // If the cell is alive, it survives
        if (num_alive >= 2)
        {
            board[x][y] = 'O';
            printf("Cell is alive.\n");
        }
        else
        {
            board[x][y] = '.';
            printf("Cell is dead.\n");
        }

        // Print the board
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Check if the player wants to continue
        printf("Do you want to continue? (Y/N): ");
        char cont;
        scanf("%c", &cont);

        if (cont == 'N')
        {
            break;
        }
    }

    printf("Thank you for playing!\n");

    return 0;
}