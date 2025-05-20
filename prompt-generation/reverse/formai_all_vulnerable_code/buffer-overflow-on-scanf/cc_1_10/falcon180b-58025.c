//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 50
#define MAX_COLORS 6

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix to represent graph
int colors[MAX_NODES]; // Array to store color assigned to each node
int num_colors; // Number of colors used in the solution

void init_graph() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int node1, int node2) {
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;
}

void print_graph() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            if (graph[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

void assign_colors() {
    int i, j, k;
    int colors_available[MAX_COLORS] = {1, 2, 3, 4, 5, 6};
    for (i = 0; i < MAX_NODES; i++) {
        colors[i] = 0;
    }
    num_colors = 1;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_COLORS; j++) {
            if (colors_available[j] == 1) {
                colors[i] = j;
                colors_available[j] = 0;
                num_colors++;
                break;
            }
        }
        if (num_colors == MAX_COLORS) {
            printf("ERROR: Not enough colors available\n");
            exit(1);
        }
    }
}

void print_solution() {
    int i;
    printf("Solution:\n");
    for (i = 0; i < MAX_NODES; i++) {
        printf("%d - %d\n", i, colors[i]);
    }
}

int main() {
    srand(time(NULL));
    init_graph();
    int num_nodes, num_edges;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);
    int i, node1, node2;
    for (i = 0; i < num_edges; i++) {
        printf("Enter two nodes connected by edge %d: ", i+1);
        scanf("%d %d", &node1, &node2);
        add_edge(node1, node2);
    }
    assign_colors();
    print_solution();
    return 0;
}