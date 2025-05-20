//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define V 9

// Function to print the solution
void printSolution(int graph[V][V], int n, int solution[V])
{
    printf("\nSolution:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");
}

// Function to check if the solution is valid or not
int isValid(int graph[V][V], int n, int solution[V], int i, int j, int k)
{
    for (int l = 0; l < V; l++) {
        if (graph[i][l] == k || graph[l][j] == k) {
            return 0;
        }
    }
    return 1;
}

// Function to color the graph using backtracking
void color(int graph[V][V], int n, int solution[V], int k, int i, int j)
{
    // Base case
    if (i == j) {
        solution[i] = k;
        return;
    }

    // Recursive case
    for (int l = 1; l <= n; l++) {
        if (isValid(graph, n, solution, i, j, l)) {
            solution[i] = l;
            solution[j] = l;
            color(graph, n, solution, l, i + 1, j - 1);
        }
    }
}

// Function to generate a random graph
void generateGraph(int graph[V][V])
{
    srand(time(NULL));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = rand() % V;
        }
    }
}

// Main function
int main()
{
    int graph[V][V], solution[V];
    int i, j, k;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &k);
    printf("\nEnter the graph:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nEnter the number of colors: ");
    scanf("%d", &k);
    color(graph, V, solution, 1, 0, V - 1);
    printf("\nThe minimum number of colors required to color the graph is %d\n", k);
    printSolution(graph, V, solution);
    return 0;
}