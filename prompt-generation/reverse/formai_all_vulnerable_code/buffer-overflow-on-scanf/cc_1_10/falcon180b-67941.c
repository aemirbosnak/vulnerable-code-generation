//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int id;
    double x, y;
} Node;

typedef struct {
    int from, to;
    double weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(double x, double y) {
    nodes[num_nodes].id = num_nodes;
    nodes[num_nodes].x = x;
    nodes[num_nodes].y = y;
    num_nodes++;
}

void add_edge(int from, int to, double weight) {
    edges[num_edges].from = from;
    edges[num_edges].to = to;
    edges[num_edges].weight = weight;
    num_edges++;
}

void generate_graph(int num_nodes, int num_edges) {
    srand(time(NULL));
    for (int i = 0; i < num_nodes; i++) {
        double x = rand() % 1000;
        double y = rand() % 1000;
        add_node(x, y);
    }

    for (int i = 0; i < num_edges; i++) {
        int from = rand() % num_nodes;
        int to = rand() % num_nodes;
        while (from == to) {
            to = rand() % num_nodes;
        }
        double weight = rand() % 1000;
        add_edge(from, to, weight);
    }
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: (%f, %f)\n", nodes[i].id, nodes[i].x, nodes[i].y);
    }

    for (int i = 0; i < num_edges; i++) {
        printf("Edge %d: (%d, %d, %f)\n", i, edges[i].from, edges[i].to, edges[i].weight);
    }
}

int main() {
    int num_nodes, num_edges;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    generate_graph(num_nodes, num_edges);
    print_graph();

    return 0;
}