//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'}
};

typedef struct QueueNode {
    int row, col, distance;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

typedef struct Coordinate {
    int row, col;
} Coordinate;

QueueNode* getQueueNode(int row, int col, int distance) {
    QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
    node->row = row;
    node->col = col;
    node->distance = distance;
    node->next = NULL;
    return node;
}

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int row, int col, int distance) {
    QueueNode* node = getQueueNode(row, col, distance);

    if (queue->front == NULL) {
        queue->front = queue->rear = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

QueueNode* dequeue(Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    QueueNode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    return temp;
}

bool isValid(int row, int col, bool visited[ROW][COL]) {
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL) &&
           maze[row][col] != '#' && !visited[row][col];
}

void findRoute(int startRow, int startCol, int endRow, int endCol) {
    bool visited[ROW][COL];
    int rowDistance[] = {-1, 0, 0, 1};
    int colDistance[] = {0, -1, 1, 0};

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            visited[i][j] = false;
    }

    visited[startRow][startCol] = true;

    Queue* queue = createQueue();
    enqueue(queue, startRow, startCol, 0);

    while (queue->front != NULL) {
        QueueNode* curr = dequeue(queue);
        int currRow = curr->row;
        int currCol = curr->col;
        int currDistance = curr->distance;

        if (currRow == endRow && currCol == endCol) {
            printf("\nFound route at a distance of %d!", currDistance);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int row = currRow + rowDistance[i];
            int col = currCol + colDistance[i];

            if (isValid(row, col, visited)) {
                visited[row][col] = true;
                enqueue(queue, row, col, currDistance + 1);
            }
        }
    }

    printf("\nNo route found!");
}

int main() {
    int startRow, startCol, endRow, endCol;
    printf("Enter starting row and column:");
    scanf("%d %d", &startRow, &startCol);
    printf("Enter ending row and column:");
    scanf("%d %d", &endRow, &endCol);

    if (isValid(startRow, startCol, NULL) && isValid(endRow, endCol, NULL)) {
        printf("\nFinding route from (%d,%d) to (%d,%d)...", startRow, startCol, endRow, endCol);
        findRoute(startRow, startCol, endRow, endCol);
    } else {
        printf("\nInvalid start or end point!");
    }

    return 0;
}