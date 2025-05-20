//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLOURS 10

typedef struct {
    int node;
    int color;
} GraphNode;

GraphNode graph[MAX_NODES];
int color_count[MAX_COLOURS];
int node_count;
int color_used[MAX_COLOURS];

void color_graph(GraphNode graph[], int node_count, int color_count[]) {
    int i, j;

    for (i = 0; i < node_count; i++) {
        for (j = 0; j < color_count[i]; j++) {
            graph[i].color = j;
        }
    }
}

int main() {
    int i, j, k;
    int node, color;

    node_count = 0;

    while (scanf("%d", &node)!= EOF) {
        node_count++;
        graph[node_count].node = node;
        graph[node_count].color = -1;
        color_used[node] = 0;
    }

    for (i = 0; i < node_count; i++) {
        for (j = 0; j < node_count; j++) {
            if (i!= j && graph[i].color!= graph[j].color) {
                graph[j].color = graph[i].color;
                color_used[graph[i].node]++;
                color_used[graph[j].node]++;
            }
        }
    }

    for (i = 0; i < node_count; i++) {
        if (color_used[i] < MAX_COLOURS) {
            color_used[i] = MAX_COLOURS;
        }
    }

    color_graph(graph, node_count, color_count);

    printf("Graph Coloring Problem\n");
    for (i = 0; i < node_count; i++) {
        printf("%d %d\n", graph[i].node, graph[i].color);
    }

    return 0;
}