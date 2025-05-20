//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h> 

/* Maximum number of vertices a graph can have */ 
#define MAX_VERTICES 100 

/* Function to check if a given vertex can be assigned a particular color or not */ 
int isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int vertex, int color, int numVertices) 
{ 
  /* Check if adjacent vertices have the same color */ 
  for (int i = 0; i < numVertices; i++) 
    if (graph[vertex][i] && color == colors[i]) 
      return 0; 

  return 1; 
} 

/* Recursive function to solve the graph coloring problem */ 
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int vertex, int numVertices, int numColors) 
{ 
  /* If all vertices are assigned a color then return 1 */ 
  if (vertex == numVertices) 
    return 1; 

  /* Try all colors one by one */ 
  for (int i = 1; i <= numColors; i++) 
  { 
    /* Check if the current color can be assigned to the vertex */ 
    if (isSafe(graph, colors, vertex, i, numVertices)) 
    { 
      colors[vertex] = i; 

      /* Recur for next vertices */ 
      if (graphColoringUtil(graph, colors, vertex + 1, numVertices, numColors)) 
        return 1; 

      /* If the current color doesn't lead to a solution, then backtrack */ 
      colors[vertex] = 0; 
    } 
  } 

  /* If no color can be assigned to this vertex, return 0 */ 
  return 0; 
} 

/* Wrapper function to solve the graph coloring problem */ 
int graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int numColors) 
{ 
  /* Initialize all colors as 0 */ 
  int colors[MAX_VERTICES]; 
  for (int i = 0; i < numVertices; i++) 
    colors[i] = 0; 

  /* Call the recursive function to solve the problem */ 
  if (!graphColoringUtil(graph, colors, 0, numVertices, numColors)) 
  { 
    printf("Solution does not exist"); 
    return 0; 
  } 

  /* Print the solution */ 
  printf("Solution Exists: The color of each vertex is as follows -\n"); 
  for (int i = 0; i < numVertices; i++) 
    printf("Vertex %d -> Color %d\n", i+1, colors[i]); 

  return 1; 
} 

/* Driver function */ 
int main() 
{ 
  int numVertices, numEdges, numColors, i, j, vertex1, vertex2; 
  int graph[MAX_VERTICES][MAX_VERTICES]; 

  /* Input */ 
  printf("Enter the number of vertices in the graph: "); 
  scanf("%d", &numVertices); 

  /* Initialize the graph with zeroes */ 
  for (i = 0; i < numVertices; i++) 
    for (j = 0; j < numVertices; j++) 
      graph[i][j] = 0; 

  /* Input the edges */ 
  printf("Enter the number of edges in the graph: "); 
  scanf("%d", &numEdges); 
  printf("Enter the edges:\n"); 

  for (i = 0; i < numEdges; i++) 
  { 
    scanf("%d%d", &vertex1, &vertex2); 
    graph[vertex1-1][vertex2-1] = graph[vertex2-1][vertex1-1] = 1; 
  } 

  /* Input the number of colors */ 
  printf("Enter the number of colors: "); 
  scanf("%d", &numColors); 

  /* Call the wrapper function to solve the problem */ 
  graphColoring(graph, numVertices, numColors); 

  return 0; 
}