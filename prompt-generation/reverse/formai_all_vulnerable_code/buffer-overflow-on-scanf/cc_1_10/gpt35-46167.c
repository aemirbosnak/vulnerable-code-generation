//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 10

int graph[N][N];
int colorCount[N];
int colorAssigned[N];

bool isSafe(int v, int c) {
    for(int i = 0; i < N; i++) {
        if(graph[v][i] && colorAssigned[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColorSolver(int v) {
    if(v == N) {
        return true;
    }

    for(int c = 1; c <= colorCount[v]; c++) {
        if(isSafe(v, c)) {
            colorAssigned[v] = c;
            if(graphColorSolver(v+1)) {
                return true;
            }
            colorAssigned[v] = 0;
        }
    }
    return false;
}

void printSolution() {
    printf("Assigned Colors :\n");
    for(int i = 0; i < N; i++) {
        printf("Vertex %d => Color %d\n", i+1, colorAssigned[i]);
    }
}

int main() {
    int i, j;
    printf("Enter the graph adjacency matrix :\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors for each vertex (minimum 1):\n");
    for(i = 0; i < N; i++) {
        printf("Vertex %d : ", i+1);
        scanf("%d", &colorCount[i]);
    }

    if(graphColorSolver(0)) {
        printSolution();
    }
    else {
        printf("No Solution Exists !!!\n");
    }
    return 0;
}