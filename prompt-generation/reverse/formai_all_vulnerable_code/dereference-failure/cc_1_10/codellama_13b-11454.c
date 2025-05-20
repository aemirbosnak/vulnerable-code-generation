//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 10

void generateMaze(int maze[M][N]) {
    // Set all cells to 0
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            maze[i][j] = 0;
        }
    }

    // Generate the maze using a randomized algorithm
    int x = M / 2;
    int y = N / 2;
    int direction = rand() % 4;
    while (x > 0 && y > 0) {
        switch (direction) {
            case 0: // Up
                x--;
                break;
            case 1: // Right
                y++;
                break;
            case 2: // Down
                x++;
                break;
            case 3: // Left
                y--;
                break;
        }

        maze[x][y] = 1;
        direction = rand() % 4;
    }
}

int main() {
    srand(time(NULL));

    int maze[M][N];
    generateMaze(maze);

    // Print the maze
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }

    return 0;
}