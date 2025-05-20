//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdlib.h>
#include <time.h>

int main()
{
    system("clear");
    srand(time(NULL));

    // Game Board
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Player's Move
    int move_row, move_col;

    // Game Loop
    while (!board[move_row][move_col] && move_row < 3 && move_col < 3)
    {
        // Get Player's Move
        printf("Enter move (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        // Validate Move
        if (move_row < 0 || move_row >= 3 || move_col < 0 || move_col >= 3)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place Mark
        board[move_row][move_col] = 1;

        // Display Board
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Check for Win
        if (board[move_row][move_col] == 1)
        {
            printf("You win!\n");
            break;
        }
    }

    // Game Over
    if (move_row >= 3 && move_col >= 3)
    {
        printf("Game over.\n");
    }

    return 0;
}