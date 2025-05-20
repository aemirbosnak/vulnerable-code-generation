#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 50

void createMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    srand(time(0));
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = rand() % 2 ? '#' : ' ';
        }
    }
}

void displayMaze(const char maze[MAZE_SIZE][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char *maze = malloc(MAZE_SIZE * MAZE_SIZE);
    if (maze == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    char mazeArray[MAZE_SIZE][MAZE_SIZE];
    createMaze(mazeArray);

    displayMaze(mazeArray);

    free(maze);
    return 0;
}
