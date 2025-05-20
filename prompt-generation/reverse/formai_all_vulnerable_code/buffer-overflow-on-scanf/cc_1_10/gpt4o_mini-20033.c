//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD '.'

void initialize_grid(char **grid, int rows, int cols);
void display_grid(char **grid, int rows, int cols);
void update_grid(char **current, char **next, int rows, int cols);
int count_neighbors(char **grid, int row, int col, int rows, int cols);
void free_grid(char **grid, int rows);

int main() {
    int rows, cols, iterations;
    
    printf("Welcome to Conway's Game of Life!\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);
    
    char **current_grid = malloc(rows * sizeof(char *));
    char **next_grid = malloc(rows * sizeof(char *));
    for(int i = 0; i < rows; i++) {
        current_grid[i] = malloc(cols * sizeof(char));
        next_grid[i] = malloc(cols * sizeof(char));
    }
    
    initialize_grid(current_grid, rows, cols);
    
    for(int iter = 0; iter < iterations; iter++) {
        display_grid(current_grid, rows, cols);
        update_grid(current_grid, next_grid, rows, cols);
        
        // Swap the grids
        char **temp = current_grid;
        current_grid = next_grid;
        next_grid = temp;

        usleep(500000); // Sleep for half a second for visualization
    }

    free_grid(current_grid, rows);
    free_grid(next_grid, rows);
    
    return 0;
}

void initialize_grid(char **grid, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2) ? ALIVE : DEAD;
        }
    }
}

void display_grid(char **grid, int rows, int cols) {
    printf("\033[H\033[J"); // Clear the terminal screen
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void update_grid(char **current, char **next, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(current, i, j, rows, cols);
            if(current[i][j] == ALIVE) {
                next[i][j] = (alive_neighbors == 2 || alive_neighbors == 3) ? ALIVE : DEAD;
            } else {
                next[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

int count_neighbors(char **grid, int row, int col, int rows, int cols) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if((i == 0 && j == 0) || 
               row + i < 0 || row + i >= rows || 
               col + j < 0 || col + j >= cols) {
                continue;
            }
            if(grid[row + i][col + j] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

void free_grid(char **grid, int rows) {
    for(int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}