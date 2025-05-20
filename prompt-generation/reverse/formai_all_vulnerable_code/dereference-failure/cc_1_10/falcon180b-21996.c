//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 9999

typedef struct {
    int id;
    char name[20];
    int degree;
    int *adj_list;
} Node;

void add_edge(Node *graph, int u, int v, int weight) {
    graph[u].adj_list[graph[u].degree++] = v;
    graph[v].adj_list[graph[v].degree++] = u;
    graph[u].adj_list[graph[u].degree - 1] = weight;
    graph[v].adj_list[graph[v].degree - 1] = weight;
}

void print_graph(Node *graph, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Node %d: %s\n", graph[i].id, graph[i].name);
        printf("Adjacency list: ");
        int j;
        for (j = 0; j < graph[i].degree; j++) {
            printf("%d ", graph[i].adj_list[j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node *graph = (Node *)malloc(n * sizeof(Node));
    int i, u, v, weight;
    for (i = 0; i < n; i++) {
        scanf("%d %s", &graph[i].id, graph[i].name);
        graph[i].degree = 0;
        graph[i].adj_list = (int *)malloc(MAX_EDGES * sizeof(int));
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        add_edge(graph, u, v, weight);
    }
    print_graph(graph, n);
    return 0;
}