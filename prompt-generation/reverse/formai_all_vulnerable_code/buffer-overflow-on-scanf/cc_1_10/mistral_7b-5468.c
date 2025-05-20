//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTS 100
#define MAX_EDGES 500
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int dest;
    bool visited;
} adjList;

int graph[MAX_VERTS][MAX_VERTS];
adjList *adjLists;
int num_verts, num_edges, colors[MAX_VERTS];

void initializeGraph() {
    int i, j;

    for (i = 0; i < MAX_VERTS; i++) {
        for (j = 0; j < MAX_VERTS; j++) {
            graph[i][j] = 0;
            adjLists[i].dest = -1;
            adjLists[i].visited = false;
        }
    }
}

void addEdge(int source, int destination) {
    graph[source][destination] = 1;
    adjLists[source].dest = destination;
}

bool isGraphColorableUtil(int v, int m) {
    for (int i = 0; i < num_verts; i++) {
        if (adjLists[i].visited && graph[i][v] && colors[i] == m) {
            return false;
        }
    }
    return true;
}

bool isGraphColorable(int m) {
    int i;

    for (i = 0; i < num_verts; i++) {
        if (!isGraphColorableUtil(i, m)) {
            return false;
        }
    }
    return true;
}

void graphColoringUtil(int m, int v) {
    if (v >= num_verts) {
        if (isGraphColorable(m)) {
            printf("Graph is colorable with %d colors\n", m);
            for (int i = 0; i < num_verts; i++) {
                printf("Vertex %d colored with %d\n", i, colors[i]);
            }
            exit(EXIT_SUCCESS);
        }
    }

    bool colorAvailable = false;

    for (int i = MIN_COLOR; i <= MAX_COLOR; i++) {
        if (isGraphColorableUtil(v, i)) {
            colors[v] = i;
            graphColoringUtil(m + 1, v + 1);
            colors[v] = -1;
            colorAvailable = true;
        }
    }

    if (!colorAvailable) {
        m--;
        if (m > MIN_COLOR) {
            graphColoringUtil(m, v);
        }
    }
}

int main() {
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &num_verts);

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    adjLists = (adjList *)calloc(num_verts, sizeof(adjList));

    initializeGraph();

    printf("Enter edges (source destination): \n");

    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &j, &k);
        addEdge(j, k);
        addEdge(k, j);
    }

    graphColoringUtil(MIN_COLOR, 0);

    free(adjLists);

    return EXIT_SUCCESS;
}