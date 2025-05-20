//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WALL '1'
#define EMPTY '0'

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate start;
    Coordinate end;
    char** maze;
    int mazeSize;
    int currentStep;
    int totalSteps;
} Maze;

void initMaze(Maze* maze, int mazeSize, Coordinate start, Coordinate end) {
    maze->start = start;
    maze->end = end;
    maze->mazeSize = mazeSize;
    maze->currentStep = 0;
    maze->totalSteps = 0;
    maze->maze = (char**)malloc(mazeSize * sizeof(char*));
    for (int i = 0; i < mazeSize; i++) {
        maze->maze[i] = (char*)malloc(mazeSize * sizeof(char));
    }
}

void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->mazeSize; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
}

void printMaze(Maze* maze) {
    for (int i = 0; i < maze->mazeSize; i++) {
        for (int j = 0; j < maze->mazeSize; j++) {
            printf("%c ", maze->maze[i][j]);
        }
        printf("\n");
    }
}

void printPath(Maze* maze) {
    for (int i = 0; i < maze->mazeSize; i++) {
        for (int j = 0; j < maze->mazeSize; j++) {
            if (maze->maze[i][j] == WALL) {
                printf("%c ", 'X');
            } else if (maze->maze[i][j] == EMPTY) {
                printf("%c ", 'O');
            }
        }
        printf("\n");
    }
}

bool isInMaze(Maze* maze, Coordinate coord) {
    return coord.x >= 0 && coord.x < maze->mazeSize && coord.y >= 0 && coord.y < maze->mazeSize;
}

bool isWall(Maze* maze, Coordinate coord) {
    return maze->maze[coord.x][coord.y] == WALL;
}

bool isEmpty(Maze* maze, Coordinate coord) {
    return maze->maze[coord.x][coord.y] == EMPTY;
}

bool isEnd(Maze* maze, Coordinate coord) {
    return coord.x == maze->end.x && coord.y == maze->end.y;
}

void setMaze(Maze* maze, Coordinate coord, char value) {
    maze->maze[coord.x][coord.y] = value;
}

Coordinate getNeighbor(Maze* maze, Coordinate coord, int direction) {
    Coordinate neighbor = coord;
    switch (direction) {
        case 0:
            neighbor.x--;
            break;
        case 1:
            neighbor.x++;
            break;
        case 2:
            neighbor.y--;
            break;
        case 3:
            neighbor.y++;
            break;
    }
    return neighbor;
}

void findPath(Maze* maze, Coordinate coord, int direction) {
    Coordinate neighbor = getNeighbor(maze, coord, direction);
    if (isInMaze(maze, neighbor) && isEmpty(maze, neighbor)) {
        setMaze(maze, neighbor, 'O');
        maze->currentStep++;
        if (isEnd(maze, neighbor)) {
            maze->totalSteps = maze->currentStep;
            return;
        }
        findPath(maze, neighbor, direction);
    }
}

int main() {
    int mazeSize = 5;
    Coordinate start = {0, 0};
    Coordinate end = {mazeSize - 1, mazeSize - 1};
    Maze maze;
    initMaze(&maze, mazeSize, start, end);
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            maze.maze[i][j] = (i == 0 || i == mazeSize - 1 || j == 0 || j == mazeSize - 1) ? WALL : EMPTY;
        }
    }
    printMaze(&maze);
    findPath(&maze, start, 0);
    printf("Total steps: %d\n", maze.totalSteps);
    printPath(&maze);
    freeMaze(&maze);
    return 0;
}