//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: distributed
#include <stdio.h>
#include <limits.h>

#define ROW 5
#define COL 5

int graph[ROW][COL] = {
    {0, 4, 2, 0, 0},
    {4, 0, 1, 5, 0},
    {2, 1, 0, 8, 10},
    {0, 5, 8, 0, 2},
    {0, 0, 10, 2, 0}
};

int visited[ROW] = {0}; // To track visited nodes 
int path[ROW] = {-1}; // To store the path of traversal  
int dist[ROW] = {INT_MAX}; // To store the minimum distance from source to each node

// Function to print the path of traversal
void printPath(int dest) {
    if (path[dest] == -1) {
        printf("%d ", dest);
        return;
    }
    printPath(path[dest]);
    printf("%d ", dest);
}

// Function to find the next node with the minimum distance
int minDistance() {
    int minDist = INT_MAX, minIndex = -1;
    
    for (int i = 0; i < ROW; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

// Dijkstra's Algorithm implementation
void dijkstra(int src) {
    dist[src] = 0; // Initialize distance of source node as 0
    
    for (int i = 0; i < ROW - 1; i++) {
        int u = minDistance(); // Pick the minimum distance vertex from the set of unvisited nodes
        visited[u] = 1; // Mark the picked node as visited
        
        for (int v = 0; v < COL; v++) { // Update dist[v] only if it is not visited, there is an edge from u to v, and total weight of path from src to v through u is smaller than current
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
}

int main() {
    int src = 0;
    printf("Enter source node (between 0 to %d): ", ROW - 1);
    scanf("%d", &src);
    
    dijkstra(src); // Find the shortest path from the given source node
    
    printf("Vertex \t Distance \t Path");
    for (int i = 0; i < ROW; i++) {
        printf("\n %d \t\t %d \t\t ", i, dist[i]);
        printPath(i);
    }
    
    return 0;
}