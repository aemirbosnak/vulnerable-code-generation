//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n, int **colors)
{
  int i, j, k, available, current_color = 0;

  for (i = 0; i < n; i++)
  {
    available = 1;
    for (j = 0; j < n; j++)
    {
      if (graph[i][j] && colors[j] == colors[i])
      {
        available = 0;
      }
    }

    if (available)
    {
      colors[i] = current_color;
      current_color++;
    }
  }
}

int main()
{
  int n, m, i, j, **graph, **colors;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the number of edges: ");
  scanf("%d", &m);

  graph = (int **)malloc(n * sizeof(int *));
  colors = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    graph[i] = (int *)malloc(m * sizeof(int));
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }

  graph_coloring(graph, n, colors);

  printf("The coloring of the graph is:\n");

  for (i = 0; i < n; i++)
  {
    printf("%d ", colors[i]);
  }

  printf("\n");

  return 0;
}