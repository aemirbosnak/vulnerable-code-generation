//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 100

int main()
{
  int num_verts, num_edges, i, j, color, best_color = -1;
  int **graph = NULL;
  int *visited = NULL;
  int *colors = NULL;

  printf("Enter the number of vertices: ");
  scanf("%d", &num_verts);

  graph = (int **)malloc(num_verts * sizeof(int *));
  visited = (int *)malloc(num_verts * sizeof(int));
  colors = (int *)malloc(num_verts * sizeof(int));

  for (i = 0; i < num_verts; i++)
  {
    graph[i] = (int *)malloc(num_verts * sizeof(int));
  }

  printf("Enter the number of edges: ");
  scanf("%d", &num_edges);

  for (i = 0; i < num_edges; i++)
  {
    scanf("%d %d", &j, &color);
    graph[j][color] = 1;
  }

  for (i = 0; i < num_verts; i++)
  {
    visited[i] = 0;
    colors[i] = -1;
  }

  for (i = 0; i < num_verts; i++)
  {
    if (!visited[i])
    {
      color = dfs(graph, visited, colors, i);
      best_color = color;
    }
  }

  printf("The best color is: %d\n", best_color);

  return 0;
}

int dfs(int **graph, int *visited, int *colors, int current)
{
  int i, color;
  visited[current] = 1;

  for (i = 0; i < MAX_VERTS; i++)
  {
    if (graph[current][i] && !visited[i])
    {
      colors[i] = color;
      dfs(graph, visited, colors, i);
    }
  }

  return color;
}