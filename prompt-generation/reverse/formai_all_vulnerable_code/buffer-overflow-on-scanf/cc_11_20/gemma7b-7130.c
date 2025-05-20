//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, n, score = 0, board[20][20] = {{0}};
    char move, direction;

    printf("Welcome to the game of Sherlock Holmes!\n");

    // Create a 20x20 board
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            board[x][y] = 0;
        }
    }

    // Place the detective in a random location
    x = rand() % 20;
    y = rand() % 20;
    board[x][y] = 1;

    // Set the number of moves
    n = 0;

    // Start the game loop
    while (score < 10 && n < 20)
    {
        // Get the user's move
        printf("Enter your move (N/S/E/W): ");
        scanf("%c", &move);

        // Validate the move
        if (move != 'N' && move != 'S' && move != 'E' && move != 'W')
        {
            printf("Invalid move.\n");
            continue;
        }

        // Move the detective
        switch (move)
        {
            case 'N':
                board[x][y] = 0;
                x--;
                board[x][y] = 1;
                break;
            case 'S':
                board[x][y] = 0;
                x++;
                board[x][y] = 1;
                break;
            case 'E':
                board[x][y] = 0;
                y++;
                board[x][y] = 1;
                break;
            case 'W':
                board[x][y] = 0;
                y--;
                board[x][y] = 1;
                break;
        }

        // Check if the detective has found the criminal
        if (board[x][y] == 2)
        {
            score = 10;
            printf("Congratulations! You have solved the case!\n");
        }

        // Increment the number of moves
        n++;
    }

    // End the game
    printf("Thank you for playing. See you next time.\n");

    return 0;
}