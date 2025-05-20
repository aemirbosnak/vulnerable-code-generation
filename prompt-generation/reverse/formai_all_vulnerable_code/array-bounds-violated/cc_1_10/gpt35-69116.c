//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 30
#define MAX_EDGES 50
#define MAX_COLORS 6

int graph[MAX_VERTICES][MAX_EDGES];
int color[MAX_VERTICES];
int number_of_vertices, number_of_edges;

/* Function to randomly generate edges in the graph */
void generate_edges() {
    srand(time(0));
    for(int i = 0; i < number_of_edges; i++) {
        int vertex1 = rand() % number_of_vertices;
        int vertex2 = rand() % number_of_vertices;
        while(vertex2 == vertex1 || 
            (graph[vertex1][0] && graph[vertex1][0] == vertex2) || 
            (graph[vertex2][0] && graph[vertex2][0] == vertex1)) {
            vertex1 = rand() % number_of_vertices;
            vertex2 = rand() % number_of_vertices;
        }
        graph[vertex1][++graph[vertex1][0]] = vertex2;
        graph[vertex2][++graph[vertex2][0]] = vertex1;
    }
}

/* Function to check if the current vertex can be assigned a certain color */
int is_color_allowed(int vertex, int c) {
    for(int i = 0; i < graph[vertex][0]; i++) {
        if(color[graph[vertex][i+1]] == c) {
            return 0;
        }
    }
    return 1;
}

/* Function to assign colors to the vertices of the graph */
void assign_colors(int vertex) {
    if(vertex == number_of_vertices) {
        // If all vertices have been assigned colors, print the solution
        printf("Solution: ");
        for(int i = 0; i < number_of_vertices; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
        return;
    }
    for(int c = 1; c <= MAX_COLORS; c++) {
        if(is_color_allowed(vertex, c)) {
            color[vertex] = c;
            assign_colors(vertex+1);
            color[vertex] = 0;
        }
    }
}

int main() {
    printf("Enter the number of vertices in the graph (<= %d): ", MAX_VERTICES);
    scanf("%d", &number_of_vertices);
    printf("Enter the number of edges in the graph (<= %d): ", number_of_vertices * (number_of_vertices - 1) / 2);
    scanf("%d", &number_of_edges);
    generate_edges();
    assign_colors(0);
    return 0;
}