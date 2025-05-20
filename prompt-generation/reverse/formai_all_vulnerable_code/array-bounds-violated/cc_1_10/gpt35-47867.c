//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

#define ROWS 10    // number of rows
#define COLS 10    // number of columns

int maze[ROWS][COLS] = {     //maze grid
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
   {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
   {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
   {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
   {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main(){
   int row, col;   // variables to store current row and column
   int end_row = ROWS-1, end_col = COLS-1;  // destination coordinates
   int path_count = 1;    // number of paths counted
   int dead_ends = 0;     // number of dead ends encountered
   int path_found = 0;    // flag to check if path is found
   int path[ROWS*COLS][2];    // array to store path coordinates
   int stack_top = -1;    // top index of path storing stack

   path[++stack_top][0] = 0;  // start coordinates
   path[stack_top][1] = 0;
   maze[0][0] = 2;     // mark start as visited

   while(stack_top >= 0){   // while there are paths to check
      row = path[stack_top][0];  // get current coordinates
      col = path[stack_top][1];

      if(row == end_row && col == end_col){  // if destination reached
         path_found = 1;      // mark path as found
         printf("Path %d found:\n", path_count++);
         for(int i=0; i<=stack_top; i++)
            printf("(%d, %d) ", path[i][0], path[i][1]);
         putchar('\n');
         stack_top--;     // remove last coordinates from stack
         maze[row][col] = 0;   // mark current block as unvisited
         continue;
      }

      // check for available paths
      if(maze[row-1][col] == 0){    // check north
         path[++stack_top][0] = row-1;   // push coordinates
         path[stack_top][1] = col;
         maze[row-1][col] = 2;    // mark block as visited
         continue;  // explore new block
      }
      if(maze[row][col+1] == 0){    // check east
         path[++stack_top][0] = row;
         path[stack_top][1] = col+1;
         maze[row][col+1] = 2;
         continue;
      }
      if(maze[row+1][col] == 0){    // check south
         path[++stack_top][0] = row+1;
         path[stack_top][1] = col;
         maze[row+1][col] = 2;
         continue;
      }
      if(maze[row][col-1] == 0){    // check west
         path[++stack_top][0] = row;
         path[stack_top][1] = col-1;
         maze[row][col-1] = 2;
         continue;
      }

      // if dead end is encountered
      maze[row][col] = 3;    // mark current block as dead end
      dead_ends++;     // count dead end
      stack_top--;     // remove last coordinates from stack
   }

   if(!path_found){     // if no path is found
      printf("No path found\n");
      return 0;
   }

   printf("\nPaths explored: %d\nDead ends encountered: %d\n", path_count-1, dead_ends);
   return 0;
}