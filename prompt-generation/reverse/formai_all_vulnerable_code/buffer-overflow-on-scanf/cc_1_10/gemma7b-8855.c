//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(int** maze, int n, int m) {
    for (int i = 0; i < n; i++) {
        maze[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            maze[i][j] = 0;
        }
    }
}

void printMaze(int** maze, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int** maze = NULL;
    createMaze(maze, n, m);

    printf("Enter the maze layout (1 for wall, 0 for free):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printMaze(maze, n, m);

    return 0;
}