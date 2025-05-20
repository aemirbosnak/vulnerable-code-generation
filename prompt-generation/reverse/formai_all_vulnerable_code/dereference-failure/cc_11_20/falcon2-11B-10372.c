//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_maze(int maze[][100], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int **maze = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        maze[i] = (int *)malloc(width * sizeof(int));
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = rand() % 2;
            if (i == 0 && j == 0) {
                start = i;
                end = j;
            } else if (i == height - 1 && j == width - 1) {
                start = i;
                end = j;
            } else if (i == 0 && j == width - 1) {
                start = i;
                end = j;
            } else if (i == height - 1 && j == 0) {
                start = i;
                end = j;
            }
        }
    }
    int visited[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            visited[i][j] = 0;
        }
    }
    int curr_row = start;
    int curr_col = end;
    int count = 0;
    while (1) {
        int new_row = curr_row + 1;
        int new_col = curr_col;
        if (new_row >= height || new_col >= width) {
            break;
        } else if (maze[new_row][new_col] == 0) {
            maze[curr_row][curr_col] = 0;
            maze[new_row][new_col] = 1;
            curr_row = new_row;
            curr_col = new_col;
            visited[curr_row][curr_col] = 1;
            count++;
        } else if (maze[curr_row][curr_col] == 1) {
            maze[curr_row][curr_col] = 0;
            maze[new_row][new_col] = 1;
            curr_row = new_row;
            curr_col = new_col;
            visited[curr_row][curr_col] = 1;
            count++;
        } else {
            maze[curr_row][curr_col] = 0;
            maze[new_row][new_col] = 1;
            curr_row = new_row;
            curr_col = new_col;
            visited[curr_row][curr_col] = 1;
            count++;
        }
    }
    print_maze(maze, width, height);
    printf("\nNumber of steps: %d\n", count);
    free(maze);
    return 0;
}