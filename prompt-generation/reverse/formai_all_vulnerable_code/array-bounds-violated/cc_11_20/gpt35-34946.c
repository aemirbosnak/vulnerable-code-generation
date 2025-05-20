//FormAI DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int arr[], int size);

int main()
{
    int cards[ROWS][COLS] = {{0}};
    int temp[ROWS * COLS / 2] = {0};
    int randIndex = 0;
    int moves = 0;
    int row1, col1, row2, col2;

    // initialize array with pairs of numbers
    for (int i = 1; i < (ROWS * COLS / 2) + 1; i++)
    {
        temp[i - 1] = i;
        temp[i + (ROWS * COLS / 2) - 1] = i;
    }
    shuffle(temp, ROWS * COLS);

    // assign shuffled numbers to card array
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            cards[r][c] = temp[r * COLS + c];
        }
    }

    printf("*** Welcome to the Memory Game! ***\n\n");
    printf("Match pairs of numbers to win the game! Let's begin...\n\n");

    while (1)
    {
        printf("   ");
        // print column numbers
        for (int i = 0; i < COLS; i++)
        {
            printf("%-4d", i + 1);
        }
        printf("\n");

        // print rows
        for (int r = 0; r < ROWS; r++)
        {
            printf("%d |", r + 1);
            for (int c = 0; c < COLS; c++)
            {
                if (cards[r][c] == 0)
                {
                    printf("    ");
                }
                else if (cards[r][c] < 10)
                {
                    printf("%-4d", cards[r][c]);
                }
                else
                {
                    printf("%-4d", cards[r][c]);
                }
            }
            printf("\n");
        }
        printf("\n");

        // get user's move
        printf("Enter two locations (row1 col1 row2 col2): ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        // check if valid move
        if (row1 < 1 || row1 > ROWS || col1 < 1 || col1 > COLS || row2 < 1 || row2 > ROWS || col2 < 1 || col2 > COLS)
        {
            printf("Invalid move. Try again.\n");
        }
        else if (cards[row1 - 1][col1 - 1] == 0 || cards[row2 - 1][col2 - 1] == 0)
        {
            printf("Invalid move. Try again.\n");
        }
        else if (row1 == row2 && col1 == col2)
        {
            printf("Invalid move. Try again.\n");
        }
        else if (cards[row1 - 1][col1 - 1] != cards[row2 - 1][col2 - 1])
        {
            printf("No match. Try again.\n");
            cards[row1 - 1][col1 - 1] = 0;
            cards[row2 - 1][col2 - 1] = 0;
            moves++;
        }
        else
        {
            printf("Match! Good job.\n");
            cards[row1 - 1][col1 - 1] = 0;
            cards[row2 - 1][col2 - 1] = 0;
            moves++;
        }

        // check if game over
        int gameOver = 1;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (cards[r][c] != 0)
                {
                    gameOver = 0;
                    break;
                }
            }
            if (gameOver == 0)
            {
                break;
            }
        }
        if (gameOver == 1)
        {
            printf("\nCongratulations! You won in %d moves.\n", moves);
            break;
        }
    }

    return 0;
}

void shuffle(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size - 1; i++)
    {
        int j = i + rand() / (RAND_MAX / (size - i) + 1);
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}