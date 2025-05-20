//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, score = 0, game_over = 0;

    // Initialize the game board
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // Display the game board
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }

    // Get the player's move
    printf("Enter your move (e.g. 0,0): ");
    scanf("%d, %d", &x, &y);

    // Check if the move is valid
    if (x < 0 || x >= 3 || y < 0 || y >= 3)
    {
        printf("Invalid move.\n");
    }
    else
    {
        // Place the player's mark on the board
        board[x][y] = 'X';

        // Check if the player has won
        if (board[x][0] == 'X' && board[x][1] == 'X' && board[x][2] == 'X')
        {
            score++;
            game_over = 1;
            printf("You won! Your score is: %d\n", score);
        }
        else if (board[0][y] == 'X' && board[1][y] == 'X' && board[2][y] == 'X')
        {
            score++;
            game_over = 1;
            printf("You won! Your score is: %d\n", score);
        }
        else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        {
            score++;
            game_over = 1;
            printf("You won! Your score is: %d\n", score);
        }
        else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        {
            score++;
            game_over = 1;
            printf("You won! Your score is: %d\n", score);
        }
        else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'O')
        {
            game_over = 1;
            printf("Draw! Your score is: %d\n", score);
        }
    }

    // Display the game board
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }

    // Check if the game is over
    if (game_over)
    {
        // Restart the game
        main();
    }

    return 0;
}