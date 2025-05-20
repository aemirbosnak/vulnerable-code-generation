//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 100
#define INF 9999999

typedef struct {
    int vertex;
    int weight;
    struct Edge *next;
} Edge;

Edge *createEdge(int u, int v, int w) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->vertex = v;
    newEdge->weight = w;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(Edge **list, int u, int v, int w) {
    Edge *newEdge = createEdge(u, v, w);
    newEdge->next = *list;
    *list = newEdge;
}

typedef struct {
    int dist[MAX_VERTEX];
    int visited[MAX_VERTEX];
    int parent[MAX_VERTEX];
} Graph;

void initGraph(Graph *graph, int n) {
    for (int i = 0; i < n; i++) {
        graph->dist[i] = INF;
        graph->visited[i] = 0;
        graph->parent[i] = -1;
    }
}

void dijkstra(Graph *graph, int start, int end) {
    int n = graph->dist[start];
    int u = start;
    int v = end;
    int minDist = INF;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!graph->visited[i] && graph->dist[i] < minDist) {
            minDist = graph->dist[i];
            minIndex = i;
        }
    }

    graph->visited[minIndex] = 1;

    for (int k = 0; k < n; k++) {
        int w = graph->dist[k];
        if (w > graph->dist[minIndex] + graph->dist[k]) {
            graph->dist[k] = w;
            graph->parent[k] = minIndex;
        }
    }
}

void printSolution(Graph *graph, int n, int start, int end) {
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, graph->dist[i]);
    }
    printf("\n");
    printf("Shortest Path: ");
    int v = end;
    while (v!= -1) {
        printf("%d ", v);
        v = graph->parent[v];
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Edge **edgeList = (Edge **)malloc(m * sizeof(Edge *));

    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&edgeList[i], u, v, w);
    }

    Graph graph;
    initGraph(&graph, n);

    int start, end;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("Enter the ending vertex: ");
    scanf("%d", &end);

    dijkstra(&graph, start, end);
    printSolution(&graph, n, start, end);

    return 0;
}