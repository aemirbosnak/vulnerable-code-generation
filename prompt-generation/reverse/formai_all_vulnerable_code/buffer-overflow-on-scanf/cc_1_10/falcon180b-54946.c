//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

int n, m, s, t, u, v, w, cnt = 0;
int dist[MAX_NODES];
int parent[MAX_NODES];
int adj[MAX_NODES][MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (adj[j][i]!= INF && dist[j] > dist[i] + adj[j][i]) {
                dist[i] = dist[j] + adj[j][i];
                parent[i] = j;
            }
        }
    }
}

int main() {
    int i, j, k, l;
    char input[100];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the source node: ");
    scanf("%d", &s);
    printf("Enter the destination node: ");
    scanf("%d", &t);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = INF;
        }
    }
    printf("Enter the edges with their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%s", input);
        k = input[0] - 'A';
        l = input[2] - 'A';
        adj[k][l] = input[4] - '0';
        adj[l][k] = adj[k][l];
    }
    dijkstra(s);
    printf("The shortest path from node %d to node %d is:\n", s, t);
    if (dist[t] == INF) {
        printf("There is no path between the two nodes.\n");
    } else {
        i = t;
        while (parent[i]!= -1) {
            printf("%c ", i + 'A');
            i = parent[i];
        }
        printf("%c\n", s + 'A');
    }
    return 0;
}