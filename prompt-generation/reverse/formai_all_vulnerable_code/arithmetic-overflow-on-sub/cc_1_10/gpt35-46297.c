//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

struct point {
    int row;
    int col;
    struct point* parent;
};

struct queue {
    struct point* data[ROWS * COLS];
    int front;
    int rear;
};

struct queue* create_queue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

void enqueue(struct queue* q, struct point* pt) {
    q->data[q->rear] = pt;
    q->rear++;
}

struct point* dequeue(struct queue* q) {
    struct point* pt = q->data[q->front];
    q->front++;
    return pt;
}

int is_empty(struct queue* q) {
    return q->front == q->rear;
}

int is_wall(int row, int col) {
    return maze[row][col] == 1;
}

int is_valid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && !is_wall(row, col);
}

void print_path(struct point* pt) {
    while (pt) {
        printf("(%d,%d)\n", pt->row, pt->col);
        pt = pt->parent;
    }
}

void bfs(int start_row, int start_col, int end_row, int end_col) {
    struct point* start = malloc(sizeof(struct point));
    start->row = start_row;
    start->col = start_col;
    start->parent = NULL;
    
    struct queue* q = create_queue();
    enqueue(q, start);
    
    while (!is_empty(q)) {
        struct point* curr = dequeue(q);
        
        if (curr->row == end_row && curr->col == end_col) {
            print_path(curr);
            return;
        }
        
        struct point* left = malloc(sizeof(struct point));
        left->row = curr->row;
        left->col = curr->col - 1;
        left->parent = curr;
        
        if (is_valid(left->row, left->col)) {
            enqueue(q, left);
            maze[left->row][left->col] = 1;
        }
        
        struct point* right = malloc(sizeof(struct point));
        right->row = curr->row;
        right->col = curr->col + 1;
        right->parent = curr;
        
        if (is_valid(right->row, right->col)) {
            enqueue(q, right);
            maze[right->row][right->col] = 1;
        }
        
        struct point* up = malloc(sizeof(struct point));
        up->row = curr->row - 1;
        up->col = curr->col;
        up->parent = curr;
        
        if (is_valid(up->row, up->col)) {
            enqueue(q, up);
            maze[up->row][up->col] = 1;
        }
        
        struct point* down = malloc(sizeof(struct point));
        down->row = curr->row + 1;
        down->col = curr->col;
        down->parent = curr;
        
        if (is_valid(down->row, down->col)) {
            enqueue(q, down);
            maze[down->row][down->col] = 1;
        }
    }
}

int main() {
    bfs(0, 0, 9, 9);
    return 0;
}