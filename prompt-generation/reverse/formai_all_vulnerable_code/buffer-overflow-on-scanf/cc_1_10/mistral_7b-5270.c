//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct Node {
    int id;
    int visited;
    int *adj;
} Node;

Node nodes[MAX_NODES];
int num_nodes, num_edges;
int graph[MAX_NODES][MAX_NODES];

void dfs(int node_id) {
    nodes[node_id].visited = true;
    printf("Visiting Node %d\n", node_id);

    for (int i = 0; i < num_nodes; ++i) {
        if (nodes[i].adj && graph[node_id][i] && !nodes[i].visited) {
            dfs(i);
        }
    }
}

void init_graph() {
    int source, destination;

    for (int i = 0; i < num_edges; ++i) {
        scanf("%d %d", &source, &destination);
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }
}

void init_nodes() {
    for (int i = 0; i < num_nodes; ++i) {
        nodes[i].id = i;
        nodes[i].visited = false;
        nodes[i].adj = malloc(num_nodes * sizeof(int));
    }
}

void map_topology() {
    for (int i = 0; i < num_nodes; ++i) {
        if (!nodes[i].visited) {
            dfs(i);
        }
    }
}

void build_adj_mat() {
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            if (i == j) continue;
            if (graph[i][j]) {
                nodes[i].adj[j] = 1;
            }
        }
    }
}

int main() {
    printf("\nWelcome, dear reader, to this enchanting journey\n");
    printf("Through the mesmerizing world of network topology mapping!\n");
    printf("Enter the number of nodes and edges in the network:\n");
    scanf("%d %d", &num_nodes, &num_edges);

    init_nodes();
    init_graph();

    printf("Building adjacency matrix...\n");
    build_adj_mat();

    printf("Network Topology Mapping:\n");
    map_topology();

    return 0;
}