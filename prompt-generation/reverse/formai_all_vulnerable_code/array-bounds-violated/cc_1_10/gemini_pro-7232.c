//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_ROWS 100
#define MAX_COLS 100

// The map of the grid
int grid[MAX_ROWS][MAX_COLS];

// The number of rows and columns in the grid
int rows, cols;

// The starting and ending positions
int startRow, startCol, endRow, endCol;

// The queue of positions to be visited
int queue[MAX_ROWS * MAX_COLS][2];
int queueSize;

// The distances from the starting position to each position in the grid
int distances[MAX_ROWS][MAX_COLS];

// The predecessors of each position in the grid
int predecessors[MAX_ROWS][MAX_COLS][2];

// Initialize the grid
void initGrid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = 0;
      distances[i][j] = INT_MAX;
      predecessors[i][j][0] = -1;
      predecessors[i][j][1] = -1;
    }
  }
}

// Print the grid
void printGrid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Add a position to the queue
void enqueue(int row, int col) {
  queue[queueSize][0] = row;
  queue[queueSize][1] = col;
  queueSize++;
}

// Remove a position from the queue
void dequeue() {
  for (int i = 0; i < queueSize - 1; i++) {
    queue[i][0] = queue[i + 1][0];
    queue[i][1] = queue[i + 1][1];
  }
  queueSize--;
}

// Check if a position is in the queue
int inQueue(int row, int col) {
  for (int i = 0; i < queueSize; i++) {
    if (queue[i][0] == row && queue[i][1] == col) {
      return 1;
    }
  }
  return 0;
}

// Get the distance from the starting position to a position
int getDistance(int row, int col) {
  return distances[row][col];
}

// Set the distance from the starting position to a position
void setDistance(int row, int col, int distance) {
  distances[row][col] = distance;
}

// Get the predecessors of a position
int* getPredecessors(int row, int col) {
  return predecessors[row][col];
}

// Set the predecessors of a position
void setPredecessors(int row, int col, int predRow, int predCol) {
  predecessors[row][col][0] = predRow;
  predecessors[row][col][1] = predCol;
}

// Find the shortest path from the starting position to the ending position
int findPath() {
  // Initialize the queue
  enqueue(startRow, startCol);

  // While the queue is not empty
  while (queueSize > 0) {
    // Get the next position in the queue
    int row = queue[0][0];
    int col = queue[0][1];
    dequeue();

    // If the current position is the ending position, return the distance
    if (row == endRow && col == endCol) {
      return distances[row][col];
    }

    // Get the neighbors of the current position
    int neighbors[4][2] = {{row - 1, col}, {row + 1, col}, {row, col - 1}, {row, col + 1}};

    // For each neighbor
    for (int i = 0; i < 4; i++) {
      int neighborRow = neighbors[i][0];
      int neighborCol = neighbors[i][1];

      // If the neighbor is within the grid and is not a wall
      if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols && grid[neighborRow][neighborCol] == 0) {
        // If the neighbor is not in the queue
        if (!inQueue(neighborRow, neighborCol)) {
          // Add the neighbor to the queue
          enqueue(neighborRow, neighborCol);
        }

        // Calculate the distance from the starting position to the neighbor
        int distance = distances[row][col] + 1;

        // If the distance to the neighbor is less than the current distance
        if (distance < getDistance(neighborRow, neighborCol)) {
          // Set the distance to the neighbor
          setDistance(neighborRow, neighborCol, distance);

          // Set the predecessors of the neighbor
          setPredecessors(neighborRow, neighborCol, row, col);
        }
      }
    }
  }

  // If no path was found, return -1
  return -1;
}

// Print the shortest path from the starting position to the ending position
void printPath() {
  int row = endRow;
  int col = endCol;

  // While the current position is not the starting position
  while (row != startRow || col != startCol) {
    // Print the current position
    printf("(%d, %d) ", row, col);

    // Get the predecessors of the current position
    int* predecessors = getPredecessors(row, col);

    // Set the current position to thePredecessor
    row = predecessors[0];
    col = predecessors[1];
  }

  // Print the starting position
  printf("(%d, %d)\n", row, col);
}

int main() {
  // Get the number of rows and columns in the grid
  printf("Enter the number of rows and columns in the grid: ");
  scanf("%d %d", &rows, &cols);

  // Initialize the grid
  initGrid();

  // Get the starting and ending positions
  printf("Enter the starting position (row, col): ");
  scanf("%d %d", &startRow, &startCol);
  printf("Enter the ending position (row, col): ");
  scanf("%d %d", &endRow, &endCol);

  // Find the shortest path from the starting position to the ending position
  int distance = findPath();

  // If a path was found, print the path
  if (distance != -1) {
    printf("The shortest path from (%d, %d) to (%d, %d) is %d units long.\n", startRow, startCol, endRow, endCol, distance);
    printPath();
  } else {
    printf("No path was found from (%d, %d) to (%d, %d).\n", startRow, startCol, endRow, endCol);
  }

  return 0;
}