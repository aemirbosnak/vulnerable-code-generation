//Gemma-7B DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>

void play_c_table_game()
{
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 1, 1, 1, 0, 0},
                           {0, 1, 0, 1, 1, 0},
                           {0, 1, 1, 0, 1, 0},
                           {0, 0, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    int player_1_turn = 1;

    // Game Loop
    while (!board[2][2] && player_1_turn)
    {
        // Get the player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Validate the move
        if (board[row][col] != 0 || row < 0 || row >= 6 || col < 0 || col >= 6)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][col] = 1;

        // Switch turns
        player_1_turn = 0;
    }

    // Game Over
    if (board[2][2] == 1)
    {
        printf("Player 1 won!\n");
    }
    else
    {
        printf("It's a draw.\n");
    }
}

int main()
{
    play_c_table_game();

    return 0;
}