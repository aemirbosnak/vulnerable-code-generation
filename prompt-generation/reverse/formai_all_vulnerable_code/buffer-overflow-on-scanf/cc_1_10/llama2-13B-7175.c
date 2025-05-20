//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to represent a table cell
typedef struct cell {
    char value;
    char color;
} cell;

// Function to draw a table cell
void draw_cell(cell *cell) {
    printf("%c%c", cell->value, cell->color);
}

// Function to print a table row
void print_row(cell row[TABLE_COLS]) {
    printf("\n");
    for (int i = 0; i < TABLE_COLS; i++) {
        draw_cell(&row[i]);
    }
    printf("\n");
}

// Function to print the table
void print_table(cell table[TABLE_ROWS][TABLE_COLS]) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        print_row(table[i]);
    }
}

// Function to get a random value for a cell
char get_random_value() {
    return 'A' + (rand() % 26);
}

// Function to get a random color for a cell
char get_random_color() {
    return (rand() % 2) ? 'R' : 'B';
}

// Function to set a cell's value and color
void set_cell(cell *cell, char value, char color) {
    cell->value = value;
    cell->color = color;
}

int main() {
    // Initialize the table
    cell table[TABLE_ROWS][TABLE_COLS];
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            set_cell(&table[i][j], get_random_value(), get_random_color());
        }
    }

    // Print the table
    print_table(table);

    // Get user input
    char user_input;
    printf("User input: ");
    scanf(" %c", &user_input);

    // Check if the user input is valid
    if (user_input == 'A' || user_input == 'a' || user_input == 'B' || user_input == 'b') {
        // Update the cell at the user's position
        int row = user_input - 'A';
        int col = user_input - 'a';
        set_cell(&table[row][col], user_input, table[row][col].color);

        // Print the updated table
        print_table(table);
    } else {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}