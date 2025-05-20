//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to represent a table cell
typedef struct {
    int value;  // Value of the cell
    int found;  // Flag to indicate if the cell has been guessed
} table_cell;

// Global variable to store the table layout
table_cell table[TABLE_ROWS][TABLE_COLS];

// Function to generate a random table layout
void generate_table() {
    int i, j;
    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            // Generate a random number between 1 and 10
            int num = (int) (rand() % 10) + 1;
            table[i][j].value = num;
            table[i][j].found = 0;
        }
    }
}

// Function to print the table layout
void print_table() {
    int i, j;
    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            printf("%d ", table[i][j].value);
        }
        printf("\n");
    }
}

// Function to guess a cell value
int guess_cell(int row, int col) {
    int i, j;
    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            if (i == row && j == col) {
                return table[i][j].value;
            }
        }
    }
    return -1;
}

int main() {
    generate_table();
    print_table();

    int guess;
    do {
        printf("Enter a row and column to guess a value (row 1-10, col 1-10): ");
        scanf("%d%d", &guess, &guess);

        if (guess < 1 || guess > TABLE_ROWS || guess < 1 || guess > TABLE_COLS) {
            printf("Invalid input. Try again.\n");
        } else {
            guess = guess_cell(guess, guess);
            if (guess != -1) {
                printf("You guessed %d at row %d, col %d\n", guess, guess, guess);
            } else {
                printf("Invalid guess. Try again.\n");
            }
        }
    } while (guess != -1);

    return 0;
}