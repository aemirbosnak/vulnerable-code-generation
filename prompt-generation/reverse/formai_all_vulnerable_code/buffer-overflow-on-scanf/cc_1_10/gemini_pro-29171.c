//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

// Table data structure
typedef struct {
    int value;
    int is_open;
} TableCell;

// Table game state
typedef struct {
    TableCell table[NUM_ROWS][NUM_COLS];
    int num_open_cells;
} TableGameState;

// Function to initialize the table game state
void init_game_state(TableGameState *state) {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the table values
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            state->table[i][j].value = rand() % 10 + 1;
            state->table[i][j].is_open = 0;
        }
    }

    // Set the number of open cells to 0
    state->num_open_cells = 0;
}

// Function to print the table game state
void print_game_state(TableGameState *state) {
    // Print the table header
    printf("  ");
    for (int i = 0; i < NUM_COLS; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // Print the table rows
    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < NUM_COLS; j++) {
            if (state->table[i][j].is_open) {
                printf("%d ", state->table[i][j].value);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Function to get the user's input
void get_user_input(TableGameState *state) {
    int row, col;

    // Prompt the user to enter a row and column
    printf("Enter a row and column (e.g. 1 2): ");
    scanf("%d %d", &row, &col);

    // Check if the row and column are valid
    if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
        printf("Invalid row or column\n");
        return;
    }

    // Open the cell
    state->table[row - 1][col - 1].is_open = 1;

    // Increment the number of open cells
    state->num_open_cells++;
}

// Function to check if the game is over
int is_game_over(TableGameState *state) {
    // Check if all cells are open
    return state->num_open_cells == NUM_ROWS * NUM_COLS;
}

// Main game loop
int main() {
    // Initialize the game state
    TableGameState state;
    init_game_state(&state);

    // Print the initial game state
    print_game_state(&state);

    // Get user input until the game is over
    while (!is_game_over(&state)) {
        get_user_input(&state);
        print_game_state(&state);
    }

    // Print the game over message
    printf("Game over!\n");

    return 0;
}