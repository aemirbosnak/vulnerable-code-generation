//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10

int maze[WIDTH][HEIGHT];

void generate_maze(int maze[WIDTH][HEIGHT]) {
    srand(time(NULL));
    bool visited[WIDTH][HEIGHT] = {false};
    int start_x = rand() % WIDTH;
    int start_y = rand() % HEIGHT;
    visited[start_x][start_y] = true;

    int x = start_x;
    int y = start_y;
    int direction = rand() % 4;

    while (true) {
        int next_x = x + (direction % 2) * 2 - 1;
        int next_y = y + (direction / 2) * 2 - 1;

        if (next_x < 0 || next_x >= WIDTH || next_y < 0 || next_y >= HEIGHT) {
            direction = (direction + 1) % 4;
            next_x = x + (direction % 2) * 2 - 1;
            next_y = y + (direction / 2) * 2 - 1;
        }

        if (visited[next_x][next_y]) {
            maze[x][y] = 1;
            visited[x][y] = true;
            x = next_x;
            y = next_y;
        } else {
            maze[x][y] = 0;
            visited[x][y] = true;
            x = next_x;
            y = next_y;
        }
    }
}

int main() {
    generate_maze(maze);

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}