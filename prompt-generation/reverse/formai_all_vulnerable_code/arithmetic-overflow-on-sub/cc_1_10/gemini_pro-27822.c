//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

int maze[MAZE_WIDTH][MAZE_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct point {
    int x;
    int y;
};

struct stack {
    struct point *points;
    int size;
    int top;
};

struct stack *stack_create(int size) {
    struct stack *stack = malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->points = malloc(sizeof(struct point) * size);
    return stack;
}

void stack_push(struct stack *stack, struct point point) {
    if (stack->top == stack->size - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    stack->top++;
    stack->points[stack->top] = point;
}

struct point stack_pop(struct stack *stack) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        return (struct point){-1, -1};
    }
    return stack->points[stack->top--];
}

int is_valid_move(int x, int y) {
    return (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[x][y] == 0);
}

int find_path(int start_x, int start_y, int end_x, int end_y) {
    struct stack *stack = stack_create(MAZE_WIDTH * MAZE_HEIGHT);
    struct point start = {start_x, start_y};
    stack_push(stack, start);

    while (stack->top != -1) {
        struct point current = stack_pop(stack);
        if (current.x == end_x && current.y == end_y) {
            return 1;
        }
        if (is_valid_move(current.x + 1, current.y)) {
            struct point next = {current.x + 1, current.y};
            stack_push(stack, next);
        }
        if (is_valid_move(current.x - 1, current.y)) {
            struct point next = {current.x - 1, current.y};
            stack_push(stack, next);
        }
        if (is_valid_move(current.x, current.y + 1)) {
            struct point next = {current.x, current.y + 1};
            stack_push(stack, next);
        }
        if (is_valid_move(current.x, current.y - 1)) {
            struct point next = {current.x, current.y - 1};
            stack_push(stack, next);
        }
    }

    return 0;
}

int main() {
    int start_x, start_y, end_x, end_y;

    printf("Enter the starting coordinates (x, y): ");
    scanf("%d %d", &start_x, &start_y);

    printf("Enter the ending coordinates (x, y): ");
    scanf("%d %d", &end_x, &end_y);

    if (find_path(start_x, start_y, end_x, end_y)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}