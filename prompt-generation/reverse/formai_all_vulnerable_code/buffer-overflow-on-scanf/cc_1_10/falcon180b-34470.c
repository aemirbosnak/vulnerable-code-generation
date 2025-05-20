//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_VERTICES 100
#define MAX_COLOR 7
#define INF 9999999

int V, E;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int ncolor[MAX_COLOR];
int min_color[MAX_VERTICES];

void init() {
    srand(time(NULL));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = rand() % 2;
        }
        color[i] = rand() % MAX_COLOR;
    }
    for (int i = 0; i < MAX_COLOR; i++) {
        ncolor[i] = 0;
    }
}

void print_solution() {
    printf("Vertex   Color\n");
    for (int i = 0; i < V; i++) {
        printf("%d %d\n", i, color[i]);
    }
    printf("\n");
}

void color_graph() {
    int k = 0;
    for (int i = 0; i < V; i++) {
        int c = 0;
        for (int j = 0; j < MAX_COLOR; j++) {
            if (graph[i][k] == 0 && color[k]!= j) {
                color[i] = j;
                graph[i][k] = 1;
                break;
            }
        }
        if (c == MAX_COLOR) {
            printf("No solution exists!\n");
            exit(0);
        }
        k = (k + 1) % V;
    }
}

void backtrack(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 0 && color[i]!= c && color[i]!= -1) {
            color[i] = c;
            graph[v][i] = 1;
            backtrack(i, c);
            graph[v][i] = 0;
        }
    }
}

void solve() {
    int s = 0;
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            s = i;
            break;
        }
    }
    color[s] = 0;
    backtrack(s, 0);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    init();
    solve();
    print_solution();

    return 0;
}