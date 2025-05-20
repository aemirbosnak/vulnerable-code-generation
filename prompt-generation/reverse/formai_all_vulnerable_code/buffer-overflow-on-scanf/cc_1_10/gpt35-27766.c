//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 50
#define INF 999999
 
int graph[MAX_NODES][MAX_NODES]; // adjacency matrix representation
int distances[MAX_NODES]; // shortest distance from source node
bool visited[MAX_NODES]; // flag for visited nodes
 
int minDistance(int n){
    int min = INF;
    int min_index = -1;
    
    for (int i = 0; i < n; i++){
        if (!visited[i] && distances[i] <= min){
            min = distances[i];
            min_index = i;
        }
    }
 
    return min_index;
}
 
void dijkstra(int n, int source){
    for (int i = 0; i < n; i++){
        distances[i] = INF;
        visited[i] = false;
    }
    
    distances[source] = 0;
    
    for (int i = 0; i < n; i++){
        int u = minDistance(n);
        visited[u] = true;
        
        for (int v = 0; v < n; v++){
            if (!visited[v] && graph[u][v] && distances[u] != INF && distances[u] + graph[u][v] < distances[v]){
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
}
 
void printDistances(int n){
    printf("Shortest distances from source:\n");
    
    for (int i = 0; i < n; i++){
        printf("%d: %d\n", i, distances[i]);
    }
}

int main(){
    int n, source, dest, weight;
    
    printf("Enter the number of nodes in the graph (up to %d): ", MAX_NODES);
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix of the graph:\n");
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the source node: ");
    scanf("%d", &source);
    
    printf("Enter the destination node: ");
    scanf("%d", &dest);
    
    dijkstra(n, source);
    printDistances(n);
    printf("Shortest distance from source to destination is: %d\n", distances[dest]);
    
    return 0;
}