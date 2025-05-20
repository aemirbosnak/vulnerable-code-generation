//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int row;
    int col;
    bool visited;
} Node;

typedef struct {
    int num_rows;
    int num_cols;
    Node** matrix;
} Maze;

void init_maze(Maze* maze, int num_rows, int num_cols) {
    assert(num_rows >= 0 && num_cols >= 0);
    assert(num_rows <= MAX_ROWS && num_cols <= MAX_COLS);

    maze->num_rows = num_rows;
    maze->num_cols = num_cols;
    maze->matrix = (Node**)malloc(num_rows * sizeof(Node*));
    for (int i = 0; i < num_rows; i++) {
        maze->matrix[i] = (Node*)malloc(num_cols * sizeof(Node));
        for (int j = 0; j < num_cols; j++) {
            maze->matrix[i][j].row = i;
            maze->matrix[i][j].col = j;
            maze->matrix[i][j].visited = false;
        }
    }
}

void free_maze(Maze* maze) {
    free(maze->matrix);
    free(maze);
}

void print_maze(Maze* maze) {
    for (int i = 0; i < maze->num_rows; i++) {
        for (int j = 0; j < maze->num_cols; j++) {
            if (maze->matrix[i][j].visited) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void solve_maze(Maze* maze, Node* start, Node* end) {
    bool solved = false;
    while (!solved) {
        Node* current = start;
        solved = true;
        for (int i = 0; i < maze->num_rows; i++) {
            for (int j = 0; j < maze->num_cols; j++) {
                if (!maze->matrix[i][j].visited) {
                    maze->matrix[i][j].visited = true;
                    current->col = j;
                    current->row = i;
                    if (current == end) {
                        solved = false;
                        break;
                    }
                }
            }
            if (solved) {
                break;
            }
        }
    }
}

int main() {
    int num_rows, num_cols;
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    Maze maze;
    init_maze(&maze, num_rows, num_cols);

    printf("Enter the starting position (row, column): ");
    scanf("%d %d", &maze.matrix[0][0].row, &maze.matrix[0][0].col);

    printf("Enter the ending position (row, column): ");
    scanf("%d %d", &maze.matrix[num_rows - 1][num_cols - 1].row, &maze.matrix[num_rows - 1][num_cols - 1].col);

    solve_maze(&maze, &maze.matrix[0][0], &maze.matrix[num_rows - 1][num_cols - 1]);

    print_maze(&maze);

    free_maze(&maze);

    return 0;
}