//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find the shortest path using A* algorithm
bool findShortestPath(int grid[3][3], int startX, int startY, int goalX, int goalY) {
    // Variables to keep track of the current position and the best path found
    int currentX = startX, currentY = startY, bestX = -1, bestY = -1;
    int currentG = 0, bestG = 0, currentH = 0, bestH = 0;

    // Variables to keep track of the explored cells
    int explored[3][3] = { 0 };

    // Variables to keep track of the queue and the open set
    int queue[100], open[100], front = -1, rear = -1;

    // Variables to keep track of the distance and heuristic calculations
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    int distance[100], heuristic[100];

    queue[++rear] = -1; // Initialize the queue with the start position

    distance[rear] = 0;
    heuristic[rear] = 0;
    queue[rear] = startX + (startY * 3);

    open[rear] = startX + (startY * 3);
    explored[startX][startY] = 1;

    while (front!= rear) {
        // Get the position of the cell with the lowest cost
        front = queue[++front];

        // If the position is not in the open set or the current position is better than the best position found so far, update the best position
        if (open[front]!= 0 || bestG > distance[front]) {
            currentG = distance[front];
            currentH = heuristic[front];
            currentX = open[front] / 3;
            currentY = open[front] % 3;
            bestX = currentX;
            bestY = currentY;
            bestG = currentG;
            bestH = currentH;
        }

        // Mark the cell as explored
        explored[currentX][currentY] = 1;

        // Check if the current position is the goal position
        if (currentX == goalX && currentY == goalY) {
            return true;
        }

        // Check the neighboring cells
        for (int i = 0; i < 4; i++) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            // Check if the neighboring cell is within the grid and has not been explored
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3 &&!explored[newX][newY]) {
                // Calculate the new cost and heuristic values
                int newG = distance[front] + 1;
                int newH = abs(goalX - newX) + abs(goalY - newY);

                // Check if the new cell is in the open set or if the new cell is better than the current cell
                if (open[newX + (newY * 3)]!= 0 || (newG < distance[newX + (newY * 3)] && newH < heuristic[newX + (newY * 3)])) {
                    // Update the distance, heuristic, open, and queue values
                    distance[newX + (newY * 3)] = newG;
                    heuristic[newX + (newY * 3)] = newH;
                    open[newX + (newY * 3)] = newX + (newY * 3);
                    queue[++rear] = newX + (newY * 3);
                }
            }
        }

        // Mark the current cell as not in the open set
        open[front] = 0;
    }

    return false;
}

int main() {
    int grid[3][3] = { { 0, 1, 2 }, { 0, 2, 0 }, { 0, 2, 0 } };
    int startX = 0, startY = 0, goalX = 2, goalY = 1;

    if (findShortestPath(grid, startX, startY, goalX, goalY)) {
        printf("Shortest path found from (%d, %d) to (%d, %d):\n", startX, startY, goalX, goalY);
    } else {
        printf("No path found from (%d, %d) to (%d, %d).\n", startX, startY, goalX, goalY);
    }

    return 0;
}