//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10
#define MAX_VERTICES 100

int num_vertices;
int num_colors;
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

bool is_valid_coloring() {
	for (int i = 0; i < num_vertices; i++) {
		for (int j = i + 1; j < num_vertices; j++) {
			if (graph[i][j] == 1 && colors[i] == colors[j]) {
				return false;
			}
		}
	}
	return true;
}

void print_coloring() {
	for (int i = 0; i < num_vertices; i++) {
		printf("Vertex %d: %d\n", i, colors[i]);
	}
}

bool color_graph(int vertex, int color) {
	if (vertex == num_vertices) {
		return is_valid_coloring();
	}

	for (int i = 0; i < num_colors; i++) {
		colors[vertex] = i;
		if (color_graph(vertex + 1, color)) {
			return true;
		}
	}

	return false;
}

int main() {
	printf("Enter the number of vertices: ");
	scanf("%d", &num_vertices);

	printf("Enter the number of colors: ");
	scanf("%d", &num_colors);

	printf("Enter the adjacency matrix:\n");
	for (int i = 0; i < num_vertices; i++) {
		for (int j = 0; j < num_vertices; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	bool found = false;
	for (int i = 0; i < num_colors; i++) {
		if (color_graph(0, i)) {
			found = true;
			break;
		}
	}

	if (found) {
		printf("A valid coloring has been found:\n");
		print_coloring();
	} else {
		printf("No valid coloring exists.\n");
	}

	return 0;
}