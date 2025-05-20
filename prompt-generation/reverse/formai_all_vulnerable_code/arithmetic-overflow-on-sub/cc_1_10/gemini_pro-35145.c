//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A* search node
typedef struct Node {
    int x, y;
    int g;  // distance from start
    int h;  // distance to goal
    int f;  // g + h
    struct Node *parent;
} Node;

// Priority queue of nodes, sorted by f-value
typedef struct PriorityQueue {
    int size;
    int capacity;
    Node **nodes;
} PriorityQueue;

// Create a new priority queue
PriorityQueue *createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->nodes = (Node **)malloc(sizeof(Node *) * capacity);
    return pq;
}

// Insert a node into the priority queue
void insertNode(PriorityQueue *pq, Node *node) {
    int i;
    for (i = pq->size - 1; i >= 0; i--) {
        if (node->f < pq->nodes[i]->f) {
            pq->nodes[i + 1] = pq->nodes[i];
        } else {
            break;
        }
    }
    pq->nodes[i + 1] = node;
    pq->size++;
}

// Get the node with the smallest f-value from the priority queue
Node *popNode(PriorityQueue *pq) {
    Node *node = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    return node;
}

// A* search
Node *aStarSearch(int **map, int width, int height, int sx, int sy, int ex, int ey) {
    // Create the start and goal nodes
    Node *start = (Node *)malloc(sizeof(Node));
    start->x = sx;
    start->y = sy;
    start->g = 0;
    start->h = abs(ex - sx) + abs(ey - sy);
    start->f = start->g + start->h;
    start->parent = NULL;
    Node *goal = (Node *)malloc(sizeof(Node));
    goal->x = ex;
    goal->y = ey;

    // Create the priority queue
    PriorityQueue *pq = createPriorityQueue(width * height);

    // Add the start node to the priority queue
    insertNode(pq, start);

    // Loop until the goal node is found
    while (pq->size > 0) {
        // Get the node with the smallest f-value from the priority queue
        Node *current = popNode(pq);

        // Check if the goal node is found
        if (current->x == goal->x && current->y == goal->y) {
            return current;
        }

        // Loop through all neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip the current node
                if (i == 0 && j == 0) {
                    continue;
                }

                // Check if the neighbor is within the map bounds
                if (current->x + i >= 0 && current->x + i < width && current->y + j >= 0 && current->y + j < height) {
                    // Get the neighbor node
                    Node *neighbor = (Node *)malloc(sizeof(Node));
                    neighbor->x = current->x + i;
                    neighbor->y = current->y + j;

                    // Check if the neighbor is an obstacle
                    if (map[neighbor->x][neighbor->y] == 1) {
                        free(neighbor);
                        continue;
                    }

                    // Calculate the neighbor's g-value
                    neighbor->g = current->g + 1;

                    // Calculate the neighbor's h-value
                    neighbor->h = abs(ex - neighbor->x) + abs(ey - neighbor->y);

                    // Calculate the neighbor's f-value
                    neighbor->f = neighbor->g + neighbor->h;

                    // Set the neighbor's parent to the current node
                    neighbor->parent = current;

                    // Add the neighbor to the priority queue
                    insertNode(pq, neighbor);
                }
            }
        }
    }

    // Goal node not found
    return NULL;
}

// Print the path from the start to the goal node
void printPath(Node *node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d, %d)\n", node->x, node->y);
}

// Free the path from the start to the goal node
void freePath(Node *node) {
    if (node == NULL) {
        return;
    }
    freePath(node->parent);
    free(node);
}

// Main function
int main() {
    // Create the map
    int map[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Get the start and goal coordinates
    int sx, sy, ex, ey;
    printf("Enter the start coordinates: ");
    scanf("%d %d", &sx, &sy);
    printf("Enter the goal coordinates: ");
    scanf("%d %d", &ex, &ey);

    // Find the path using A* search
    Node *path = aStarSearch(map, 5, 5, sx, sy, ex, ey);

    // Print the path
    if (path == NULL) {
        printf("No path found\n");
    } else {
        printPath(path);
    }

    // Free the path
    freePath(path);

    return 0;
}