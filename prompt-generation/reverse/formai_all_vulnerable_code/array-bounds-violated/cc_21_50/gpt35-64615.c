//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main()
{
    // Generate random numbers from 1 to 25 as BINGO game numbers.
    srand(time(NULL));
    int bingo_nums[] = { 0 };
    for (int i = 0; i < 25; i++)
    {
        int num = rand() % 25 + 1;
        // Check if the generated number already exists, if yes, generate again.
        for (int j = 0; j < i; j++)
        {
            if (num == bingo_nums[j])
            {
                num = rand() % 25 + 1;
                j = -1; // start from beginning again
            }
        }
        // add the unique generated number to bingo numbers array.
        bingo_nums[i] = num;
    }

    // Create a new 2D array with 5 rows and 5 columns.
    int bingo_board[ROWS][COLS];

    // Fill the bingo board with numbers from 1 to 25.
    for (int i = 0, k = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++, k++)
        {
            bingo_board[i][j] = bingo_nums[k];
        }
    }

    // Print the bingo board with numbers.
    printf("\n\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%2d | ", bingo_board[i][j]);
        }
        printf("\n");
        for (int k = 0; k < COLS * 4; k++)
        {
            printf("-");
        }
        printf("\n");
    }

    // Call out random numbers one by one and keep track of the marked numbers.
    int marked_nums[] = { 0 };
    int count = 0;
    while (count < 25)
    {
        int num = rand() % 25 + 1;
        int is_marked = 0;
        // Check if the called number already exists as marked or not.
        for (int i = 0; i < count; i++)
        {
            if (num == marked_nums[i])
            {
                is_marked = 1;
                break;
            }
        }
        // If the called number is not marked yet, mark it.
        if (!is_marked)
        {
            int row = 0, col = 0;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (bingo_board[i][j] == num)
                    {
                        row = i;
                        col = j;
                        break;
                    }
                }
                if (row != 0 || col != 0)
                {
                    break;
                }
            }

            marked_nums[count] = num;
            count++;

            // Update the bingo board with X at the location of called number.
            bingo_board[row][col] = 'X';

            // Print the updated bingo board with X marked.
            printf("\n\n");
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (bingo_board[i][j] == 'X')
                    {
                        printf("X  | ");
                    }
                    else
                    {
                        printf("%2d | ", bingo_board[i][j]);
                    }
                }
                printf("\n");
                for (int k = 0; k < COLS * 4; k++)
                {
                    printf("-");
                }
                printf("\n");
            }

            // Check if any row, column or diagonal has all marked numbers, if yes, print BINGO and exit the game.
            int is_bingo = 0;
            // Checking rows.
            for (int i = 0; i < ROWS; i++)
            {
                int is_row_complete = 1;
                for (int j = 0; j < COLS; j++)
                {
                    if (bingo_board[i][j] != 'X')
                    {
                        is_row_complete = 0;
                    }
                }
                if (is_row_complete)
                {
                    printf("\n\nBINGO!! Row %d is complete.\n\n", i + 1);
                    is_bingo = 1;
                    break;
                }
            }
            if (is_bingo)
            {
                break;
            }
            // Checking columns.
            for (int j = 0; j < COLS; j++)
            {
                int is_col_complete = 1;
                for (int i = 0; i < ROWS; i++)
                {
                    if (bingo_board[i][j] != 'X')
                    {
                        is_col_complete = 0;
                    }
                }
                if (is_col_complete)
                {
                    printf("\n\nBINGO!! Column %d is complete.\n\n", j + 1);
                    is_bingo = 1;
                    break;
                }
            }
            if (is_bingo)
            {
                break;
            }
            // Checking diagonals.
            if (bingo_board[0][0] == 'X' && bingo_board[1][1] == 'X' && bingo_board[2][2] == 'X' && bingo_board[3][3] == 'X' && bingo_board[4][4] == 'X')
            {
                printf("\n\nBINGO!! Diagonal from top-left to bottom-right is complete.\n\n");
                break;
            }
            if (bingo_board[0][4] == 'X' && bingo_board[1][3] == 'X' && bingo_board[2][2] == 'X' && bingo_board[3][1] == 'X' && bingo_board[4][0] == 'X')
            {
                printf("\n\nBINGO!! Diagonal from top-right to bottom-left is complete.\n\n");
                break;
            }
        }
    }

    return 0;
}