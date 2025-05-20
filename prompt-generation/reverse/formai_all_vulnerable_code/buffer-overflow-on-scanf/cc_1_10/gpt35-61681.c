//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_vertices 100

bool graph[max_vertices][max_vertices];
int num_vertices, num_colors;
int vertex_colors[max_vertices];

void init_graph(){
   int i, j;
   for(i=0; i<num_vertices; i++)
      for(j=0; j<num_vertices; j++)
         graph[i][j] = false;
}

void add_edge(int v1, int v2){
   graph[v1][v2] = true;
   graph[v2][v1] = true;
}

bool is_valid_coloring(int vertex, int color){
   int i;
   for(i=0; i<num_vertices; i++)
      if(graph[vertex][i] && vertex_colors[i] == color)
         return false;
   return true;   
}

bool color_graph(int vertex){
   int color;
   if(vertex == num_vertices)
      return true;

   for(color=1; color<=num_colors; color++){
      if(is_valid_coloring(vertex, color)){
         vertex_colors[vertex] = color;
         if(color_graph(vertex+1))
            return true;
      }
      vertex_colors[vertex] = 0;
   }
   return false;   
}

void print_colors(){
   int i;
   for(i=0; i<num_vertices; i++)
      printf("Vertex %d: Color %d\n", i, vertex_colors[i]);
}

int main(){
   int num_edges, i, v1, v2;
   printf("Enter number of vertices: ");
   scanf("%d", &num_vertices);

   init_graph();

   printf("Enter number of edges: ");
   scanf("%d", &num_edges);

   printf("Enter edges (vertex1 vertex2): \n");
   for(i=0; i<num_edges; i++){
      scanf("%d%d", &v1, &v2);
      add_edge(v1, v2);
   }

   printf("Enter number of colors: ");
   scanf("%d", &num_colors);

   if(color_graph(0)){
      printf("Possible coloring:\n");
      print_colors();
   }
   else
      printf("No valid coloring found\n");

   return 0;
}