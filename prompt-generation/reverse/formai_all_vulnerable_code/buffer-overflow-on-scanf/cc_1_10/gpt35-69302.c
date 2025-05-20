//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void read_graph(int vertices) {
    int i, j;
    for(i=0;i<vertices;i++) {
        for(j=0;j<vertices;j++) {
            scanf("%d",&graph[i][j]);
        }
    }
}

int safe_color(int vert, int vertices, int c) {
    int i;
    for(i=0;i<vertices;i++) {
        if(graph[vert][i] && color[i]==c) {
            return 0;
        }
    }
    return 1;
}

void print_colors(int vertices) {
    int i;
    printf("\nVertex\tColor\n");
    for(i=0;i<vertices;i++) {
        printf("%d\t%d\n",i,color[i]);
    }
}

void graph_coloring(int vert, int vertices, int colors) {
    int i;
    if(vert == vertices) {
        print_colors(vertices);
        return;
    }
    for(i=1;i<=colors;i++) {
        if(safe_color(vert, vertices, i)) {
            color[vert] = i;
            graph_coloring(vert + 1, vertices, colors);
            color[vert] = 0;
        }
    }
}

int main() {
    int vertices, colors;
    printf("Enter number of vertices : ");
    scanf("%d",&vertices);
    printf("Enter adjacency matrix :\n");
    read_graph(vertices);
    printf("Enter number of colors : ");
    scanf("%d",&colors);
    graph_coloring(0, vertices, colors);
    return 0;
}