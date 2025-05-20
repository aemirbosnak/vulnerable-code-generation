//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node struct
typedef struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
    struct Node *parent;
} Node;

// Priority Queue struct
typedef struct PriorityQueue {
    int size;
    Node **nodes;
} PriorityQueue;

// Create a new node
Node *createNode(int x, int y, int g, int h, Node *parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

// Create a new priority queue
PriorityQueue *createPriorityQueue() {
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->nodes = (Node **)malloc(sizeof(Node *) * 100);
    return queue;
}

// Add a node to the priority queue
void addNode(PriorityQueue *queue, Node *node) {
    int i = queue->size;
    queue->nodes[i] = node;
    queue->size++;

    // Bubble the node up the heap
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (queue->nodes[parent]->f > queue->nodes[i]->f) {
            Node *temp = queue->nodes[parent];
            queue->nodes[parent] = queue->nodes[i];
            queue->nodes[i] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

// Remove the node with the lowest f-score from the priority queue
Node *removeNode(PriorityQueue *queue) {
    if (queue->size == 0) {
        return NULL;
    }

    Node *node = queue->nodes[0];

    // Move the last node to the root
    queue->nodes[0] = queue->nodes[queue->size - 1];
    queue->size--;

    // Bubble the node down the heap
    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < queue->size && queue->nodes[left]->f < queue->nodes[smallest]->f) {
            smallest = left;
        }
        if (right < queue->size && queue->nodes[right]->f < queue->nodes[smallest]->f) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }

        // Swap the node with its smallest child
        Node *temp = queue->nodes[smallest];
        queue->nodes[smallest] = queue->nodes[i];
        queue->nodes[i] = temp;
        i = smallest;
    }

    return node;
}

// Find the path from the start node to the end node
Node *findPath(Node *start, Node *end) {
    // Create a priority queue
    PriorityQueue *queue = createPriorityQueue();

    // Add the start node to the queue
    addNode(queue, start);

    // While the queue is not empty
    while (queue->size > 0) {
        // Remove the node with the lowest f-score from the queue
        Node *current = removeNode(queue);

        // If the current node is the end node, then we have found the path
        if (current == end) {
            return current;
        }

        // Add the current node's neighbors to the queue
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int x = current->x + i;
                int y = current->y + j;

                // Check if the neighbor is valid
                if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                    // Create a new node
                    Node *neighbor = createNode(x, y, current->g + 1, abs(x - end->x) + abs(y - end->y), current);

                    // Add the neighbor to the queue
                    addNode(queue, neighbor);
                }
            }
        }
    }

    // No path found
    return NULL;
}

// Print the path from the start node to the end node
void printPath(Node *start, Node *end) {
    printf("Path from (%d, %d) to (%d, %d):\n", start->x, start->y, end->x, end->y);
    Node *current = end;
    while (current != start) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }
    printf("(%d, %d)\n", start->x, start->y);
}

// Main function
int main() {
    // Create the start and end nodes
    Node *start = createNode(0, 0, 0, 0, NULL);
    Node *end = createNode(9, 9, 0, 0, NULL);

    // Find the path from the start node to the end node
    Node *path = findPath(start, end);

    // Print the path
    printPath(start, path);

    return 0;
}