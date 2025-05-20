//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 10 //Number of vertices
#define C 4 //Number of colors
#define INF 999 //Infinity
#define DEBUG 1 //Debug flag

int graph[V][V]; //Adjacency matrix
int color[V]; //Vertex colors
int min_color[V]; //Minimum color for each vertex
int parent[V]; //Parent vertex for each vertex

void init() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = rand() % 2; //Randomly assign edges
        }
    }
}

void print_solution(int v) {
    printf("Vertex %d: ", v);
    for (int i = 0; i < V; i++) {
        if (color[i] == min_color[v]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void print_graph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

void backtrack(int v, int c) {
    if (v == -1) {
        return;
    }
    color[v] = c;
    min_color[v] = c;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == -1) {
            parent[i] = v;
            backtrack(i, c + 1);
        }
    }
}

int main() {
    srand(time(NULL));
    init();
    int start_time = clock();
    backtrack(0, 0);
    int end_time = clock();
    printf("Time taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    if (DEBUG) {
        print_graph();
        for (int i = 0; i < V; i++) {
            print_solution(i);
        }
    }
    return 0;
}