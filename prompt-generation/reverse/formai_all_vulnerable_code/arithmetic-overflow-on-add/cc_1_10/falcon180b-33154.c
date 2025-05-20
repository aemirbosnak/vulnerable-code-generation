//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int id;
    int degree;
    int *adj_list;
} Node;

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

int read_graph(Node *nodes, Edge *edges) {
    FILE *fp;
    fp = fopen("graph.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open graph file.\n");
        exit(1);
    }

    int num_nodes = 0, num_edges = 0;
    fscanf(fp, "%d %d", &num_nodes, &num_edges);

    for (int i = 0; i < num_nodes; i++) {
        fscanf(fp, "%d", &nodes[i].id);
        nodes[i].degree = 0;
        nodes[i].adj_list = (int*)malloc(MAX_EDGES * sizeof(int));
        memset(nodes[i].adj_list, -1, MAX_EDGES * sizeof(int));
    }

    for (int i = 0; i < num_edges; i++) {
        fscanf(fp, "%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        nodes[edges[i].u].degree++;
        nodes[edges[i].v].degree++;
    }

    fclose(fp);
    return 0;
}

void print_graph(Node *nodes, Edge *edges) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (nodes[i].id!= -1) {
            printf("%d (%d edges): ", nodes[i].id, nodes[i].degree);
            for (int j = 0; j < nodes[i].degree; j++) {
                if (nodes[i].adj_list[j]!= -1) {
                    printf("%d ", nodes[i].adj_list[j]);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    read_graph(nodes, edges);
    print_graph(nodes, edges);

    return 0;
}