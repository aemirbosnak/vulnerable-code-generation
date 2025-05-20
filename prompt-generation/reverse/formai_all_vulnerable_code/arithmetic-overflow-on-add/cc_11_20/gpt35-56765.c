//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define ROW 8
#define COL 8

// Function to print the path taken by the algorithm
void printPath(int path[ROW][COL], int sx, int sy, int ex, int ey) {
    printf("Path Taken:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (path[i][j] == 1 && i == sx && j == sy) {
                printf("S ");
            } else if (path[i][j] == 1 && i == ex && j == ey) {
                printf("E ");
            } else if (path[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to perform the A* search algorithm
void aStar(int maze[ROW][COL], int sx, int sy, int ex, int ey) {
    int openList[ROW * COL][2], closedList[ROW * COL][2], path[ROW][COL];
    int fCost[ROW][COL], gCost[ROW][COL], hCost[ROW][COL];
    int current[2], end[2];
    int index, counter, temp, found, movementCost, min, next;
    
    // Initialise arrays and variables
    counter = 0;
    found = 0;
    openList[counter][0] = sx;
    openList[counter][1] = sy;
    gCost[sx][sy] = 0;
    hCost[sx][sy] = abs(ex - sx) + abs(ey - sy);
    fCost[sx][sy] = gCost[sx][sy] + hCost[sx][sy];
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if ((i == sx && j == sy) || (i == ex && j == ey)) {
                continue;
            }
            gCost[i][j] = ROW * COL;
            hCost[i][j] = abs(ex - i) + abs(ey - j);
            fCost[i][j] = gCost[i][j] + hCost[i][j];
        }
    }
    
    // Loop until goal is found or there are no more nodes in the open list
    while (found == 0 && counter < ROW * COL) {
        // Find the node with the lowest fCost
        min = ROW * COL;
        for (int i = 0; i <= counter; i++) {
            if (fCost[openList[i][0]][openList[i][1]] < min) {
                min = fCost[openList[i][0]][openList[i][1]];
                index = i;
            }
        }
        
        // Remove node from the open list and add to closed list
        current[0] = openList[index][0];
        current[1] = openList[index][1];
        openList[index][0] = -1;
        openList[index][1] = -1;
        counter++;
        
        closedList[counter][0] = current[0];
        closedList[counter][1] = current[1];
        
        // Check if goal node has been reached
        if (current[0] == ex && current[1] == ey) {
            found = 1;
            break;
        }
        
        // Loop through adjacent nodes and calculate movement cost
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                next = 0;
                if (current[0]+i >= 0 && current[0]+i < ROW && current[1]+j >= 0 && current[1]+j < COL && maze[current[0]+i][current[1]+j] == 0) {
                    movementCost = 1;
                    next = 1;
                    for (int k = 1; k <= counter; k++) {
                        if (current[0]+i == closedList[k][0] && current[1]+j == closedList[k][1]) {
                            next = 0;
                            break;
                        }
                    }
                    if (next == 1) {
                        temp = gCost[current[0]][current[1]] + movementCost;
                        if (temp < gCost[current[0]+i][current[1]+j]) {
                            gCost[current[0]+i][current[1]+j] = temp;
                            hCost[current[0]+i][current[1]+j] = abs(ex - (current[0]+i)) + abs(ey - (current[1]+j));
                            fCost[current[0]+i][current[1]+j] = gCost[current[0]+i][current[1]+j] + hCost[current[0]+i][current[1]+j];
                            path[current[0]+i][current[1]+j] = 1;
                            for (int k = 0; k <= counter; k++) {
                                if (openList[k][0] == current[0]+i && openList[k][1] == current[1]+j) {
                                    next = 0;
                                    break;
                                }
                            }
                            if (next == 1) {
                                counter++;
                                openList[counter][0] = current[0]+i;
                                openList[counter][1] = current[1]+j;
                            }
                        }
                    }
                }
            }
        }
    }
    
    // If goal was found, print path
    if (found == 1) {
        printPath(path, sx, sy, ex, ey);
    } else {
        printf("Goal not found!\n");
    }
}

int main() {
    int maze[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 1, 0, 1, 0, 0},
                          {0, 0, 0, 0, 1, 1, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 1, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0}};
    int startX, startY, endX, endY;
    
    printf("Enter starting x and y coordinates: ");
    scanf("%d %d", &startX, &startY);
    printf("Enter ending x and y coordinates: ");
    scanf("%d %d", &endX, &endY);
    
    aStar(maze, startX, startY, endX, endY);
    
    return 0;
}