//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// Node struct for the graph
typedef struct Node {
    int x, y;
    struct Node *parent;
    int g, h, f;
} Node;

// Queue struct for the open and closed lists
typedef struct Queue {
    Node **nodes;
    int size, capacity;
} Queue;

// Function to create a new node
Node *create_node(int x, int y) {
    Node *node = malloc(sizeof(Node));
    if (!node) return NULL;
    node->x = x;
    node->y = y;
    node->parent = NULL;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    return node;
}

// Function to create a new queue
Queue *create_queue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) return NULL;
    queue->nodes = malloc(sizeof(Node *) * capacity);
    if (!queue->nodes) {
        free(queue);
        return NULL;
    }
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to enqueue a node to the queue
void enqueue(Queue *queue, Node *node) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->nodes = realloc(queue->nodes, sizeof(Node *) * queue->capacity);
    }
    queue->nodes[queue->size++] = node;
}

// Function to dequeue a node from the queue
Node *dequeue(Queue *queue) {
    if (queue->size == 0) return NULL;
    Node *node = queue->nodes[0];
    for (int i = 1; i < queue->size; i++) {
        queue->nodes[i - 1] = queue->nodes[i];
    }
    queue->size--;
    return node;
}

// Function to check if a node is in the queue
bool contains(Queue *queue, Node *node) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->nodes[i] == node) return true;
    }
    return false;
}

// Function to calculate the heuristic cost of a node
int heuristic(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// Function to compare two nodes based on their f-scores
int compare_nodes(const void *a, const void *b) {
    Node *node1 = *(Node **)a;
    Node *node2 = *(Node **)b;
    return node1->f - node2->f;
}

// Thread function to find the path from the start node to the goal node
void *find_path(void *arg) {
    Queue *open_list = create_queue(100);
    Queue *closed_list = create_queue(100);
    Node *start_node = arg;
    Node *goal_node = create_node(10, 10);
    enqueue(open_list, start_node);
    while (open_list->size > 0) {
        Node *current_node = dequeue(open_list);
        if (current_node->x == goal_node->x && current_node->y == goal_node->y) {
            printf("Path found!\n");
            printf("Printing the path:\n");
            while (current_node != NULL) {
                printf("(%d, %d)\n", current_node->x, current_node->y);
                current_node = current_node->parent;
            }
            return NULL;
        }
        enqueue(closed_list, current_node);
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                Node *neighbor_node = create_node(current_node->x + i, current_node->y + j);
                if (!neighbor_node) continue;
                if (contains(closed_list, neighbor_node)) {
                    free(neighbor_node);
                    continue;
                }
                neighbor_node->parent = current_node;
                neighbor_node->g = current_node->g + 1;
                neighbor_node->h = heuristic(neighbor_node, goal_node);
                neighbor_node->f = neighbor_node->g + neighbor_node->h;
                if (!contains(open_list, neighbor_node)) {
                    enqueue(open_list, neighbor_node);
                }
            }
        }
    }
    printf("No path found!\n");
    return NULL;
}

// Main function
int main() {
    pthread_t thread;
    Node *start_node = create_node(0, 0);
    pthread_create(&thread, NULL, find_path, start_node);
    pthread_join(thread, NULL);
    return 0;
}