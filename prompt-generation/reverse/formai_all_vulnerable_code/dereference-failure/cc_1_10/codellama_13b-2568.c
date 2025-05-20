//Code Llama-13B DATASET v1.0 Category: Pathfinding algorithms ; Style: dynamic
// Dynamic programming approach to find the shortest path in a 2D grid

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a node in the grid
typedef struct {
    int x;
    int y;
} Node;

// Structure to represent the grid
typedef struct {
    int rows;
    int cols;
    int** grid;
} Grid;

// Structure to represent the path
typedef struct {
    Node** path;
    int size;
} Path;

// Function to create a new node
Node* newNode(int x, int y) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    return node;
}

// Function to create a new grid
Grid* newGrid(int rows, int cols) {
    Grid* grid = (Grid*) malloc(sizeof(Grid));
    grid->rows = rows;
    grid->cols = cols;
    grid->grid = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid->grid[i] = (int*) malloc(cols * sizeof(int));
    }
    return grid;
}

// Function to create a new path
Path* newPath(Node** path, int size) {
    Path* p = (Path*) malloc(sizeof(Path));
    p->path = path;
    p->size = size;
    return p;
}

// Function to print the path
void printPath(Path* path) {
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d) -> ", path->path[i]->x, path->path[i]->y);
    }
    printf("\n");
}

// Function to check if the node is valid
bool isValidNode(Grid* grid, Node* node) {
    return node->x >= 0 && node->x < grid->rows && node->y >= 0 && node->y < grid->cols;
}

// Function to check if the node is blocked
bool isBlocked(Grid* grid, Node* node) {
    return grid->grid[node->x][node->y] == 0;
}

// Function to find the shortest path using dynamic programming
Path* findShortestPath(Grid* grid) {
    // Create a 2D array to store the distances from the starting node
    int** distances = (int**) malloc(grid->rows * sizeof(int*));
    for (int i = 0; i < grid->rows; i++) {
        distances[i] = (int*) malloc(grid->cols * sizeof(int));
    }

    // Initialize the starting node
    Node* current = newNode(0, 0);
    distances[current->x][current->y] = 0;

    // Loop until the goal node is reached
    while (current->x != grid->rows - 1 || current->y != grid->cols - 1) {
        // Find the node with the minimum distance
        int minDistance = INT_MAX;
        Node* minNode = NULL;
        for (int i = 0; i < grid->rows; i++) {
            for (int j = 0; j < grid->cols; j++) {
                Node* node = newNode(i, j);
                if (isValidNode(grid, node) && isBlocked(grid, node) && distances[node->x][node->y] < minDistance) {
                    minDistance = distances[node->x][node->y];
                    minNode = node;
                }
            }
        }

        // If the minimum distance is infinity, then there is no path
        if (minDistance == INT_MAX) {
            return NULL;
        }

        // Update the current node and the distance array
        current = minNode;
        distances[current->x][current->y] = minDistance + 1;
    }

    // Create the path
    Path* path = newPath((Node**) malloc(distances[current->x][current->y] * sizeof(Node*)), distances[current->x][current->y]);
    path->path[0] = current;
    for (int i = 1; i < path->size; i++) {
        path->path[i] = newNode(current->x - 1, current->y - 1);
        current = path->path[i];
    }
    return path;
}

int main() {
    // Create a grid with 5 rows and 5 columns
    Grid* grid = newGrid(5, 5);

    // Initialize the grid with blocked nodes
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            grid->grid[i][j] = 0;
        }
    }

    // Set the starting and goal nodes
    grid->grid[0][0] = 1;
    grid->grid[4][4] = 1;

    // Find the shortest path
    Path* path = findShortestPath(grid);
    if (path == NULL) {
        printf("No path found\n");
    } else {
        printPath(path);
    }

    // Free the memory
    for (int i = 0; i < grid->rows; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
    free(path);

    return 0;
}