//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 99

int main()
{
    int board[ROWS][COLS] = {0};
    int called[MAX_NUM] = {0};
    int num_called = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Fill the board with random numbers
    for (int i = 0; i < ROWS; i++)
    {
        for (int j  = 0; j < COLS; j++)
        {
            int num = rand() % MAX_NUM + 1;
            board[i][j] = num;

            // Print the number with a leading zero if necessary
            if (num < 10)
            {
                printf("0%d ", num);
            }
            else
            {
                printf("%d ", num);
            }
        }
        printf("\n");
    }

    printf("\n");

    // Keep calling numbers until someone wins
    while (1)
    {
        // Generate a random number that hasn't been called before
        int num_to_call;
        do
        {
            num_to_call = rand() % MAX_NUM + 1;
        } while (called[num_to_call]);

        // Mark the number as called
        called[num_to_call] = 1;
        num_called++;

        printf("The number called is: %02d\n", num_to_call);

        // Check if any player has won
        for (int i = 0; i < ROWS; i++)
        {
            int row_sum = 0;
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == num_to_call)
                {
                    row_sum++;
                }
            }
            if (row_sum == COLS)
            {
                printf("Player wins with a horizontal bingo on row %d!\n", i+1);
                printf("It took %d calls to make this happen.\n", num_called);
                return 0;
            }
        }

        for (int j = 0; j < COLS; j++)
        {
            int col_sum = 0;
            for (int i = 0; i < ROWS; i++)
            {
                if (board[i][j] == num_to_call)
                {
                    col_sum++;
                }
            }
            if (col_sum == ROWS)
            {
                printf("Player wins with a vertical bingo on column %d!\n", j+1);
                printf("It took %d calls to make this happen.\n", num_called);
                return 0;
            }
        }

        int diag_sum1 = 0;
        int diag_sum2 = 0;
        for (int i = 0; i < ROWS; i++)
        {
            if (board[i][i] == num_to_call)
            {
                diag_sum1++;
            }
            if (board[i][COLS-i-1] == num_to_call)
            {
                diag_sum2++;
            }
        }
        if (diag_sum1 == ROWS)
        {
            printf("Player wins with a diagonal bingo from top left to bottom right!\n");
            printf("It took %d calls to make this happen.\n", num_called);
            return 0;
        }
        if (diag_sum2 == ROWS)
        {
            printf("Player wins with a diagonal bingo from top right to bottom left!\n");
            printf("It took %d calls to make this happen.\n", num_called);
            return 0;
        }
    }

    return 0;
}