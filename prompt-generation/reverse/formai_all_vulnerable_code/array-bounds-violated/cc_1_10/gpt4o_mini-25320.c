//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 9
#define COL 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point parent;
    int f, g, h;
} Node;

typedef struct {
    Point* points;
    int size;
    int capacity;
} Path;

Node grid[ROW][COL];
bool closedList[ROW][COL];

Point start = {0, 0};
Point end = {8, 9};

Point directions[] = {
    {0, 1},  // Right
    {1, 0},  // Down
    {0, -1}, // Left
    {-1, 0}, // Up
    {1, 1},  // Down-Right
    {1, -1}, // Down-Left
    {-1, 1}, // Up-Right
    {-1, -1} // Up-Left
};

// Function to check if a point is valid
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Heuristic function for A* (Manhattan distance)
int calculateH(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// A* Search Algorithm
bool aStar(Point start, Point end) {
    // Initialize open and closed lists
    int openCount = 0;
    Node openList[ROW * COL];
    
    openList[openCount++] = (Node){{-1, -1}, 0, 0, calculateH(start, end)};

    while (openCount > 0) {
        // Find the node with the lowest f value
        int minIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i].f < openList[minIndex].f) {
                minIndex = i;
            }
        }

        Node currentNode = openList[minIndex];
        Point current = {currentNode.parent.x, currentNode.parent.y};

        // If we reached the destination
        if (current.x == end.x && current.y == end.y) {
            return true;
        }

        // Move current node to closedList
        closedList[current.x][current.y] = true;

        // Loop through neighbors
        for (int i = 0; i < sizeof(directions) / sizeof(directions[0]); i++) {
            Point neighbor = {current.x + directions[i].x, current.y + directions[i].y};

            if (isValid(neighbor.x, neighbor.y) && !closedList[neighbor.x][neighbor.y]) {
                int gNew = currentNode.g + 1;
                int hNew = calculateH(neighbor, end);
                int fNew = gNew + hNew;

                // Check if this path to the neighbor is better than previous
                bool foundInOpen = false;
                for (int j = 0; j < openCount; j++) {
                    if (openList[j].parent.x == neighbor.x && openList[j].parent.y == neighbor.y) {
                        foundInOpen = true;
                        if (fNew < openList[j].f) {
                            openList[j].f = fNew;
                            openList[j].g = gNew;
                            openList[j].h = hNew;
                            openList[j].parent = current;
                        }
                        break;
                    }
                }

                // If neighbor not in open list, add it
                if (!foundInOpen) {
                    openList[openCount++] = (Node){current, fNew, gNew, hNew};
                }
            }
        }

        // Remove the current node from open list
        for (int i = minIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;
    }

    return false;
}

// Function to print the path
void printPath(Point current) {
    if (current.x == -1) {
        return;
    }
    printPath(grid[current.x][current.y].parent);
    printf("(%d, %d) -> ", current.x, current.y);
}

int main() {
    if (aStar(start, end)) {
        printf("Path found:\n");
        printPath(end);
        printf("End: (%d, %d)\n", end.x, end.y);
    } else {
        printf("No path found from (%d, %d) to (%d, %d).\n", start.x, start.y, end.x, end.y);
    }
    return 0;
}