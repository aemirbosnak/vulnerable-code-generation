//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], color[MAX], V, E;

void setColor(int node) {
    int i, c;
    for(c = 1; ; c++) {
        for(i = 1; i <= V; i++)
            if(adj[node][i] && color[i] == c) 
                goto NextColor;
        break;
        NextColor: continue;
    }
    color[node] = c;
}

void printColors() {
    int i;
    printf("\n");
    for(i = 1; i <= V; i++)
        printf("Vertex %d : Color %d\n", i, color[i]);
}

int main() {
    int i, j, v1, v2;
    printf("Welcome to the Graph Coloring Problem Program! :))\n\n");
    printf("Please enter the number of vertices: ");
    scanf("%d", &V);
    printf("Please enter the number of edges: ");
    scanf("%d", &E);
    printf("\n");

    for(i = 1; i <= V; i++)
        for(j = 1; j <= V; j++)
            adj[i][j] = 0;
    
    printf("Enter the connection between two vertices: \n");
    for(i = 0; i < E; i++) {
        printf("Edge %d : ", i + 1);
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;
    }

    for(i = 1; i <= V; i++) 
        color[i] = 0;
    
    printf("\n-- Coloring of Vertices --\n");
    for(i = 1; i <= V; i++) {
        setColor(i);
        printf("Vertex %d is colored!\n", i);
    }

    printf("\n-- Final Coloring --\n");
    printColors();

    printf("\nGreat Job! You have successfully colored your graph! :))");

    return 0;
}