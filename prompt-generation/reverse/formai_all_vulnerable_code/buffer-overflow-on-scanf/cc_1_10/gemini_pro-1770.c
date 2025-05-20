//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 4

// Define the number of guesses
#define NUM_GUESSES 10

// Define the cell states
typedef enum {
    CELL_EMPTY,
    CELL_COVERED,
    CELL_OPENED,
    CELL_MATCHED
} cell_state;

// Define the cell structure
typedef struct {
    cell_state state;
    int value;
} cell;

// Define the grid structure
typedef struct {
    cell cells[GRID_SIZE][GRID_SIZE];
} grid;

// Function to initialize the grid
void init_grid(grid *grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].state = CELL_EMPTY;
            grid->cells[i][j].value = 0;
        }
    }
}

// Function to print the grid
void print_grid(grid *grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            switch (grid->cells[i][j].state) {
                case CELL_EMPTY:
                    printf("  ");
                    break;
                case CELL_COVERED:
                    printf("[]");
                    break;
                case CELL_OPENED:
                    printf(" %d", grid->cells[i][j].value);
                    break;
                case CELL_MATCHED:
                    printf("==");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to generate a random number
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to fill the grid with random numbers
void fill_grid(grid *grid) {
    int values[] = {1, 1, 2, 2, 3, 3, 4, 4};
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int index = get_random_number(0, 7);
            grid->cells[i][j].value = values[index];
        }
    }
}

// Function to check if two cells match
bool cells_match(cell *cell1, cell *cell2) {
    return cell1->value == cell2->value;
}

// Function to open a cell
void open_cell(grid *grid, int x, int y) {
    grid->cells[x][y].state = CELL_OPENED;
}

// Function to close a cell
void close_cell(grid *grid, int x, int y) {
    grid->cells[x][y].state = CELL_COVERED;
}

// Function to match two cells
void match_cells(grid *grid, int x1, int y1, int x2, int y2) {
    grid->cells[x1][y1].state = CELL_MATCHED;
    grid->cells[x2][y2].state = CELL_MATCHED;
}

// Function to check if the game is over
bool game_over(grid *grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].state != CELL_MATCHED) {
                return false;
            }
        }
    }
    return true;
}

// Function to play the game
void play_game() {
    // Initialize the grid
    grid grid;
    init_grid(&grid);

    // Fill the grid with random numbers
    fill_grid(&grid);

    // Print the grid
    print_grid(&grid);

    // Get the user's guess
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first cell (x, y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second cell (x, y): ");
    scanf("%d %d", &x2, &y2);

    // Open the cells
    open_cell(&grid, x1, y1);
    open_cell(&grid, x2, y2);

    // Print the grid
    print_grid(&grid);

    // Check if the cells match
    if (cells_match(&grid.cells[x1][y1], &grid.cells[x2][y2])) {
        printf("Match!\n");
        match_cells(&grid, x1, y1, x2, y2);
    } else {
        printf("No match!\n");
        close_cell(&grid, x1, y1);
        close_cell(&grid, x2, y2);
    }

    // Check if the game is over
    if (game_over(&grid)) {
        printf("Congratulations! You won the game!\n");
    } else {
        // Continue playing the game
        play_game();
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}