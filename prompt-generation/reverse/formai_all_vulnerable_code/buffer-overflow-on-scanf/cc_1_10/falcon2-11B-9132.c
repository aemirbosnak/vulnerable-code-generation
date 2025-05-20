//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int checkColor(int **graph, int n, int *color, int index){
    if(index == n)
        return 1;

    int nextIndex = index + 1;
    if(nextIndex == n)
        return 1;

    int tempColor = color[nextIndex];
    color[nextIndex] = color[index];
    if(checkColor(graph, n, color, nextIndex) == 1){
        color[index] = tempColor;
        return 1;
    }
    color[index] = tempColor;
    return 0;
}

int minimumNumberOfColors(int **graph, int n){
    int color[n];
    for(int i = 0; i < n; i++){
        color[i] = i + 1;
    }
    if(checkColor(graph, n, color, 0) == 1)
        return 1;
    return 0;
}

int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **graph = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        graph[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            graph[i][j] = 0;
        }
    }
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("%d\n", minimumNumberOfColors(graph, n));
    return 0;
}