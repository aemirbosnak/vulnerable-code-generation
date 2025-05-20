//Gemma-7B DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

int main()
{
    int num_players = 2;
    int current_player = 0;
    int board[MAX_NUM] = {0};

    // Initialize the board
    for (int i = 0; i < MAX_NUM; i++)
    {
        board[i] = -1;
    }

    // Game loop
    while (board[MAX_NUM - 1] != num_players)
    {
        // Get the player's move
        int move = get_move();

        // Validate the move
        if (move < 0 || move >= MAX_NUM)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the token on the board
        board[move] = current_player;

        // Check if the player has won
        if (check_win(board, current_player))
        {
            printf("Congratulations, %d, you have won!\n", current_player);
            board[MAX_NUM - 1] = current_player;
        }

        // Next player
        current_player = (current_player == 0) ? 1 : 0;
    }

    // Game over
    printf("Game over.\n");

    return 0;
}

int get_move()
{
    int move;

    printf("Enter your move: ");
    scanf("%d", &move);

    return move;
}

int check_win(int *board, int player)
{
    // Check if the player has won in a row
    for (int i = 0; i < MAX_NUM - 1; i++)
    {
        if (board[i] == board[i + 1] && board[i] == player)
        {
            return 1;
        }
    }

    // Check if the player has won in a column
    for (int j = 0; j < MAX_NUM; j++)
    {
        if (board[j] == board[j + MAX_NUM] && board[j] == player)
        {
            return 1;
        }
    }

    // Check if the player has won in a diagonal
    if (board[0] == board[MAX_NUM - 1] && board[0] == player)
    {
        return 1;
    }

    // No win
    return 0;
}