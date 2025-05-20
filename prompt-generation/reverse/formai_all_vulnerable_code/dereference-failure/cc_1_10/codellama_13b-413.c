//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: modular
// maze_route_finder.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to represent a node in the maze
typedef struct node {
    int x;
    int y;
    bool visited;
    struct node *next;
} node_t;

// Struct to represent the maze
typedef struct maze {
    int rows;
    int cols;
    node_t **nodes;
} maze_t;

// Function to create a new maze
maze_t *create_maze(int rows, int cols) {
    maze_t *maze = malloc(sizeof(maze_t));
    maze->rows = rows;
    maze->cols = cols;
    maze->nodes = malloc(sizeof(node_t *) * rows);
    for (int i = 0; i < rows; i++) {
        maze->nodes[i] = malloc(sizeof(node_t) * cols);
        for (int j = 0; j < cols; j++) {
            maze->nodes[i][j].x = i;
            maze->nodes[i][j].y = j;
            maze->nodes[i][j].visited = false;
            maze->nodes[i][j].next = NULL;
        }
    }
    return maze;
}

// Function to set the current node as visited
void set_visited(maze_t *maze, int row, int col) {
    maze->nodes[row][col].visited = true;
}

// Function to check if the current node is visited
bool is_visited(maze_t *maze, int row, int col) {
    return maze->nodes[row][col].visited;
}

// Function to get the neighbors of a node
node_t **get_neighbors(maze_t *maze, int row, int col) {
    node_t **neighbors = malloc(sizeof(node_t *) * 4);
    int count = 0;
    if (row > 0 && !is_visited(maze, row - 1, col)) {
        neighbors[count++] = &maze->nodes[row - 1][col];
    }
    if (row < maze->rows - 1 && !is_visited(maze, row + 1, col)) {
        neighbors[count++] = &maze->nodes[row + 1][col];
    }
    if (col > 0 && !is_visited(maze, row, col - 1)) {
        neighbors[count++] = &maze->nodes[row][col - 1];
    }
    if (col < maze->cols - 1 && !is_visited(maze, row, col + 1)) {
        neighbors[count++] = &maze->nodes[row][col + 1];
    }
    return neighbors;
}

// Function to find the shortest path from the start node to the end node
void find_path(maze_t *maze, int start_row, int start_col, int end_row, int end_col) {
    node_t *current = &maze->nodes[start_row][start_col];
    set_visited(maze, start_row, start_col);
    while (current->x != end_row || current->y != end_col) {
        node_t **neighbors = get_neighbors(maze, current->x, current->y);
        for (int i = 0; i < 4; i++) {
            node_t *neighbor = neighbors[i];
            if (neighbor != NULL) {
                current = neighbor;
                set_visited(maze, current->x, current->y);
                break;
            }
        }
        free(neighbors);
    }
}

int main() {
    // Create a 3x3 maze
    maze_t *maze = create_maze(3, 3);
    // Set the start and end nodes
    int start_row = 0;
    int start_col = 0;
    int end_row = 2;
    int end_col = 2;
    // Find the shortest path from the start node to the end node
    find_path(maze, start_row, start_col, end_row, end_col);
    // Print the shortest path
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->nodes[i][j].visited) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}