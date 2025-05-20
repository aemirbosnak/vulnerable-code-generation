//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to represent a table cell
typedef struct {
    char value;
    char color;
} cell_t;

// Array to store the table data
cell_t table[TABLE_ROWS][TABLE_COLS];

// Function to print the table
void print_table(void);

// Function to get a random value for a cell
int get_random_value(void);

// Function to get a random color for a cell
char get_random_color(void);

// Function to update the table based on user input
void update_table(void);

int main(void) {
    // Initialize the table with random values and colors
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table[i][j].value = get_random_value();
            table[i][j].color = get_random_color();
        }
    }

    // Print the table
    print_table();

    // Update the table based on user input
    update_table();

    return 0;
}

// Function to print the table
void print_table(void) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            printf("%c%c", table[i][j].value, table[i][j].color);
        }
        printf("\n");
    }
}

// Function to get a random value for a cell
int get_random_value(void) {
    return (rand() % 2) ? 1 : 0;
}

// Function to get a random color for a cell
char get_random_color(void) {
    return (rand() % 2) ? 'R' : 'G';
}

// Function to update the table based on user input
void update_table(void) {
    int row, col;

    // Get the row and column from the user
    printf("Enter row and column (e.g. '1 2'): ");
    scanf("%d%d", &row, &col);

    // Update the value and color of the cell
    table[row][col].value = get_random_value();
    table[row][col].color = get_random_color();

    // Print the updated table
    print_table();
}