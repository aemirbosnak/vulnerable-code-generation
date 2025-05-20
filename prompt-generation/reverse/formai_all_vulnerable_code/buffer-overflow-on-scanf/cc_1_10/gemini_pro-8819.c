//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NUM 100
#define MAX_COLOR_NUM 10

typedef struct {
    int vertex_num;
    int edge_num;
    int adjacency_matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertex_color[MAX_VERTEX_NUM];
} Graph;

Graph* create_graph(int vertex_num, int edge_num) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertex_num = vertex_num;
    graph->edge_num = edge_num;
    
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    
    for (int i = 0; i < edge_num; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph->adjacency_matrix[vertex1][vertex2] = 1;
        graph->adjacency_matrix[vertex2][vertex1] = 1;
    }
    
    return graph;
}

void print_graph(Graph* graph) {
    printf("Vertex Number: %d\n", graph->vertex_num);
    printf("Edge Number: %d\n", graph->edge_num);
    
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertex_num; i++) {
        for (int j = 0; j < graph->vertex_num; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Vertex Color:\n");
    for (int i = 0; i < graph->vertex_num; i++) {
        printf("%d ", graph->vertex_color[i]);
    }
    printf("\n");
}

int is_safe(Graph* graph, int vertex, int color) {
    for (int i = 0; i < graph->vertex_num; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && graph->vertex_color[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(Graph* graph, int vertex, int color_num) {
    if (vertex == graph->vertex_num) {
        return 1;
    }
    
    for (int color = 1; color <= color_num; color++) {
        if (is_safe(graph, vertex, color)) {
            graph->vertex_color[vertex] = color;
            if (graph_coloring(graph, vertex + 1, color_num)) {
                return 1;
            }
            graph->vertex_color[vertex] = 0;
        }
    }
    
    return 0;
}

int main() {
    int vertex_num, edge_num, color_num;
    scanf("%d %d %d", &vertex_num, &edge_num, &color_num);
    
    Graph* graph = create_graph(vertex_num, edge_num);
    
    if (graph_coloring(graph, 0, color_num)) {
        printf("Graph can be colored with %d colors.\n", color_num);
        print_graph(graph);
    } else {
        printf("Graph cannot be colored with %d colors.\n", color_num);
    }
    
    return 0;
}