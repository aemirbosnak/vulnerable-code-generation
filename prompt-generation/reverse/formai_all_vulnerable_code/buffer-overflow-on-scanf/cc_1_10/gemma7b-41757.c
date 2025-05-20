//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
    int player = 1;
    int move = 0;

    // Paranoid AI moves
    move = rand() % 9;
    if (board[move / 3][move % 3] != 0)
    {
        move = rand() % 9;
    }

    // Game loop
    while (move < 9)
    {
        printf("Enter your move (1-9): ");
        int move_ = 0;
        scanf("%d", &move_);

        // Validate move
        if (move_ < 1 || move_ > 9)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make move
        board[move_ / 3][move_ % 3] = player;

        // Check if player won
        if (board[move_ / 3][move_ % 3] == player && (board[move_ / 3][move_ % 3] == board[0][0] || board[move_ / 3][move_ % 3] == board[1][1] || board[move_ / 3][move_ % 3] == board[2][2]))
        {
            printf("You won!");
            break;
        }

        // Next move
        player *= -1;
        move++;
    }

    // Draw game
    if (move == 9)
    {
        printf("It's a draw!");
    }

    return 0;
}