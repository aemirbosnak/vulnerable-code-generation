//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

struct Node {
    char name[10];
    int id;
    int visited;
};

struct Edge {
    int node1;
    int node2;
    int weight;
};

void addEdge(struct Edge* edges, int n, int u, int v, int w) {
    edges[n].node1 = u;
    edges[n].node2 = v;
    edges[n].weight = w;
    n++;
}

void dijkstra(int* dist, int n, struct Edge* edges, int start) {
    int i, j, u, v;
    int minDist = INF;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    for (i = 1; i <= n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (dist[j]!= INF && dist[j] + edges[j].weight < dist[edges[j].node1]) {
                dist[edges[j].node1] = dist[j] + edges[j].weight;
            }
        }
    }
}

void printSolution(int dist[], int n) {
    int i;
    printf("\nVertex\t Distance from source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int n, m, i, j, u, v, w, start;
    struct Node nodes[MAX_NODES];
    struct Edge edges[MAX_EDGES];
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    char name[10];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i + 1;
        nodes[i].visited = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges in the form of node1 node2 weight: ");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(edges, 0, u, v, w);
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(dist, n, edges, start);

    printf("\nThe shortest distances from node %d are:\n", start);
    printSolution(dist, n);

    return 0;
}