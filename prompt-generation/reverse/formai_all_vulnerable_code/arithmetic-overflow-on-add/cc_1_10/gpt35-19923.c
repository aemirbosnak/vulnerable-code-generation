//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 9

// Define the grid
char grid[ROW][COL] = {
    {'S', ' ', ' ', '#', ' ', ' ', ' ', '#', 'E'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' '},
    {'#', ' ', '#', '#', ' ', '#', '#', '#', ' '},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' '}
};

// Define the node structure
struct Node {
    int row;
    int col;
    int distance;
    struct Node* parent;
    bool visited;
};

// Create a queue (FIFO)
struct Queue {
    int front, back, size;
    unsigned capacity;
    struct Node** array;
};

// Create a new node
struct Node* newNode(int row, int col, int distance, struct Node* parent) {
    struct Node* node = malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->distance = distance;
    node->parent = parent;
    node->visited = false;
    return node;
}

// Check if the cell is valid
bool isValid(int row, int col) {
    return (row >= 0 && row < ROW) && (col >= 0 && col < COL) && grid[row][col] != '#';
}

// Check if it's the end cell
bool isEnd(int row, int col) {
    return grid[row][col] == 'E';
}

// Print the path from start to end
void printPath(struct Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d,%d) ", node->row, node->col);
}

// Create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->back = capacity - 1;
    queue->array = malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Check if the queue is full
bool isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

// Add a new node to the queue
void enqueue(struct Queue* queue, struct Node* node) {
    if (isFull(queue)) return;
    queue->back = (queue->back + 1) % queue->capacity;
    queue->array[queue->back] = node;
    queue->size += 1;
}

// Remove a node from the front of the queue
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct Node* node = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return node;
}

// Find the shortest path from start to end using BFS
void BFS(int startRow, int startCol) {
    struct Queue* queue = createQueue(ROW * COL);
    struct Node* startNode = newNode(startRow, startCol, 0, NULL);
    enqueue(queue, startNode);

    while (!isEmpty(queue)) {
        struct Node* current = dequeue(queue);
        int row = current->row;
        int col = current->col;
        int distance = current->distance;

        if (isEnd(row, col)) {
            printf("Shortest path is %d steps long: ", distance);
            printPath(current);
            printf("\n");
            return;
        }

        if (isValid(row - 1, col)) {
            struct Node* north = newNode(row - 1, col, distance + 1, current);
            if (!north->visited) {
                north->visited = true;
                enqueue(queue, north);
            }
        }
        if (isValid(row, col + 1)) {
            struct Node* east = newNode(row, col + 1, distance + 1, current);
            if (!east->visited) {
                east->visited = true;
                enqueue(queue, east);
            }
        }
        if (isValid(row + 1, col)) {
            struct Node* south = newNode(row + 1, col, distance + 1, current);
            if (!south->visited) {
                south->visited = true;
                enqueue(queue, south);
            }
        }
        if (isValid(row, col - 1)) {
            struct Node* west = newNode(row, col - 1, distance + 1, current);
            if (!west->visited) {
                west->visited = true;
                enqueue(queue, west);
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    BFS(0, 0);
    return 0;
}