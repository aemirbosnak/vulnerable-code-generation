//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 100
#define MAX_COLORS 7

int num_nodes, num_edges;
int adj_matrix[MAX_NODES][MAX_NODES];
int color_map[MAX_NODES];

void init_graph() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(int node1, int node2) {
    adj_matrix[node1][node2] = 1;
    adj_matrix[node2][node1] = 1;
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (adj_matrix[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

int is_valid_color(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[node][i] == 1 && color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int start_time = clock();

    srand(time(NULL));

    for (int i = 0; i < num_nodes; i++) {
        color_map[i] = rand() % MAX_COLORS;
    }

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < MAX_COLORS; j++) {
            if (is_valid_color(i, j)) {
                color_map[i] = j;
                break;
            }
        }
    }

    int end_time = clock();
    printf("Time taken: %d ms\n", end_time - start_time);

    print_graph();
}

int main() {
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &num_nodes, &num_edges);

    init_graph();

    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        printf("Enter the two nodes connected by edge %d: ", i+1);
        scanf("%d %d", &node1, &node2);
        add_edge(node1, node2);
    }

    color_graph();

    return 0;
}