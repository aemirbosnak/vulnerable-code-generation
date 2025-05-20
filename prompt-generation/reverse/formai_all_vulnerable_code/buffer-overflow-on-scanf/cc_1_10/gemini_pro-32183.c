//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: minimalist
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct maze_cell {
    bool n, e, s, w;
} maze_cell;

maze_cell maze[MAX_SIZE][MAX_SIZE];
int size;

void generate_maze() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            maze[i][j].n = maze[i][j].e = maze[i][j].s = maze[i][j].w = true;
        }
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 2 == 0) {
                if (i > 0) {
                    maze[i][j].n = false;
                    maze[i - 1][j].s = false;
                }
            } else {
                if (j < size - 1) {
                    maze[i][j].e = false;
                    maze[i][j + 1].w = false;
                }
            }
        }
    }
}

void print_maze() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j].n) {
                printf("+---");
            } else {
                printf("+   ");
            }
        }
        printf("+\n");

        for (int j = 0; j < size; j++) {
            if (maze[i][j].w) {
                printf("|   ");
            } else {
                printf("    ");
            }
        }
        printf("|\n");
    }

    for (int j = 0; j < size; j++) {
        printf("+---");
    }
    printf("+\n");
}

int main() {
    printf("Enter the size of the maze: ");
    scanf("%d", &size);

    generate_maze();
    print_maze();

    return 0;
}