//FormAI DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Set the size of the grid
#define MAX_ATTEMPTS 2 // Set the maximum number of attempts per guess

// Function to initialize the grid
void InitializeGrid(char grid[][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = '-';
        }
    }
}

// Function to print the grid
void PrintGrid(char grid[][SIZE], int reveal) {
    int i, j;

    printf("\n");
    printf("  ");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);

        for (j = 0; j < SIZE; j++) {
            if (reveal || grid[i][j] != 'X') {
                printf("%c ", grid[i][j]);
            } else {
                printf("X ");
            }
        }

        printf("\n");
    }
}

// Function to randomly place the symbols on the grid
void PlaceSymbols(char grid[][SIZE], int num_symbols) {
    char symbols[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    int counts[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int i, j, k, symbol, row, column;

    srand(time(NULL));

    for (k = 0; k < num_symbols; k++) {
        symbol = k % 8;

        // Find a random available spot for the symbol
        do {
            row = rand() % SIZE;
            column = rand() % SIZE;
        } while (grid[row][column] != '-');

        grid[row][column] = symbols[symbol];
        counts[symbol]++;
    }

    printf("\n");

    for (i = 0; i < 8; i++) {
        printf("%c: %d  ", symbols[i], counts[i]);
    }

    printf("\n");
}

// Function to get the user's guess
void GetUserGuess(int *row, int *column) {
    printf("\nEnter row and column separated by a space: ");
    scanf("%d %d", row, column);
}

// Function to check if the user's guess is correct
int CheckGuess(char grid[][SIZE], int row1, int column1, int row2, int column2) {
    if (grid[row1][column1] == grid[row2][column2]) {
        printf("\nCorrect!");
        return 1;
    } else {
        printf("\nIncorrect.");
        return 0;
    }
}

int main() {
    char grid[SIZE][SIZE];
    int i, j, attempts, correct_guesses, row1, column1, row2, column2;

    InitializeGrid(grid);
    PlaceSymbols(grid, SIZE * SIZE / 2); // Place half as many symbols as there are spots on the grid
    PrintGrid(grid, 0); // Print the initial grid with hidden symbols

    correct_guesses = 0;
    attempts = 0;

    while (correct_guesses < SIZE * SIZE / 2) { // Keep guessing until all symbols are matched
        GetUserGuess(&row1, &column1);

        if (grid[row1][column1] == '-') { // Check if the spot has already been guessed
            printf("\nSpot already guessed. Try again.");
        } else {
            grid[row1][column1] = 'X';
            attempts++;

            GetUserGuess(&row2, &column2);

            if (grid[row2][column2] == '-') {
                printf("\nSpot already guessed. Try again.");
                grid[row1][column1] = '-';
            } else {
                grid[row2][column2] = 'X';
                attempts++;

                if (CheckGuess(grid, row1, column1, row2, column2)) {
                    correct_guesses++;
                } else {
                    grid[row1][column1] = '-';
                    grid[row2][column2] = '-';
                }

                PrintGrid(grid, 1); // Print the updated grid with revealed symbols
            }
        }

        if (attempts % MAX_ATTEMPTS == 0) { // Pause after each round of MAX_ATTEMPTS attempts
            printf("\nPress enter to continue...");
            getchar();
        }
    }

    printf("\nYou win! It took you %d attempts.", attempts);

    return 0;
}