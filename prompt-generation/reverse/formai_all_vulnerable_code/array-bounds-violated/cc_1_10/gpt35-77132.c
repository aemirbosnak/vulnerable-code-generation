//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

int maze[ROW_SIZE][COL_SIZE] = {
    {0, 1, 1, 0, 1, 1, 0, 0, 0, 1},
    {0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
    {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 1, 0, 0, 0, 0},
};

typedef struct node{
    int x;
    int y;
    struct node* next;
} Node;

typedef struct queue{
    Node *front;
    Node *rear;
} Queue;

int solveMaze(int startX, int startY, int endX, int endY);
void enqueue(Queue *queue, int x, int y);
Node* dequeue(Queue *queue);
bool isEmpty(Queue *queue);

int main() {
    int startX, startY, endX, endY;
    printf("Enter starting x and y coordinates of the maze (between 0 to 9, e.g. 0 0): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter ending x and y coordinates of the maze (between 0 to 9, e.g. 9 9): ");
    scanf("%d %d", &endX, &endY);
 
    int steps = solveMaze(startX, startY, endX, endY);

    if(steps) {
        printf("Route found in %d steps.\n", steps);
    } else {
        printf("Route not found.\n");
    }
 
    return 0;
}

int solveMaze(int startX, int startY, int endX, int endY) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    int visited[ROW_SIZE][COL_SIZE] = {0};
    
    visited[startX][startY] = 1;
    enqueue(queue, startX, startY);
    
    int steps = 0;
    while(!isEmpty(queue)) {
        int size = 0;
        for(int i = 0; i < steps+1; i++) {
            Node* current = dequeue(queue);
            int row = current->x;
            int col = current->y;
            if(row == endX && col == endY) {
                return steps;
            }
            if(row-1 >= 0 && maze[row-1][col] == 0 && visited[row-1][col] == 0) {
                visited[row-1][col] = 1;
                enqueue(queue, row-1, col);
            }
            if(row+1 < ROW_SIZE && maze[row+1][col] == 0 && visited[row+1][col] == 0) {
                visited[row+1][col] = 1;
                enqueue(queue, row+1, col);
            }
            if(col-1 >= 0 && maze[row][col-1] == 0 && visited[row][col-1] == 0) {
                visited[row][col-1] = 1;
                enqueue(queue, row, col-1);
            }
            if(col+1 < COL_SIZE && maze[row][col+1] == 0 && visited[row][col+1] == 0) {
                visited[row][col+1] = 1;
                enqueue(queue, row, col+1);
            }
            free(current);
            size++;
        }
        steps++;
    }
    return 0;
}

void enqueue(Queue *queue, int x, int y) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    
    if(queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

Node* dequeue(Queue *queue) {
    if(queue->front == NULL) {
        return NULL;
    }
    Node *current = queue->front;
    queue->front = current->next;
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    return current;
}

bool isEmpty(Queue *queue) {
    return queue->front == NULL;
}