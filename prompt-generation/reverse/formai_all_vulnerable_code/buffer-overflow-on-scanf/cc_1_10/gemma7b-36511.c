//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void createMaze(int **maze, int n, int m);
void printMaze(int **maze, int n, int m);
int solveMaze(int **maze, int n, int m, int x, int y);

int main()
{
  int n, m, x, y;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  printf("Enter the number of columns: ");
  scanf("%d", &m);

  int **maze = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    maze[i] = (int *)malloc(m * sizeof(int));
  }

  createMaze(maze, n, m);
  printMaze(maze, n, m);

  x = solveMaze(maze, n, m, 0, 0);

  if (x)
  {
    printf("The solution: \n");
    printMaze(maze, n, m);
  }
  else
  {
    printf("No solution found.\n");
  }

  free(maze);

  return 0;
}

void createMaze(int **maze, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      maze[i][j] = 0;
    }
  }

  maze[0][0] = 1;
  maze[n - 1][m - 1] = 1;
}

void printMaze(int **maze, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int solveMaze(int **maze, int n, int m, int x, int y)
{
  if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] != 0)
  {
    return 0;
  }

  maze[x][y] = 1;

  if (x == n - 1 && y == m - 1)
  {
    return 1;
  }

  return solveMaze(maze, n, m, x - 1, y) || solveMaze(maze, n, m, x, y - 1);
}