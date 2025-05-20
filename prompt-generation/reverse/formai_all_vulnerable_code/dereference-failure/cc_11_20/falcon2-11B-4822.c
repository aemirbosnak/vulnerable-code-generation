//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct maze {
    int rows;
    int cols;
    char** cells;
};

void print_maze(struct maze* maze) {
    int i, j;
    for (i = 0; i < maze->rows; i++) {
        for (j = 0; j < maze->cols; j++) {
            printf("%c", maze->cells[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct maze* maze = malloc(sizeof(struct maze));
    maze->rows = 5;
    maze->cols = 5;
    maze->cells = malloc(maze->rows * sizeof(char*));
    for (int i = 0; i < maze->rows; i++) {
        maze->cells[i] = malloc(maze->cols * sizeof(char));
    }

    // Fill the maze with walls
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (i == 0 || j == 0 || i == maze->rows - 1 || j == maze->cols - 1) {
                maze->cells[i][j] = '#';
            } else {
                maze->cells[i][j] = '.';
            }
        }
    }

    // Print the maze
    print_maze(maze);

    // Find the route
    int route[maze->rows * maze->cols];
    int start_row = 0;
    int start_col = 0;
    int end_row = maze->rows - 1;
    int end_col = maze->cols - 1;
    int current_row = start_row;
    int current_col = start_col;
    int steps = 0;

    while (current_row!= end_row || current_col!= end_col) {
        int next_row = current_row + (current_col - start_col) / (end_col - start_col);
        int next_col = current_col - (current_row - start_row) / (end_row - start_row);
        if (next_row < 0 || next_row >= maze->rows || next_col < 0 || next_col >= maze->cols) {
            current_row--;
            current_col++;
        } else {
            current_row = next_row;
            current_col = next_col;
        }
        steps++;
    }
    printf("Steps: %d\n", steps);

    for (int i = 0; i < maze->rows * maze->cols; i++) {
        route[i] = 0;
    }
    route[start_row * maze->cols + start_col] = 1;
    for (int i = 0; i < steps; i++) {
        int row = current_row / maze->cols;
        int col = current_col / maze->cols;
        if (route[row * maze->cols + col + 1] == 0) {
            route[row * maze->cols + col + 1] = 1;
            current_row++;
            current_col = 0;
        } else {
            current_row--;
            current_col++;
        }
    }

    // Print the route
    printf("Route:\n");
    for (int i = 0; i < maze->rows * maze->cols; i++) {
        if (i % maze->cols == 0 && i > 0) {
            printf("\n");
        }
        printf("%c", maze->cells[i / maze->cols][i % maze->cols]);
    }
    printf("\n");

    // Free memory
    for (int i = 0; i < maze->rows; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);

    return 0;
}