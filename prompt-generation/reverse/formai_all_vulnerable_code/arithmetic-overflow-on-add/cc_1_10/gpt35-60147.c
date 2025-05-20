//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M;   // N = Number of nodes, M = Number of edges
int **adj;  // adjacency matrix
int *coloring;  // node color assignments
bool *used; // node usage tracker

// Initialize adjacency matrix with 0 values
void initAdj(){
    adj = (int**) malloc((N+1) * sizeof(int*));
    int i, j;
    for(i=1; i <= N; i++){
        adj[i] = (int*) calloc((N+1), sizeof(int));
    }
}

// Read input graph with given number of nodes and edges
void readGraph(){
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    printf("Enter the number of edges: ");
    scanf("%d", &M);
    initAdj();
    
    printf("Enter the edges (Eg. 2 3):\n");
    int i, j;
    for(i=1; i <= M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // undirected graph
    }
}

// Recursive graph coloring function
bool colorGraph(int node, int color){
    int i;
    for(i=1; i <= N; i++){
        if(adj[node][i] == 1 && coloring[i] == color){
            return false; // same color already used by adjacent node
        }
    }
    coloring[node] = color;
    used[node] = true;
    
    for(i=1; i <= N; i++){
        if(adj[node][i] == 1 && !used[i]){
            int j;
            for(j=1; j <= N; j++){
                if(colorGraph(i, j)){
                    return true;
                }
            }
        }
    }
    
    if(node == N){
        return true; // all nodes colored without conflicts
    }
    
    coloring[node] = 0;
    used[node] = false;
    return false;
}

// Main program
int main(){
    readGraph();
    coloring = (int*) calloc((N+1), sizeof(int));
    used = (bool*) calloc((N+1), sizeof(bool));
    
    int i, j;
    for(i=1; i <= N; i++){
        for(j=1; j <= N; j++){
            if(adj[i][j] != 1){
                adj[i][j] = 0;
            }
        }
    }
    
    int k;
    for(k=1; k <= N; k++){
        if(colorGraph(1, k)){
            printf("Graph is %d-colorable.\n", k);
            for(i=1; i <= N; i++){
                printf("Node %d: Color %d\n", i, coloring[i]);
            }
            break;
        }
    }
    
    if(k > N){
        printf("Graph is not colorable.\n");
    }
    
    free(coloring);
    free(used);
    for(i=1; i <= N; i++){
        free(adj[i]);
    }
    free(adj);
    return 0;
}