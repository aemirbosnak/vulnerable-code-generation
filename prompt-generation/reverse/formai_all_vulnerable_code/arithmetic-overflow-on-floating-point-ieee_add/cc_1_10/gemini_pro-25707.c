//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
typedef struct Node {
    int x, y;
    float g, h, f;
    struct Node *parent;
} Node;

// Grid dimensions
#define WIDTH 10
#define HEIGHT 10

// Start and end coordinates
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Heuristic function
float heuristic(Node *a, Node *b) {
    return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

// Initialize the grid
Node **init_grid() {
    Node **grid = malloc(sizeof(Node *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(sizeof(Node) * WIDTH);
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j].x = j;
            grid[i][j].y = i;
            grid[i][j].g = INFINITY;
            grid[i][j].h = heuristic(&grid[i][j], &grid[END_Y][END_X]);
            grid[i][j].f = grid[i][j].g + grid[i][j].h;
            grid[i][j].parent = NULL;
        }
    }
    return grid;
}

// Free the grid
void free_grid(Node **grid) {
    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Find the neighbors of a node
Node **get_neighbors(Node **grid, Node *node) {
    int x = node->x;
    int y = node->y;
    Node **neighbors = malloc(sizeof(Node *) * 8);
    int count = 0;
    if (x > 0) {
        neighbors[count++] = &grid[y][x - 1];
    }
    if (x < WIDTH - 1) {
        neighbors[count++] = &grid[y][x + 1];
    }
    if (y > 0) {
        neighbors[count++] = &grid[y - 1][x];
    }
    if (y < HEIGHT - 1) {
        neighbors[count++] = &grid[y + 1][x];
    }
    if (x > 0 && y > 0) {
        neighbors[count++] = &grid[y - 1][x - 1];
    }
    if (x < WIDTH - 1 && y > 0) {
        neighbors[count++] = &grid[y - 1][x + 1];
    }
    if (x > 0 && y < HEIGHT - 1) {
        neighbors[count++] = &grid[y + 1][x - 1];
    }
    if (x < WIDTH - 1 && y < HEIGHT - 1) {
        neighbors[count++] = &grid[y + 1][x + 1];
    }
    return neighbors;
}

// A* pathfinding algorithm
Node *a_star(Node **grid) {
    // Initialize the open and closed lists
    Node **open_list = malloc(sizeof(Node *) * WIDTH * HEIGHT);
    Node **closed_list = malloc(sizeof(Node *) * WIDTH * HEIGHT);
    int open_count = 0;
    int closed_count = 0;

    // Add the start node to the open list
    open_list[open_count++] = &grid[START_Y][START_X];

    // While the open list is not empty
    while (open_count > 0) {
        // Find the node with the lowest f score
        Node *current_node = open_list[0];
        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->f < current_node->f) {
                current_node = open_list[i];
            }
        }

        // Remove the current node from the open list
        for (int i = 0; i < open_count; i++) {
            if (open_list[i] == current_node) {
                for (int j = i; j < open_count - 1; j++) {
                    open_list[j] = open_list[j + 1];
                }
                open_count--;
                break;
            }
        }

        // Add the current node to the closed list
        closed_list[closed_count++] = current_node;

        // Check if the current node is the end node
        if (current_node == &grid[END_Y][END_X]) {
            return current_node;
        }

        // Get the neighbors of the current node
        Node **neighbors = get_neighbors(grid, current_node);

        // For each neighbor
        for (int i = 0; i < 8; i++) {
            Node *neighbor = neighbors[i];

            // If the neighbor is not in the closed list
            int in_closed_list = 0;
            for (int j = 0; j < closed_count; j++) {
                if (closed_list[j] == neighbor) {
                    in_closed_list = 1;
                    break;
                }
            }
            if (in_closed_list) {
                continue;
            }

            // Calculate the g score
            float g = current_node->g + 1.0;

            // If the neighbor is not in the open list or the new g score is lower
            int in_open_list = 0;
            for (int j = 0; j < open_count; j++) {
                if (open_list[j] == neighbor) {
                    in_open_list = 1;
                    if (g < open_list[j]->g) {
                        open_list[j]->g = g;
                        open_list[j]->f = g + open_list[j]->h;
                        open_list[j]->parent = current_node;
                    }
                    break;
                }
            }
            if (!in_open_list) {
                neighbor->g = g;
                neighbor->f = g + neighbor->h;
                neighbor->parent = current_node;
                open_list[open_count++] = neighbor;
            }
        }
    }

    // No path found
    return NULL;
}

// Print the path
void print_path(Node *node) {
    if (node == NULL) {
        printf("No path found\n");
        return;
    }

    printf("Path:\n");
    while (node != NULL) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->parent;
    }
}

int main() {
    // Initialize the grid
    Node **grid = init_grid();

    // Find the path
    Node *path = a_star(grid);

    // Print the path
    print_path(path);

    // Free the grid
    free_grid(grid);

    return 0;
}