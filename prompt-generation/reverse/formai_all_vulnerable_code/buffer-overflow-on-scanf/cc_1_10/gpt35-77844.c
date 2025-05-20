//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES]; // matrix to store circuit graph
int visited[MAX_NODES]; // to keep track of visited nodes

int num_nodes, num_edges;

void DFS(int node) // depth-first traversal
{
    visited[node] = 1;
    printf("%d ", node);
    
    for(int i=0; i<num_nodes; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main()
{
    printf("Enter number of nodes in the circuit: ");
    scanf("%d", &num_nodes);
    
    printf("Enter number of edges in the circuit: ");
    scanf("%d", &num_edges);
    
    printf("Enter edge connections: \n");
    for(int i=0; i<num_edges; i++) {
        int node1, node2;
        printf("Edge %d: ", i+1);
        scanf("%d %d", &node1, &node2);
        
        if(node1<num_nodes && node2<num_nodes) {
            graph[node1][node2] = 1;
            graph[node2][node1] = 1;
        }
        else {
            printf("Invalid node!\n");
            i--;
        }
    }
    
    printf("Circuit graph:\n");
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    printf("DFS traversal of the circuit graph: ");
    DFS(0);
    
    return 0;
}