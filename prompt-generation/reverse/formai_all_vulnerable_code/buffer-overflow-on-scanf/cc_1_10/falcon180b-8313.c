//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 9999

typedef struct {
    int vertex;
    int weight;
    struct edge* next;
} Edge;

typedef struct {
    int vertex;
    int degree;
    Edge* adj;
} Vertex;

void addEdge(Vertex* graph, int u, int v, int w) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->vertex = v;
    newEdge->weight = w;
    newEdge->next = graph[u].adj;
    graph[u].adj = newEdge;
    graph[v].degree++;
}

void dijkstra(Vertex* graph, int source, int destination) {
    int n = graph[0].degree;
    int visited[n];
    int distance[n];
    for(int i=0; i<n; i++) {
        visited[i] = 0;
        distance[i] = INF;
    }
    distance[source] = 0;
    for(int i=1; i<n; i++) {
        int u = -1;
        int minDistance = INF;
        for(int j=0; j<n; j++) {
            if(!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                u = j;
            }
        }
        visited[u] = 1;
        for(Edge* e = graph[u].adj; e!= NULL; e = e->next) {
            int v = e->vertex;
            int newDistance = distance[u] + e->weight;
            if(newDistance < distance[v]) {
                distance[v] = newDistance;
            }
        }
    }
    printf("Shortest distance from %d to %d is %d\n", source, destination, distance[destination]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Vertex* graph = (Vertex*)malloc(sizeof(Vertex) * n);
    for(int i=0; i<n; i++) {
        graph[i].vertex = i;
        graph[i].degree = 0;
        graph[i].adj = NULL;
    }
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
        addEdge(graph, v, u, w);
        graph[u].degree++;
        graph[v].degree++;
    }
    int source, destination;
    scanf("%d %d", &source, &destination);
    dijkstra(graph, source, destination);
    return 0;
}