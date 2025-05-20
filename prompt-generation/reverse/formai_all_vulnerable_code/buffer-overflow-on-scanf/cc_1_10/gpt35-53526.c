//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VERTICES 50

int adj[MAX_VERTICES][MAX_VERTICES];
int vertexColor[MAX_VERTICES];

void generateGraph(int n){
    srand(time(NULL));
    int i, j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(rand()%2){
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
}

void printGraph(int n){
    int i, j;
    for(i=0;i<n;i++){
        printf("%d: ", i);
        for(j=0;j<n;j++){
            if(adj[i][j]){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int isSafe(int v, int c, int n){
    int i;
    for(i=0;i<n;i++){
        if(adj[v][i] && vertexColor[i] == c){
            return 0;
        }
    }
    return 1;
}

int graphColoringUtil(int n, int m, int v){
    if(v == n){
        return 1;
    }
    int c;
    for(c=1;c<=m;c++){
        if(isSafe(v, c, n)){
            vertexColor[v] = c;
            if(graphColoringUtil(n, m, v+1)){
                return 1;
            }
            vertexColor[v] = 0;
        }
    }
    return 0;
}

int graphColoring(int n, int m){
    int v;
    for(v=0;v<n;v++){
        vertexColor[v] = 0;
    }
    if(!graphColoringUtil(n, m, 0)){
        return 0;
    }
    return 1;
}

int main(){
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    generateGraph(n);
    printf("The generated graph is:\n");
    printGraph(n);
    if(graphColoring(n, m)){
        printf("The graph can be colored using %d colors\n", m);
        printf("The color of each vertex is:\n");
        int i;
        for(i=0;i<n;i++){
            printf("%d ", vertexColor[i]);
        }
    }else{
        printf("The graph cannot be colored using %d colors\n", m);
    }
    return 0;
}