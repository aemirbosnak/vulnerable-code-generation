//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 12

int graph[ROW][COL] = {
  {1,1,1,1,0,0,1,1,1,1,1,1},
  {1,0,0,0,1,0,1,1,1,1,1,1},
  {1,1,1,0,0,0,1,0,1,1,1,1},
  {1,1,1,1,1,1,1,0,1,1,1,1},
  {1,0,1,1,1,0,0,0,1,1,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1}
};

int size[ROW][COL];
bool visited[ROW][COL];

void BFS(int row, int col) {
  int i, j;
  for(i = 0; i < ROW; i++) {
    for(j = 0; j < COL; j++) {
      size[i][j] = -1;
    }
  }

  size[row][col] = 0;
  visited[row][col] = true;

  int queue[ROW * COL];
  int front = 0, rear = 0;
  queue[rear++] = row * COL + col;

  while(front < rear) {
    int cur = queue[front++];
    row = cur / COL;
    col = cur % COL;

    if(row > 0 && !visited[row - 1][col] && graph[row - 1][col]) {
      queue[rear++] = (row - 1) * COL + col;
      visited[row - 1][col] = true;
      size[row - 1][col] = size[row][col] + 1;
    }
    if(row < ROW - 1 && !visited[row + 1][col] && graph[row + 1][col]) {
      queue[rear++] = (row + 1) * COL + col;
      visited[row + 1][col] = true;
      size[row + 1][col] = size[row][col] + 1;
    }
    if(col > 0 && !visited[row][col - 1] && graph[row][col - 1]) {
      queue[rear++] = row * COL + col - 1;
      visited[row][col - 1] = true;
      size[row][col - 1] = size[row][col] + 1;
    }
    if(col < COL - 1 && !visited[row][col + 1] && graph[row][col + 1]) {
      queue[rear++] = row * COL + col + 1;
      visited[row][col + 1] = true;
      size[row][col + 1] = size[row][col] + 1;
    }
  }
}

void printLengths() {
  int i, j;
  printf("Distances from start:\n");
  for(i = 0; i < ROW; i++) {
    for(j = 0; j < COL; j++) {
      printf("%2d ", size[i][j]);
    }
    printf("\n");
  }
}

void printPath(int row, int col) {
  int curSize = size[row][col];
  printf("(%d,%d)", row, col);
  while(curSize > 0) {
    if(row > 0 && size[row - 1][col] == curSize - 1) {
      printf("<-(%d,%d)", row - 1, col);
      row--;
    } else if(row < ROW - 1 && size[row + 1][col] == curSize - 1) {
      printf("<-(%d,%d)", row + 1, col);
      row++;
    } else if(col > 0 && size[row][col - 1] == curSize - 1) {
      printf("<-(%d,%d)", row, col - 1);
      col--;
    } else if(col < COL - 1 && size[row][col + 1] == curSize - 1) {
      printf("<-(%d,%d)", row, col + 1);
      col++;
    }
    curSize--;
  }
}

int main() {
  int row, col;
  printf("Enter start row and column: ");
  scanf("%d %d", &row, &col);

  BFS(row, col);

  printLengths();

  printf("Enter destination row and column: ");
  scanf("%d %d", &row, &col);
  printf("Shortest path:\n");
  printPath(row, col);
  printf("\n");

  return 0;
}