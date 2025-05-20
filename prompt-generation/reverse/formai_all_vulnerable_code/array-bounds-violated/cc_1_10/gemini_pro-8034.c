//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the grid size
#define GRID_SIZE 10

// Define the start and goal positions
int start_x = 0, start_y = 0;
int goal_x = 9, goal_y = 9;

// Define the grid
int grid[GRID_SIZE][GRID_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the heuristic function
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Define the A* algorithm
int astar(int start_x, int start_y, int goal_x, int goal_y) {
    // Create the open and closed lists
    int open_list[GRID_SIZE * GRID_SIZE];
    int closed_list[GRID_SIZE * GRID_SIZE];

    // Add the start node to the open list
    open_list[0] = start_x + start_y * GRID_SIZE;

    // While the open list is not empty
    while (open_list[0] != -1) {
        // Get the node with the lowest f-score from the open list
        int current_node = open_list[0];
        for (int i = 1; i < GRID_SIZE * GRID_SIZE; i++) {
            if (open_list[i] != -1 && grid[current_node / GRID_SIZE][current_node % GRID_SIZE] + heuristic(current_node / GRID_SIZE, current_node % GRID_SIZE, goal_x, goal_y) > grid[open_list[i] / GRID_SIZE][open_list[i] % GRID_SIZE] + heuristic(open_list[i] / GRID_SIZE, open_list[i] % GRID_SIZE, goal_x, goal_y)) {
                current_node = open_list[i];
            }
        }

        // Remove the current node from the open list
        for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
            if (open_list[i] == current_node) {
                open_list[i] = -1;
                break;
            }
        }

        // Add the current node to the closed list
        closed_list[current_node] = 1;

        // Check if the goal node has been reached
        if (current_node == goal_x + goal_y * GRID_SIZE) {
            return 1;
        }

        // Get the neighbors of the current node
        int neighbors[4] = {current_node - 1, current_node + 1, current_node - GRID_SIZE, current_node + GRID_SIZE};

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            // Check if the neighbor is valid and not in the closed list
            if (neighbors[i] >= 0 && neighbors[i] < GRID_SIZE * GRID_SIZE && closed_list[neighbors[i]] == 0) {
                // Calculate the g-score and f-score of the neighbor
                int g_score = grid[neighbors[i] / GRID_SIZE][neighbors[i] % GRID_SIZE] + grid[current_node / GRID_SIZE][current_node % GRID_SIZE];
                int f_score = g_score + heuristic(neighbors[i] / GRID_SIZE, neighbors[i] % GRID_SIZE, goal_x, goal_y);

                // Add the neighbor to the open list if it is not already in the list
                int found = 0;
                for (int j = 0; j < GRID_SIZE * GRID_SIZE; j++) {
                    if (open_list[j] == neighbors[i]) {
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    open_list[GRID_SIZE * GRID_SIZE] = neighbors[i];
                }
            }
        }
    }

    // Return 0 if the goal node was not reached
    return 0;
}

// Main function
int main() {
    // Check if the goal node is reachable
    if (astar(start_x, start_y, goal_x, goal_y) == 1) {
        printf("The goal node was reached.\n");
    } else {
        printf("The goal node was not reached.\n");
    }

    return 0;
}