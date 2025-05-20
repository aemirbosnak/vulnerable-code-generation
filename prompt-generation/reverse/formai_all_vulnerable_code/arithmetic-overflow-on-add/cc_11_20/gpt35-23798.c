//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int row, col;
    struct Node* parent;
    int g, h, f;
    bool closed;
} Node;

int heuristic(Node* node, Node* goal) {
    return abs(node->row - goal->row) + abs(node->col - goal->col);
}

int main() {
    Node grid[ROWS][COLS];
    Node* start = &grid[0][0];
    Node* goal = &grid[ROWS-1][COLS-1];
    start->row = 0;
    start->col = 0;
    start->parent = NULL;
    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    
    // Initialize grid
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == 0 && col == 0) continue;
            if (row == ROWS-1 && col == COLS-1) continue;
            grid[row][col].row = row;
            grid[row][col].col = col;
            grid[row][col].parent = NULL;
            grid[row][col].g = -1;
            grid[row][col].h = -1;
            grid[row][col].f = -1;
            grid[row][col].closed = false;
        }
    }
    
    // A* algorithm
    Node* open_list[ROWS*COLS];
    int open_list_len = 0;
    open_list[0] = start;
    open_list_len++;
    
    while (open_list_len > 0) {
        // Find node with minimum f-cost
        Node* current = open_list[0];
        int current_idx = 0;
        for (int i = 1; i < open_list_len; i++) {
            Node* node = open_list[i];
            if (node->f < current->f) {
                current = node;
                current_idx = i;
            }
        }
        
        // Goal found
        if (current == goal) {
            printf("Path found!\n");
            // Display path
            Node* node = current;
            while (node != NULL) {
                printf("Row: %d, Col: %d\n", node->row, node->col);
                node = node->parent;
            }
            return 0;
        }
        
        // Remove current from open_list
        for (int i = current_idx; i < open_list_len-1; i++) {
            open_list[i] = open_list[i+1];
        }
        open_list_len--;
        
        // Add neighbors to open_list
        int row = current->row;
        int col = current->col;
        if (row > 0) {
            Node* node = &grid[row-1][col];
            if (node->closed == false) {
                if (node->g == -1 || current->g+1 < node->g) {
                    node->g = current->g + 1;
                    node->h = heuristic(node, goal);
                    node->f = node->g + node->h;
                    node->parent = current;
                    open_list[open_list_len] = node;
                    open_list_len++;
                }
            }
        }
        if (row < ROWS-1) {
            Node* node = &grid[row+1][col];
            if (node->closed == false) {
                if (node->g == -1 || current->g+1 < node->g) {
                    node->g = current->g + 1;
                    node->h = heuristic(node, goal);
                    node->f = node->g + node->h;
                    node->parent = current;
                    open_list[open_list_len] = node;
                    open_list_len++;
                }
            }
        }
        if (col > 0) {
            Node* node = &grid[row][col-1];
            if (node->closed == false) {
                if (node->g == -1 || current->g+1 < node->g) {
                    node->g = current->g + 1;
                    node->h = heuristic(node, goal);
                    node->f = node->g + node->h;
                    node->parent = current;
                    open_list[open_list_len] = node;
                    open_list_len++;
                }
            }
        }
        if (col < COLS-1) {
            Node* node = &grid[row][col+1];
            if (node->closed == false) {
                if (node->g == -1 || current->g+1 < node->g) {
                    node->g = current->g + 1;
                    node->h = heuristic(node, goal);
                    node->f = node->g + node->h;
                    node->parent = current;
                    open_list[open_list_len] = node;
                    open_list_len++;
                }
            }
        }
        
        // Close current
        current->closed = true;
    }
    
    printf("No path found.\n");
    return 0;
}