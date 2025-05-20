#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void printMaze(int maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int *maze = (int *)malloc(SIZE * SIZE * sizeof(int));
    if (!maze) return 1;

    srand(time(0));
    for (int i = 0; i < SIZE * SIZE; i++) {
        maze[i] = rand() % 2;
    }

    printMaze((int (*)[SIZE])maze);

    free(maze);
    return 0;
}
