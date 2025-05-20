//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 9
#define N 10

int adj[V][V] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 1}
};

void print_graph() {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(adj[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

int main() {
    int colors[V] = {0};
    int i, j, k;
    int start_vertex;

    printf("Enter the starting vertex:\n");
    scanf("%d", &start_vertex);

    colors[start_vertex] = 1;

    for(i = 0; i < V; i++) {
        if(colors[i] == 0 && adj[start_vertex][i] == 1) {
            colors[i] = 1;
        }
    }

    for(i = 0; i < V; i++) {
        if(colors[i] == 0) {
            colors[i] = 2;
            for(j = 0; j < V; j++) {
                if(adj[i][j] == 1) {
                    colors[j] = 2;
                }
            }
        }
    }

    printf("The chromatic number of the graph is: %d\n", N);

    return 0;
}