//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10

// Define a Node structure to represent a location in the search space
typedef struct {
    int row, col;
    double f, g, h;
    bool closed;
    struct node *parent;
} Node;

// Define a priority queue to store the nodes that still need to be explored
typedef struct {
    Node *nodes[ROWS*COLS];
    int size;
} PriorityQueue;

// Define a function to create a new node
Node* new_node(int row, int col, double g, double h, Node* parent) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->closed = false;
    node->parent = parent;
    return node;
}

// Define a function to calculate the heuristic distance between two nodes
double manhattan_distance(Node* node1, Node* node2) {
    return fabs(node1->row - node2->row) + fabs(node1->col - node2->col);
}

// Define a function to add a node to the priority queue
void push(PriorityQueue* queue, Node* node) {
    int i = queue->size++;
    while(i > 0 && queue->nodes[(i-1)/2]->f > node->f) {
        queue->nodes[i] = queue->nodes[(i-1)/2];
        i = (i-1)/2;
    }
    queue->nodes[i] = node;
}

// Define a function to remove the node with the lowest f value from the priority queue
Node* pop(PriorityQueue* queue) {
    Node* min_node = queue->nodes[0];
    queue->nodes[0] = queue->nodes[--queue->size];
    int i = 0;
    while(true) {
        int min_child = i*2 + 1;
        if(min_child >= queue->size) break;
        if(min_child+1 < queue->size && queue->nodes[min_child+1]->f < queue->nodes[min_child]->f) min_child++;
        if(queue->nodes[min_child]->f < queue->nodes[i]->f) {
            Node* temp = queue->nodes[i];
            queue->nodes[i] = queue->nodes[min_child];
            queue->nodes[min_child] = temp;
            i = min_child;
        } else {
            break;
        }
    }
    return min_node;
}

// Define a function to check if a node is within the search space
bool is_within_bounds(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Define a function to check if a node is traversable
bool is_traversable(int map[][COLS], int row, int col) {
    return (map[row][col] == 0);
}

// Define the main function for the A* pathfinding algorithm
void a_star(int map[][COLS], Node* start_node, Node* end_node) {
    PriorityQueue open_queue = { .size = 0 };
    push(&open_queue, start_node);

    while(open_queue.size > 0) {
        Node* current_node = pop(&open_queue);
        if(current_node == end_node) {
            // Path found, reconstruct and print path
            int path_length = 0;
            for(Node* node = current_node; node != NULL; node = node->parent) {
                path_length++;
            }
            Node* path[path_length];
            int i = 0;
            for(Node* node = current_node; node != NULL; node = node->parent) {
                path[i++] = node;
            }
            printf("Path found (length=%d):\n", path_length);
            for(int j=i-1; j>=0; j--) {
                printf("(%d,%d) ", path[j]->row, path[j]->col);
            }
            printf("\n");
            return;
        }
        current_node->closed = true;

        // Check each neighbor of the current node
        for(int drow=-1; drow<=1; drow++) {
            for(int dcol=-1; dcol<=1; dcol++) {
                if((drow == 0 && dcol == 0) || !is_within_bounds(current_node->row+drow, current_node->col+dcol)) continue;

                Node* neighbor_node = new_node(current_node->row+drow, current_node->col+dcol, 0, 0, current_node);
                if(!is_traversable(map, neighbor_node->row, neighbor_node->col) || neighbor_node->closed) {
                    free(neighbor_node);
                    continue;
                }
                neighbor_node->g = current_node->g + 1;
                neighbor_node->h = manhattan_distance(neighbor_node, end_node);
                neighbor_node->f = neighbor_node->g + neighbor_node->h;

                // Add neighbor node to open queue
                Node* existing_node = NULL;
                for(int i=0; i<open_queue.size; i++) {
                    Node* node = open_queue.nodes[i];
                    if(node->row == neighbor_node->row && node->col == neighbor_node->col) {
                        existing_node = node;
                        break;
                    }
                }
                if(existing_node != NULL && existing_node->f <= neighbor_node->f) {
                    free(neighbor_node);
                } else {
                    if(existing_node != NULL) existing_node->closed = true;
                    push(&open_queue, neighbor_node);
                }
            }
        }
    }

    printf("Path not found.\n");
}

int main() {
    int map[ROWS][COLS] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };

    Node* start_node = new_node(0, 0, 0, 0, NULL);
    Node* end_node = new_node(6, 6, 0, 0, NULL);

    a_star(map, start_node, end_node);

    free(start_node);
    free(end_node);

    return 0;
}