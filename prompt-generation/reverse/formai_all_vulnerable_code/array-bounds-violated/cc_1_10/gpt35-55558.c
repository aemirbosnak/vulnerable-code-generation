//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50
#define MAX_DEGREE 50

int graph[MAX_VERTICES][MAX_DEGREE];
int color[MAX_VERTICES];
bool used[MAX_VERTICES];
int vertices, edges, numColors;

void get_adjacent_vertices(int vertex, int adjacent_vertices[]) {
    int count = 0;

    for (int i = 0; i < edges; i++) {
        if (graph[vertex][i] == 1) {
            adjacent_vertices[count++] = i;
        }
    }
}

void solve(int vertex) {
    int adjacent_vertices[MAX_DEGREE];
    int i, j, c;

    get_adjacent_vertices(vertex, adjacent_vertices);

    for (c = 1; c <= numColors; c++) {
        bool okay = true;

        for (j = 0; j < vertices; j++) {
            if (graph[vertex][j] && color[j] == c) {
                okay = false;
                break;
            }
        }

        if (okay) {
            color[vertex] = c;

            for (i = 0; i < edges; i++) {
                if (graph[vertex][i] == 1 && !used[i]) {
                    used[i] = true;
                    solve(i);
                    used[i] = false;
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < edges; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {
        int edgeStart, edgeEnd;
        printf("Enter the start vertex and end vertex of edge %d: ", i+1);
        scanf("%d %d", &edgeStart, &edgeEnd);

        graph[edgeStart][i] = 1;
        graph[edgeEnd][i] = 1;
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    for (int i = 0; i < vertices; i++) {
        color[i] = 0;
        used[i] = false;
    }

    solve(0);

    printf("The solution to the graph coloring problem is:\n");

    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: Color %d\n", i+1, color[i]);
    }

    return 0;
}