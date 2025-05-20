//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int number_of_vertices, number_of_edges, number_of_colors;
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

/**
 * @brief Display the graph in matrix form
 * 
 */
void display_graph() {
    printf("The graph in matrix form is as follows:\n");
    for(int i = 0; i < number_of_vertices; i++) {
        for(int j = 0; j < number_of_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Get input from the user about the graph
 * 
 */
void get_input() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &number_of_vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &number_of_edges);

    printf("Enter the number of colors to be used to color the vertices: ");
    scanf("%d", &number_of_colors);

    printf("Enter the edges in the graph:\n");
    for(int i = 0; i < number_of_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
}

/**
 * @brief Check if the given vertex can be assigned the given color
 * 
 * @param vertex The vertex
 * @param color The color
 * @return true If the given color can be assigned to the vertex
 * @return false Otherwise
 */
bool is_safe(int vertex, int color) {
    for(int i = 0; i < number_of_vertices; i++) {
        if(graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Recursively assign colors to the vertices of the graph
 * 
 * @param vertex The vertex to be assigned a color
 * @return true If all the vertices can be assigned colors
 * @return false Otherwise
 */
bool graph_coloring(int vertex) {
    if(vertex == number_of_vertices) {
        return true;
    }

    for(int i = 1; i <= number_of_colors; i++) {
        if(is_safe(vertex, i)) {
            colors[vertex] = i;
            if(graph_coloring(vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }

    return false;
}

/**
 * @brief Display the colored graph
 * 
 */
void display_colored_graph() {
    printf("The colored graph is as follows:\n");
    for(int i = 0; i < number_of_vertices; i++) {
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    }
}

int main() {
    get_input();
    display_graph();

    bool can_color = graph_coloring(0);

    if(can_color) {
        display_colored_graph();
    } else {
        printf("The graph cannot be colored with %d colors.\n", number_of_colors);
    }

    return 0;
}