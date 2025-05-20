//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define ROW 10 
#define COL 10 

// Structure to hold a cell's coordinates
struct coord {
    int row;
    int col;
}; 

// Structure to hold a cell's information
struct node {
    struct coord cell;
    int f, g, h;
    struct node* parent;
}; 

// Array to represent the map
int map[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1}, 
    {1, 1, 0, 0, 0, 0, 1, 0, 1, 1}, 
    {1, 1, 0, 1, 1, 1, 1, 0, 1, 1}, 
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1}, 
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
};

// Function to check if a cell is valid (not a wall, not out of bounds)
int is_valid(struct coord cell) {
    if (cell.row < 0 || cell.col < 0 || cell.row >= ROW || cell.col >= COL) {
        return 0;
    }
    if (map[cell.row][cell.col] == 1) {
        return 0;
    }
    return 1;
}

// Function to calculate the Manhattan distance between two cells
int manhattan_dist(struct coord cell1, struct coord cell2) {
    return abs(cell1.row - cell2.row) + abs(cell1.col - cell2.col);
}

// Function to find the lowest f cost node in the open list
struct node* lowest_f_cost(struct node** open_list, int open_size) {
    int lowest_f = open_list[0]->f;
    struct node* lowest_node = open_list[0];
    for (int i = 1; i < open_size; i++) {
        if (open_list[i]->f < lowest_f) {
            lowest_f = open_list[i]->f;
            lowest_node = open_list[i];
        }
    }
    return lowest_node;
}

// Function to check if a cell is in a list
int is_in_list(struct coord cell, struct node** list, int list_size) {
    for (int i = 0; i < list_size; i++) {
        if (list[i]->cell.row == cell.row && list[i]->cell.col == cell.col) {
            return 1;
        }
    }
    return 0;
}

// Function to free all allocated node memory
void free_nodes(struct node** open_list, int open_size, struct node** closed_list, int closed_size) {
    for (int i = 0; i < open_size; i++) {
        free(open_list[i]);
    }
    for (int i = 0; i < closed_size; i++) {
        free(closed_list[i]);
    }
}

// Function to print the path found by the algorithm
void print_path(struct node* node_ptr) {
    printf("Path:\n");
    while (node_ptr != NULL) {
        printf("(%d, %d)\n", node_ptr->cell.row, node_ptr->cell.col);
        node_ptr = node_ptr->parent;
    }
}

// Main A* pathfinding algorithm
void a_star(struct coord start, struct coord end) {
    struct node* start_node = malloc(sizeof(struct node));
    start_node->cell = start;
    start_node->f = 0;
    start_node->g = 0;
    start_node->h = 0;
    start_node->parent = NULL;
    
    struct node* open_list[ROW*COL];
    int open_size = 1;
    open_list[0] = start_node;
    
    struct node* closed_list[ROW*COL];
    int closed_size = 0;
    
    while (open_size > 0) {
        struct node* current_node = lowest_f_cost(open_list, open_size);
        if (current_node->cell.row == end.row && current_node->cell.col == end.col) {
            print_path(current_node);
            free_nodes(open_list, open_size, closed_list, closed_size);
            return;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                struct coord neighbor = {current_node->cell.row + i, current_node->cell.col + j};
                if (!is_valid(neighbor) || is_in_list(neighbor, closed_list, closed_size)) {
                    continue;
                }
                struct node* neighbor_node = malloc(sizeof(struct node));
                neighbor_node->cell = neighbor;
                neighbor_node->parent = current_node;
                neighbor_node->g = current_node->g + 1;
                neighbor_node->h = manhattan_dist(neighbor, end);
                neighbor_node->f = neighbor_node->g + neighbor_node->h;
                if (is_in_list(neighbor, open_list, open_size)) {
                    for (int k = 0; k < open_size; k++) {
                        if (open_list[k]->cell.row == neighbor.row && open_list[k]->cell.col == neighbor.col) {
                            if (neighbor_node->g < open_list[k]->g) {
                                open_list[k]->parent = current_node;
                                open_list[k]->g = neighbor_node->g;
                                open_list[k]->f = neighbor_node->f;
                            }
                            free(neighbor_node);
                            neighbor_node = NULL;
                            break;
                        }
                    }
                } else {
                    open_list[open_size] = neighbor_node;
                    open_size++;
                }
            }
        }
        for (int i = 0; i < open_size; i++) {
            if (open_list[i] == current_node) {
                open_list[i] = NULL;
                for (int j = i; j < open_size-1; j++) {
                    open_list[j] = open_list[j+1];
                }
                open_size--;
                break;
            }
        }
        closed_list[closed_size] = current_node;
        closed_size++;
    }
    printf("No path found.\n");
    free_nodes(open_list, open_size, closed_list, closed_size);
}

// Main function to test A* algorithm
int main() {
    struct coord start = {1, 1};
    struct coord end = {8, 8};
    a_star(start, end);
    return 0;
}