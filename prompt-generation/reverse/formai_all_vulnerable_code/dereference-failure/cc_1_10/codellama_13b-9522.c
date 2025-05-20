//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
// Procedurally Generated Maze Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_ROWS 5
#define MIN_COLS 5
#define MAX_ROWS 15
#define MAX_COLS 30
#define MAX_ITERATIONS 10000
#define WALL '#'
#define SPACE ' '
#define PATH '.'

typedef struct {
    int row;
    int col;
} Point;

void init_maze(int rows, int cols, char maze[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = WALL;
        }
    }
}

void generate_maze(int rows, int cols, char maze[rows][cols]) {
    srand(time(NULL));
    Point start = {0, 0};
    Point current = {0, 0};
    Point neighbors[4];
    int n = 0;
    bool visited[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }
    visited[start.row][start.col] = true;
    maze[start.row][start.col] = SPACE;
    while (n < MAX_ITERATIONS) {
        current = neighbors[rand() % 4];
        if (current.row >= 0 && current.row < rows && current.col >= 0 && current.col < cols && !visited[current.row][current.col]) {
            visited[current.row][current.col] = true;
            if (current.row == rows - 1 && current.col == cols - 1) {
                break;
            }
            neighbors[0] = (Point){current.row - 1, current.col};
            neighbors[1] = (Point){current.row + 1, current.col};
            neighbors[2] = (Point){current.row, current.col - 1};
            neighbors[3] = (Point){current.row, current.col + 1};
            n++;
            maze[current.row][current.col] = SPACE;
        }
    }
}

void print_maze(int rows, int cols, char maze[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = MIN_ROWS + rand() % (MAX_ROWS - MIN_ROWS + 1);
    int cols = MIN_COLS + rand() % (MAX_COLS - MIN_COLS + 1);
    char maze[rows][cols];
    init_maze(rows, cols, maze);
    generate_maze(rows, cols, maze);
    print_maze(rows, cols, maze);
    return 0;
}