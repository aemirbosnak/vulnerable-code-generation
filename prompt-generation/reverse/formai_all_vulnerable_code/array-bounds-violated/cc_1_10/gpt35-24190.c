//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: random
#include <stdio.h>

#define ROW_SIZE 10
#define COLUMN_SIZE 10

int start[2] = {2, 2};
int destination[2] = {7, 8};

int heuristic(int current[2]) {
    return abs(destination[0] - current[0]) + abs(destination[1] - current[1]);
}

int main() {
    int grid[ROW_SIZE][COLUMN_SIZE];
    int visited[ROW_SIZE][COLUMN_SIZE];

    // Initialize the grid
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {            
            grid[i][j] = rand() % 2; // randomly assign obstacles in the grid
            visited[i][j] = 0;
            printf("%d ", grid[i][j]); // print the grid for visualization purposes
        }
        printf("\n");
    }

    printf("\n");

    // Implement the A* Pathfinding Algorithm
    int current[2] = {start[0], start[1]};
    visited[start[0]][start[1]] = 1;

    while(current[0] != destination[0] || current[1] != destination[1]) {
        int min_fscore = -1;
        int next[2];
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int neighbor[2] = {current[0]+i, current[1]+j};
                if (neighbor[0] < 0 || neighbor[0] >= ROW_SIZE || neighbor[1] < 0 || neighbor[1] >= COLUMN_SIZE) {
                    continue;
                }
                if (grid[neighbor[0]][neighbor[1]] == 1) {
                    continue;
                }
                if (visited[neighbor[0]][neighbor[1]] == 1) {
                    continue;
                }
                int g_score = heuristic(current) + heuristic(neighbor); // g_score and heuristic values are equal for this implementation
                int f_score = g_score + heuristic(neighbor);
                if (min_fscore == -1 || f_score < min_fscore) {
                    min_fscore = f_score;
                    next[0] = neighbor[0];
                    next[1] = neighbor[1];
                }
            }
        }
        printf("Moving to location (%d,%d)\n", next[0], next[1]);
        current[0] = next[0];
        current[1] = next[1];
        visited[current[0]][current[1]] = 1;
    }

    printf("\nReached destination at (%d,%d)!\n", current[0], current[1]);

    return 0;
}