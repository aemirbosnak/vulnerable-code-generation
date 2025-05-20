//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 8
#define COL 8

// Structure for a node
typedef struct node {
    int row;
    int col;
    int f;  // f = g + h
    int g;  // actual cost from start node to current node
    int h;  // heuristic cost from current node to end node
    struct node* parent;
} Node;

// Structure for a priority queue
typedef struct PriorityQueue {
    Node** data;
    int size;
} PriorityQueue;

// Create a priority queue
PriorityQueue* create_priority_queue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->data = (Node**)malloc(sizeof(Node*) * ROW * COL);
    queue->size = 0;
    return queue;
}

// Create a node
Node* create_node(int row, int col, int g, int h, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = g + h;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

// Calculate the Manhattan distance between two nodes
int calc_distance(Node* node1, Node* node2) {
    int dx = abs(node1->row - node2->row);
    int dy = abs(node1->col - node2->col);
    return dx + dy;
}

// Enqueue a node into a priority queue
void enqueue(PriorityQueue* queue, Node* node) {
    queue->data[queue->size++] = node;
    int i = queue->size - 1;
    int j;
    while (i > 0) {
        j = (i - 1) / 2;
        if (queue->data[i]->f >= queue->data[j]->f) {
            break;
        }
        Node* temp = queue->data[i];
        queue->data[i] = queue->data[j];
        queue->data[j] = temp;
        i = j;
    }
}

// Dequeue the highest priority node from a priority queue
Node* dequeue(PriorityQueue* queue) {
    Node* node = queue->data[0];
    queue->data[0] = queue->data[--queue->size];
    int i = 0;
    int j;
    while (i < queue->size) {
        j = i * 2 + 1;
        if (j >= queue->size) {
            break;
        }
        if (j + 1 < queue->size && queue->data[j+1]->f < queue->data[j]->f) {
            j++;
        }
        if (queue->data[i]->f <= queue->data[j]->f) {
            break;
        }
        Node* temp = queue->data[i];
        queue->data[i] = queue->data[j];
        queue->data[j] = temp;
        i = j;
    }
    return node;
}

// Check if a node is inside the grid
int is_inside_grid(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

// Check if a node is blocked
int is_blocked(int grid[][COL], int row, int col) {
    return grid[row][col] == 1;
}

// Get the neighbors of a node
void get_neighbors(Node* node, Node* neighbors[]) {
    int row = node->row;
    int col = node->col;
    int i, j, k = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (is_inside_grid(row+i, col+j)) {
                neighbors[k++] = create_node(row+i, col+j, 0, 0, NULL);
            }
        }
    }
}

// A* pathfinding algorithm
void astar(int grid[][COL], Node* start, Node* end) {
    int visited[ROW][COL] = {0};
    PriorityQueue* queue = create_priority_queue();
    Node* current;
    Node* neighbors[8];
    Node* temp;
    int i;
    enqueue(queue, start);
    while (queue->size > 0) {
        current = dequeue(queue);
        if (current->row == end->row && current->col == end->col) {
            printf("Path found!\n");
            temp = current;
            while (temp != NULL) {
                grid[temp->row][temp->col] = 2;
                temp = temp->parent;
            }
            for (i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    if (grid[i][j] == 0) {
                        printf(" ");
                    } else if (grid[i][j] == 1) {
                        printf("#");
                    } else if (grid[i][j] == 2) {
                        printf("*");
                    }
                }
                printf("\n");
            }
            return;
        }
        visited[current->row][current->col] = 1;
        get_neighbors(current, neighbors);
        for (i = 0; i < 8; i++) {
            if (neighbors[i] == NULL) {
                continue;
            }
            if (is_blocked(grid, neighbors[i]->row, neighbors[i]->col) || visited[neighbors[i]->row][neighbors[i]->col]) {
                free(neighbors[i]);
                continue;
            }
            neighbors[i]->g = current->g + 1;
            neighbors[i]->h = calc_distance(neighbors[i], end);
            neighbors[i]->f = neighbors[i]->g + neighbors[i]->h;
            neighbors[i]->parent = current;
            enqueue(queue, neighbors[i]);
            visited[neighbors[i]->row][neighbors[i]->col] = 1;
        }
    }
    printf("No path found!\n");
}

int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0}
    };
    Node* start = create_node(0, 0, 0, 0, NULL);
    Node* end = create_node(ROW-1, COL-1, 0, 0, NULL);
    astar(grid, start, end);
    return 0;
}