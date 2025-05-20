//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000
#define MAX_NAME_LENGTH 20

typedef struct node {
    char name[MAX_NAME_LENGTH];
    int index;
    int visited;
} Node;

typedef struct edge {
    Node *node1;
    Node *node2;
    int weight;
} Edge;

Node *create_node(char *name) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->index = -1;
    node->visited = 0;
    return node;
}

Edge *create_edge(Node *node1, Node *node2, int weight) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->node1 = node1;
    edge->node2 = node2;
    edge->weight = weight;
    return edge;
}

void add_edge(Edge *edges, int n, Node *node1, Node *node2, int weight) {
    edges[n].node1 = node1;
    edges[n].node2 = node2;
    edges[n].weight = weight;
}

void dfs(Node *nodes, int n, int start, int *visited) {
    visited[start] = 1;
    printf("%s ", nodes[start].name);
    for (int i = 0; i < n; i++) {
        if (nodes[i].visited == 0 && nodes[i].index == start) {
            dfs(nodes, n, i, visited);
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Node *nodes = (Node *) malloc(sizeof(Node) * n);
    Edge *edges = (Edge *) malloc(sizeof(Edge) * m);

    for (int i = 0; i < n; i++) {
        printf("Enter the name of node %d: ", i);
        scanf(" %[^\n]s", nodes[i].name);
        nodes[i].index = i;
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        printf("Enter the start node index: ");
        scanf("%d", &start);
        printf("Enter the end node index: ");
        scanf("%d", &end);
        add_edge(edges, i, nodes + start, nodes + end, 1);
    }

    int start = 0;
    int *visited = (int *) malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);

    dfs(nodes, n, start, visited);

    return 0;
}