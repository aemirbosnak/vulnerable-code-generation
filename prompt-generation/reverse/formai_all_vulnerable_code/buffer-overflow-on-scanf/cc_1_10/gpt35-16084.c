//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

#define MAX_COLORS 4
#define MAX_VERTICES 10

int G[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int promising(int idx, int color) {
    for(int i=0;i<MAX_VERTICES;i++) {
        if(G[idx][i] == 1 && colors[i] == color)
            return 0;
    }
    return 1;
}

void graph(int vertices) {
    printf("\nEnter the graph adjacency matrix:\n");
    for(int i=0;i<vertices;i++) {
        for(int j=0;j<vertices;j++) {
            scanf("%d",&G[i][j]);
        }
    }
}

void print_colors(int vertices) {
    printf("\nThe coloring of graph is:\n");
    for(int i=0;i<vertices;i++) {
        printf("Vertex %d --> Color %d\n",i+1,colors[i]);
    }
}

void graph_coloring(int idx, int vertices) {
    if(idx == vertices) {
        print_colors(vertices);
        exit(0);
    }
    for(int i=1;i<=MAX_COLORS;i++) {
        if(promising(idx,i)) {
            colors[idx] = i;
            graph_coloring(idx+1,vertices);
            colors[idx] = 0;
        }
    }
}

int main() {
    int vertices;
    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d",&vertices);
    graph(vertices);
    graph_coloring(0,vertices);
    printf("\nNo solution exists for given graph.\n");
    return 0;
}