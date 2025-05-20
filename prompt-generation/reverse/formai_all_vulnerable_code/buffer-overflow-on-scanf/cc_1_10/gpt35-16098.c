//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

int stack[MAX_NODES], top = -1;
int visited[MAX_NODES] = {0};
int adj_matrix[MAX_NODES][MAX_NODES];
int num_of_nodes;

void dfs(int source, int destination) {
    if(source == destination) {
        printf("%d ", destination);
        return;
    }

    visited[source] = 1;
    stack[++top] = source;

    for(int i = 0; i < num_of_nodes; i++) {
        if(adj_matrix[source][i] && !visited[i]) {
            dfs(i, destination);
            if(stack[top] == destination) {
                printf("%d ", source);
                return;
            }
        }
    }

    top--;
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_of_nodes);

    printf("Enter the adjaceny matrix:\n");

    for(int i=0; i<num_of_nodes; i++) {
        for(int j=0; j<num_of_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    int source, destination;
    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter the destination node: ");
    scanf("%d", &destination);

    printf("Path between %d and %d is ", source, destination);
    dfs(source, destination);

    return 0;
}