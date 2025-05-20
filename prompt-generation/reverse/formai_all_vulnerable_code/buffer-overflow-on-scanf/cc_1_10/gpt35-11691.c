//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 /* Maximum number of vertices */
#define MAX_COLOR 10 /* Maximum number of colors */
#define TRUE 1
#define FALSE 0

int adj[MAX_VERTICES][MAX_VERTICES], degree[MAX_VERTICES], color[MAX_VERTICES];

int n, m; /* number of vertices, edges */

void InitGraph()
{
 int i, j;
 
 for(i=0; i<n; i++)
 {
  degree[i] = 0;
  
  for(j=0; j<n; j++)
  {
   adj[i][j] = 0;
  }
 }
}

void ReadGraph()
{
 int i, j, v1, v2;
 
 scanf("%d %d", &n, &m);
 
 InitGraph();
 
 for(i=0; i<m; i++)
 {
  scanf("%d %d", &v1, &v2);
  
  adj[v1][v2] = adj[v2][v1] = 1;
  
  degree[v1]++;
  degree[v2]++;
 }
}

int GetNextVertex(int currentIndex)
{
 int i;
 
 for(i=currentIndex+1; i<n; i++)
 {
  if(color[i] == 0)
  {
   return i;
  }
 }
 
 return -1; /* All vertices have been colored */
}

int IsOK(int vertexIndex, int currentColor)
{
 int i;
 
 for(i=0; i<n; i++)
 {
  if(adj[vertexIndex][i] && currentColor == color[i])
  {
   return FALSE;
  }
 }
 
 return TRUE;
}

int Coloring(int index)
{
 int i, j;
 
 if(index == n)
 {
  return TRUE; /* All vertices have been colored */
 }
 
 for(i=1; i<=MAX_COLOR; i++)
 {
  if(IsOK(index, i))
  {
   color[index] = i;
   
   j = GetNextVertex(index);
   
   if(j == -1 || Coloring(j))
   {
    return TRUE;
   }
   
   color[index] = 0; /* Un-color the vertex */
  }
 }
 
 return FALSE; /* Coloring failed */
}

void PrintSolution()
{
 int i;
 
 printf("\nSolution:\n");
 
 for(i=0; i<n; i++)
 {
  printf("Color[%d]: %d\n", i, color[i]);
 }
}

int main()
{
 printf("Enter the graph (number of vertices and edges):\n");
 ReadGraph();
 
 if(Coloring(0))
 {
  PrintSolution();
 }
 else
 {
  printf("\nColoring failed!\n");
 }
 
 return 0;
}