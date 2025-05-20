//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

int nodes, edges;
int graph[1000][1000];

int getColor(int node, int color[], int max_colors) {
    int used[max_colors];
    for(int i=0; i<max_colors; i++) {
        used[i] = 0;
    }

    for(int neighbour=0; neighbour<nodes; neighbour++) {
        if(graph[node][neighbour]) {
            if(color[neighbour] != -1) {
                used[color[neighbour]] = 1;
            }
        }
    }

    for(int c=0; c<max_colors; c++) {
        if(!used[c]) {
            return c;
        }
    }

    return -1;
}

void graphColoring(int max_colors) {
    int color[nodes];
    for(int i=0;i<nodes;i++) {
        color[i] = -1;
    }

    for(int node=0; node<nodes; node++) {
        color[node] = getColor(node, color, max_colors);
    }

    printf("Coloring of vertices\n");
    for(int i=0;i<nodes;i++) {
        printf("Vertex: %d Color: %d\n", i+1, color[i]+1);
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for(int i=0;i<edges;i++){
        printf("\nEnter the start and end vertices of edge %d:\n",i+1);
        int u, v;
        scanf("%d %d", &u,&v);
        graph[u-1][v-1] = graph[v-1][u-1] = 1;
    }

    int max_colors;
    printf("\nEnter the maximum number of colors: ");
    scanf("%d", &max_colors);

    graphColoring(max_colors);

    return 0;
}