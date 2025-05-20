//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
/** 
 * Romeo and Juliet Pathfinding Algorithm
 * 
 * Two star-crossed lovers, Romeo and Juliet, must find their way 
 * to each other through a maze. Romeo starts on the left side of 
 * the maze, while Juliet starts on the right. They must navigate 
 * through the maze by moving up, down, left, or right, without 
 * crossing each other's paths. Once they reach the same cell in 
 * the maze, they are reunited and the algorithm ends.
 *
 **/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

struct cell {
    int x;
    int y;
};

struct queue {
    struct cell* items[100];
    int front;
    int rear;
};

struct cell* create_cell(int x, int y) {
    struct cell* new_cell = malloc(sizeof(struct cell));
    new_cell->x = x;
    new_cell->y = y;
    return new_cell;
}

struct queue* create_queue() {
    struct queue* new_queue = malloc(sizeof(struct queue));
    new_queue->front = -1;
    new_queue->rear = -1;
    return new_queue;
}

void enqueue(struct queue* q, struct cell* c) {
    if (q->rear == 99) {
        fprintf(stderr, "Queue overflow");
        exit(EXIT_FAILURE);
    }
    q->rear++;
    q->items[q->rear] = c;
    if (q->front == -1) {
        q->front = 0;
    }
}

struct cell* dequeue(struct queue* q) {
    if (q->front == -1) {
        fprintf(stderr, "Queue underflow");
        exit(EXIT_FAILURE);
    }
    struct cell* item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

int is_empty(struct queue* q) {
    if (q->rear == -1) {
        return 1;
    }
    return 0;
}

int is_valid(struct cell* c) {
    if (c->x < 0 || c->x >= ROWS || c->y < 0 || c->y >= COLS) {
        return 0;
    }
    return 1;
}

int is_wall(int maze[ROWS][COLS], struct cell* c) {
    if (maze[c->x][c->y] == 1) {
        return 1;
    }
    return 0;
}

void breadth_first_search(int maze[ROWS][COLS], struct cell* start, struct cell* end) {
    int visited[ROWS][COLS] = {0};
    struct queue* q = create_queue();
    visited[start->x][start->y] = 1;
    enqueue(q, start);
    while (!is_empty(q)) {
        struct cell* current = dequeue(q);
        if (current->x == end->x && current->y == end->y) {
            printf("Romeo and Juliet are reunited! They embrace and live happily ever after.");
            return;
        }
        struct cell* north = create_cell(current->x - 1, current->y);
        struct cell* south = create_cell(current->x + 1, current->y);
        struct cell* east = create_cell(current->x, current->y + 1);
        struct cell* west = create_cell(current->x, current->y - 1);
        if (is_valid(north) && !is_wall(maze, north) && !visited[north->x][north->y]) {
            visited[north->x][north->y] = 1;
            enqueue(q, north);
        }
        if (is_valid(south) && !is_wall(maze, south) && !visited[south->x][south->y]) {
            visited[south->x][south->y] = 1;
            enqueue(q, south);
        }
        if (is_valid(east) && !is_wall(maze, east) && !visited[east->x][east->y]) {
            visited[east->x][east->y] = 1;
            enqueue(q, east);
        }
        if (is_valid(west) && !is_wall(maze, west) && !visited[west->x][west->y]) {
            visited[west->x][west->y] = 1;
            enqueue(q, west);
        }
    }
    printf("Romeo and Juliet could not find a path to each other. They tragically die alone.");
    return;
}

int main() {
    int maze[ROWS][COLS] = {
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0}
    };
    struct cell* romeo_start = create_cell(0, 0);
    struct cell* juliet_start = create_cell(ROWS - 1, COLS - 1);
    breadth_first_search(maze, romeo_start, juliet_start);
    return 0;
}