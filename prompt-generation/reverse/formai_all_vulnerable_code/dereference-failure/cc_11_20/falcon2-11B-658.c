//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct maze {
    int size;
    int **maze;
} Maze;

Maze *create_maze(int size) {
    Maze *maze = malloc(sizeof(Maze));
    maze->size = size;
    maze->maze = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        maze->maze[i] = malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            maze->maze[i][j] = 0;
        }
    }
    return maze;
}

void destroy_maze(Maze *maze) {
    for (int i = 0; i < maze->size; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

int main() {
    Maze *maze = create_maze(5);

    maze->maze[0][0] = 1;
    maze->maze[0][1] = 1;
    maze->maze[0][2] = 1;
    maze->maze[0][3] = 1;
    maze->maze[0][4] = 1;

    maze->maze[1][0] = 1;
    maze->maze[1][1] = 0;
    maze->maze[1][2] = 0;
    maze->maze[1][3] = 0;
    maze->maze[1][4] = 1;

    maze->maze[2][0] = 0;
    maze->maze[2][1] = 1;
    maze->maze[2][2] = 1;
    maze->maze[2][3] = 1;
    maze->maze[2][4] = 0;

    maze->maze[3][0] = 0;
    maze->maze[3][1] = 1;
    maze->maze[3][2] = 0;
    maze->maze[3][3] = 1;
    maze->maze[3][4] = 1;

    maze->maze[4][0] = 0;
    maze->maze[4][1] = 0;
    maze->maze[4][2] = 1;
    maze->maze[4][3] = 0;
    maze->maze[4][4] = 1;

    printf("Maze:\n");
    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            printf("%d ", maze->maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int start = 0;
    int goal = 4;

    printf("Start at (%d, %d), goal at (%d, %d)\n", start, 0, goal, 0);

    Maze *visited = create_maze(maze->size * 2 + 1);

    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            visited->maze[i * 2][j * 2] = -1;
        }
    }

    visited->maze[start * 2][goal * 2] = 0;

    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            if (maze->maze[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + (k == 0? 1 : 0);
                    int nj = j + (k == 1? 1 : 0);
                    if (ni >= 0 && ni < maze->size && nj >= 0 && nj < maze->size && maze->maze[ni][nj] == 0 && visited->maze[ni * 2][nj * 2] == -1) {
                        visited->maze[ni * 2][nj * 2] = 1;
                        int ni_2 = ni + (k == 0? 1 : 0);
                        int nj_2 = nj + (k == 1? 1 : 0);
                        if (ni_2 >= 0 && ni_2 < maze->size && nj_2 >= 0 && nj_2 < maze->size && maze->maze[ni_2][nj_2] == 0 && visited->maze[ni_2 * 2][nj_2 * 2] == -1) {
                            visited->maze[ni_2 * 2][nj_2 * 2] = 2;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < maze->size * 2 + 1; i++) {
        for (int j = 0; j < maze->size * 2 + 1; j++) {
            if (visited->maze[i][j] == 0) {
                printf("%d ", 1);
            } else if (visited->maze[i][j] == 1) {
                printf("%d ", 2);
            } else {
                printf("%d ", 3);
            }
        }
        printf("\n");
    }
    printf("\n");

    destroy_maze(maze);
    destroy_maze(visited);

    return 0;
}