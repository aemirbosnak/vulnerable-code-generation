//FormAI DATASET v1.0 Category: Graph representation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define MAX 50

struct Graph {
    int V; //total vertices in graph
    int E; //total edges in graph
    int** adj_mat; //pointer to store adjacency matrix
};

//function to create a new graph 
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    if(!graph) {
        printf("Memory allocation error!\n");
        return NULL;
    }

    graph->V = V;
    graph->E = E;
    
    //allocation of memory for adjacency matrix
    graph->adj_mat = (int**) malloc(sizeof(int*) * V);
    for(int i=0; i<V; i++) {
        graph->adj_mat[i] = (int*) malloc(sizeof(int) * V);
    }

    //initializing the matrix with '0'
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            graph->adj_mat[i][j] = 0;
        }
    }

    return graph;
}

//function to add edges to the graph
void add_edges(struct Graph* graph) {
    int u, v;
    for(int i=0; i<graph->E; i++) {
        printf("Enter the start and end point of an edge: ");
        scanf("%d %d", &u, &v);
        graph->adj_mat[u][v] = 1;
        graph->adj_mat[v][u] = 1;
    }
}

//function to print the graph
void printGraph(struct Graph* graph) {
    printf("The adjacency matrix representation of the graph:\n");
    for(int i=0; i<graph->V; i++) {
        for(int j=0; j<graph->V; j++) {
            printf("%d ", graph->adj_mat[i][j]);
        }
        printf("\n");
    }
}

//driver program to test the above functions
int main() {
    int V, E;
    printf("Enter the number of vertices in graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in graph: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    add_edges(graph);

    printGraph(graph);

    return 0;
}