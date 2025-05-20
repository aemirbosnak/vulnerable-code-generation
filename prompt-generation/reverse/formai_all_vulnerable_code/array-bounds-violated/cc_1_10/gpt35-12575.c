//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

int is_valid(int row, int col, int maze[ROW][COL], int visited[ROW][COL])
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && maze[row][col] && !visited[row][col];
}

void pathfinding(int maze[ROW][COL], int start_row, int start_col, int end_row, int end_col)
{
    int row_move[] = {-1, 0, 0, 1};
    int col_move[] = {0, -1, 1, 0};
    int visited[ROW][COL];
    int distances[ROW][COL];

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            visited[row][col] = 0;
            distances[row][col] = INT_MAX;
        }
    }

    visited[start_row][start_col] = 1;
    distances[start_row][start_col] = 0;

    for (int i = 0; i < ROW*COL-1; i++) {
        int min_distance = INT_MAX;
        int current_row, current_col;

        for (int row = 0; row < ROW; row++) {
            for (int col = 0; col < COL; col++) {
                if (visited[row][col] == 0 && distances[row][col] < min_distance) {
                    min_distance = distances[row][col];
                    current_row = row;
                    current_col = col;
                }
            }
        }

        visited[current_row][current_col] = 1;

        for (int j = 0; j < 4; j++) {
            int new_row = current_row + row_move[j];
            int new_col = current_col + col_move[j];

            if (is_valid(new_row, new_col, maze, visited)) {
                distances[new_row][new_col] = distances[current_row][current_col] + 1;
            }
        }
    }

    printf("The shortest distance between (%d, %d) and (%d, %d) is %d", start_row, start_col, end_row, end_col, distances[end_row][end_col]);
}

int main()
{
    int maze[ROW][COL] = {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1}
    };
    
    pathfinding(maze, 0, 0, 4, 4);

    return 0;
}