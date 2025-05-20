//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the grid
#define ROWS 10
#define COLS 10

// Define directions
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

// Define a node on the grid
typedef struct Node {
    int row;
    int col;
    int f_score;
    int g_score;
    int h_score;
    struct Node* parent;
} Node;

// Declare the start and end nodes
Node start_node = { 0, 0 };
Node end_node = { ROWS - 1, COLS - 1 };

// Declare the grid
int grid[ROWS][COLS] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 }
};

// Declare the open and closed lists
Node* open_list[ROWS * COLS];
int open_list_size = 0;
bool closed_list[ROWS][COLS];

// Helper function to check if a node is in the open list
bool in_open_list(Node* node) {
    for (int i = 0; i < open_list_size; i++) {
        if (open_list[i]->row == node->row && open_list[i]->col == node->col) {
            return true;
        }
    }
    return false;
}

// Helper function to calculate the h score (distance from a node to the end node)
int calculate_h_score(Node* node) {
    int row_diff = abs(node->row - end_node.row);
    int col_diff = abs(node->col - end_node.col);
    return row_diff + col_diff;
}

// Function to get the node with the lowest f score from the open list
Node* get_lowest_f_score_node() {
    Node* lowest_f_score_node = open_list[0];
    int lowest_f_score = open_list[0]->f_score;
    for (int i = 1; i < open_list_size; i++) {
        if (open_list[i]->f_score < lowest_f_score) {
            lowest_f_score_node = open_list[i];
            lowest_f_score = open_list[i]->f_score;
        }
    }
    return lowest_f_score_node;
}

// Helper function to add a node to the open list
void add_to_open_list(Node* node) {
    open_list[open_list_size] = node;
    open_list_size++;
}

// Helper function to remove a node from the open list
void remove_from_open_list(Node* node) {
    int index;
    for (int i = 0; i < open_list_size; i++) {
        if (open_list[i]->row == node->row && open_list[i]->col == node->col) {
            index = i;
            break;
        }
    }
    for (int i = index; i < open_list_size - 1; i++) {
        open_list[i] = open_list[i + 1];
    }
    open_list_size--;
}

// Helper function to add a node to the closed list
void add_to_closed_list(Node* node) {
    closed_list[node->row][node->col] = true;
}

// Helper function to check if a node is in the closed list
bool in_closed_list(Node* node) {
    return closed_list[node->row][node->col];
}

// Function to get the neighbors of a node
void get_neighbors(Node* node, Node** neighbors) {
    int count = 0;
    // Check north neighbor
    int row = node->row - 1;
    int col = node->col;
    if (row >= 0 && !in_closed_list(&grid[row][col])) {
        neighbors[count] = &grid[row][col];
        count++;
    }
    // Check south neighbor
    row = node->row + 1;
    col = node->col;
    if (row < ROWS && !in_closed_list(&grid[row][col])) {
        neighbors[count] = &grid[row][col];
        count++;
    }
    // Check east neighbor
    row = node->row;
    col = node->col + 1;
    if (col < COLS && !in_closed_list(&grid[row][col])) {
        neighbors[count] = &grid[row][col];
        count++;
    }
    // Check west neighbor
    row = node->row;
    col = node->col - 1;
    if (col >= 0 && !in_closed_list(&grid[row][col])) {
        neighbors[count] = &grid[row][col];
        count++;
    }
}

// Function to find the shortest path using the A* algorithm
void find_shortest_path() {
    // Initialize the start node
    start_node.parent = NULL;
    start_node.g_score = 0;
    start_node.h_score = calculate_h_score(&start_node);
    start_node.f_score = start_node.g_score + start_node.h_score;
    add_to_open_list(&start_node);

    // Loop until the end node is reached or the open list is empty
    while (open_list_size > 0) {
        // Get the node with the lowest f score from the open list
        Node* current_node = get_lowest_f_score_node();

        // Check if the current node is the end node
        if (current_node->row == end_node.row && current_node->col == end_node.col) {
            // Print the path from end to start
            Node* path_node = current_node;
            while (path_node != NULL) {
                printf("(%d, %d)\n", path_node->row, path_node->col);
                path_node = path_node->parent;
            }
            return;
        }

        // Remove the current node from the open list and add it to the closed list
        remove_from_open_list(current_node);
        add_to_closed_list(current_node);

        // Get the current node's neighbors
        Node* neighbors[4];
        get_neighbors(current_node, neighbors);

        // Loop through the neighbors
        for (int i = 0; i < 4; i++) {
            if (neighbors[i] == NULL) {
                continue;
            }
            // Calculate the tentative g score for the neighbor
            int tentative_g_score = current_node->g_score + 1;

            // Check if the neighbor is already in the open list
            bool in_open_list_flag = in_open_list(neighbors[i]);

            // If the neighbor is not in the open list, add it and calculate its scores
            if (!in_open_list_flag) {
                neighbors[i]->parent = current_node;
                neighbors[i]->g_score = tentative_g_score;
                neighbors[i]->h_score = calculate_h_score(neighbors[i]);
                neighbors[i]->f_score = neighbors[i]->g_score + neighbors[i]->h_score;
                add_to_open_list(neighbors[i]);
            }
            // If the neighbor is in the open list and the tentative g score is lower than its current g score, update its scores
            else if (tentative_g_score < neighbors[i]->g_score) {
                neighbors[i]->parent = current_node;
                neighbors[i]->g_score = tentative_g_score;
                neighbors[i]->f_score = neighbors[i]->g_score + neighbors[i]->h_score;
            }
        }
    }

    // Print an error message if the end node cannot be reached
    printf("No path found.\n");
}

// Main function
int main() {
    find_shortest_path();
    return 0;
}