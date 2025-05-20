//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Function prototypes
Graph* create_graph(int vertices);
void add_edge(Graph *g, int src, int dest);
void display_graph(Graph *g);
void bfs(Graph *g, int start_vertex);
void dfs(Graph *g, int start_vertex, bool visited[]);

// Main function
int main() {
    int vertices, edges, src, dest;
    Graph *g;

    printf("Welcome to the Awesome Graph Representation Program!\n");
    printf("How many vertices does your graph have (max %d)? ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Invalid number of vertices! Please try again!\n");
        return -1;
    }

    g = create_graph(vertices);
    printf("How many edges do you want to add? ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (format: src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        add_edge(g, src, dest);
    }

    printf("\nHere is your graph's representation:\n");
    display_graph(g);

    int start_vertex;
    printf("\nLet's perform a BFS traversal!\nEnter the starting vertex: ");
    scanf("%d", &start_vertex);
    bfs(g, start_vertex);

    printf("\nLet's perform a DFS traversal!\nEnter the starting vertex: ");
    scanf("%d", &start_vertex);
    bool visited[MAX_VERTICES] = {false}; // Initiating the visited array
    dfs(g, start_vertex, visited);

    // Free memory
    free(g);
    return 0;
}

// Function to create a graph
Graph* create_graph(int vertices) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->num_vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->edges[i][j] = 0; // Initialize edges to 0
        }
    }
    return g;
}

// Function to add an edge
void add_edge(Graph *g, int src, int dest) {
    if (src >= g->num_vertices || dest >= g->num_vertices || src < 0 || dest < 0) {
        printf("Invalid edge!\n");
        return;
    }
    g->edges[src][dest] = 1; // Add edge from src to dest
    g->edges[dest][src] = 1; // Uncomment for undirected graph
}

// Function to display the graph
void display_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->edges[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// BFS traversal function
void bfs(Graph *g, int start_vertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[start_vertex] = true;
    queue[rear++] = start_vertex;

    printf("BFS Traversal: ");
    while (front < rear) {
        int current_vertex = queue[front++];
        printf("%d ", current_vertex);

        for (int i = 0; i < g->num_vertices; i++) {
            if (g->edges[current_vertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS traversal function
void dfs(Graph *g, int start_vertex, bool visited[]) {
    visited[start_vertex] = true;
    printf("%d ", start_vertex);

    for (int i = 0; i < g->num_vertices; i++) {
        if (g->edges[start_vertex][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}