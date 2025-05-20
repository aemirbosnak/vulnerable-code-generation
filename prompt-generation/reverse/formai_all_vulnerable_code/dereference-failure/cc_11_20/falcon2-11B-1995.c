//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int rows = 20;
   int cols = 20;
   int** maze = malloc(rows * sizeof(int*));
   int** visited = malloc(rows * sizeof(int*));
   for(int i = 0; i < rows; i++) {
      maze[i] = malloc(cols * sizeof(int));
      visited[i] = malloc(cols * sizeof(int));
   }
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         maze[i][j] = rand() % 2 == 0? 1 : 0;
         visited[i][j] = 0;
      }
   }
   // Print maze
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         if(maze[i][j] == 1)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }
   printf("\n");
   // Start BFS from random point
   int r = rand() % rows;
   int c = rand() % cols;
   int* q = malloc(rows * sizeof(int));
   int* visited_ptr = malloc(rows * sizeof(int));
   for(int i = 0; i < rows; i++)
      q[i] = 0;
   visited_ptr[r] = 1;
   q[0] = r;
   int num_visited = 1;
   while(num_visited < rows * cols) {
      int next_row = q[0];
      q[0] = q[num_visited - 1];
      num_visited--;
      for(int i = 0; i < cols; i++) {
         if(visited[next_row][i] == 0 && maze[next_row][i] == 1) {
            q[num_visited] = i;
            visited[next_row][i] = 1;
            num_visited++;
         }
      }
   }
   // Print path
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         if(visited[i][j] == 1)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }
   printf("\n");
   return 0;
}