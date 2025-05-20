//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: funny
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

int grid[ROW][COL] = {0};
int closedList[ROW][COL];
int openList[ROW*COL][2];
int parent[ROW*COL][2];
int h[ROW][COL];
int g[ROW][COL];
int f[ROW][COL];
int startX, startY, endX, endY;
int listLength = 0;

void reset() {
    int i,j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            closedList[i][j] = 0;
            grid[i][j] = 0;
            h[i][j] = 0;
            g[i][j] = 0;
            f[i][j] = 0;
            parent[i][j] = -1;
        }
    }
}

void printGrid() {
    int i,j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void printPath(int startX, int startY, int endX, int endY) {
    int path[ROW*COL][2];
    int i = 0;
    int j;
    int next[2];
    int current[2] = {endX, endY};
    while(current[0] != startX || current[1] != startY) {
        path[i][0] = current[0];
        path[i][1] = current[1];
        i++;
        current[0] = parent[current[0]*COL+current[1]][0];
        current[1] = parent[current[0]*COL+current[1]][1];
    }
    printf("Path: (%d, %d) ", startX, startY);
    for(j=i-1; j>=0; j--) {
        printf("-> (%d, %d) ", path[j][0], path[j][1]);
    }
    printf("-> (%d, %d)\n", endX, endY);
}

int calcH(int x, int y) {
    return abs(endX-x) + abs(endY-y);
}

int calcG(int x, int y) {
    return g[x][y] + 1;
}

int calcF(int x, int y) {
    return h[x][y] + calcG(x,y);
}

void addToOpenList(int x, int y) {
    if(x >= 0 && x < ROW && y >= 0 && y < COL) {
        if(grid[x][y] != 1 && closedList[x][y] == 0) {
            openList[listLength][0] = x;
            openList[listLength][1] = y;
            listLength++;
        }
    }
}

int main() {
    //initialize the grid
    reset();
    int i,j;
    for(i=0; i<ROW; i++) {
        for(j=0; j<COL; j++) {
            if(i == 0 || i == ROW-1 || j == 0 || j == COL-1) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
    //set the starting and ending points
    startX = 2;
    startY = 2;
    endX = 8;
    endY = 8;
    //initialize the lists
    listLength = 0;
    for(i=0; i<ROW*COL; i++) {
        openList[i][0] = -1;
        openList[i][1] = -1;
    }
    //A* algorithm
    int currentX, currentY;
    openList[listLength][0] = startX;
    openList[listLength][1] = startY;
    listLength++;
    g[startX][startY] = 0;
    h[startX][startY] = calcH(startX, startY);
    f[startX][startY] = calcF(startX, startY);
    while(listLength > 0) {
        int minF = ROW*COL+1;
        int minIndex = -1;
        for(i=0; i<listLength; i++) {
            if(f[openList[i][0]][openList[i][1]] < minF) {
                minF = f[openList[i][0]][openList[i][1]];
                minIndex = i;
            }
        }
        currentX = openList[minIndex][0];
        currentY = openList[minIndex][1];
        if(currentX == endX && currentY == endY) {
            printf("Path Found!\n");
            printPath(startX, startY, endX, endY);
            break;
        }
        for(i=-1; i<=1; i++) {
            for(j=-1; j<=1; j++) {
                if(i==0 && j==0) continue;
                int neighborX = currentX+i;
                int neighborY = currentY+j;
                if(i*j == 0) {
                    if(i==0) {
                        if(j==1) {
                            printf("Robot moved right.");
                        }
                        else {
                            printf("Robot moved left.");
                        }
                    }
                    else {
                        if(i==1) {
                            printf("Robot moved down.");
                        }
                        else {
                            printf("Robot moved up.");
                        }
                    }
                }
                else {
                    printf("Robot tried to move diagonally but failed miserably.");
                }
                printf("\n");
                int neighborG = calcG(neighborX, neighborY);
                if(grid[neighborX][neighborY] == 1) continue;
                if(closedList[neighborX][neighborY] == 1) continue;
                if(neighborX < 0 || neighborX >= ROW) continue;
                if(neighborY < 0 || neighborY >= COL) continue;

                int index = -1;
                int k;
                for(k=0; k<listLength; k++) {
                    if(openList[k][0] == neighborX && openList[k][1] == neighborY) {
                        index = k;
                        break;
                    }
                }
                if(index == -1) {
                    parent[neighborX*COL+neighborY][0] = currentX;
                    parent[neighborX*COL+neighborY][1] = currentY;
                    h[neighborX][neighborY] = calcH(neighborX, neighborY);
                    g[neighborX][neighborY] = neighborG;
                    f[neighborX][neighborY] = calcF(neighborX, neighborY);
                    addToOpenList(neighborX, neighborY);
                }
                else {
                    if(neighborG < g[neighborX][neighborY]) {
                        g[neighborX][neighborY] = neighborG;
                        f[neighborX][neighborY] = calcF(neighborX, neighborY);
                        parent[neighborX*COL+neighborY][0] = currentX;
                        parent[neighborX*COL+neighborY][1] = currentY;
                    }
                }
            }
        }
        closedList[currentX][currentY] = 1;
        openList[minIndex][0] = openList[listLength-1][0];
        openList[minIndex][1] = openList[listLength-1][1];
        listLength--;
    }
    if(listLength <= 0) {
        printf("Path Not Found!\n");
    }
    return 0;
}