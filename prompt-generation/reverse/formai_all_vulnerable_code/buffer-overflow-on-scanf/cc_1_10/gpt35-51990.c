//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// Structure for the individual player
struct player {
   int x;
   int y;
};

// Initialize the maze
int maze[ROW][COL] = {
   {1, 0, 1, 1, 1},
   {1, 0, 1, 0, 1},
   {1, 0, 1, 0, 1},
   {1, 0, 1, 0, 1},
   {1, 1, 1, 0, 1},
};

// Arrays to store the coordinates for the shortest path
int pathX[ROW*COL];
int pathY[ROW*COL];
int pathLength = 0;

// Function to print the maze
void printMaze() {
   int i, j;
   for (i=0; i<ROW; i++) {
      for (j=0; j<COL; j++) {
         printf("%d ", maze[i][j]);
      }
      printf("\n");
   }
}

// Function to check if a given coordinate is within the maze
int isInside(int x, int y) {
   if (x>=0 && x<ROW && y>=0 && y<COL) {
      return 1;
   }
   else {
      return 0;
   }
}

// Function to check if a given coordinate is a valid path
// A valid path is a coordinate with a value of 1
int isValidPath(int x, int y) {
   if (isInside(x, y) == 1 && maze[x][y] == 1) {
      return 1;
   }
   else {
      return 0;
   }
}

// Function to find the shortest path between two coordinates using Breadth First Search algorithm
void findShortestPath(int sourceX, int sourceY, int destX, int destY) {
   int visited[ROW][COL], distance[ROW][COL];
   int prevX[ROW][COL], prevY[ROW][COL];
   int queueRow[ROW*COL], queueCol[ROW*COL];
   int queueSize = 0;
   struct player players[2] = {{sourceX, sourceY}, {destX, destY}};
   int currentPlayer = 0;
   
   // Initialize all distances to infinity
   int i, j;
   for (i=0; i<ROW; i++) {
      for (j=0; j<COL; j++) {
         distance[i][j] = 9999;
         visited[i][j] = 0;
      }
   }
   
   // Mark the source as visited and set its distance to 0
   visited[sourceX][sourceY] = 1;
   distance[sourceX][sourceY] = 0;
   
   // Add the source to the queue
   queueRow[queueSize] = sourceX;
   queueCol[queueSize] = sourceY;
   queueSize++;
   
   // Breadth First Search algorithm
   while (queueSize > 0) {
      // Get the next coordinate from the queue
      int currentRow = queueRow[0];
      int currentCol = queueCol[0];
      queueSize--;
      int nextRow, nextCol;
      
      // Check all the adjacent coordinates
      for (i=-1; i<=1; i++) {
         for (j=-1; j<=1; j++) {
            // Ignore the current coordinate
            if (i==0 && j==0) {
               continue;
            }
            
            // Calculate the next coordinate
            nextRow = currentRow + i;
            nextCol = currentCol + j;
            
            // Check if the next coordinate is a valid path and has not been visited yet
            if (isValidPath(nextRow, nextCol) == 1 && visited[nextRow][nextCol] == 0) {
               // Mark the next coordinate as visited and set its distance
               visited[nextRow][nextCol] = 1;
               distance[nextRow][nextCol] = distance[currentRow][currentCol] + 1;
               prevX[nextRow][nextCol] = currentRow;
               prevY[nextRow][nextCol] = currentCol;
               
               // Add the next coordinate to the queue
               queueRow[queueSize] = nextRow;
               queueCol[queueSize] = nextCol;
               queueSize++;
            }
         }
      }
      
      if (currentRow == destX && currentCol == destY) {
          // Straighten the path by removing nodes that are not necessary
          int tempX = destX, tempY = destY;
          while (tempX != sourceX || tempY != sourceY) {
             pathX[pathLength] = tempX;
             pathY[pathLength] = tempY;
             pathLength++;
             int tempX2 = tempX;
             tempX = prevX[tempX][tempY];
             tempY = prevY[tempX2][tempY];
          }

          pathX[pathLength] = sourceX;
          pathY[pathLength] = sourceY;
          pathLength++;

          // Print the path
          printf("\nShortest path:\n");
          int k;
          for (k=pathLength-1; k>=0; k--) {
              printf("(%d, %d) -> ", pathX[k], pathY[k]);
          }
          printf("(%d, %d)\n", destX, destY);
          break;
       }
       currentPlayer++;
       currentPlayer %= 2;
       sourceX = players[currentPlayer].x;
       sourceY = players[currentPlayer].y;
   }
}

int main()
{
   // Initialize the starting and ending coordinates
   int startX, startY, endX, endY;
   printf("Enter the starting coordinates (row, col): ");
   scanf("%d%d", &startX, &startY);
   printf("Enter the ending coordinates (row, col): ");
   scanf("%d%d", &endX, &endY);

   // Find the shortest path between the starting and ending coordinates
   findShortestPath(startX, startY, endX, endY);

   return 0;
}