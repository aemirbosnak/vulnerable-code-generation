//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COLUMN 10

typedef struct Node {
    int row;
    int col;
    int g_cost;
    int h_cost;
    int f_cost;
    struct Node* parent;
} QNode;

typedef struct {
    QNode* arr[ROW * COLUMN];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, QNode* node) {
    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->arr[0] = node;
        return;
    }
    q->rear++;
    q->arr[q->rear] = node;
}

QNode* dequeue(Queue* q) {
    QNode* node = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return node;
}

bool isValid(int x, int y) {
    return x >= 0 && x < ROW && y >= 0 && y < COLUMN;
}

bool isBlocked(int grid[][COLUMN], int x, int y) {
    return grid[x][y] == 1;
}

bool isDestination(int x, int y, QNode* dest) {
    return x == dest->row && y == dest->col;
}

int heuristic(int x, int y, QNode* dest) {
    return abs(dest->row - x) + abs(dest->col - y);
}

void tracePath(QNode* dest) {
    printf("Path: ");
    QNode* node = dest;
    while (node != NULL) {
        printf("(%d,%d) ", node->row, node->col);
        node = node->parent;
    }
}

void aStar(int grid[][COLUMN], QNode* src, QNode* dest) {
    Queue* openSet = createQueue();
    Queue* closedSet = createQueue();
    enqueue(openSet, src);
    while (!isEmpty(openSet)) {
        QNode* currNode = dequeue(openSet);
        enqueue(closedSet, currNode);
        if (isDestination(currNode->row, currNode->col, dest)) {
            tracePath(currNode);
            return;
        }
        int x = currNode->row;
        int y = currNode->col;
        int g_cost = currNode->g_cost + 1;
        int h_cost = heuristic(x, y, dest);
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (isValid(x + i, y + j) && !isBlocked(grid, x + i, y + j)) {
                    QNode* neighbor = (QNode*) malloc(sizeof(QNode));
                    neighbor->row = x + i;
                    neighbor->col = y + j;
                    neighbor->g_cost = g_cost;
                    neighbor->h_cost = heuristic(neighbor->row, neighbor->col, dest);
                    neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;
                    neighbor->parent = currNode;
                    QNode* existingNode;
                    bool isInClosedSet = false;
                    for (int i = closedSet->front; i <= closedSet->rear; i++) {
                        existingNode = closedSet->arr[i];
                        if (existingNode->row == neighbor->row && existingNode->col == neighbor->col) {
                            isInClosedSet = true;
                            break;
                        }
                    }
                    if (isInClosedSet) {
                        continue;
                    }
                    bool isInOpenSet = false;
                    for (int i = openSet->front; i <= openSet->rear; i++) {
                        existingNode = openSet->arr[i];
                        if (existingNode->row == neighbor->row && existingNode->col == neighbor->col) {
                            isInOpenSet = true;
                            break;
                        }
                    }
                    if (!isInOpenSet) {
                        enqueue(openSet, neighbor);
                    } else {
                        if (neighbor->g_cost < existingNode->g_cost) {
                            existingNode->g_cost = neighbor->g_cost;
                            existingNode->f_cost = existingNode->g_cost + existingNode->h_cost;
                            existingNode->parent = currNode;
                        }
                    }
                }
            }
        }
    }
    printf("No path found!");
}

int main() {
    int grid[ROW][COLUMN] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,1,0,0,0,1,0,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,0,0,1,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    QNode* src = (QNode*) malloc(sizeof(QNode));
    src->row = 0;
    src->col = 0;
    src->g_cost = 0;
    src->h_cost = heuristic(src->row, src->col, src);
    src->f_cost = src->g_cost + src->h_cost;
    src->parent = NULL;
    QNode* dest = (QNode*) malloc(sizeof(QNode));
    dest->row = 9;
    dest->col = 9;
    dest->g_cost = 0;
    dest->h_cost = 0;
    dest->f_cost = 0;
    dest->parent = NULL;
    aStar(grid, src, dest);
    return 0;
}