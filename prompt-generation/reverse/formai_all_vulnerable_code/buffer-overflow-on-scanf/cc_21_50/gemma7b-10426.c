//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0;
    int lives = 3;
    char board[4][4] = {{' ', ' ', ' ', ' '},
                              {' ', 'O', ' ', ' '},
                              {' ', 'O', 'O', ' '},
                              {' ', ' ', ' ', ' '}};

    // Game Loop
    while (lives > 0)
    {
        // Print Board
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Get User Input
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Validate Input
        if (row < 0 || row >= 4 || column < 0 || column >= 4)
        {
            printf("Invalid input!\n");
            continue;
        }

        // Place O on Board
        board[row][column] = 'O';

        // Check if O won
        if (board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O' && board[row][3] == 'O')
        {
            printf("You won!\n");
            score++;
            break;
        }
        else if (board[0][column] == 'O' && board[1][column] == 'O' && board[2][column] == 'O' && board[3][column] == 'O')
        {
            printf("You won!\n");
            score++;
            break;
        }
        else if (board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O' && board[row][3] == 'O')
        {
            printf("You won!\n");
            score++;
            break;
        }
        else if (board[0][column] == 'O' && board[1][column] == 'O' && board[2][column] == 'O' && board[3][column] == 'O')
        {
            printf("You won!\n");
            score++;
            break;
        }

        // If no win, check if game over
        if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' && board[0][3] == 'O')
        {
            printf("Game over!\n");
            lives--;
        }
    }

    // Final Score
    printf("Your final score is: %d\n", score);

    return 0;
}