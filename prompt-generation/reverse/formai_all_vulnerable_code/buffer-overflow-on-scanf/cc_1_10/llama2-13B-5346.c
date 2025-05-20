//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_ROWS 10
#define TABLE_COLS 10

// Structure to represent a table cell
typedef struct {
    char value;
    char next;
} cell_t;

// Function to initialize the table with random values
void init_table(cell_t* table) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            table[i * TABLE_COLS + j].value = 'A' + (rand() % 26);
            table[i * TABLE_COLS + j].next = 'A' + (rand() % 26);
        }
    }
}

// Function to print the table
void print_table(cell_t* table) {
    for (int i = 0; i < TABLE_ROWS; i++) {
        for (int j = 0; j < TABLE_COLS; j++) {
            printf("%c", table[i * TABLE_COLS + j].value);
        }
        printf("\n");
    }
}

// Function to move a cell to the next position
void move_cell(cell_t* table, int row, int col) {
    cell_t temp = table[row * TABLE_COLS + col];
    table[row * TABLE_COLS + col] = table[row * TABLE_COLS + (col + 1) % TABLE_COLS];
    table[row * TABLE_COLS + (col + 1) % TABLE_COLS] = temp;
}

int main() {
    srand(time(NULL));

    // Create a table with 10 rows and 10 columns
    cell_t table[TABLE_ROWS][TABLE_COLS];

    // Initialize the table with random values
    init_table(table);

    // Print the table
    print_table(table);

    // Ask the user to move a cell
    printf("Enter the row and column of the cell you want to move (1-10, 1-10): ");
    int row, col;
    scanf("%d%d", &row, &col);

    // Move the cell
    move_cell(table, row, col);

    // Print the updated table
    print_table(table);

    return 0;
}