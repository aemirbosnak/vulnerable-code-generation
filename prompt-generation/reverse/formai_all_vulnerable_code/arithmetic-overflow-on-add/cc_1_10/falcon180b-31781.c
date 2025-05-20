//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int id;
    char name[20];
    int x, y;
} Node;

typedef struct {
    int u, v;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int n, m, start, end;

void add_node(int id, char* name, int x, int y) {
    nodes[id].id = id;
    strcpy(nodes[id].name, name);
    nodes[id].x = x;
    nodes[id].y = y;
}

void add_edge(int u, int v, int weight) {
    edges[m].u = u;
    edges[m].v = v;
    edges[m].weight = weight;
    m++;
}

int dijkstra(int start, int end) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1, min_dist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }

        visited[u] = 1;

        for (int j = 0; j < m; j++) {
            if (edges[j].u == u &&!visited[edges[j].v]) {
                int new_dist = dist[u] + edges[j].weight;

                if (new_dist < dist[edges[j].v]) {
                    dist[edges[j].v] = new_dist;
                }
            }
        }
    }

    return dist[end];
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char name[20];
        printf("Enter node %d name: ", i + 1);
        scanf("%s", name);
        add_node(i + 1, name, 0, 0);
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        printf("Enter edge %d details (u v weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        add_edge(u, v, weight);
    }

    int start, end;
    printf("Enter start node ID: ");
    scanf("%d", &start);
    printf("Enter end node ID: ");
    scanf("%d", &end);

    int shortest_path = dijkstra(start, end);

    if (shortest_path == INF) {
        printf("No path found.\n");
    } else {
        printf("Shortest path: %d\n", shortest_path);
    }

    return 0;
}