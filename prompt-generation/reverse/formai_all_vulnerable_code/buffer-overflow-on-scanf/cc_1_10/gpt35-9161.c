//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLOR 4

int n;
int edgeCount;
int maxDegree;
int maxDIndex;
int colors[1000];
int degree[1000];
int edge[1000][1000];

bool isSafe(int vertexIndex, int color){
    for(int i=0; i<n; i++){
        if(edge[vertexIndex][i] && color==colors[i]){
            return false;
        }
    }
    return true;
}

void setColor(int vertexIndex){
    for(int c=1; c<=MAX_COLOR; c++){
        if(isSafe(vertexIndex, c)){
            colors[vertexIndex] = c;
            break;
        }
    }
}

void printColors(){
    for(int i=0; i<n; i++){
        printf("Vertex %d --> Color %d\n", i,colors[i]);
    }
}

void greedyColoring(){
    for(int i=0; i<n; i++){
        setColor(i);
    }
}

int main(){
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);
    printf("Enter the edges: \n");

    for(int e=0; e<edgeCount; e++){
        int edges[2];
        scanf("%d %d", &edges[0], &edges[1]);
        edge[edges[0]][edges[1]] = 1;
        edge[edges[1]][edges[0]] = 1;
        degree[edges[0]]++;
        degree[edges[1]]++;

        if(degree[edges[0]] > maxDegree){
            maxDegree = degree[edges[0]];
            maxDIndex = edges[0];
        }
        if(degree[edges[1]] > maxDegree){
            maxDegree = degree[edges[1]];
            maxDIndex = edges[1];
        }
    }

    greedyColoring();
    printColors();

    return 0;
}