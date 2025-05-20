//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 3

// function prototypes
void initialize_grid(char grid[][GRID_SIZE]);
void display_grid(char grid[][GRID_SIZE]);
bool make_move(char grid[][GRID_SIZE], int row, int col, char symbol);
bool has_won(char grid[][GRID_SIZE], char symbol);
bool is_tie(char grid[][GRID_SIZE]);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    char player = 'X';
    int row, col;

    initialize_grid(grid);

    printf("Welcome to Tic Tac Toe!\n");
    display_grid(grid);

    while (true) {
        printf("Player %c, please enter your move (row col): ", player);
        scanf("%d %d", &row, &col);

        if (make_move(grid, row, col, player)) {
            if (has_won(grid, player)) {
                printf("Player %c wins!\n", player);
                break;
            } else if (is_tie(grid)) {
                printf("It's a tie!\n");
                break;
            }

            // switch turns
            player = (player == 'X') ? 'O' : 'X';

            display_grid(grid);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}

// initializes the grid to contain blank spaces
void initialize_grid(char grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = ' ';
        }
    }
}

// prints out the current grid
void display_grid(char grid[][GRID_SIZE]) {
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf(" %c | %c | %c ", grid[i][0], grid[i][1], grid[i][2]);
        printf("\n");

        if (i != GRID_SIZE - 1) {
            printf("-----------\n");
        }
    }

    printf("\n");
}

// puts a symbol on the grid at the specified row and column
// returns true if the move was successful, false otherwise
bool make_move(char grid[][GRID_SIZE], int row, int col, char symbol) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return false; // out of bounds
    }

    if (grid[row][col] != ' ') {
        return false; // spot already taken
    }

    grid[row][col] = symbol;

    return true; // success
}

// returns true if the specified symbol has won the game, false otherwise
bool has_won(char grid[][GRID_SIZE], char symbol) {
    // check rows
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            return true;
        }
    }

    // check columns
    for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol) {
            return true;
        }
    }

    // check diagonals
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return true;
    }

    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        return true;
    }

    return false;
}

// returns true if the game is a tie, false otherwise
bool is_tie(char grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == ' ') {
                return false; // game isn't over yet
            }
        }
    }

    return true; // all spots are filled - it's a tie
}