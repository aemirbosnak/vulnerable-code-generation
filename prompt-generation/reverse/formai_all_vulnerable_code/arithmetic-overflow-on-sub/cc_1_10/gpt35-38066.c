//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int graph[MAX][MAX], color[MAX];
int n, m;

//function to check if the current color is safe for the vertex
int isSafe(int vertex, int c){
    for(int i=0; i<n; i++){
        if(graph[vertex][i] && c==color[i]){
            return 0;
        }
    }
    return 1;
}

//function to color the vertex with a safe color
int colorVertex(int vertex, int maxColors){
    if(vertex == n){   //if all vertices are already colored
        return 1;
    }
    for(int i=1; i<=maxColors; i++){
        if(isSafe(vertex, i)){
            color[vertex] = i;
            if(colorVertex(vertex+1, maxColors)){
                return 1;
            }
            color[vertex] = 0;    //backtrack
        }
    }
    return 0;
}

int main(){
    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\n Enter the number of edges: ");
    scanf("%d", &m);
    int u, v;
    for(int i=0; i<m; i++){
        printf("\n Enter the vertices of edge %d: ", i+1);
        scanf("%d%d", &u, &v);
        graph[u-1][v-1] = graph[v-1][u-1] = 1;   //edge exists between u and v
    }

    int maxColors = n;    //maximum possible colors
    while(!colorVertex(0, maxColors)){
        maxColors++;    //increase the maximum colors until a valid coloring is possible
        for(int i=0; i<n; i++){
            color[i] = 0;    //reset the colors
        }
    }

    printf("\n The graph can be colored using %d colors as: \n", maxColors);
    for(int i=0; i<n; i++){
        printf(" Vertex %d ---> Color %d \n", i+1, color[i]);
    }

    return 0;
}