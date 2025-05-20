//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

enum {
    OPEN = ' ',
    CLOSED = '#',
    PATH = '*',
    START = 'S',
    END = 'E',
};

struct point {
    int x;
    int y;
};

struct maze {
    char grid[ROWS][COLS];
    struct point start;
    struct point end;
};

struct stack {
    struct point *points;
    int size;
    int top;
};

struct stack *stack_create() {
    struct stack *stack = malloc(sizeof(struct stack));
    stack->points = malloc(sizeof(struct point) * 100);
    stack->size = 100;
    stack->top = -1;
    return stack;
}

void stack_push(struct stack *stack, struct point point) {
    if (stack->top == stack->size - 1) {
        stack->size *= 2;
        stack->points = 
            realloc(stack->points, sizeof(struct point) * stack->size);
    }
    stack->points[++stack->top] = point;
}

struct point stack_pop(struct stack *stack) {
    if (stack->top == -1) {
        fprintf(stderr, "Error: stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->points[stack->top--];
}

int stack_is_empty(struct stack *stack) {
    return stack->top == -1;
}

void stack_free(struct stack *stack) {
    free(stack->points);
    free(stack);
}

struct maze *maze_create(const char *filename) {
    struct maze *maze = malloc(sizeof(struct maze));
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(fp, "%c", &maze->grid[i][j]);
            if (maze->grid[i][j] == START) {
                maze->start.x = j;
                maze->start.y = i;
            } else if (maze->grid[i][j] == END) {
                maze->end.x = j;
                maze->end.y = i;
            }
        }
        fscanf(fp, "\n");
    }
    fclose(fp);
    return maze;
}

void maze_free(struct maze *maze) {
    free(maze);
}

void maze_print(struct maze *maze) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

int maze_solve(struct maze *maze) {
    struct stack *stack = stack_create();
    struct point current = maze->start;
    while (current.x != maze->end.x || current.y != maze->end.y) {
        maze->grid[current.y][current.x] = PATH;
        if (current.x + 1 < COLS && maze->grid[current.y][current.x + 1] != CLOSED && maze->grid[current.y][current.x + 1] != PATH) {
            current.x++;
            stack_push(stack, current);
        } else if (current.y + 1 < ROWS && maze->grid[current.y + 1][current.x] != CLOSED && maze->grid[current.y + 1][current.x] != PATH) {
            current.y++;
            stack_push(stack, current);
        } else if (current.x - 1 >= 0 && maze->grid[current.y][current.x - 1] != CLOSED && maze->grid[current.y][current.x - 1] != PATH) {
            current.x--;
            stack_push(stack, current);
        } else if (current.y - 1 >= 0 && maze->grid[current.y - 1][current.x] != CLOSED && maze->grid[current.y - 1][current.x] != PATH) {
            current.y--;
            stack_push(stack, current);
        } else {
            current = stack_pop(stack);
        }
    }
    stack_free(stack);
    return 1;
}

int main() {
    struct maze *maze = maze_create("maze.txt");
    maze_print(maze);
    if (maze_solve(maze)) {
        printf("Maze solved!\n");
    } else {
        printf("Maze could not be solved.\n");
    }
    maze_free(maze);
    return 0;
}