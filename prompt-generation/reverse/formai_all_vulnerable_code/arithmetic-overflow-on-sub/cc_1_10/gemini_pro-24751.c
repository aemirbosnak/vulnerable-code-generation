//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

// A 2D matrix to represent the map
int map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// A structure to represent a node in the graph
typedef struct Node {
    int x;
    int y;
    int g;  // Cost from the starting node
    int h;  // Heuristic cost to the goal node
    struct Node *parent;
} Node;

// A structure to represent the priority queue
typedef struct PriorityQueue {
    int size;
    Node **nodes;
} PriorityQueue;

// Create a new node
Node *create_node(int x, int y, int g, int h, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

// Create a new priority queue
PriorityQueue *create_priority_queue(int size) {
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->nodes = malloc(sizeof(Node *) * size);
    return queue;
}

// Insert a node into the priority queue
void insert_priority_queue(PriorityQueue *queue, Node *node) {
    int i;
    for (i = queue->size; i > 0; i--) {
        if (queue->nodes[i - 1]->h > node->h) {
            queue->nodes[i] = queue->nodes[i - 1];
        } else {
            break;
        }
    }
    queue->nodes[i] = node;
    queue->size++;
}

// Get the node with the lowest heuristic cost from the priority queue
Node *get_min_priority_queue(PriorityQueue *queue) {
    return queue->nodes[0];
}

// Remove the node with the lowest heuristic cost from the priority queue
void remove_min_priority_queue(PriorityQueue *queue) {
    int i;
    for (i = 0; i < queue->size - 1; i++) {
        queue->nodes[i] = queue->nodes[i + 1];
    }
    queue->size--;
}

// Check if a node is in the priority queue
int is_in_priority_queue(PriorityQueue *queue, Node *node) {
    int i;
    for (i = 0; i < queue->size; i++) {
        if (queue->nodes[i] == node) {
            return 1;
        }
    }
    return 0;
}

// Get the neighbors of a node
Node **get_neighbors(Node *node) {
    Node **neighbors = malloc(sizeof(Node *) * 4);
    int i = 0;
    if (node->x > 0) {
        neighbors[i++] = create_node(node->x - 1, node->y, node->g + 1, abs(node->x - 1 - 9) + abs(node->y - 9), node);
    }
    if (node->y > 0) {
        neighbors[i++] = create_node(node->x, node->y - 1, node->g + 1, abs(node->x - 9) + abs(node->y - 1 - 9), node);
    }
    if (node->x < 9) {
        neighbors[i++] = create_node(node->x + 1, node->y, node->g + 1, abs(node->x + 1 - 9) + abs(node->y - 9), node);
    }
    if (node->y < 9) {
        neighbors[i++] = create_node(node->x, node->y + 1, node->g + 1, abs(node->x - 9) + abs(node->y + 1 - 9), node);
    }
    return neighbors;
}

// Check if a node is in the map
int is_in_map(Node *node) {
    return node->x >= 0 && node->x < 10 && node->y >= 0 && node->y < 10 && map[node->x][node->y] == 0;
}

// Find the path from the starting node to the goal node
Node **find_path(Node *start, Node *goal) {
    // Create a priority queue
    PriorityQueue *queue = create_priority_queue(100);

    // Insert the starting node into the priority queue
    insert_priority_queue(queue, start);

    // While the priority queue is not empty
    while (queue->size > 0) {
        // Get the node with the lowest heuristic cost from the priority queue
        Node *node = get_min_priority_queue(queue);

        // Remove the node from the priority queue
        remove_min_priority_queue(queue);

        // If the node is the goal node, return the path
        if (node->x == goal->x && node->y == goal->y) {
            Node **path = malloc(sizeof(Node *) * 100);
            int i = 0;
            while (node != NULL) {
                path[i++] = node;
                node = node->parent;
            }
            return path;
        }

        // Get the neighbors of the node
        Node **neighbors = get_neighbors(node);

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            Node *neighbor = neighbors[i];

            // If the neighbor is in the map and not in the priority queue
            if (is_in_map(neighbor) && !is_in_priority_queue(queue, neighbor)) {
                // Insert the neighbor into the priority queue
                insert_priority_queue(queue, neighbor);
            }
        }

        // Free the neighbors
        free(neighbors);
    }

    // Return NULL if no path is found
    return NULL;
}

// Print the path
void print_path(Node **path) {
    int i;
    for (i = 0; path[i] != NULL; i++) {
        printf("(%d, %d)\n", path[i]->x, path[i]->y);
    }
}

// Free the path
void free_path(Node **path) {
    int i;
    for (i = 0; path[i] != NULL; i++) {
        free(path[i]);
    }
    free(path);
}

// Main function
int main() {
    // Create the starting and goal nodes
    Node *start = create_node(0, 0, 0, abs(0 - 9) + abs(0 - 9), NULL);
    Node *goal = create_node(9, 9, 0, 0, NULL);

    // Find the path from the starting node to the goal node
    Node **path = find_path(start, goal);

    // Print the path
    print_path(path);

    // Free the path
    free_path(path);

    // Free the starting and goal nodes
    free(start);
    free(goal);

    return 0;
}