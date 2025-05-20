//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to represent a table cell
typedef struct {
    char symbol;   // Symbol printed in the cell
    int value;    // Value of the cell
} cell_t;

// Array to store the table data
cell_t table[TABLE_ROWS][TABLE_COLS];

// Function to print the table
void print_table(void) {
    int i, j;

    // Print the table header
    printf("   A  B  C  D  E  F  G  H  I \n");

    for (i = 0; i < TABLE_ROWS; i++) {
        for (j = 0; j < TABLE_COLS; j++) {
            printf("%c %d", table[i][j].symbol, table[i][j].value);
            if (j != TABLE_COLS - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to get a random value for a cell
int get_random_value(void) {
    return (int)(rand() % 10);
}

// Function to set a cell's value to a random value
void set_random_value(int row, int col) {
    table[row][col].value = get_random_value();
}

// Function to roll the dice and update the table
void roll_dice(int row, int col) {
    int value = (int)(rand() % 6) + 1;

    // If the dice roll is a 6, print a special message
    if (value == 6) {
        printf("Wild! You got a 6!\n");
    }

    // Update the cell's value with the rolled value
    table[row][col].value = value;
}

// Main game loop
int main(void) {
    int row, col;

    // Initialize the table with random values
    for (row = 0; row < TABLE_ROWS; row++) {
        for (col = 0; col < TABLE_COLS; col++) {
            set_random_value(row, col);
        }
    }

    // Print the table
    print_table();

    // Game loop
    while (1) {
        // Print the current state of the table
        print_table();

        // Ask the player for their move (row and col)
        printf("Enter row and col (1-10): ");
        scanf("%d%d", &row, &col);

        // Roll the dice and update the table
        roll_dice(row, col);
    }

    return 0;
}