//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void generateMaze(int **maze, int n, int m);
void findPath(int **maze, int n, int m, int x, int y, char **path);

int main()
{
  int n, m;
  int **maze;
  char **path;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  printf("Enter the number of columns: ");
  scanf("%d", &m);

  maze = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    maze[i] = (int *)malloc(m * sizeof(int));
  }

  path = (char *)malloc((n + 1) * (m + 1) * sizeof(char));

  generateMaze(maze, n, m);
  findPath(maze, n, m, 0, 0, path);

  printf("The path is: ");
  for (int i = 0; path[i] != '\0'; i++)
  {
    printf("%c ", path[i]);
  }

  return 0;
}

void generateMaze(int **maze, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      maze[i][j] = rand() % 2;
    }
  }
}

void findPath(int **maze, int n, int m, int x, int y, char **path)
{
  path[x][y] = 'x';

  if (x == n - 1 && y == m - 1)
  {
    return;
  }

  if (maze[x][y] == 0 && path[x][y] != 'x')
  {
    findPath(maze, n, m, x + 1, y, path);
    findPath(maze, n, m, x, y + 1, path);
  }
}