//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ROWS 50
#define MAX_COLS 50

typedef struct Coord {
    int x;
    int y;
} Coord;

typedef struct Stack {
    Coord arr[MAX_ROWS * MAX_COLS];
    int top;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, Coord coord) {
    stack->arr[++stack->top] = coord;
}

Coord pop(Stack* stack) {
    return stack->arr[stack->top--];
}

Coord peek(Stack* stack) {
    return stack->arr[stack->top];
}

int distance(Coord coord1, Coord coord2) {
    return abs(coord1.x - coord2.x) + abs(coord1.y - coord2.y);
}

void print_path(Stack* stack) {
    printf("\nPath: ");
    while (!is_empty(stack)) {
        Coord coord = pop(stack);
        printf("(%d,%d) ", coord.x, coord.y);
    }
    printf("\n");
}

void find_path(int maze[MAX_ROWS][MAX_COLS], Coord start, Coord end) {

    Stack* stack = create_stack();

    Coord current = start;
    push(stack, current);

    int visited[MAX_ROWS][MAX_COLS] = {{0}};
    visited[current.x][current.y] = 1;

    while (!is_empty(stack)) {

        current = peek(stack);

        if (current.x == end.x && current.y == end.y) {
            print_path(stack);
            return;
        }

        Coord next = current;

        if (!visited[current.x+1][current.y] && maze[current.x+1][current.y]) {
            next.x = current.x + 1;
            push(stack, next);
            visited[next.x][next.y] = 1;
            continue;
        }

        if (!visited[current.x][current.y+1] && maze[current.x][current.y+1]) {
            next.y = current.y + 1;
            push(stack, next);
            visited[next.x][next.y] = 1;
            continue;
        }

        if (!visited[current.x-1][current.y] && maze[current.x-1][current.y]) {
            next.x = current.x - 1;
            push(stack, next);
            visited[next.x][next.y] = 1;
            continue;
        }

        if (!visited[current.x][current.y-1] && maze[current.x][current.y-1]) {
            next.y = current.y - 1;
            push(stack, next);
            visited[next.x][next.y] = 1;
            continue;
        }

        pop(stack);
    }

    printf("\nNo path found.\n");
}

void print_maze(int maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("MAZE:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    // Seed random number generator
    srand(time(NULL));

    int maze[MAX_ROWS][MAX_COLS] = {{0}};

    int rows, cols;
    printf("Enter number of rows (maximum %d): ", MAX_ROWS);
    scanf("%d", &rows);

    printf("Enter number of columns (maximum %d): ", MAX_COLS);
    scanf("%d", &cols);

    // Ensure maze is at least 3 rows and 3 cols
    if (rows < 3) rows = 3;
    if (cols < 3) cols = 3;

    // Initialize start and end coordinates
    Coord start = {rand() % rows, rand() % cols};
    Coord end = {rand() % rows, rand() % cols};
    while (distance(start, end) < rows/2) {
        end = (Coord){rand() % rows, rand() % cols};
    }

    // Generate random maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows-1 || j == cols-1)
                maze[i][j] = 1;
            else
                maze[i][j] = rand() % 2;
        }
    }

    // Mark start and end points in maze
    maze[start.x][start.y] = 2;
    maze[end.x][end.y] = 3;

    // Print maze
    print_maze(maze, rows, cols);

    // Find route through maze
    find_path(maze, start, end);

    return 0;
}