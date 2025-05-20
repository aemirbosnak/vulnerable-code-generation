//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 10
#define COL 10

// Structure to represent a cell in the grid
typedef struct {
    int parent_i, parent_j; 
    double f, g, h;
} Cell;

Cell grid[ROW][COL];

// Function prototypes
void printPath(int path[][COL], int n);
double calculateH(int row, int col, int dest_row, int dest_col);
bool isValid(int row, int col);
bool isDestination(int row, int col, int dest_row, int dest_col);
void aStar(int start_row, int start_col, int dest_row, int dest_col);

// Main function
int main() {
    printf("Welcome to the A* Pathfinding Algorithm!\n");
    int start_row, start_col, dest_row, dest_col;

    printf("Enter start coordinates (row col): ");
    scanf("%d %d", &start_row, &start_col);
    printf("Enter destination coordinates (row col): ");
    scanf("%d %d", &dest_row, &dest_col);

    aStar(start_row, start_col, dest_row, dest_col);
    return 0;
}

// Function to calculate heuristic value (Manhattan distance)
double calculateH(int row, int col, int dest_row, int dest_col) {
    return abs(row - dest_row) + abs(col - dest_col);
}

// Function to check if the position is valid
bool isValid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// Function to check if the position is the destination
bool isDestination(int row, int col, int dest_row, int dest_col) {
    return (row == dest_row && col == dest_col);
}

// Function to print the path from start to destination
void printPath(int path[][COL], int n) {
    printf("The path is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < COL; j++) {
            if (path[i][j] == 1) {
                printf("-> ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

// Function that implements A* Pathfinding algorithm
void aStar(int start_row, int start_col, int dest_row, int dest_col) {
    if (!isValid(start_row, start_col) || !isValid(dest_row, dest_col)) {
        printf("Invalid start or destination coordinates. Make sure they are within bounds!\n");
        return;
    }

    if (isDestination(start_row, start_col, dest_row, dest_col)) {
        printf("You are already at the destination!\n");
        return;
    }

    // Create a path array to store the path
    int path[ROW][COL];
    memset(path, 0, sizeof(path));
    path[start_row][start_col] = 1;

    // Initialize the grid
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j].f = grid[i][j].g = grid[i][j].h = 0.0;
            grid[i][j].parent_i = -1;
            grid[i][j].parent_j = -1;
        }
    }

    // Create the priority queue for open cells
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));
    grid[start_row][start_col].g = 0.0;
    grid[start_row][start_col].h = calculateH(start_row, start_col, dest_row, dest_col);
    grid[start_row][start_col].f = grid[start_row][start_col].g + grid[start_row][start_col].h;

    // Open list containing the path nodes
    int openList[ROW * COL][2], openListHead = 0;
    openList[openListHead][0] = start_row;
    openList[openListHead][1] = start_col;
    openListHead++;

    // Main loop
    while (openListHead > 0) {
        int minIndex = 0;
        double minF = grid[openList[0][0]][openList[0][1]].f;

        // Get the cell with the least F value
        for (int i = 1; i < openListHead; i++) {
            if (grid[openList[i][0]][openList[i][1]].f < minF) {
                minF = grid[openList[i][0]][openList[i][1]].f;
                minIndex = i;
            }
        }

        int current_row = openList[minIndex][0];
        int current_col = openList[minIndex][1];

        // Mark the current node as closed
        closedList[current_row][current_col] = true;

        // Check if we have reached the destination
        if (isDestination(current_row, current_col, dest_row, dest_col)) {
            printf("Goal reached!\n");
            printPath(path, ROW);
            return;
        }

        // Check all 4 adjacent cells
        for (int rowOffset = -1; rowOffset <= 1; rowOffset++) {
            for (int colOffset = -1; colOffset <= 1; colOffset++) {
                if (abs(rowOffset) == abs(colOffset)) continue; // skip diagonals

                int adj_row = current_row + rowOffset;
                int adj_col = current_col + colOffset;

                // If the new cell is valid
                if (isValid(adj_row, adj_col) && !closedList[adj_row][adj_col]) {
                    if (isDestination(adj_row, adj_col, dest_row, dest_col)) {
                        grid[adj_row][adj_col].parent_i = current_row;
                        grid[adj_row][adj_col].parent_j = current_col;
                        printf("Goal reached!\n");
                        printPath(path, ROW);
                        return;
                    }

                    // Calculate G, H, and F
                    double gNew = grid[current_row][current_col].g + 1.0;
                    double hNew = calculateH(adj_row, adj_col, dest_row, dest_col);
                    double fNew = gNew + hNew;

                    // If this path is better than previous paths
                    if (grid[adj_row][adj_col].f == 0 || grid[adj_row][adj_col].f > fNew) {
                        path[adj_row][adj_col] = 1;
                        grid[adj_row][adj_col].f = fNew;
                        grid[adj_row][adj_col].g = gNew;
                        grid[adj_row][adj_col].h = hNew;
                        grid[adj_row][adj_col].parent_i = current_row;
                        grid[adj_row][adj_col].parent_j = current_col;

                        // If the cell is not in the open list, add it
                        openList[openListHead][0] = adj_row;
                        openList[openListHead][1] = adj_col;
                        openListHead++;
                    }
                }
            }
        }
    }

    printf("No path found!\n");
}