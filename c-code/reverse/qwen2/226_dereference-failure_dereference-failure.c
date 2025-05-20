#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void generateMaze(int** maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze(int** maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int** maze = (int**)malloc(HEIGHT * sizeof(int*));
    if (maze == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = (int*)malloc(WIDTH * sizeof(int));
        if (maze[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(maze[j]);
            }
            free(maze);
            return 1;
        }
    }

    generateMaze(maze);
    printMaze(maze);

    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);

    // Intentional vulnerability: Dereferencing an out-of-bounds pointer
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 42;
        free(ptr);
    } else {
        fprintf(stderr, "Memory allocation failed\n");
    }

    // Vulnerability: Using freed memory
    printf("Value at freed memory: %d\n", *ptr); // Undefined behavior

    return 0;
}
