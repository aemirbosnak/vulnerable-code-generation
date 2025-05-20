//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdlib.h>
#include <stdio.h>

#define ROWS 51
#define COLS 101
#define WALL '#'
#define PASSAGE ' '

typedef struct cell {
    int row;
    int col;
    int walls;
} cell;

void shuffle(int *array, int len) {
    int i, j, tmp;
    for (i = 0; i < len - 1; i++) {
        j = rand() % (len - i) + i;
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

int **create_maze() {
    int **maze = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        maze[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    int directions[] = {0, 1, 2, 3};
    int stack[ROWS * COLS];
    int stack_top = 0;

    cell start = {1, 1, 0xF};
    stack[stack_top++] = start.row * COLS + start.col;

    while (stack_top > 0) {
        cell current = {stack[--stack_top] / COLS, stack[stack_top] % COLS, 0xF};

        shuffle(directions, 4);

        for (int i = 0; i < 4; i++) {
            int next_row = current.row + (directions[i] % 2) * (1 - 2 * (directions[i] / 2));
            int next_col = current.col + ((directions[i] + 1) % 2) * (1 - 2 * (directions[i] % 2));

            if (next_row < 1 || next_row >= ROWS - 1 || next_col < 1 || next_col >= COLS - 1 || maze[next_row][next_col] != WALL) {
                continue;
            }

            maze[current.row][current.col] &= ~(1 << directions[i]);
            maze[next_row][next_col] &= ~(1 << ((directions[i] + 2) % 4));

            cell next = {next_row, next_col, 0xF};
            stack[stack_top++] = next.row * COLS + next.col;
        }
    }

    return maze;
}

void print_maze(int **maze) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] & 1) {
                printf("%c", WALL);
            } else {
                printf("%c", PASSAGE);
            }
        }
        printf("\n");
    }
}

int main() {
    char input;
    int **maze;

    while (1) {
        printf("Generate a new maze? (y/n): ");
        scanf(" %c", &input);

        if (input == 'y') {
            if (maze != NULL) {
                for (int i = 0; i < ROWS; i++) {
                    free(maze[i]);
                }
                free(maze);
            }

            maze = create_maze();
            print_maze(maze);
        } else if (input == 'n') {
            break;
        } else {
            printf("Invalid input\n");
        }
    }

    for (int i = 0; i < ROWS; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}