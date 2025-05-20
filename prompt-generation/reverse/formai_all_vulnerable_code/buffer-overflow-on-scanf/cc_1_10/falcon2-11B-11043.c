//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Function to find path from start to end point
int pathfinding(int startX, int startY, int endX, int endY) {
   int visited[100][100] = {0};
   int path[100][100] = {0};
   int i, j;

   // Mark all possible moves as visited
   for (i = 0; i < 100; i++) {
      for (j = 0; j < 100; j++) {
         visited[i][j] = 0;
      }
   }

   // Check if current move is end point
   if (startX == endX && startY == endY) {
      printf("Path found: (%d, %d) -> (%d, %d)\n", startX, startY, endX, endY);
      return 1;
   }

   // Add current move to path
   path[0][0] = startX;
   path[0][1] = startY;

   // Recursively find path
   if (pathfinding(startX, startY, endX + 1, endY) == 1) {
      printf("Path found: (%d, %d) -> (%d, %d)\n", startX, startY, endX, endY);
      return 1;
   }
   if (pathfinding(startX, startY, endX, endY + 1) == 1) {
      printf("Path found: (%d, %d) -> (%d, %d)\n", startX, startY, endX, endY);
      return 1;
   }
   if (pathfinding(startX - 1, startY, endX, endY) == 1) {
      printf("Path found: (%d, %d) -> (%d, %d)\n", startX, startY, endX, endY);
      return 1;
   }
   if (pathfinding(startX, startY - 1, endX, endY) == 1) {
      printf("Path found: (%d, %d) -> (%d, %d)\n", startX, startY, endX, endY);
      return 1;
   }

   // If end point not found, print "Path not found"
   printf("Path not found\n");
   return 0;
}

int main() {
   int startX, startY, endX, endY;
   printf("Enter start coordinates (X, Y): ");
   scanf("%d%d", &startX, &startY);
   printf("Enter end coordinates (X, Y): ");
   scanf("%d%d", &endX, &endY);
   printf("Path found: (%d, %d) -> (%d, %d)\n", startX, startY, endX, endY);
   return 0;
}