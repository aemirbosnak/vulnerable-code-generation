//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    int degree;
    bool visited;
} Node;

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(int id) {
    nodes[num_nodes].id = id;
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].visited = false;
    num_nodes++;
}

void add_edge(int start, int end, int weight) {
    edges[num_edges].start = start;
    edges[num_edges].end = end;
    edges[num_edges].weight = weight;
    num_edges++;
}

void dfs(int start, int parent) {
    nodes[start].visited = true;
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].visited)
            continue;
        if (edges[i].start == start) {
            dfs(edges[i].end, start);
        }
    }
}

int main() {
    int num_vertices, num_edges, start, end, weight;
    scanf("%d %d", &num_vertices, &num_edges);

    for (int i = 0; i < num_vertices; i++) {
        add_node(i);
    }

    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        add_edge(start, end, weight);
    }

    printf("DFS Traversal:\n");
    for (int i = 0; i < num_vertices; i++) {
        if (!nodes[i].visited) {
            dfs(i, -1);
            printf("\n");
        }
    }

    return 0;
}