//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLANETS 100

// Structure to represent a graph
typedef struct {
    int V; // Number of vertices (planets)
    int graph[MAX_PLANETS][MAX_PLANETS]; // Adjacency matrix representation
} Graph;

// Function to create a graph with V vertices
Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->graph[i][j] = 0;

    return g;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->graph[src][dest] = 1;
    g->graph[dest][src] = 1; // For undirected graph
}

// Function to print the coloring of the planets
void printResult(int color[], int V) {
    printf("Planet Color Assignment:\n");
    for (int i = 0; i < V; i++)
        printf("Planet %d: Color %d\n", i + 1, color[i] + 1); // Color indices start from 0
}

// Check if the current color assignment is safe for planet `v`
bool isSafe(Graph* g, int color[], int v, int c) {
    for (int i = 0; i < g->V; i++) {
        if (g->graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Recursive utility function to solve the coloring problem
bool graphColoringUtil(Graph* g, int m, int color[], int v) {
    if (v == g->V)
        return true;

    for (int c = 0; c < m; c++) {
        if (isSafe(g, color, v, c)) {
            color[v] = c; // Assign color to planet `v`
            if (graphColoringUtil(g, m, color, v + 1))
                return true;
            color[v] = -1; // Backtrack
        }
    }
    return false;
}

// Function to solve the m-coloring problem
bool graphColoring(Graph* g, int m) {
    int* color = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++)
        color[i] = -1; // Initialize all planets as uncolored

    if (!graphColoringUtil(g, m, color, 0)) {
        printf("Solution does not exist.\n");
        free(color);
        return false;
    }

    printResult(color, g->V);
    free(color);
    return true;
}

int main() {
    // Create a futuristic graph representing interstellar alliances among planets
    printf("Welcome to the Interstellar Coloring Federation!\n");
    printf("Let's assign colors to planets based on their alliances.\n");

    int n; // Number of planets
    int m; // Maximum number of colors

    printf("Enter the number of planets: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PLANETS) {
        printf("Invalid number of planets.\n");
        return 1;
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &m);

    Graph* g = createGraph(n);
    
    printf("Enter the alliances between planets as pairs (0 to %d) and -1 to stop:\n", n - 1);
    int src, dest;
    while (true) {
        scanf("%d", &src);
        if (src == -1) break;
        scanf("%d", &dest);
        
        if (src < 0 || src >= n || dest < 0 || dest >= n) {
            printf("Invalid planet index. Please try again.\n");
            continue;
        }
        
        addEdge(g, src, dest);
    }

    printf("\nStarting the color assignment process...\n");
    if (!graphColoring(g, m)) {
        printf("Interstellar conflict resolution failed.\n");
    } else {
        printf("Interstellar color assignment successful!\n");
    }

    // Free allocated memory
    free(g);
    return 0;
}