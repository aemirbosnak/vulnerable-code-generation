//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

int maze[HEIGHT][WIDTH];
int start_x, start_y;
int end_x, end_y;

void create_maze() {
    int x, y;
    int count = 0;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            maze[y][x] = 1;
        }
    }

    srand(time(NULL));
    start_x = rand() % WIDTH;
    start_y = rand() % HEIGHT;
    end_x = rand() % WIDTH;
    end_y = rand() % HEIGHT;

    while (count < 50) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;

        if (dx == 0 && dy == 0)
            continue;

        int nx = start_x + dx;
        int ny = start_y + dy;

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[ny][nx] == 1) {
            maze[ny][nx] = 0;
            maze[ny + dy][nx + dx] = 0;
            count++;
        }
    }
}

void print_maze() {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (maze[y][x] == 1) {
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
    print_maze();

    return 0;
}