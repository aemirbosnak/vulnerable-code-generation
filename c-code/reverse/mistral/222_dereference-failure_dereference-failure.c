#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

void generateMaze(int **maze);
void printMaze(int **maze);

int main() {
    srand(time(NULL));
    int *maze = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(int **maze) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y * WIDTH + x] = (rand() % 2);
            if (x > 0 && maze[(y * WIDTH) + (x - 1)] == 0) {
                maze[y * WIDTH + x] = 1;
                if (x < WIDTH - 1 && rand() % 2)
                    maze[(y * WIDTH) + (x + 1)] = 1;
            }
            if (y > 0 && maze[(y - 1) * WIDTH + x] == 0) {
                maze[y * WIDTH + x] = 1;
                if (y < HEIGHT - 1 && rand() % 2)
                    maze[(y + 1) * WIDTH + x] = 1;
            }
        }
    }
}

void printMaze(int **maze) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", maze[y * WIDTH + x]);
        }
        printf("\n");
    }
}
