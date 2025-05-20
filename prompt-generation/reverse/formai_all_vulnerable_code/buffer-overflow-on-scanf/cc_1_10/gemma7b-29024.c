//Gemma-7B DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int player_1_wins = 0;
    int player_2_wins = 0;
    int current_player = 1;
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Game loop
    while (player_1_wins == 0 && player_2_wins == 0)
    {
        // Get the player's move
        int move = get_move();

        // Place the player's move on the board
        board[move - 1] = current_player;

        // Check if the player has won
        if (check_win(current_player, board))
        {
            // The player has won, increment their wins
            current_player == 1 ? player_1_wins++ : player_2_wins++;

            // Game over
            break;
        }

        // Switch to the next player
        current_player = (current_player == 1) ? 2 : 1;
    }

    // Print the game results
    printf("Player 1 wins: %d\n", player_1_wins);
    printf("Player 2 wins: %d\n", player_2_wins);

    return 0;
}

int get_move()
{
    int move;

    // Get the player's move
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    // Validate the move
    if (move < 1 || move > 9)
    {
        printf("Invalid move. Please try again.\n");
        get_move();
    }

    return move;
}

int check_win(int player, char board[])
{
    // Check if the player has won horizontally
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player)
        {
            return 1;
        }
    }

    // Check if the player has won vertically
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player)
        {
            return 1;
        }
    }

    // Check if the player has won diagonally
    if (board[0] == player && board[4] == player && board[8] == player)
    {
        return 1;
    }

    // If the player has not won, return 0
    return 0;
}