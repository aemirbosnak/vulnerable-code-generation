//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generateMaze(int** maze, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            maze[i][j] = 1;
        }
    }
    int startX = rand() % height;
    int startY = rand() % width;
    maze[startX][startY] = 0;
    Point current = {startX, startY};
    while (1) {
        int directions[4] = {0, 1, 0, -1};
        int randomDirection = rand() % 4;
        int newX = current.x + directions[randomDirection];
        int newY = current.y + directions[randomDirection + 1];
        if (newX >= 0 && newX < height && newY >= 0 && newY < width && maze[newX][newY] == 1) {
            maze[current.x][current.y] &= ~(1 << randomDirection);
            maze[newX][newY] &= ~(1 << (randomDirection + 1));
            current.x = newX;
            current.y = newY;
        } else {
            break;
        }
    }
}

void printMaze(int** maze, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (maze[i][j] & 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int width, height;
    printf("Enter the width of the maze: ");
    scanf("%d", &width);
    printf("Enter the height of the maze: ");
    scanf("%d", &height);
    int** maze = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        maze[i] = (int*)malloc(width * sizeof(int));
    }
    generateMaze(maze, width, height);
    printMaze(maze, width, height);
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}