//Falcon-180B DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int rows, cols;
    int board[MAX_ROWS][MAX_COLS];
    int i, j, value;
    int start_row, start_col;
    int end_row, end_col;
    int path_length;
    int path[MAX_ROWS][MAX_COLS];

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            value = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
            board[i][j] = value;
        }
    }

    printf("Maze:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    start_row = rand() % rows;
    start_col = rand() % cols;
    end_row = rand() % rows;
    end_col = rand() % cols;

    path_length = 0;
    path[0][0] = start_row;
    path[0][1] = start_col;

    while (path_length < rows * cols) {
        int dx = 0;
        int dy = 0;

        if (path[path_length][0] > end_row)
            dy = -1;
        else if (path[path_length][0] < end_row)
            dy = 1;

        if (path[path_length][1] > end_col)
            dx = -1;
        else if (path[path_length][1] < end_col)
            dx = 1;

        path[path_length + 1][0] = path[path_length][0] + dy;
        path[path_length + 1][1] = path[path_length][1] + dx;

        path_length++;
    }

    printf("Path:\n");
    for (i = 0; i < path_length; i++) {
        printf("%d %d\n", path[i][0], path[i][1]);
    }

    return 0;
}