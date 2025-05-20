//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

int num_vertices, num_edges;
int graph[MAX_VERTICES][MAX_VERTICES];

void colorGraph(int colors[])
{
    int i, j;

    for (i = 0; i < num_vertices; i++) {
        int available[MAX_VERTICES] = { 0 };

        for (j = 0; j < num_vertices; j++) {
            if (graph[i][j] && colors[j] != -1) {
                available[colors[j]] = 1;
            }
        }

        for (j = 0; j < num_vertices; j++) {
            if (!available[j]) {
                break;
            }
        }

        colors[i] = j;
    }
}

int main()
{
    int i, j;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &num_vertices, &num_edges);

    for (i = 0; i < num_edges; i++) {
        int u, v;

        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        graph[u][v] = graph[v][u] = 1;
    }

    int colors[MAX_VERTICES] = { -1 };
    colorGraph(colors);

    printf("Vertex\tColor\n");
    for (i = 0; i < num_vertices; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }

    return 0;
}