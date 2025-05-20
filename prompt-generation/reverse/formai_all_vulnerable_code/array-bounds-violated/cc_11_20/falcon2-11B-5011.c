//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

Point start, end;
Point walls[MAX_WIDTH * MAX_HEIGHT];
int num_walls;

void create_maze() {
    srand(time(NULL));

    // Start and end points
    start.x = 10;
    start.y = 10;
    end.x = 15;
    end.y = 15;

    // Generate walls
    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
        walls[i].x = rand() % MAX_WIDTH;
        walls[i].y = rand() % MAX_HEIGHT;
        if (walls[i].x == start.x && walls[i].y == start.y) {
            start.x = rand() % MAX_WIDTH;
            start.y = rand() % MAX_HEIGHT;
        }
        if (walls[i].x == end.x && walls[i].y == end.y) {
            end.x = rand() % MAX_WIDTH;
            end.y = rand() % MAX_HEIGHT;
        }
        if (walls[i].x == start.x || walls[i].y == start.y) {
            walls[i].x = rand() % MAX_WIDTH;
            walls[i].y = rand() % MAX_HEIGHT;
        }
        if (walls[i].x == end.x || walls[i].y == end.y) {
            walls[i].x = rand() % MAX_WIDTH;
            walls[i].y = rand() % MAX_HEIGHT;
        }
        if (walls[i].x == walls[i - 1].x && walls[i].y == walls[i - 1].y) {
            walls[i].x = rand() % MAX_WIDTH;
            walls[i].y = rand() % MAX_HEIGHT;
        }
        if (walls[i].x == walls[i + 1].x && walls[i].y == walls[i + 1].y) {
            walls[i].x = rand() % MAX_WIDTH;
            walls[i].y = rand() % MAX_HEIGHT;
        }
        if (walls[i].x == walls[i - MAX_WIDTH].x && walls[i].y == walls[i - MAX_WIDTH].y) {
            walls[i].x = rand() % MAX_WIDTH;
            walls[i].y = rand() % MAX_HEIGHT;
        }
        if (walls[i].x == walls[i + MAX_WIDTH].x && walls[i].y == walls[i + MAX_WIDTH].y) {
            walls[i].x = rand() % MAX_WIDTH;
            walls[i].y = rand() % MAX_HEIGHT;
        }
    }

    num_walls = MAX_WIDTH * MAX_HEIGHT;
    printf("Generated maze with %d walls\n", num_walls);

    // Print maze
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (walls[i * MAX_WIDTH + j].x == j && walls[i * MAX_WIDTH + j].y == i) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    create_maze();

    return 0;
}