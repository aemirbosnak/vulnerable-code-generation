//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
// A Maze Route Finder program in a puzzling style

#include <stdio.h>

#define N 100 // size of the maze

int maze[N][N]; // 2D array to represent the maze
int visited[N][N]; // 2D array to keep track of visited cells
int current[2]; // current position of the robot
int destination[2]; // destination position of the robot

void printMaze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void readMaze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
}

void setVisited(int x, int y) {
    visited[x][y] = 1;
}

void setCurrent(int x, int y) {
    current[0] = x;
    current[1] = y;
}

void setDestination(int x, int y) {
    destination[0] = x;
    destination[1] = y;
}

void move(int direction) {
    int newX = current[0] + (direction == 0 ? 1 : 0);
    int newY = current[1] + (direction == 1 ? 1 : 0);
    if (newX >= 0 && newX < N && newY >= 0 && newY < N && maze[newX][newY] == 0 && !visited[newX][newY]) {
        setCurrent(newX, newY);
        setVisited(newX, newY);
    }
}

void findRoute() {
    while (current[0] != destination[0] || current[1] != destination[1]) {
        move(0);
        move(1);
    }
}

int main() {
    readMaze();
    printMaze();
    setCurrent(0, 0);
    setDestination(N - 1, N - 1);
    findRoute();
    printf("Route: ");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) {
                printf("%d ", visited[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}