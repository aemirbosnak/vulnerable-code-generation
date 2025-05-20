//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_WRONG_GUESSES 10

// Function to initialize the grid with random numbers
void init_grid(int grid[ROWS][COLS]);

// Function to check if a given number is present in the grid
int is_number_present(int grid[ROWS][COLS], int number, int *row, int *col);

int main()
{
    int grid[ROWS][COLS], number, row, col, correct_guesses = 0, wrong_guesses = 0;

    // Initialize the grid with random numbers
    init_grid(grid);

    while (correct_guesses < ROWS * COLS) {
        printf("Enter a number present in the grid: ");
        scanf("%d", &number);

        // Check if the number is present in the grid
        if (is_number_present(grid, number, &row, &col)) {
            correct_guesses++;
            printf("Correct guess at row %d, column %d\n", row, col);
        } else {
            wrong_guesses++;
            printf("Incorrect guess. You have %d correct and %d incorrect guesses.\n", correct_guesses, wrong_guesses);

            // Check if the maximum number of incorrect guesses is reached
            if (wrong_guesses >= MAX_WRONG_GUESSES) {
                printf("Game Over! You have reached the maximum number of incorrect guesses.\n");
                break;
            }
        }
    }

    // Check if all numbers are guessed
    if (correct_guesses == ROWS * COLS) {
        printf("Congratulations! You have guessed all the numbers in the grid.\n");
    }

    return 0;
}

// Function to initialize the grid with random numbers
void init_grid(int grid[ROWS][COLS])
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 100 + 1;
        }
    }
}

// Function to check if a given number is present in the grid
int is_number_present(int grid[ROWS][COLS], int number, int *row, int *col)
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == number) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }

    return 0;
}