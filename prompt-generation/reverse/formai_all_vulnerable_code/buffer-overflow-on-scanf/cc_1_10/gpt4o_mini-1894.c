//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_COLORS 5

typedef struct {
    int n; // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
} Graph;

void initGraph(Graph *g, int vertices) {
    g->n = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adj[i][j] = 0; // Initialize adjacency matrix
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1; // Undirected graph
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->n; j++) {
            if (g->adj[i][j])
                printf("%d ", j);
        }
        printf("\n");
    }
}

int isSafe(Graph *g, int v, int color[], int c) {
    for (int i = 0; i < g->n; i++) {
        if (g->adj[v][i] && color[i] == c)
            return 0; // Unsafe to color
    }
    return 1; // Safe to color
}

int graphColoringUtil(Graph *g, int m, int color[], int v) {
    if (v == g->n) 
        return 1; // All vertices processed
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(g, v, color, c)) {
            color[v] = c; // Assign color c
            if (graphColoringUtil(g, m, color, v + 1))
                return 1;
            color[v] = 0; // Backtrack
        }
    }
    return 0; // No valid coloring found
}

void graphColoring(Graph *g, int m) {
    int *color = (int *)malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++)
        color[i] = 0; // Initialize colors

    if (!graphColoringUtil(g, m, color, 0)) {
        printf("Solution does not exist\n");
        return;
    }
    
    printf("Solution Found:\n");
    for (int i = 0; i < g->n; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    
    free(color);
}

int main() {
    Graph g;
    int vertices, edges, u, v, m;
    
    printf("Welcome to the Magical Graph Coloring Adventure!\n");
    printf("How many vertices (1-20) does your graph possess?: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX_VERTICES) {
        printf("You mighty traveler, the number of vertices must be between 1 and %d!\n", MAX_VERTICES);
        return 1;
    }

    initGraph(&g, vertices);
    
    printf("Now, brave soul, how many edges shall connect these vertices?: ");
    scanf("%d", &edges);
    
    printf("Begin your daring edge creations!\n");
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            addEdge(&g, u, v);
        } else {
            printf("Your edge creation failed! Both vertices must be between 0 and %d.\n", vertices - 1);
            i--; // Retry the same edge input
        }
    }

    printGraph(&g);

    printf("Last but certainly not least, Santa's reindeer need how many colors to paint this graph? (1 to 5): ");
    scanf("%d", &m);
    
    if (m < 1 || m > MAX_COLORS) {
        printf("Halt! You can only use colors between 1 and %d!\n", MAX_COLORS);
        return 2;
    }

    graphColoring(&g, m);
    
    printf("The adventure of coloring is complete! Go forth and conquer.\n");
    return 0;
}