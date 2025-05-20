//Gemma-7B DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, i, j, k, score = 0, round = 1;
    char board[6][6] = {{'a', 'b', 'c', 'd', 'e', 'f'},
                              {'g', 'h', 'i', 'j', 'k', 'l'},
                              {'m', 'n', 'o', 'p', 'q', 'r'},
                              {'s', 't', 'u', 'v', 'w', 'x'},
                              {'y', 'z', 'A', 'B', 'C', 'D'},
                              {'E', 'F', 'G', 'H', 'I', 'J'}};

    printf("Welcome to the wacky world of C Table Game!\n\n");
    system("pause");

    while (round <= 3)
    {
        printf("It's round %d! Let's play...\n", round);

        // Player's turn
        printf("Enter the row and column you want to place your piece: ");
        scanf("%d %d", &x, &y);

        // Check if the move is valid
        if (x < 0 || x >= 6 || y < 0 || y >= 6)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the piece on the board
        board[x][y] = 'O';

        // Check if the player has won
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (board[i][j] == 'O' && board[i][j] == board[i][(j-1)] && board[i][j] == board[i][(j+1)] && board[i][j] == board[i-1][j] && board[i][j] == board[i+1][j])
                {
                    score++;
                    printf("Congratulations! You won the game!\n");
                    break;
                }
            }
        }

        // If the player has not won, move to the next round
        if (score == 0)
        {
            round++;
        }
    }

    // Game over
    printf("Thank you for playing! See you next time.\n");

    return 0;
}