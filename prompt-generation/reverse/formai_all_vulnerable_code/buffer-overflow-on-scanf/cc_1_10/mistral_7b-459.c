//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 25
#define HEIGHT 15

typedef struct {
    float x, y;
} point;

typedef struct {
    point pos;
    int haunted;
} cell;

cell grid[WIDTH][HEIGHT];

void init() {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].pos.x = i;
            grid[i][j].pos.y = j;
            grid[i][j].haunted = 0;
        }
    }
}

point randomPoint() {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    return (point){(float)x, (float)y};
}

void haunt(point p) {
    int x = (int)p.x;
    int y = (int)p.y;
    grid[x][y].haunted = 1;
}

void printGrid() {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c", grid[i][j].haunted ? '#' : '.');
        }
        printf("\n");
    }
}

void simulate(int numScares) {
    int i, j;
    point p;

    srand(time(NULL));

    for (i = 0; i < numScares; i++) {
        p = randomPoint();
        haunt(p);
        printf("Scare at (%f, %f)\n", p.x, p.y);
    }

    printGrid();
}

int main() {
    int numScares;

    scanf("%d", &numScares);

    init();
    simulate(numScares);

    return 0;
}