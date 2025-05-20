//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct graph {
    int V; // Number of vertices in the graph
    int **adj; // Adjacency matrix of the graph
};

// Function to initialize a graph
void init_graph(struct graph *g, int V) {
    g->V = V;
    g->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0; // Initialize all edges as NULL
        }
    }
}

// Function to add an edge to the graph
void add_edge(struct graph *g, int v1, int v2) {
    g->adj[v1][v2] = 1; // Add an edge from vertex v1 to v2
}

// Function to print the graph
void print_graph(struct graph *g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            if (g->adj[i][j] == 1) {
                printf("(%d, %d) ", i+1, j+1);
            }
        }
        printf("\n");
    }
}

// Function to check if there is a path from vertex u to vertex v in the graph
bool has_path(struct graph *g, int u, int v) {
    if (u == v) {
        return true; // There is a path from u to itself
    }
    if (g->adj[u][v] == 1) {
        return true; // There is a direct edge from u to v
    }
    for (int i = 0; i < g->V; i++) {
        if (has_path(g, u, i) && has_path(g, i, v)) {
            return true; // There is a path from u to i and from i to v
        }
    }
    return false; // There is no path from u to v
}

// Function to find the shortest path between two vertices in the graph
void find_shortest_path(struct graph *g, int u, int v, int *dist, int *pred) {
    dist[u] = 0; // Initialize distance from u to itself as 0
    pred[u] = -1; // Initialize predecessor of u as NULL

    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            if (g->adj[i][j] == 1) {
                dist[j] = dist[i] + 1; // Update distance from i to j
            }
        }
    }

    dist[v] = -1; // Mark v as unreachable

    for (int i = 0; i < g->V; i++) {
        if (has_path(g, u, i) && dist[i] < dist[v]) {
            dist[v] = dist[i];
            pred[v] = i; // Update shortest distance and predecessor
        }
    }
}

// Main function
int main() {
    int V; // Number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct graph g;
    init_graph(&g, V); // Initialize the graph

    int u, v; // Vertex indices
    printf("Enter the vertices to add an edge: ");
    scanf("%d %d", &u, &v);
    add_edge(&g, u-1, v-1); // Add an edge between u and v

    printf("\nGraph representation:\n");
    print_graph(&g); // Print the graph representation

    int dist[V], pred[V]; // Distance and predecessor arrays
    find_shortest_path(&g, 0, V-1, dist, pred); // Find the shortest path

    printf("\nShortest path from vertex 0 to vertex %d is: ", V-1);
    for (int i = 0; i < V; i++) {
        if (i == V-1) {
            printf("%d\n", dist[i]);
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("Predecessor of vertex %d is: ", V-1);
    printf("%d\n", pred[V-1]);

    return 0;
}