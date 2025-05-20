//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

int maze[MAX_SIZE][MAX_SIZE];
int width, height;

void generateMaze() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 1;
        }
    }

    int currentRow = rand() % height;
    int currentCol = rand() % width;

    while (true) {
        int direction = rand() % 4;

        switch (direction) {
            case 0: // up
                if (currentRow > 0 && maze[currentRow - 1][currentCol] == 1) {
                    maze[currentRow][currentCol] = 0;
                    maze[currentRow - 1][currentCol] = 0;
                    currentRow--;
                }
                break;
            case 1: // down
                if (currentRow < height - 1 && maze[currentRow + 1][currentCol] == 1) {
                    maze[currentRow][currentCol] = 0;
                    maze[currentRow + 1][currentCol] = 0;
                    currentRow++;
                }
                break;
            case 2: // left
                if (currentCol > 0 && maze[currentRow][currentCol - 1] == 1) {
                    maze[currentRow][currentCol] = 0;
                    maze[currentRow][currentCol - 1] = 0;
                    currentCol--;
                }
                break;
            case 3: // right
                if (currentCol < width - 1 && maze[currentRow][currentCol + 1] == 1) {
                    maze[currentRow][currentCol] = 0;
                    maze[currentRow][currentCol + 1] = 0;
                    currentCol++;
                }
                break;
        }

        int numWallsRemaining = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (maze[i][j] == 1) {
                    numWallsRemaining++;
                }
            }
        }

        if (numWallsRemaining == 0) {
            break;
        }
    }
}

void printMaze() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the width of the maze: ");
    scanf("%d", &width);

    printf("Enter the height of the maze: ");
    scanf("%d", &height);

    generateMaze();
    printMaze();

    return 0;
}