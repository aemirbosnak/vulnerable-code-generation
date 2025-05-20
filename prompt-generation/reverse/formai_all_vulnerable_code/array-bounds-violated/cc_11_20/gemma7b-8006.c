//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, y, z, i, j, k, l, m, n, score = 0, highscore = 0, game_over = 0;
    char board[10][10] = {0};
    char direction = ' ';

    system("clear");

    // Game Setup
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            board[i][j] = '#';
        }
    }

    board[5][5] = 'O';

    // Game Loop
    while (!game_over)
    {
        // Display Board
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Get User Input
        printf("Enter direction (N/S/E/W): ");
        scanf("%c", &direction);

        // Move Piece
        switch (direction)
        {
            case 'N':
                board[x][y] = ' ';
                x--;
                board[x][y] = 'O';
                break;
            case 'S':
                board[x][y] = ' ';
                x++;
                board[x][y] = 'O';
                break;
            case 'E':
                board[x][y] = ' ';
                y++;
                board[x][y] = 'O';
                break;
            case 'W':
                board[x][y] = ' ';
                y--;
                board[x][y] = 'O';
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check Game Over
        if (board[x][y] == '#')
        {
            game_over = 1;
            printf("Game Over! Your score: %d\n", score);
        }

        // Update Highscore
        if (score > highscore)
        {
            highscore = score;
            printf("New highscore: %d\n", highscore);
        }

        // Increment Score
        score++;
    }

    return 0;
}