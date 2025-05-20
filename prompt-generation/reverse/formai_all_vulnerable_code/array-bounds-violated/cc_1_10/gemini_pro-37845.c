//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int nrows=60, ncols=100;
typedef enum { N, S, E, W } Direction;
typedef struct {
    int row, col;
    Direction dir;
} Position;

Position start = {1,1,E};
Position current = {1,1,E};
int map[50][50];
int visited[50][50];

// Declare all the functions
void drawMaze();
Position getNewPosition();
void setVisited(Position);
void populateMap();
Direction getDirection(Position);

int main() {
    srand(time(NULL));
    drawMaze();
    populateMap();
    while (1) { // Keep looping until user quits
        Position next = getNewPosition();
        if (next.row == -1) { // Exit condition
            break;
        }
        map[current.row][current.col] = 1;
        setVisited(current);
        current = next;
    }
    return 0;
}

void drawMaze() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printf("%c", (map[i][j] == 1) ? '#' : ' ');
        }
        printf("\n");
    }
}

Position getNewPosition() {
    int direction = rand() % 4;
    Position next = current;
    switch (direction) {
        case N:
            next.row--;
            break;
        case S:
            next.row++;
            break;
        case E:
            next.col++;
            break;
        case W:
            next.col--;
            break;
    }

    if (next.row < 1 || next.row >= nrows || next.col < 1 || next.col >= ncols || visited[next.row][next.col]) { // Out of bounds or already visited
        return (Position){-1, -1, N};
    }
    return next;
}

void setVisited(Position p) {
    visited[p.row][p.col] = 1;
}

void populateMap() {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

Direction getDirection(Position p) {
    if (p.dir == N) {
        return S;
    } else if (p.dir == S) {
        return N;
    } else if (p.dir == E) {
        return W;
    } else {
        return E;
    }
}