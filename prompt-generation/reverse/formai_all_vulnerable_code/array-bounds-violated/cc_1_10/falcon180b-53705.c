//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int maze[HEIGHT][WIDTH];

void init_maze()
{
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
}

void generate_maze()
{
    int x, y, dir;
    int count = 0;

    srand(time(NULL));
    dir = rand() % 4;
    x = rand() % HEIGHT;
    y = rand() % WIDTH;

    while (count < 100000) {
        int nx, ny;

        switch (dir) {
        case 0: ny = y - 1; break;
        case 1: ny = y + 1; break;
        case 2: nx = x - 1; break;
        case 3: nx = x + 1; break;
        }

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[ny][nx] == 1) {
            maze[y][x] = 0;
            maze[ny][nx] = 0;
            x = nx;
            y = ny;
        } else {
            dir = rand() % 4;
            x = rand() % HEIGHT;
            y = rand() % WIDTH;
        }

        count++;
    }
}

void print_maze()
{
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    init_maze();
    generate_maze();
    print_maze();

    return 0;
}