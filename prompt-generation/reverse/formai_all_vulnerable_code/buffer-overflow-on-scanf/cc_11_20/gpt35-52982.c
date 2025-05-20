//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4 // Number of rows in the memory game board
#define COLS 4 // Number of columns in the memory game board

int main()
{
    int board[ROWS][COLS], i, j, k, l, count = 0, turnedPairs = 0;
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    srand(time(NULL)); // Initialize random seed
    printf("Welcome to the Memory Game!\n\n");

    // Assign the symbols randomly to the memory game board
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = -1;
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS/2; j++)
        {
            int randomNumber = rand() % (ROWS * COLS);
            while (1)
            {
                int row = randomNumber / COLS;
                int col = randomNumber % COLS;

                if (board[row][col] == -1)
                {
                    board[row][col] = symbols[count];
                    count++;
                    break;
                }

                randomNumber++;
                if (randomNumber == ROWS * COLS)
                {
                    randomNumber = 0;
                }
            }
        }
    }

    // Play Memory Game
    while (turnedPairs < (ROWS * COLS) / 2)
    {
        int row1, col1, row2, col2;
        printf("Enter the coordinates of two cards (e.g. 0 1 2 3): ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        // Check if the user entered a valid input
        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS || row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS)
        {
            printf("Invalid input!\n");
            continue;
        }

        // Check if the cards are already turned or not
        if (board[row1][col1] == -1 || board[row2][col2] == -1)
        {
            printf("These cards are already turned or not available!\n");
            continue;
        }

        printf("Cards: [%c] and [%c]\n", board[row1][col1], board[row2][col2]);
        if (board[row1][col1] == board[row2][col2])
        {
            printf("Great job! You found a pair!\n");
            board[row1][col1] = -1;
            board[row2][col2] = -1;
            turnedPairs++;
        }
        else
        {
            printf("Oops, these cards do not match. Try again!\n");
        }
    }

    printf("Congratulations! You won the game!\n");
    return 0;
}