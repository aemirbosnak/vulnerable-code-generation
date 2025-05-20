//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, y, z, w, n, score = 0, highscore = 0;
    char c, board[5][5] = {
        { ' ', ' ', ' ', ' ', ' ' },
        { ' ', 'O', ' ', ' ', ' ' },
        { ' ', ' ', 'O', ' ', ' ' },
        { ' ', ' ', ' ', 'O', ' ' },
        { ' ', ' ', ' ', ' ', ' ' }
    };

    srand(time(NULL));

    // Game Loop
    while (1)
    {
        // Display Board
        for (y = 0; y < 5; y++)
        {
            for (x = 0; x < 5; x++)
            {
                printf("%c ", board[y][x]);
            }
            printf("\n");
        }

        // Get User Input
        printf("Enter move (x, y): ");
        scanf("%d %d", &w, &n);

        // Validate Move
        if (w < 0 || w >= 5 || n < 0 || n >= 5)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place Mark
        board[w][n] = 'O';

        // Check for Win
        if (board[w][0] == 'O' && board[w][1] == 'O' && board[w][2] == 'O')
        {
            score++;
            printf("You win! Score: %d\n", score);
            highscore = score > highscore ? score : highscore;
            break;
        }
        else if (board[0][n] == 'O' && board[1][n] == 'O' && board[2][n] == 'O')
        {
            score++;
            printf("You win! Score: %d\n", score);
            highscore = score > highscore ? score : highscore;
            break;
        }
        else if (board[w][0] == 'O' && board[w][1] == 'O' && board[w][2] == 'O')
        {
            score++;
            printf("You win! Score: %d\n", score);
            highscore = score > highscore ? score : highscore;
            break;
        }
        else if (board[0][n] == 'O' && board[1][n] == 'O' && board[2][n] == 'O')
        {
            score++;
            printf("You win! Score: %d\n", score);
            highscore = score > highscore ? score : highscore;
            break;
        }

        // Check for Draw
        if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' && board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' && board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
        {
            score++;
            printf("Draw! Score: %d\n", score);
            highscore = score > highscore ? score : highscore;
            break;
        }

        // Continue Game
        printf("Press any key to continue...");
        getchar();
    }

    // Highscore Record
    printf("Highscore: %d\n", highscore);

    return 0;
}