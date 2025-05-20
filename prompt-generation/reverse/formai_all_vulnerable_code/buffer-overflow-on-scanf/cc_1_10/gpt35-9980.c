//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_COLORS 10

int n; //number of vertices
int m; //number of edges
int graph[MAX_VERTICES][MAX_VERTICES]; //adjacency matrix

int domain[MAX_VERTICES]; //domain of colors
int colors[MAX_VERTICES]; //actual colors assigned to each vertex

//initialize colors to 0
void initColors() {
  for(int i=0; i<n; i++){
    colors[i] = 0;
  }
}

//check if a vertex is safe to color with a particular color
int isSafe(int vertex, int color) {
  for(int i=0; i<n; i++){
    if(graph[vertex][i] && color == colors[i]) {
      return 0;
    }
  }
  return 1;
}

//print the colors of each vertex
void printColors() {
  printf("Vertex Colors:\n");
  for(int i=0; i<n; i++){
    printf("Vertex %d: Color %d\n", i, colors[i]);
  }
  printf("\n");
}

//recursive function to assign colors to vertices
int assignColors(int vertex) {
  if(vertex == n) {
    return 1;
  }
  
  //try each color in the domain
  for(int i=0; i<m; i++){
    int color = domain[i];
    if(isSafe(vertex, color)) {
      colors[vertex] = color;
      //recurse to the next vertex
      if(assignColors(vertex+1)){
        return 1;
      }
      //backtrack
      colors[vertex] = 0;
    }
  }
  return 0;
}

int main(){
  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &n, &m);
  
  printf("Enter the edges (i, j):\n");
  for(int i=0; i<m; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u][v] = graph[v][u] = 1;
  }
  
  //initialize domain of colors
  for(int i=0; i<m; i++){
    domain[i] = i+1;
  }
  
  initColors();
  if(assignColors(0)){
    printf("Graph can be colored using at most %d colors\n", m);
    printColors();
  }
  else{
    printf("Graph cannot be colored using at most %d colors\n", m);
  }
  return 0;
}