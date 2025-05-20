//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NODES 10
#define MAX_COLORS 3

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix representation of graph
int color[MAX_NODES]; // Array to store color assigned to each node

int isSafe(int node, int c, int n) {
    for(int i=0; i<n; i++) { // Check if any adjacent nodes has the same color
        if(graph[node][i] && color[i]==c) {
            return 0;
        }
    }
    return 1;
}

void printGraph(int n) {
    printf("\nAdjacency Matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printColoring(int n) {
    printf("\nColors Assigned:\n");
    for(int i=0; i<n; i++) {
        printf("Node %d: Color %d\n", i+1, color[i]);
    }
}

void graphColor(int node, int n, int colors) {
    if(node==n) { // Base case: all nodes have been assigned colors
        printColoring(n);
        return;
    }
    for(int i=1; i<=colors; i++) { // Try all possible colors for the current node
        if(isSafe(node, i, n)) { // If assigning this color is safe, proceed with recursion
            color[node] = i;
            graphColor(node+1, n, colors);
            color[node] = 0; // Backtrack
        }
    }
}

int main() {

    srand(time(NULL)); // Seed for random graph generation

    int n, c; // Number of nodes, number of colors
    printf("Enter the number of nodes in the graph (max %d): ", MAX_NODES);
    scanf("%d", &n);
    if(n>MAX_NODES) {
        printf("Invalid input. Exiting...\n");
        return 0;
    }
    printf("Enter the number of colors to be used (max %d): ", MAX_COLORS);
    scanf("%d", &c);
    if(c>MAX_COLORS) {
        printf("Invalid input. Exiting...\n");
        return 0;
    }
    printf("\nGenerating random graph...\n");
    for(int i=0; i<n; i++) { // Generate a random graph
        for(int j=0; j<n; j++) {
            if(i==j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = rand()%2; // Randomly generate 0 or 1
                graph[j][i] = graph[i][j]; // Graph is undirected, so copy to opposite diagonal element
            }
        }
    }
    printGraph(n);
    printf("\nFinding color assignments...\n");
    graphColor(0, n, c);
    return 0;
}