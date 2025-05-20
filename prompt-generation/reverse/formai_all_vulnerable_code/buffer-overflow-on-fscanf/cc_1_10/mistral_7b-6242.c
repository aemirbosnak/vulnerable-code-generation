//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    int id;
    int visited;
} Node;

typedef struct {
    int src;
    int dest;
} Edge;

Node nodes[MAX_NODES];
int num_nodes, num_edges;
Edge adj_matrix[MAX_NODES][MAX_NODES];

void dfs(int node_id) {
    nodes[node_id].visited = true;
    printf("Visited Node %d\n", node_id);

    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[node_id][i].dest != -1) {
            if (!nodes[i].visited) {
                dfs(i);
            }
        }
    }
}

void read_input(const char *filename) {
    FILE *fp = fopen(filename, "r");
    int id1, id2;

    while (fscanf(fp, "%d %d", &id1, &id2) != EOF) {
        adj_matrix[id1][id2].dest = id2;
        adj_matrix[id2][id1].dest = id1;
        num_edges++;
    }

    fclose(fp);
}

void init() {
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i].id = i;
        nodes[i].visited = false;
    }

    num_nodes = 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    read_input(argv[1]);
    init();

    int start_node = 0;
    dfs(start_node);

    return 0;
}