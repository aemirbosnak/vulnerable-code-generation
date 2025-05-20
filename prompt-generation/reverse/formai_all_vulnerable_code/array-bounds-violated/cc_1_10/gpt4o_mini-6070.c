//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INF 999999

int grid[MAX][MAX]; // Represents the grid
int dist[MAX][MAX]; // Distance from source
bool visited[MAX][MAX]; // For keeping track of visited nodes

int rows, cols;

// Movement directions: right, down, left, up
int rowDir[] = {0, 1, 0, -1};
int colDir[] = {1, 0, -1, 0};

// Function to initialize the grid
void initializeGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 1; // Assuming 1 is a walkable cell
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }
}

// Function to print the distance matrix
void printDistanceMatrix() {
    printf("Distance Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Main pathfinding function (Dijkstra's algorithm)
void dijkstra(int startRow, int startCol, int endRow, int endCol) {
    dist[startRow][startCol] = 0;
    
    while (true) {
        int minDist = INF;
        int minRow = -1, minCol = -1;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && dist[i][j] < minDist) {
                    minDist = dist[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }

        // If there's no reachable node left, break
        if (minDist == INF) break;

        visited[minRow][minCol] = true;

        // Update distance for neighbors
        for (int d = 0; d < 4; d++) {
            int newRow = minRow + rowDir[d];
            int newCol = minCol + colDir[d];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (!visited[newRow][newCol] && grid[newRow][newCol] != 0) {
                    if (dist[newRow][newCol] > dist[minRow][minCol] + grid[newRow][newCol]) {
                        dist[newRow][newCol] = dist[minRow][minCol] + grid[newRow][newCol];
                    }
                }
            }
        }
    }
    
    // Print results
    printf("Shortest distance from (%d, %d) to (%d, %d): %d\n", startRow, startCol, endRow, endCol, dist[endRow][endCol]);
}

// Entry point of the program
int main() {
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of cols: ");
    scanf("%d", &cols);
    
    initializeGrid();
    
    int startRow, startCol, endRow, endCol;
    printf("Enter start row and column (0-indexed): ");
    scanf("%d %d", &startRow, &startCol);
    printf("Enter end row and column (0-indexed): ");
    scanf("%d %d", &endRow, &endCol);

    // Set some arbitrary obstacles
    grid[1][1] = 0; // Block cell (1,1)
    grid[1][2] = 0; // Block cell (1,2)
    grid[2][1] = 0; // Block cell (2,1)

    dijkstra(startRow, startCol, endRow, endCol);
    printDistanceMatrix();

    return 0;
}