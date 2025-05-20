//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int n, m, k;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void init()
{
    srand(time(NULL));
    for (int i = 0; i < MAX_VERTICES; i++) {
        color[i] = rand() % MAX_COLORS;
    }
}

void print_solution()
{
    printf("Color of each vertex:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, color[i]);
    }
}

int is_valid(int v, int c)
{
    int count = 0;
    for (int u = 0; u < n; u++) {
        if (graph[v][u] == 1 && color[u] == c) {
            count++;
        }
    }
    return count == 0;
}

void backtrack(int v)
{
    if (v == n) {
        print_solution();
        exit(0);
    }

    for (int c = 1; c <= k; c++) {
        if (is_valid(v, c)) {
            color[v] = c;
            backtrack(v + 1);
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of colors: ");
    scanf("%d", &k);

    init();

    printf("Enter the edges of the graph (u v):\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
    }

    backtrack(0);

    return 0;
}