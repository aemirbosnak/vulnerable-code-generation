#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void generateMaze(char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = (rand() % 2) ? '#' : ' ';
        }
    }
}

void printMaze(const char maze[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char maze[SIZE][SIZE];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}
