//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#define max 100

int color[max];
int adj[max][max];
int n;

void graph_input() {
    int i,j;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix: \n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d",&adj[i][j]);
        }
    }
}

void graph_color(int vertex) {
    int i,j;
    int c=1;
    while(1) {
        int ok=1;
        for(i=0; i<n; i++) {
            if(adj[vertex][i] && color[i]==c) {
                ok=0;
                break;
            }
        }
        if(ok) {
            color[vertex]=c;
            break;
        }
        c++;
    }
}

void graph_coloring() {
    int i,j;
    for(i=0; i<n; i++) {
        color[i]=0;
    }
    for(i=0; i<n; i++) {
        graph_color(i);
    }
}

void graph_output() {
    int i;
    printf("\nColoring of the vertices: ");
    for(i=0; i<n; i++) {
        printf("%d ",color[i]);
    }
}

int main() {
    graph_input();
    graph_coloring();
    graph_output();
    return 0;
}