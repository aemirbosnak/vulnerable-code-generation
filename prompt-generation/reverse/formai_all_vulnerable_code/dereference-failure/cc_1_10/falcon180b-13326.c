//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_V 100

// structure for vertex
struct Vertex {
    char name[20];
    int parent[20];
};

// structure for graph
struct Graph {
    int V;
    struct Vertex *adj_matrix;
};

// function to add an edge
void addEdge(struct Graph *graph, char u, char v) {
    int i, j;
    for(i=0; i<graph->V; i++) {
        if(graph->adj_matrix[i].name[0] == u) {
            for(j=0; j<graph->V; j++) {
                if(graph->adj_matrix[j].name[0] == v) {
                    graph->adj_matrix[i].parent[j] = 1;
                    break;
                }
            }
        }
    }
}

// function to check if two vertices are connected
int isConnected(struct Graph *graph, char u, char v) {
    int i, j;
    for(i=0; i<graph->V; i++) {
        if(graph->adj_matrix[i].name[0] == u) {
            for(j=0; j<graph->V; j++) {
                if(graph->adj_matrix[j].name[0] == v) {
                    if(graph->adj_matrix[i].parent[j] == 1) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// function to print the graph
void printGraph(struct Graph *graph) {
    int i, j;
    for(i=0; i<graph->V; i++) {
        printf("%c ", graph->adj_matrix[i].name[0]);
        for(j=0; j<graph->V; j++) {
            if(graph->adj_matrix[i].parent[j] == 1) {
                printf("(%d) ", j);
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    struct Graph graph;
    graph.V = 5;
    graph.adj_matrix = (struct Vertex *)malloc(graph.V * sizeof(struct Vertex));
    strcpy(graph.adj_matrix[0].name, "A");
    strcpy(graph.adj_matrix[1].name, "B");
    strcpy(graph.adj_matrix[2].name, "C");
    strcpy(graph.adj_matrix[3].name, "D");
    strcpy(graph.adj_matrix[4].name, "E");
    addEdge(&graph, 'A', 'B');
    addEdge(&graph, 'A', 'C');
    addEdge(&graph, 'B', 'D');
    addEdge(&graph, 'C', 'D');
    addEdge(&graph, 'C', 'E');
    addEdge(&graph, 'D', 'E');
    printf("Graph:\n");
    printGraph(&graph);
    printf("\nIs A connected to E? %d\n", isConnected(&graph, 'A', 'E'));
    return 0;
}