//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Struct to represent a table
struct Table {
    int data[ROWS][COLS];
};

// Function to initialize a table
void init_table(struct Table *table) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table->data[i][j] = 0;
        }
    }
}

// Function to print a table
void print_table(struct Table *table) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", table->data[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a row is filled
int row_filled(struct Table *table, int row) {
    for (int i = 0; i < COLS; i++) {
        if (table->data[row][i] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a column is filled
int col_filled(struct Table *table, int col) {
    for (int i = 0; i < ROWS; i++) {
        if (table->data[i][col] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a diagonal is filled
int diag_filled(struct Table *table) {
    for (int i = 0; i < ROWS; i++) {
        if (table->data[i][i] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a reverse diagonal is filled
int rev_diag_filled(struct Table *table) {
    for (int i = 0; i < ROWS; i++) {
        if (table->data[i][ROWS - i - 1] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the game is over
int game_over(struct Table *table) {
    return row_filled(table, 0) || col_filled(table, 0) || diag_filled(table) || rev_diag_filled(table);
}

// Function to play a game of tic-tac-toe
void play_game(struct Table *table) {
    // Initialize the table
    init_table(table);

    // Print the initial table
    print_table(table);

    // Play the game
    int player = 1;
    while (!game_over(table)) {
        // Get the move from the user
        int row, col;
        printf("Player %d, enter a row and column: ", player);
        scanf("%d %d", &row, &col);

        // Make the move
        table->data[row][col] = player;

        // Print the updated table
        print_table(table);

        // Check if the game is over
        if (game_over(table)) {
            break;
        }

        // Switch players
        player = (player == 1) ? 2 : 1;
    }

    // Print the final table
    print_table(table);
}

int main() {
    // Create a table
    struct Table table;

    // Play a game of tic-tac-toe
    play_game(&table);

    return 0;
}