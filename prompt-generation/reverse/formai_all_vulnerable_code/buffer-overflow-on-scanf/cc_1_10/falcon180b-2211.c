//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10
#define INF INT_MAX

// Graph representation
int graph[MAX_VERTICES][MAX_VERTICES];
int n;

// Solution representation
int solution[MAX_VERTICES];

// Check if vertex v is adjacent to vertex u
int isAdjacent(int u, int v) {
    return graph[u][v]!= 0;
}

// Print the solution
void printSolution(int solution[], int n) {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, solution[i]);
    }
}

// Check if the solution is valid
int isValid(int solution[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isAdjacent(i, j) && solution[i] == solution[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Generate a random graph
void generateGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

// Solve the graph coloring problem using backtracking
int solveGraphColoring(int solution[], int n, int k, int color) {
    if (k == n) {
        return 1;
    }
    int i = rand() % n;
    if (solution[i] == -1) {
        for (int j = 0; j < MAX_COLORS; j++) {
            if (isValid(solution, n)) {
                solution[i] = j;
                if (solveGraphColoring(solution, n, k + 1, (j + 1) % MAX_COLORS)) {
                    return 1;
                }
            }
        }
        solution[i] = -1;
        return 0;
    }
    return 0;
}

// Main function
int main() {
    int n, k;
    srand(time(NULL));
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of colors: ");
    scanf("%d", &k);
    generateGraph(n);
    int solution[MAX_VERTICES];
    for (int i = 0; i < n; i++) {
        solution[i] = -1;
    }
    if (solveGraphColoring(solution, n, 0, 0)) {
        printSolution(solution, n);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}