//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], nodes, edges;

void read_graph() {
    int i, j, start, end, color;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for(i = 0; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }
    for(i = 0; i < edges; i++) {
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);
        graph[start - 1][end - 1] = 1;
        graph[end - 1][start - 1] = 1;
    }
}

void color_graph(int colors[]) {
    int i, j, k, available[MAX];
    colors[0] = 0;
    for(i = 1; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            available[j] = 1;
        }
        for(j = 0; j < nodes; j++) {
            if(graph[i][j]) {
                if(colors[j] != -1) {
                    available[colors[j]] = 0;
                }
            }
        }
        for(k = 0; k < nodes; k++) {
            if(available[k]) {
                break;
            }
        }
        colors[i] = k;
    }
}

void print_graph(int colors[]) {
    int i, j;
    printf("Colors: \n");
    for(i = 0; i < nodes; i++) {
        printf("Node %d: Color %d\n", i + 1, colors[i]);
    }
}

int main() {
    int colors[MAX], i;

    read_graph();

    for(i = 0; i < nodes; i++) {
        colors[i] = -1;
    }

    color_graph(colors);

    print_graph(colors);

    return 0;
}