//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct node {
    int value;
    int weight;
} Node;

int cmpfunc(const void* a, const void* b) {
    return ((Node*)a)->weight - ((Node*)b)->weight;
}

int main() {
    int n, m;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    
    Node graph[MAX_NODES][MAX_NODES];
    
    printf("Enter the adjacency matrix of the graph: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &graph[i][j].value);
            graph[i][j].weight = 0;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(graph[i][j].value != 0) {
                printf("Enter the weight between node %d and %d: ", i+1, j+1);
                scanf("%d", &graph[i][j].weight);
            }
        }
    }
    
    printf("Enter the starting node: ");
    int startNode;
    scanf("%d", &startNode);
    
    int visited[MAX_NODES] = {0};
    int finalPath[MAX_NODES];
    int pathLength = 0;
    
    printf("\nCalculating minimum path using greedy algorithm...\n");
    visited[startNode-1] = 1;
    finalPath[pathLength++] = startNode;
    int current = startNode-1;
    while(pathLength < n) {
        Node smallest;
        smallest.weight = 1000000;
        for(int i=0; i<n; i++) {
            if(i != current && graph[current][i].value != 0 && visited[i] == 0 && graph[current][i].weight < smallest.weight) {
                smallest = graph[current][i];
            }
        }
        if(smallest.weight == 1000000) {
            printf("Error: The graph is not connected\n");
            return 0;
        }
        visited[smallest.value-1] = 1;
        finalPath[pathLength++] = smallest.value;
        current = smallest.value-1;
    }
    
    printf("The minimum path is: %d", finalPath[0]);
    for(int i=1; i<n; i++) {
        printf(" -> %d", finalPath[i]);
    }
    printf("\n");
    return 0;
}