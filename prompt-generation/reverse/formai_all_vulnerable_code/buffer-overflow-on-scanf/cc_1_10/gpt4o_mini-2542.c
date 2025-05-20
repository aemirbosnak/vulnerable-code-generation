//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define EMPTY ' '
#define ALIVE '*'
#define DEAD '.'

void allocate_grid(char ***grid, int rows, int cols);
void initialize_grid(char **grid, int rows, int cols);
void display_grid(char **grid, int rows, int cols);
void update_grid(char **old_grid, char **new_grid, int rows, int cols);
int count_neighbors(char **grid, int row, int col, int rows, int cols);
void swap_grids(char ***old_grid, char ***new_grid);
void free_grid(char **grid, int rows);
void clear_screen();
void pause_program();
void randomize_grid(char **grid, int rows, int cols, double fill_percentage);
char get_user_choice();

int main() {
    srand(time(NULL));
    int rows, cols, generations;
    double fill_percentage;
    char **grid1, **grid2;

    printf("Welcome to Conway's Game of Life!\n");
    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);
    printf("Please enter the number of generations: ");
    scanf("%d", &generations);
    printf("Enter fill percentage for the grid (0-100): ");
    scanf("%lf", &fill_percentage);
    
    allocate_grid(&grid1, rows, cols);
    allocate_grid(&grid2, rows, cols);
    
    randomize_grid(grid1, rows, cols, fill_percentage);

    for (int gen = 0; gen < generations; gen++) {
        clear_screen();
        display_grid(grid1, rows, cols);
        update_grid(grid1, grid2, rows, cols);
        swap_grids(&grid1, &grid2);
        pause_program();
    }

    free_grid(grid1, rows);
    free_grid(grid2, rows);
    
    printf("Game over.\n");
    return 0;
}

void allocate_grid(char ***grid, int rows, int cols) {
    *grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        (*grid)[i] = malloc(cols * sizeof(char));
    }
}

void initialize_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

void display_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void update_grid(char **old_grid, char **new_grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(old_grid, i, j, rows, cols);
            if (old_grid[i][j] == ALIVE) {
                new_grid[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
            } else {
                new_grid[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

int count_neighbors(char **grid, int row, int col, int rows, int cols) {
    int delta[] = {-1, 0, 1};
    int count = 0;

    for (int dr = 0; dr < 3; dr++) {
        for (int dc = 0; dc < 3; dc++) {
            if (delta[dr] == 0 && delta[dc] == 0) continue; 
            int new_row = row + delta[dr];
            int new_col = col + delta[dc];
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && grid[new_row][new_col] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

void swap_grids(char ***old_grid, char ***new_grid) {
    char **temp = *old_grid;
    *old_grid = *new_grid;
    *new_grid = temp;
}

void free_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

void pause_program() {
    printf("Press Enter to continue...");
    while (getchar() != '\n'); // Wait for user to press Enter
}

void randomize_grid(char **grid, int rows, int cols, double fill_percentage) {
    int total_cells = rows * cols;
    int filled_cells = (int)(total_cells * (fill_percentage / 100.0));
    
    for (int i = 0; i < filled_cells; i++) {
        int r = rand() % rows;
        int c = rand() % cols;
        grid[r][c] = ALIVE;
    }

    // Ensure that the rest of the grid is dead
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != ALIVE) {
                grid[i][j] = DEAD;
            }
        }
    }
}