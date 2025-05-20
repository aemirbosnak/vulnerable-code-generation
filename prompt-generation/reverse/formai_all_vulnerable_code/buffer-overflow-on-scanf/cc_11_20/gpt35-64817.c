//FormAI DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main()
{
    srand(time(NULL));
    int board[ROWS][COLS];
    int i, j, k;
    int num_pairs = (ROWS * COLS) / 2;
    int pairs_found = 0;
    int first_row, first_col, second_row, second_col;
    int temp_row, temp_col, temp_value;
    int moves = 0;

    // Initialize the board with random numbers between 1 and 10
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            board[i][j] = rand() % 10 + 1;
        }
    }

    // Randomly swap pairs of numbers on the board
    for(k = 0; k < num_pairs; k++)
    {
        // Generate two random positions on the board
        first_row = rand() % ROWS;
        first_col = rand() % COLS;
        second_row = rand() % ROWS;
        second_col = rand() % COLS;

        // Swap the two positions
        temp_value = board[first_row][first_col];
        board[first_row][first_col] = board[second_row][second_col];
        board[second_row][second_col] = temp_value;
    }

    // Print the initial state of the board
    printf("Welcome to the Memory Game!\n");
    printf("Find all %d pairs of numbers.\n", num_pairs);
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("|%2d|", board[i][j]);
        }
        printf("\n");
    }

    // Loop until all pairs are found
    while(pairs_found != num_pairs)
    {
        printf("Enter the row and column of the two numbers you want to flip (e.g. 1 3 2 4): ");
        scanf("%d %d %d %d", &first_row, &first_col, &second_row, &second_col);

        // Check if the two positions are valid
        if(first_row < 0 || first_row >= ROWS || first_col < 0 || first_col >= COLS ||
           second_row < 0 || second_row >= ROWS || second_col < 0 || second_col >= COLS)
        {
            printf("Invalid positions, try again.\n");
            continue;
        }

        // Check if the two positions are the same
        if(first_row == second_row && first_col == second_col)
        {
            printf("You picked the same position twice, try again.\n");
            continue;
        }

        // Increment the number of moves
        moves++;

        // Flip the two positions and print the new state of the board
        temp_value = board[first_row][first_col];
        board[first_row][first_col] = board[second_row][second_col];
        board[second_row][second_col] = temp_value;

        printf("You flipped these two positions:\n");
        for(i = 0; i < ROWS; i++)
        {
            for(j = 0; j < COLS; j++)
            {
                printf("|%2d|", board[i][j]);
            }
            printf("\n");
        }

        // Check if the two flipped positions have the same value
        if(board[first_row][first_col] == board[second_row][second_col])
        {
            printf("You found a pair!\n");
            pairs_found++;
        }
        else
        {
            // Flip the positions back if they don't match
            temp_value = board[first_row][first_col];
            board[first_row][first_col] = board[second_row][second_col];
            board[second_row][second_col] = temp_value;
        }
    }

    printf("Congratulations! You found all %d pairs in %d moves.\n", num_pairs, moves);

    return 0;
}