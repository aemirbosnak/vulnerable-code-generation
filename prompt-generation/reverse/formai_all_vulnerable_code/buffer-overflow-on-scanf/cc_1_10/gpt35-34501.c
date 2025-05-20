//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 30 // maximum number of vertices in graph

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix representation of graph
int colors[MAX_VERTICES]; // array to store the color of each vertex
int num_vertices, num_colors; // variables to store the number of vertices and colors

bool is_valid(int v, int c) { 
	// function to check if it is valid to color vertex 'v' with color 'c'
	for (int i = 0; i < num_vertices; i++) {
		if (graph[v][i] && c == colors[i]) {
			return false;
		}
	}
	return true;
}

bool graph_coloring(int v) {
	// recursive function to perform graph coloring
	if (v == num_vertices) {
		// all vertices have been colored
		return true;
	}
	for (int c = 1; c <= num_colors; c++) {
		if (is_valid(v, c)) {
			colors[v] = c;
			if (graph_coloring(v + 1)) {
				return true;
			}
			// backtrack
			colors[v] = 0;
		}
	}
	return false;
}

int main() {
	printf("Enter the number of vertices in the graph: ");
	scanf("%d", &num_vertices);
	
	printf("Enter the adjacency matrix of the graph:\n");
	for (int i = 0; i < num_vertices; i++) {
		for (int j = 0; j < num_vertices; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	
	printf("Enter the number of colors to be used: ");
	scanf("%d", &num_colors);
	
	if (graph_coloring(0)) {
		printf("The graph can be colored with %d colors as follows:\n", num_colors);
		for (int i = 0; i < num_vertices; i++) {
			printf("Vertex %d: Color %d\n", i, colors[i]);
		}
	}
	else {
		printf("The graph cannot be colored with %d colors.\n", num_colors);
	}
	
	return 0;
}