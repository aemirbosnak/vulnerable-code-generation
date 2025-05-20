//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

int maze[ROW_SIZE][COL_SIZE] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point data[ROW_SIZE*COL_SIZE];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

bool isEmpty(Stack *s)
{
    return (s->top == -1);
}

bool isFull(Stack *s)
{
    return (s->top == ROW_SIZE*COL_SIZE - 1);
}

void push(Point p, Stack *s)
{
    if (isFull(s)) {
        printf("Cannot push to full stack\n");
        return;
    }
    s->top++;
    s->data[s->top] = p;
}

Point pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("Cannot pop from empty stack\n");
        exit(1);
    }
    Point p = s->data[s->top];
    s->top--;
    return p;
}

bool isMovable(Point p, int dir)
{
    int row = p.row;
    int col = p.col;
    if (dir == 0) {         // move right
        col++;
    } else if (dir == 1) {  // move down
        row++;
    } else if (dir == 2) {  // move left
        col--;
    } else if (dir == 3) {  // move up
        row--;
    }
    if (row >= 0 && row < ROW_SIZE && col >= 0 && col < COL_SIZE && maze[row][col] == 1) {
        return true;
    } else {
        return false;
    }
}

void printPath(Stack *solution)
{
    printf("The path to the end:\n");
    for (int i = solution->top; i >= 0; i--) {
        printf("(%d,%d) ", solution->data[i].row, solution->data[i].col);
    }
    printf("\n");
}

void findPath(Point start, Point end)
{
    Stack path;
    Stack solution;
    int dir = 0;
    Point current = start;
    initialize(&path);
    initialize(&solution);
    push(start, &path);

    while (!isEmpty(&path)) {
        if (current.row == end.row && current.col == end.col) {
            push(current, &solution);
            printPath(&solution);
            return;
        }
        if (dir < 4) {
            if (isMovable(current, dir)) {
                push(current, &path);
                current.row += (dir % 2) * (dir - 2);
                current.col += ((dir + 1) % 2) * (dir - 1);
                maze[current.row][current.col] = 2;
                dir = 0;
            } else {
                dir++;
            }
        } else {
            pop(&path);
            current = path.data[path.top];
            dir = 0;
        }
    }
    printf("No path to the end\n");
}

int main()
{
    Point start = {0, 0};
    Point end = {9, 9};
    findPath(start, end);
    return 0;
}