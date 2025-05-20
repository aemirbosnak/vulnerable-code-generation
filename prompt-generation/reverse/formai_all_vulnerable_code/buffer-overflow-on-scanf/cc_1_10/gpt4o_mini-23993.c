//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define COLORS 3

typedef struct Creature {
    int id;
    char name[20];
} Creature;

typedef struct Graph {
    int vertices;
    bool adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    Creature creatures[MAX_VERTICES];
} Graph;

void initializeGraph(Graph *g, int vertices);
void addEdge(Graph *g, int source, int destination);
bool isSafe(int vertex, Graph *g, int color[], int c);
bool graphColoringUtil(Graph *g, int m, int color[], int vertex);
void printSolution(int color[], int vertices);
void assignCreatureNames(Graph *g);
void displayGraph(Graph *g);

int main() {
    Graph g;
    int m; // number of colors

    printf("Welcome to the Land of Colorful Creatures!\n");
    printf("How many homes (vertices) do we have? (Max %d): ", MAX_VERTICES);
    scanf("%d", &g.vertices);

    initializeGraph(&g, g.vertices);
    assignCreatureNames(&g);

    printf("Let's connect these homes with friendships! Enter the friendships (pairs of vertices, -1 to stop): \n");
    int src, dest;
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 || dest == -1) {
            break;
        }
        addEdge(&g, src, dest);
    }

    printf("Now, how many colors should we use to paint these homes? (Max %d): ", COLORS);
    scanf("%d", &m);

    int color[MAX_VERTICES];
    for (int i = 0; i < g.vertices; i++) {
        color[i] = -1; // Initialize all colors as -1
    }

    if (graphColoringUtil(&g, m, color, 0)) {
        printSolution(color, g.vertices);
    } else {
        printf("No solution possible with %d colors!\n", m);
    }

    displayGraph(&g);

    return 0;
}

void initializeGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = false;
        }
    }
}

void addEdge(Graph *g, int source, int destination) {
    g->adjacencyMatrix[source][destination] = true;
    g->adjacencyMatrix[destination][source] = true; // Undirected graph
}

bool isSafe(int vertex, Graph *g, int color[], int c) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjacencyMatrix[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(Graph *g, int m, int color[], int vertex) {
    if (vertex == g->vertices) {
        return true;
    }
    
    for (int c = 0; c < m; c++) {
        if (isSafe(vertex, g, color, c)) {
            color[vertex] = c;
            if (graphColoringUtil(g, m, color, vertex + 1)) {
                return true;
            }
            color[vertex] = -1; // Backtrack
        }
    }
    return false;
}

void printSolution(int color[], int vertices) {
    printf("Coloring of the homes:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Creature ID: %d, Color: %d\n", i, color[i]);
    }
}

void assignCreatureNames(Graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        sprintf(g->creatures[i].name, "Creature_%d", i);
    }
}

void displayGraph(Graph *g) {
    printf("Friendship Connections:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            if (g->adjacencyMatrix[i][j]) {
                printf("%s <-> %s\n", g->creatures[i].name, g->creatures[j].name);
            }
        }
    }
}