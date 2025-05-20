//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES]; // Graph matrix
int colors[MAX_VERTICES]; // Color array
int n_vertices, n_colors; // Number of vertices and colors

void print_colors(int vertices);

int can_be_colored(int vertex, int color) {
  for(int i=0; i<n_vertices; i++) {
    if(graph[vertex][i] && color == colors[i]) {
        return 0;
    }
  }
  return 1;
}

int color_graph(int vertex) {
  if(vertex == n_vertices) {
    print_colors(vertex);
    return 1;
  }

  for(int color=1; color<=n_colors; color++) {
    if(can_be_colored(vertex, color)) {
        colors[vertex] = color;

        if(color_graph(vertex+1)) {
            return 1;
        }

        colors[vertex] = 0;  // backtrack
    }
  }
  return 0;
}

int main() {
  printf("Welcome to the Graph Coloring Problem in C!\n\n");
  printf("Our program will help you color your graph using the minimum number of colors possible.\n");
  printf("Please enter the number of vertices (Max 50): ");
  scanf("%d", &n_vertices);
  printf("Please enter the number of colors: ");
  scanf("%d", &n_colors);
  printf("\n");
  
  printf("Great! Now please enter the graph in the following format:\n");
  printf("(For example, to enter an edge between vertices 0 and 1, enter '0 1'. To exit, enter '-1 -1')\n\n");

  // Initialize graph
  for(int i=0; i<n_vertices; i++) {
    for(int j=0; j<n_vertices; j++) {
        graph[i][j] = 0;
    }
  }

  int u, v;
  printf("Enter an edge: ");
  scanf("%d %d", &u, &v);

  while(u != -1 && v != -1) {
    if(u>=n_vertices || v>=n_vertices || u<0 || v<0) {
        printf("The entered vertex is out of range. Please enter a valid vertex.\n");
    }
    else {
        graph[u][v] = graph[v][u] = 1;
    }
    printf("Enter an edge: ");
    scanf("%d %d", &u, &v);
  }

  // Color the graph
  printf("\n\nColoring the graph...\n\n");
  if(color_graph(0)) {
    printf("\nThe graph was successfully colored using %d colors!\n", n_colors);
  }
  else {
    printf("\nUnable to color the graph using %d colors.\n", n_colors);
  }

  return 0;
}

void print_colors(int vertex) {
  printf("Coloring...\n");
  for(int i=0; i<vertex; i++) {
    printf("Vertex %d => Color %d\n", i, colors[i]);
  }
  printf("\n");
}