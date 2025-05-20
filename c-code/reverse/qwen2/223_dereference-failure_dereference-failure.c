#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void generateMaze(char **maze, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            maze[i][j] = rand() % 2 ? '#' : ' ';
        }
    }
}

void printMaze(char **maze, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    char **maze = (char **)malloc(SIZE * sizeof(char *));
    for (int i = 0; i < SIZE; i++) {
        maze[i] = (char *)malloc(SIZE * sizeof(char));
    }

    generateMaze(maze, SIZE);
    printMaze(maze, SIZE);

    for (int i = 0; i < SIZE; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
