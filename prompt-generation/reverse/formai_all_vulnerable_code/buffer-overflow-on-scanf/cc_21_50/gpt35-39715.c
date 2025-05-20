//FormAI DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create the game board with a 3x3 grid
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Define the players
    int player1 = 1;
    int player2 = 2;

    // Determine who goes first
    int turn = rand() % 2 + 1;

    // Create a variable to keep track of the number of moves
    int moves = 0;

    // Main game loop
    while (1)
    {
        // Print the game board
        printf("\n\n");
        printf("     0   1   2\n");
        printf("    -----------\n");
        for (int i = 0; i < 3; i++)
        {
            printf(" %d |", i);
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == player1)
                {
                    printf(" X |");
                }
                else if (board[i][j] == player2)
                {
                    printf(" O |");
                }
                else
                {
                    printf("   |");
                }
            }
            printf("\n");
            printf("    -----------\n");
        }

        // Determine which player's turn it is
        int current_player;
        if (turn == 1)
        {
            current_player = player1;
        }
        else
        {
            current_player = player2;
        }

        // Get the user's move
        int row, col;
        printf("Player %d, enter your move (row, column): ", current_player);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            printf("Invalid move. Please enter a row and column between 0 and 2.\n");
            continue;
        }
        if (board[row][col] != 0)
        {
            printf("Invalid move. That square is already taken.\n");
            continue;
        }

        // Make the move
        board[row][col] = current_player;
        moves++;

        // Check if the game has been won or tied
        int winner = 0;
        if (board[0][0] == current_player && board[0][1] == current_player && board[0][2] == current_player)
        {
            winner = current_player;
        }
        else if (board[1][0] == current_player && board[1][1] == current_player && board[1][2] == current_player)
        {
            winner = current_player;
        }
        else if (board[2][0] == current_player && board[2][1] == current_player && board[2][2] == current_player)
        {
            winner = current_player;
        }
        else if (board[0][0] == current_player && board[1][0] == current_player && board[2][0] == current_player)
        {
            winner = current_player;
        }
        else if (board[0][1] == current_player && board[1][1] == current_player && board[2][1] == current_player)
        {
            winner = current_player;
        }
        else if (board[0][2] == current_player && board[1][2] == current_player && board[2][2] == current_player)
        {
            winner = current_player;
        }
        else if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player)
        {
            winner = current_player;
        }
        else if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)
        {
            winner = current_player;
        }
        if (winner != 0)
        {
            printf("\n\nCongratulations, Player %d has won the game!\n\n", current_player);
            break;
        }
        if (moves == 9)
        {
            printf("\n\nThe game is a tie!\n\n");
            break;
        }

        // Switch to the other player's turn
        if (turn == 1)
        {
            turn = 2;
        }
        else
        {
            turn = 1;
        }
    }

    return 0;
}