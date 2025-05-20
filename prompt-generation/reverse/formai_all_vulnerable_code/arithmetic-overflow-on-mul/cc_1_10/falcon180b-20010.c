//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_NAME 20

struct node {
    char name[MAX_NAME];
    int id;
    int degree;
    int visited;
};

struct edge {
    int src;
    int dest;
    int weight;
};

void add_edge(struct edge edges[], int size, int src, int dest, int weight) {
    if (size >= MAX_EDGES) {
        printf("Error: Maximum edges limit reached\n");
        return;
    }
    edges[size].src = src;
    edges[size].dest = dest;
    edges[size].weight = weight;
    size++;
}

void add_node(struct node nodes[], int size, char name[], int id) {
    if (size >= MAX_NODES) {
        printf("Error: Maximum nodes limit reached\n");
        return;
    }
    strcpy(nodes[size].name, name);
    nodes[size].id = id;
    nodes[size].degree = 0;
    nodes[size].visited = 0;
    size++;
}

void bfs(struct node nodes[], int size, struct edge edges[], int start) {
    int i, j, k, u, v;
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    nodes[start].visited = 1;
    queue[rear++] = start;

    while (front < rear) {
        u = queue[front++];
        for (i = 0; i < nodes[u].degree; i++) {
            v = edges[nodes[u].id * MAX_NODES + i].dest;
            if (!nodes[v].visited) {
                nodes[v].visited = 1;
                nodes[v].degree++;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int i, j, n, m, u, v, w;
    char name[MAX_NAME];
    struct node nodes[MAX_NODES];
    struct edge edges[MAX_EDGES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%s", name);
        add_node(nodes, 0, name, i);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the source node ID: ");
        scanf("%d", &u);
        printf("Enter the destination node ID: ");
        scanf("%d", &v);
        printf("Enter the weight of edge: ");
        scanf("%d", &w);
        add_edge(edges, 0, u, v, w);
    }

    printf("BFS traversal starting from node %d:\n", 0);
    bfs(nodes, n, edges, 0);

    for (i = 0; i < n; i++) {
        if (!nodes[i].visited) {
            printf("Node %d is not reachable from node %d\n", i + 1, 0);
        }
    }

    return 0;
}