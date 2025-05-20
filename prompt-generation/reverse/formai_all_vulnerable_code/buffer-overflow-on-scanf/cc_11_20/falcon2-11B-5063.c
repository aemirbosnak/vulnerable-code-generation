//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define DIR_UP 0
#define DIR_RIGHT 1
#define DIR_DOWN 2
#define DIR_LEFT 3

void generate_maze(int maze[MAX_SIZE][MAX_SIZE], int size) {
    int rows = size;
    int cols = size;
    int visited[MAX_SIZE][MAX_SIZE] = {0};
    int i, j, start_row, start_col, current_row, current_col;
    int direction = 0;

    start_row = rand() % rows;
    start_col = rand() % cols;
    visited[start_row][start_col] = 1;

    current_row = start_row;
    current_col = start_col;

    while (visited[current_row][current_col]!= 1) {
        for (i = 0; i < 4; i++) {
            int next_row = current_row + DIR_UP * (i + 1);
            int next_col = current_col + DIR_RIGHT * (i + 1);

            if (next_row >= rows || next_row < 0 || next_col >= cols || next_col < 0 || visited[next_row][next_col] == 1) {
                continue;
            }

            if (i == 0 && direction == DIR_UP) {
                direction = DIR_RIGHT;
                current_col = next_col;
            } else if (i == 0 && direction == DIR_RIGHT) {
                direction = DIR_DOWN;
                current_row = next_row;
            } else if (i == 0 && direction == DIR_DOWN) {
                direction = DIR_LEFT;
                current_col = next_col;
            } else if (i == 0 && direction == DIR_LEFT) {
                direction = DIR_UP;
                current_row = next_row;
            } else if (i == 3 && direction == DIR_UP) {
                direction = DIR_LEFT;
                current_col = next_col;
            } else if (i == 3 && direction == DIR_LEFT) {
                direction = DIR_DOWN;
                current_row = next_row;
            } else if (i == 3 && direction == DIR_DOWN) {
                direction = DIR_RIGHT;
                current_col = next_col;
            } else if (i == 3 && direction == DIR_RIGHT) {
                direction = DIR_UP;
                current_row = next_row;
            }

            visited[next_row][next_col] = 1;
        }

        direction = (direction + 1) % 4;
        current_row = current_row + DIR_UP * (direction == DIR_UP? 1 : -1);
        current_col = current_col + DIR_RIGHT * (direction == DIR_RIGHT? 1 : -1);
    }
}

int main() {
    int maze[MAX_SIZE][MAX_SIZE];
    int size;

    printf("Enter the size of the maze (10-99): ");
    scanf("%d", &size);

    if (size < 10 || size > 99) {
        printf("Invalid size. Exiting...\n");
        return 1;
    }

    generate_maze(maze, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maze[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}