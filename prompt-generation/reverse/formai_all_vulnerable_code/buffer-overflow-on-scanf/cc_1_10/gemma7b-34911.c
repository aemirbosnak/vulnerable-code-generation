//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
  int n, m, i, j, k, l, graph[MAX][MAX], color[MAX], paranoia[MAX];
  char flag[MAX], message[MAX];

  n = m = 0;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the number of edges: ");
  scanf("%d", &m);

  graph[0][0] = 1;
  graph[0][1] = 1;
  graph[1][0] = 1;
  graph[1][2] = 1;
  graph[2][1] = 1;
  graph[2][3] = 1;
  graph[3][2] = 1;

  for (i = 0; i < n; i++)
  {
    color[i] = 0;
  }

  for (i = 0; i < m; i++)
  {
    paranoia[i] = 0;
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (graph[i][j] == 1)
      {
        paranoia[i] = 1;
      }
    }
  }

  for (i = 0; i < m; i++)
  {
    if (paranoia[i] == 1)
    {
      flag[i] = 1;
    }
  }

  printf("The vertices that are connected to a vertex with a paranoia flag are: ");

  for (i = 0; i < m; i++)
  {
    if (flag[i] == 1)
    {
      printf("%d ", i + 1);
    }
  }

  printf("\n");

  return 0;
}