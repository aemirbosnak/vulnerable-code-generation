//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    int player_1_color = 1;
    int player_2_color = 2;

    int turn = 0;

    // Game loop
    while (!board[2][2] || turn % 2 == 0)
    {
        // Get the move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Validate the move
        if (x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece
        board[x][y] = player_1_color;

        // Check if the player has won
        if (board[x][y] == player_1_color && board[x][y] == board[x-1][y] && board[x][y] == board[x][y-1])
        {
            printf("You have won!\n");
            break;
        }

        // Next turn
        turn++;
    }

    // Game over
    if (board[2][2] == 0)
    {
        printf("It's a draw.\n");
    }

    return 0;
}