//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int start_row;
    int start_col;
    int end_row;
    int end_col;
} Coordinates;

typedef struct {
    Coordinates start;
    Coordinates end;
    char maze[MAX_ROWS][MAX_COLS];
} Maze;

typedef struct {
    Maze *maze;
    int *visited;
    int start_row;
    int start_col;
    int end_row;
    int end_col;
    int max_iterations;
    int current_iteration;
    int num_threads;
} AsyncMazeRouteFinder;

void *find_route(void *data) {
    AsyncMazeRouteFinder *amrf = (AsyncMazeRouteFinder *)data;
    int *visited = amrf->visited;
    int max_iterations = amrf->max_iterations;
    int current_iteration = amrf->current_iteration;
    int num_threads = amrf->num_threads;
    for (int i = 0; i < num_threads; i++) {
        int thread_index = i + 1;
        int start_row = amrf->start_row + thread_index % (amrf->end_row - amrf->start_row);
        int start_col = amrf->start_col + thread_index / (amrf->end_row - amrf->start_row);
        int end_row = amrf->end_row + thread_index % (amrf->end_row - amrf->start_row);
        int end_col = amrf->end_col + thread_index / (amrf->end_row - amrf->start_row);

        if (start_row < 0 || start_row >= MAX_ROWS || start_col < 0 || start_col >= MAX_COLS) {
            continue;
        }
        if (end_row < 0 || end_row >= MAX_ROWS || end_col < 0 || end_col >= MAX_COLS) {
            continue;
        }
        if (visited[start_row * MAX_COLS + start_col]) {
            continue;
        }
        visited[start_row * MAX_COLS + start_col] = 1;
        amrf->current_iteration++;
        if (current_iteration == max_iterations) {
            break;
        }
        if (start_row == end_row && start_col == end_col) {
            printf("Route found: %d,%d\n", start_row, start_col);
            return NULL;
        }
        for (int row = -1; row < 2; row++) {
            for (int col = -1; col < 2; col++) {
                int new_row = start_row + row;
                int new_col = start_col + col;
                if (new_row < 0 || new_row >= MAX_ROWS || new_col < 0 || new_col >= MAX_COLS) {
                    continue;
                }
                if (visited[new_row * MAX_COLS + new_col]) {
                    continue;
                }
                if (amrf->maze->maze[new_row][new_col] == '*') {
                    continue;
                }
                visited[new_row * MAX_COLS + new_col] = 1;
                amrf->current_iteration++;
                if (amrf->current_iteration == max_iterations) {
                    break;
                }
                if (new_row == end_row && new_col == end_col) {
                    printf("Route found: %d,%d\n", new_row, new_col);
                    return NULL;
                }
            }
        }
    }
    return NULL;
}

int main() {
    Maze maze;
    Coordinates start, end;
    char maze_input[100][100];
    int visited[MAX_ROWS * MAX_COLS];

    printf("Enter maze rows and columns: ");
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%c", &maze_input[i][j]);
            if (maze_input[i][j] == '*') {
                start.start_row = i;
                start.start_col = j;
                end.start_row = i;
                end.start_col = j;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze_input[i][j] == '*') {
                end.end_row = i;
                end.end_col = j;
            }
        }
    }
    maze.start.start_row = start.start_row;
    maze.start.start_col = start.start_col;
    maze.end.start_row = end.start_row;
    maze.end.start_col = end.start_col;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze.maze[i][j] = maze_input[i][j];
        }
    }

    AsyncMazeRouteFinder amrf;
    amrf.maze = &maze;
    amrf.visited = visited;
    amrf.start_row = start.start_row;
    amrf.start_col = start.start_col;
    amrf.end_row = end.start_row;
    amrf.end_col = end.start_col;
    amrf.max_iterations = 1000;
    amrf.num_threads = 10;

    pthread_t threads[amrf.num_threads];
    for (int i = 0; i < amrf.num_threads; i++) {
        pthread_create(&threads[i], NULL, find_route, (void *)&amrf);
    }
    for (int i = 0; i < amrf.num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}